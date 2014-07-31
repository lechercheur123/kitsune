//*****************************************************************************
//
// commands.c - FreeRTOS porting example on CCS4
//
// Copyright (c) 2012 Fuel7, Inc.
//
//*****************************************************************************

#include <stdio.h>
#include <string.h>
#include <assert.h>

#include <hw_types.h>
#include <hw_memmap.h>
#include <prcm.h>
#include <pin.h>
#include <uart.h>
#include <stdarg.h>
#include <stdlib.h>
#include "rom_map.h"

/* FreeRTOS includes */
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "queue.h"

#include "fault.h"

#include "cmdline.h"
#include "ustdlib.h"
#include "uartstdio.h"

#include "wifi_cmd.h"
#include "i2c_cmd.h"
#include "dust_cmd.h"

#define NUM_LOGS 72

//// ==============================================================================
//// The CPU usage in percent, in 16.16 fixed point format.
//// ==============================================================================
//extern unsigned long g_ulCPUUsage;
//
//// ==============================================================================
//// This function implements the "cpu" command.  It prints the CPU type, speed
//// and current percentage utilization.
//// ==============================================================================
//int Cmd_cpu(int argc, char *argv[])
//{
//    //
//    // Print some header text.
//    //
//    UARTprintf("ARM Cortex-M4F %u MHz - ",configCPU_CLOCK_HZ / 1000000);
//    UARTprintf("%2u%% utilization\n", (g_ulCPUUsage+32768) >> 16);
//
//    // Return success.
//    return(0);
//}

// ==============================================================================
// This function implements the "free" command.  It prints the free memory.
// ==============================================================================
int Cmd_free(int argc, char *argv[]) {
	//
	// Print some header text.
	//
	UARTprintf("%d bytes free\n", xPortGetFreeHeapSize());

	// Return success.
	return (0);
}

#include "fs.h"

int Cmd_fs_write(int argc, char *argv[]) {
	//
	// Print some header text.
	//
	unsigned long tok;
	int err;
	long hndl, bytes;
	SlFsFileInfo_t info;

	sl_FsGetInfo(argv[1], tok, &info);

	if (sl_FsOpen(argv[1],
	FS_MODE_OPEN_WRITE, &tok, &hndl)) {
		UARTprintf("error opening file, trying to create\n");

		if (sl_FsOpen(argv[1],
				FS_MODE_OPEN_CREATE(65535, _FS_FILE_OPEN_FLAG_COMMIT), &tok,
				&hndl)) {
			UARTprintf("error opening for write\n");
			return -1;
		}
	}

	bytes = sl_FsWrite(hndl, info.FileLen, argv[2], strlen(argv[2]));
	UARTprintf("wrote to the file %d bytes\n", bytes);

	sl_FsClose(hndl, 0, 0, 0);

	// Return success.
	return (0);
}
int Cmd_fs_read(int argc, char *argv[]) {
	//
	// Print some header text.
	//
#define minval( a,b ) a < b ? a : b
#define BUF_SZ 600
	unsigned long tok;
	long hndl, err, bytes, i;
	SlFsFileInfo_t info;
	char buffer[BUF_SZ];

	sl_FsGetInfo(argv[1], tok, &info);

	if (err = sl_FsOpen(argv[1], FS_MODE_OPEN_READ, &tok, &hndl)) {
		UARTprintf("error opening for read %d\n", err);
		return -1;
	}

	if (bytes = sl_FsRead(hndl, 0, buffer, minval(info.FileLen, BUF_SZ))) {
		UARTprintf("read %d bytes\n", bytes);
	}

	sl_FsClose(hndl, 0, 0, 0);

	for (i = 0; i < bytes; ++i) {
		UARTprintf("%x", buffer[i]);
	}

	// Return success.
	return (0);
}
int Cmd_fs_delete(int argc, char *argv[]) {
	//
	// Print some header text.
	//
	int err;

	if (err = sl_FsDel(argv[1], 0)) {
		UARTprintf("error %d\n", err);
		return -1;
	}

	// Return success.
	return (0);
}

/* Bitlog function
 * Invented by Tom Lehman at Invivo Research, Inc.,
 * ca. 1990
 *
 * Gives an integer analog of the log function
 * For large x,
 *
 * B(x) = 8*(log(base 2)(x) - 1)
 */

short bitlog(unsigned long n)
{
   short b;

   // shorten computation for small numbers
   if(n <= 8)
      return (short)(2 * n);

   // find the highest non-zero bit
   b=31;
   while((b > 2) && ((long)n > 0))
   {
      --b;
      n <<= 1;
   }
   n &= 0x70000000;
   n >>= 28;
   return (short)n + 8 * (b - 1);
}


