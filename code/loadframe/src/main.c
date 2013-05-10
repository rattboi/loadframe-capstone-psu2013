/*
===============================================================================
 Name        : main.c
 Author      : 
 Version     :
 Copyright   : Copyright (C) 
 Description : main definition
===============================================================================
*/

#ifdef __USE_CMSIS
#include "LPC11xx.h"
#endif
#include "driver_config.h"
#include <cr_section_macros.h>
#include <NXP/crp.h>
#include "gpio.h"
#include <stdint.h>
#include "adc.h"
#include "dac.h"
#include "sseg.h"

// Variable to store CRP value in. Will be placed automatically
// by the linker when "Enable Code Read Protect" selected.
// See crp.h header for more information
__CRP const unsigned int CRP_WORD = CRP_NO_CRP ;

// TODO: insert other include files here

// TODO: insert other definitions and declarations here

int main(void) {
	GPIOInit();
	dac_init();
    adc_init();
    sseg_init();

    GPIOSetDir( 0, 5, 1);
    GPIOSetValue( 0,5,1);
    GPIOSetDir( 0, 3, 1);
    GPIOSetValue( 0,3,1);
    GPIOSetDir( 0, 4, 1);
    GPIOSetValue( 0,4,1);
	// TODO: insert code here

	// Enter an infinite loop, just incrementing a counter
	volatile static uint16_t sample = 0 ;
  adc_channels adc_data;
    int i;
    uint32_t sum;
    uint32_t sum2;
    while(1) {
		sum = 0;
		sum2 = 0;
		for (i = 0; i < 32; i++) {
          adc_data = adc_read();
          sum += adc_data.loadcell;
          sum2 += adc_data.lvdt;
		}
		sum /= 32;
		sum2 /= 32;
		dac_send(sum);
		SysTick->CTRL &=~1;
		update_display(LOADC_DISP, sum);
		update_display(LVDT_DISP,  sum2);
		SysTick->CTRL |=1;
	}
	return 0 ;
}
