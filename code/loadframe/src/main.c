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

int ProcessToggleButton(int pin)
{

#define INTEGRATOR_MAX 500

	static int integrator[2] = {0,0};
	static int output[2] = {1,1};

	int button_state;

	button_state = (!! LPC_GPIO[1]->MASKED_ACCESS[1 << (pin + 5)]);

	if (button_state == 0)
	{
		if (integrator[pin] > 0)
			integrator[pin]--;
	}
	else if (integrator[pin] < INTEGRATOR_MAX)
		integrator[pin]++;

	if (integrator[pin] == 0)
	{
		output[pin] = 0;
	}
	else if (integrator[pin] >= INTEGRATOR_MAX)
	{
		integrator[pin] = INTEGRATOR_MAX;
		output[pin] = 1;
	}
	return !(output[pin]);
}

int GetButton(int pin)
{
	static int button[6];
	static int last_state[6] ;
	static int state[6];

	state[pin] = ProcessToggleButton(pin);

	if (state[pin] == 1 && last_state[pin] != 1 )
	{
		button[pin] = button[pin] ^ 1;
	}

	last_state[pin] = state[pin];
}

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

    GPIOSetDir( 1, 5, 0);
    GPIOSetDir( 1, 6, 0);

	// Enter an infinite loop, just incrementing a counter
	volatile static uint16_t sample = 0 ;
	adc_channels adc_data;
    int i = 0;
    int left,right;
    int left_last,right_last;
    uint32_t sum;
    uint32_t sum2;
    const int count = 1024;
    while(1) {
    	i++;
		adc_data = adc_read();
		sum += adc_data.loadcell;
		sum2 += adc_data.lvdt;
		if (!(i % count))
		{
			sum /= count;
			sum2 /= count;
			SysTick->CTRL &=~1;
			update_display(LOADC_DISP, sum);
			update_display(LVDT_DISP,  sum2);
			SysTick->CTRL |=1;
			i = sum = sum2 = 0;
		}
		//dac_send(sum);

		left =  ProcessToggleButton(0);
		right = ProcessToggleButton(1);

		if (left && !left_last)
			blink_left();

		if (right && !right_last)
			blink_right();

		left_last = left;
		right_last = right;
	}
	return 0 ;
}