/* Bitexp function
 * returns an integer value equivalent to the exponential. For numbers > 16,
bitexp(x) approx = 2^(x/8 + 1) */

unsigned long bitexp(unsigned short n)
{
   unsigned short b = n/8;
   unsigned long retval;

   // make sure no overflow
   if(n > 247)
      return 0xf0000000;

   // shorten computation for small numbers
   if(n <= 16)
      return (unsigned long)(n / 2);

   retval = n & 7;
   retval |= 8;

   return (retval << (b - 2));
}

unsigned long get_time() {
	portTickType now = xTaskGetTickCount();
	static portTickType unix_now = 0;
	unsigned long ntp = 0;
	static unsigned long last_ntp = 0;

	if (last_ntp == 0) {

		while (ntp == 0) {
			while (!(sl_status & HAS_IP)) {
				vTaskDelay(100);
			} //wait for a connection the first time...

			ntp = last_ntp = unix_time();
		}

		unix_now = now;
	} else if (last_ntp != 0) {
		ntp = last_ntp + (now - unix_now) / 1000;
		last_ntp = ntp;
		unix_now = now;
	}
	return ntp;
}

int thread_prox(void* unused) {
	while (1) {
		int prox = get_prox();

		UARTprintf("%d\n", prox);

		vTaskDelay( 100 );
	} //try every little bit
}

#define SENSOR_RATE 60

static unsigned int dust_val=0;
static unsigned int dust_cnt=0;
xSemaphoreHandle dust_smphr;

int thread_dust(void* unused) {
    #define maxval( a, b ) a>b ? a : b
	while (1) {
		if (xSemaphoreTake(dust_smphr, portMAX_DELAY)) {
			++dust_cnt;
			dust_val += get_dust();
			xSemaphoreGive(dust_smphr);
		}

		vTaskDelay( 100 );
	}
}

static int light_m2,light_mean, light_cnt,light_log_sum,light_sf;
static xSemaphoreHandle light_smphr;

static xSemaphoreHandle i2c_smphr;

int thread_light(void* unused) {
    #define maxval( a, b ) a>b ? a : b
	#define LIGHT_BUFSZ 10
	unsigned char buf[LIGHT_BUFSZ];
	unsigned int idx,i;

	while (1) {
		portTickType now = xTaskGetTickCount();
		int light;

		if (xSemaphoreTake(i2c_smphr, portMAX_DELAY)) {
			light = get_light();
			xSemaphoreGive(i2c_smphr);

			if (xSemaphoreTake(light_smphr, portMAX_DELAY)) {
				light_log_sum += bitlog(light);
				++light_cnt;

				int delta = light - light_mean;
				light_mean = light_mean + delta/light_cnt;
				light_m2 = light_m2 + delta * ( light - light_mean);
				if( light_m2 < 0 ) {
					light_m2 = 0x7FFFFFFF;
				}

				//UARTprintf( "%d %d %d %d\n", delta, light_mean, light_m2, light_cnt);

				xSemaphoreGive(light_smphr);
			}
		} else {
			vTaskDelay(100);
			continue;
		}

		vTaskDelayUntil(&now, 100 );
	}
}

xQueueHandle data_queue = 0;

int thread_tx(void* unused) {
	data_t data;

	while (1) {
		if( data_queue != 0 && !xQueueReceive( data_queue, &( data ), portMAX_DELAY ) ) {
			vTaskDelay(100);
			continue;
		}

		UARTprintf("sending time %d\tlight %d, %d, %d\ttemp %d\thumid %d\tdust %d\n",
				data.time, data.light, data.light_variability, data.light_tonality, data.temp, data.humid,
				data.dust);

		while (!send_data_pb(&data) == 0) {
			do {vTaskDelay(100);} //wait for a connection...
			while( !(sl_status&HAS_IP ) );
		}//try every little bit
	}
}


