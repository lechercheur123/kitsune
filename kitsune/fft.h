#ifndef FFT_H
#define FFT_H

#include <stdint.h>


#ifdef __cplusplus
extern "C" {
#endif

#define MEL_SCALE_SIZE (16)
    
int32_t fft(int16_t fr[], int16_t fi[], int32_t m);
int32_t fftr(int16_t f[], int32_t m); //this does not work, do not use it.

    
uint8_t bitlog(uint32_t n);
uint32_t bitexp(uint16_t n);

int16_t fxd_sin( uint16_t x );


void logpsdmel(int16_t * logTotalEnergy,int16_t psd[],const int16_t fr[],const int16_t fi[],uint8_t log2scaleOfRawSignal,uint16_t min_energy);


void dct(int16_t fr[],int16_t fi[],const int16_t ndct);




#ifdef __cplusplus
}
#endif
    
#endif
