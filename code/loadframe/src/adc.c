/*
 * adc.c
 *
 *  Created on: Apr 28, 2013
 *      Author: agoetz
 */

#include "driver_config.h"
#include "adc.h"
#include "ssp.h"
#include "type.h"
int adc_init() {
        SSP_IOConfig(0);
        SSP_Init(0);
        return FALSE;
}

adc_channels adc_read() {
        uint16_t reading;
        adc_channels result;
        uint16_t command;
        /* assume that the adc is set to read channel 0 */
        command = 0b11 << 14;
        SSP_Send(0, &command, 1);
        SSP_Receive(0, &reading, 1);
        result.lvdt = reading;
        command = 0b10 << 14;
        SSP_Send(0, &command, 1);
        SSP_Receive(0, &reading, 1);
        result.loadcell = reading;
        return result;
}
