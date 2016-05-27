#include "hlo_pipe.h"
#include "task.h"
#include "uart_logger.h"


int hlo_stream_transfer_until(transfer_direction direction,
							hlo_stream_t * stream,
							uint8_t * buf,
							uint32_t buf_size,
							uint32_t transfer_delay,
							bool * flush ) {

	int ret, idx = 0;
	while(idx < buf_size){
		if(direction == INTO_STREAM){
			ret = hlo_stream_write(stream, buf+idx, buf_size - idx);
		}else{
			ret = hlo_stream_read(stream, buf+idx, buf_size - idx);
		}

		if( flush && *flush ) {
			if( ret > 0 ) {
				return ret + idx;
			} else {
				return HLO_STREAM_EOF;
			}
		}
		if(ret == HLO_STREAM_EOF){
			if( idx ){
				return idx;
			}else{
				return ret;
			}
		}else if(ret < 0){
			return ret;
		}else{
			idx += ret;
			if(idx == buf_size){
				return idx;
			}
			if(ret == 0){
				vTaskDelay(transfer_delay);
			}
		}
	}
	return HLO_STREAM_ERROR;
}

int hlo_stream_transfer_all(transfer_direction direction,
							hlo_stream_t * stream,
							uint8_t * buf,
							uint32_t buf_size,
							uint32_t transfer_delay){
	return hlo_stream_transfer_until( direction, stream, buf, buf_size, transfer_delay, NULL);
}
int hlo_stream_transfer_between(
		hlo_stream_t * src,
		hlo_stream_t * dst,
		uint8_t * buf,
		uint32_t buf_size,
		uint32_t transfer_delay){

	int ret = hlo_stream_transfer_all(FROM_STREAM, src, buf,buf_size, transfer_delay);
	if(ret < 0){
		return ret;
	}
	return hlo_stream_transfer_all(INTO_STREAM, dst, buf,ret,transfer_delay);

}

#define DBG_FRAMEPIPE(...)

int frame_pipe_encode( pipe_ctx * pipe ) {
	uint8_t buf[512];
	uint16_t short_len;
	int ret;
	int transfer_delay = 100;

	DBG_FRAMEPIPE("e frame start\n");

	ret = hlo_stream_transfer_until(FROM_STREAM, pipe->source, buf,sizeof(buf), transfer_delay, &pipe->flush);
	DBG_FRAMEPIPE("erd %d\n", ret);
	if(ret < 0){
		return ret;
	}
	short_len = ret;
	ret = hlo_stream_transfer_all(INTO_STREAM, pipe->sink, (uint8_t*)&short_len,ret,transfer_delay);
	DBG_FRAMEPIPE("elen %d\n", ret);
	if(ret < 0){
		return ret;
	}
	return hlo_stream_transfer_all(INTO_STREAM, pipe->sink, buf,ret,transfer_delay);
}
int frame_pipe_decode( pipe_ctx * pipe ) {
	uint8_t buf[512];
	uint16_t short_len;
	int bytes_remaining;
	int ret;
	int transfer_delay = 100;

	DBG_FRAMEPIPE("frame start\n");

	ret = hlo_stream_transfer_until(FROM_STREAM, pipe->source, (uint8_t*)&short_len,sizeof(short_len),transfer_delay, &pipe->flush);
	if(ret < 0){
		return ret;
	}
	bytes_remaining = short_len;
	while( bytes_remaining > 0 ) {
		DBG_FRAMEPIPE("dlen %d\n", short_len);
		ret = hlo_stream_transfer_until(FROM_STREAM, pipe->source, buf,short_len,transfer_delay,&pipe->flush);
		DBG_FRAMEPIPE("pipe read %d\n", ret);
		if(ret < 0){
			return ret;
		}
		DBG_FRAMEPIPE("read %d\n", ret);
		ret = hlo_stream_transfer_all(INTO_STREAM, pipe->sink, buf,ret,transfer_delay);
		if(ret < 0){
			return ret;
		}
		bytes_remaining -= ret;
		DBG_FRAMEPIPE("left %d\n", short_len);
	}
	DBG_FRAMEPIPE("frame stop\n");

	return ret;
 }
void thread_frame_pipe_encode(void* ctx) {
	pipe_ctx * pctx = (pipe_ctx*)ctx;
	while(frame_pipe_encode( pctx ) >= 0) {
		vTaskDelay(100);
	}
	xSemaphoreGive(pctx->join_sem);
	vTaskDelete(NULL);
}
void thread_frame_pipe_decode(void* ctx) {
	pipe_ctx * pctx = (pipe_ctx*)ctx;
	while(frame_pipe_decode( pctx ) >= 0) {
		vTaskDelay(100);
	}
	xSemaphoreGive(pctx->join_sem);
	vTaskDelete(NULL);
}
