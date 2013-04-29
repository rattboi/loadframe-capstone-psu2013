/*
 * adc.h
 *
 *  Created on: Apr 28, 2013
 *      Author: agoetz
 */

#ifndef ADC_H_
#define ADC_H_
#include <stdint.h>

typedef struct {
        uint16_t lvdt;
        uint16_t loadcell;
}adc_channels;

int adc_init();

adc_channels adc_read(void);


#endif /* ADC_H_ */