int thread_sensor_poll(void* unused) {

	//
	// Print some header text.
	//

	data_t data;

	while (1) {
		portTickType now = xTaskGetTickCount();
		int light;

		data.time = get_time();

		if( xSemaphoreTake( dust_smphr, portMAX_DELAY ) ) {
			if( dust_cnt != 0 ) {
				data.dust = dust_val / dust_cnt;
			} else {
				data.dust = get_dust();
			}
			dust_val = dust_cnt = 0;
			xSemaphoreGive( dust_smphr );
		} else {
			data.dust = get_dust();
		}
		if (xSemaphoreTake(light_smphr, portMAX_DELAY)) {
			light_log_sum /= light_cnt;
			light_sf = (light_mean<<8) / bitexp( light_log_sum );

			int light_var = light_m2 / (light_cnt-1);

			//UARTprintf( "%d lightsf %d var %d cnt\n", light_sf, light_var, light_cnt );

			data.light_variability = light_var;
			data.light_tonality = light_sf;
			data.light = light_mean;
			light_m2 = light_mean = light_cnt = light_log_sum = light_sf = 0;
			xSemaphoreGive(light_smphr);
		}
		if (xSemaphoreTake(i2c_smphr, portMAX_DELAY)) {
			data.humid = get_humid();
			data.temp = get_temp();
			xSemaphoreGive(i2c_smphr);
		} else {
			continue;
		}
		UARTprintf("collecting time %d\tlight %d, %d, %d\ttemp %d\thumid %d\tdust %d\n",
				data.time, data.light, data.light_variability, data.light_tonality, data.temp, data.humid,
				data.dust);

		    // ...

        xQueueSend( data_queue, ( void * ) &data, 10 );

		UARTprintf("delay...\n");
		vTaskDelayUntil(&now, SENSOR_RATE * configTICK_RATE_HZ);
	}

}

// ==============================================================================
// This function implements the "tasks" command.  It prints a list of the
// current FreeRTOS tasks with information about status, stack usage, etc.
// ==============================================================================
#if ( configUSE_TRACE_FACILITY == 1 )

int Cmd_tasks(int argc, char *argv[]) {
	signed char* pBuffer;

	pBuffer = pvPortMalloc(1024);
	vTaskList(pBuffer);
	UARTprintf("\t\t\t\t\tUnused\nTaskName\t\tStatus\tPri\tStack\tTask ID\n");
	UARTprintf("=======================================================");
	UARTprintf("%s", pBuffer);

	vPortFree(pBuffer);
	return 0;
}

#endif /* configUSE_TRACE_FACILITY */

// ==============================================================================
// This function implements the "help" command.  It prints a simple list of the
// available commands with a brief description.
// ==============================================================================
int Cmd_help(int argc, char *argv[]) {
	tCmdLineEntry *pEntry;

	//
	// Print some header text.
	//
	UARTprintf("\nAvailable commands\n");
	UARTprintf("------------------\n");

	//
	// Point at the beginning of the command table.
	//
	pEntry = &g_sCmdTable[0];

	//
	// Enter a loop to read each entry from the command table.  The end of the
	// table has been reached when the command name is NULL.
	//
	while (pEntry->pcCmd) {
		//
		// Print the command name and the brief description.
		//
		UARTprintf("%s: %s\n", pEntry->pcCmd, pEntry->pcHelp);

		//
		// Advance to the next entry in the table.
		//
		pEntry++;
	}

	//
	// Return success.
	//
	return (0);
}


int Cmd_fault(int argc, char *argv[]) {
	*(int*) (0x40001) = 1; /* error logging test... */

	return (0);
}

// ==============================================================================
// This is the table that holds the command names, implementing functions, and
// brief description.
// ==============================================================================
tCmdLineEntry g_sCmdTable[] = {
		{ "help", Cmd_help, "Display list of commands" },
		{ "?", Cmd_help,"alias for help" },
//    { "cpu",      Cmd_cpu,      "Show CPU utilization" },
		{ "free", Cmd_free, "Report free memory" },
		{ "connect", Cmd_connect, "Connect to an AP" },
		{ "ping", Cmd_ping, "Ping a server" },
		{ "time", Cmd_time, "get ntp time" },
		{ "status", Cmd_status, "status of simple link" },
//    { "mnt",      Cmd_mnt,      "Mount the SD card" },
//    { "umnt",     Cmd_umnt,     "Unount the SD card" },
//    { "ls",       Cmd_ls,       "Display list of files" },
//    { "chdir",    Cmd_cd,       "Change directory" },
//    { "cd",       Cmd_cd,       "alias for chdir" },
//    { "mkdir",    Cmd_mkdir,    "make a directory" },
//    { "rm",       Cmd_rm,       "Remove file" },
//    { "write",    Cmd_write,    "Write some text to a file" },
//    { "mkfs",     Cmd_mkfs,     "Make filesystem" },
//    { "pwd",      Cmd_pwd,      "Show current working directory" },
//    { "cat",      Cmd_cat,      "Show contents of a text file" },
		{ "fault", Cmd_fault, "Trigger a hard fault" },
		{ "i2crd", Cmd_i2c_read,"i2c read" },
		{ "i2cwr", Cmd_i2c_write, "i2c write" },
		{ "i2crdrg", Cmd_i2c_readreg, "i2c readreg" },
        { "i2cwrrg", Cmd_i2c_writereg, "i2c_writereg" },

		{ "humid", Cmd_readhumid, "i2 read humid" },
		{ "temp", Cmd_readtemp,	"i2 read temp" },
		{ "light", Cmd_readlight, "i2 read light" },
		{"proximity", Cmd_readproximity, "i2 read proximity" },
#if ( configUSE_TRACE_FACILITY == 1 )
		{ "tasks", Cmd_tasks, "Report stats of all tasks" },
#endif

		{ "dust", Cmd_dusttest, "dust sensor test" },

		{ "fswr", Cmd_fs_write, "fs write" },
		{ "fsrd", Cmd_fs_read, "fs read" },
		{ "fsdl", Cmd_fs_delete, "fs delete" },
		//{ "readout", Cmd_readout_data, "read out sensor data log" },
		{ "sl", Cmd_sl, "start smart config" },
		{ "mode", Cmd_mode, "set the ap/station mode" },

		{ 0, 0, 0 } };

