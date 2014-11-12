#include "audiohelper.h"

#include "network.h"
#include "audioprocessingtask.h"
#include "mcasp_if.h"
#include "hw_types.h"
#include "udma.h"
#include "pcm_handler.h"
#include "i2c_cmd.h"
#include "i2s.h"
#include "udma_if.h"
#include "circ_buff.h"
#include "simplelink.h"
#include "rom.h"
#include "rom_map.h"
#include "utils.h"
#include "hw_ints.h"
// common interface includes
#include "common.h"
#include "hw_memmap.h"
#include "fatfs_cmd.h"
#include "ff.h"


/* externs */
extern tCircularBuffer *pTxBuffer;
extern tCircularBuffer *pRxBuffer;

#define AUDIO_CAPTURE_RATE_HZ  (16000)
#define AUDIO_PLAYBACK_RATE_HZ (48000)

static const unsigned int CPU_XDATA_CAPTURE = 1; //1: enabled CPU interrupt triggerred

static const unsigned int CPU_XDATA_PLAYBACK = 0; //1: enabled CPU interrupt triggerred, 0 for DMA


uint8_t InitAudioCapture(void) {
	pTxBuffer = CreateCircularBuffer(TX_BUFFER_SIZE);

	if(pTxBuffer == NULL) {
		return 0;
	}

	get_codec_mic_NAU();

	// Initialize the Audio(I2S) Module
	AudioCapturerInit(CPU_XDATA_CAPTURE, AUDIO_CAPTURE_RATE_HZ);

	// Initialize the DMA Module
	UDMAInit();

	UDMAChannelSelect(UDMA_CH4_I2S_RX, NULL);

	// Setup the DMA Mode
	SetupPingPongDMATransferTx();

	// Setup the Audio In/Out
	AudioCapturerSetupDMAMode(DMAPingPongCompleteAppCB_opt, CB_EVENT_CONFIG_SZ);
	AudioCaptureRendererConfigure(I2S_PORT_DMA, AUDIO_CAPTURE_RATE_HZ);

	// Start Audio Tx/Rx
	Audio_Start();

	return 1;
}

void DeinitAudioCapture(void) {
	Audio_Stop();

	McASPDeInit();

	if (pTxBuffer) {
		DestroyCircularBuffer(pTxBuffer);
		pTxBuffer = NULL;
	}
}

uint8_t InitAudioPlayback(int32_t vol) {

	//create circular buffer
	pRxBuffer = CreateCircularBuffer(RX_BUFFER_SIZE);

	if (!pRxBuffer) {
		return 0;
	}

	//zero out RX byffer
	memset(pRxBuffer->pucBufferStartPtr,0,RX_BUFFER_SIZE);

	//////
	// SET UP AUDIO PLAYBACK
	get_codec_NAU(vol);

	// Initialize the Audio(I2S) Module
	AudioCapturerInit(CPU_XDATA_PLAYBACK, AUDIO_PLAYBACK_RATE_HZ);

	// Initialize the DMA Module
	UDMAInit();

	UDMAChannelSelect(UDMA_CH5_I2S_TX, NULL);

	// Setup the DMA Mode
	SetupPingPongDMATransferRx();

	// Setup the Audio In/Out
	AudioCapturerSetupDMAMode(DMAPingPongCompleteAppCB_opt, CB_EVENT_CONFIG_SZ);
	AudioCaptureRendererConfigure(I2S_PORT_DMA, AUDIO_PLAYBACK_RATE_HZ);

	//do whatever this function does
	Audio_Start();

	return 1;

}

void DeinitAudioPlayback(void) {
	close_codec_NAU();
	Audio_Stop();

	McASPDeInit();

	if (pRxBuffer) {
		DestroyCircularBuffer(pRxBuffer);
	}
}


///// FILE STUFF/////


uint8_t InitFile(Filedata_t * pfiledata) {
	FRESULT res;
	FILINFO file_info;

	/*  If we got here, then the file should already be closed */
	uint8_t ret = 1;
	/* open file */
	res = f_open(&pfiledata->file_obj, pfiledata->file_name, FA_WRITE|FA_OPEN_ALWAYS);

	/*  Did something horrible happen?  */
	if(res != FR_OK && res != FR_EXIST){
		ret = 0;
	}
	else {
		//append to file if it already exists
		memset(&file_info, 0, sizeof(FILINFO));

		f_stat(pfiledata->file_name, &file_info);

		if(file_info.fsize != 0 ){
			res = f_lseek(&pfiledata->file_obj, file_info.fsize);
		}
	}

	return ret;

}

uint8_t WriteToFile(Filedata_t * pfiledata,const WORD bytes_to_write,const uint8_t * const_ptr_samples_bytes) {
	WORD bytes = 0;
	WORD bytes_written = 0;
	FRESULT res;
	uint8_t ret = 1;


	/* write until we cannot write anymore.  This does take a finite amount of time, by the way.  */
	do {
		res = f_write(&pfiledata->file_obj, const_ptr_samples_bytes +  bytes_written , bytes_to_write-bytes_written, &bytes );

		bytes_written+=bytes;

		if (res != FR_OK) {
			ret = 0;
			break;
		}

	} while( bytes_written < bytes_to_write );

	return ret;

}

void CloseFile(Filedata_t * pfiledata) {
	f_close(&pfiledata->file_obj)	;
	memset(&pfiledata->file_obj, 0, sizeof(file_obj));

}
