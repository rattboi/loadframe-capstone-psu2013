/*
 * dac.c
 *
 *  Created on: Nov 12, 2012
 *      Author: agoetz
 */

#include "driver_config.h"
#include "dac.h"
#include "ssp.h"
#include "type.h"
#include "gpio.h"
#include <stdint.h>
int dac_init()
{
	SSP_IOConfig(1);
	SSP_Init(1);
	return FALSE;
}

int dac_send(uint16_t value)
{
	
       	uint8_t command_bytes[3];
	command_bytes[2] = value & 0xff;
	command_bytes[1] = value >> 8;
	command_bytes[0] = 0;
	

	/* make sure we have a falling edge on ssel */
	while ( (LPC_SSP1->SR & (SSPSR_TNF|SSPSR_BSY)) != SSPSR_TNF );
	GPIOSetValue( PORT2, 0, 1 );
	GPIOSetValue( PORT2, 0, 0 );

	/* send the 3 bytes command word */
	SSP_Send8(1, command_bytes, 3);
	return FALSE;
}