//#include "fault.h"
//static void checkFaults() {
//    faultInfo f;
//    memcpy( (void*)&f, SHUTDOWN_MEM, sizeof(f) );
//    if( f.magic == SHUTDOWN_MAGIC ) {
//        faultPrinter(&f);
//    }
//}

// ==============================================================================
// This is the UARTTask.  It handles command lines received from the RX IRQ.
// ==============================================================================
extern xSemaphoreHandle g_xRxLineSemaphore;
void UARTStdioIntHandler(void);

void vUARTTask(void *pvParameters) {
	char cCmdBuf[64];
	int nStatus;

	//
	// Initialize the UART for console I/O.
	//
	UARTStdioInit(0);

	UARTIntRegister(UARTA0_BASE, UARTStdioIntHandler);

	sl_mode = sl_Start(NULL, NULL, NULL);
	unsigned char mac[6];
	unsigned char mac_len;
	sl_NetCfgGet(SL_MAC_ADDRESS_GET, NULL, &mac_len, mac);

	UARTprintf("\n\nFreeRTOS %s, %d, %s %x%x%x%x%x%x\n",
	tskKERNEL_VERSION_NUMBER, KIT_VER, MORPH_NAME, mac[0], mac[1], mac[2],
			mac[3], mac[4], mac[5]);
	UARTprintf("\n? for help\n");
	UARTprintf("> ");

	vTaskDelay(1000);
	if (sl_mode == ROLE_AP || !sl_status) {
		Cmd_sl(0, 0);
	}

	 data_queue = xQueueCreate( 60, sizeof( data_t ) );
	 vSemaphoreCreateBinary( dust_smphr );
	 vSemaphoreCreateBinary( light_smphr );
	 vSemaphoreCreateBinary( i2c_smphr );

	if (data_queue == 0) {
		UARTprintf("Failed to create the data_queue.\n");
	}

	xTaskCreate(thread_light, "lightTask", 5 * 1024 / 4, NULL, 3, NULL);
	xTaskCreate(thread_dust, "dustTask", 256 / 4, NULL, 3, NULL);
	xTaskCreate(thread_sensor_poll, "pollTask", 1 * 1024 / 4, NULL, 3, NULL);
	xTaskCreate(thread_tx, "txTask", 7 * 1024 / 4, NULL, 2, NULL);

	//checkFaults();

	/* Loop forever */
	while (1) {

		/* Wait for a signal indicating we have an RX line to process */
		xSemaphoreTake(g_xRxLineSemaphore, portMAX_DELAY);

		if (UARTPeek('\r') != -1) {
			/* Read data from the UART and process the command line */
			UARTgets(cCmdBuf, sizeof(cCmdBuf));
			if (ustrlen(cCmdBuf) == 0) {
				UARTprintf("> ");
				continue;
			}

			//
			// Pass the line from the user to the command processor.  It will be
			// parsed and valid commands executed.
			//
			nStatus = CmdLineProcess(cCmdBuf);

			//
			// Handle the case of bad command.
			//
			if (nStatus == CMDLINE_BAD_CMD) {
				UARTprintf("Bad command!\n");
			}

			//
			// Handle the case of too many arguments.
			//
			else if (nStatus == CMDLINE_TOO_MANY_ARGS) {
				UARTprintf("Too many arguments for command processor!\n");
			}

			//
			// Otherwise the command was executed.  Print the error code if one was
			// returned.
			//
			else if (nStatus != 0) {
				UARTprintf("Command returned error code %d\n", nStatus);
			}

			UARTprintf("> ");
		}
	}
}
