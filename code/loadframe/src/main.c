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

void ProcessTareButtons();
void ProcessToggleSwitch();
void ProcessEncoder();

int ProcessButton(int port, int bit)
{

#define INTEGRATOR_MAX 500

	static int integrator[3][11];
	static int output[3][11] = {{[0 ... 10] = 1},
								{[0 ... 10] = 1},
								{[0 ... 10] = 1}};
	int button_state;

	button_state = (!! LPC_GPIO[port]->MASKED_ACCESS[1 << (bit)]);

	if (button_state == 0)
	{
		if (integrator[port][bit] > 0)
			integrator[port][bit]--;
	}
	else if (integrator[port][bit] < INTEGRATOR_MAX)
		integrator[port][bit]++;

	if (integrator[port][bit] == 0)
	{
		output[port][bit] = 0;
	}
	else if (integrator[port][bit] >= INTEGRATOR_MAX)
	{
		integrator[port][bit] = INTEGRATOR_MAX;
		output[port][bit] = 1;
	}
	return !(output[port][bit]);
}

int GetButton(int pin)
{
	static int button[6];
	static int last_state[6] ;
	static int state[6];

	//state[pin] = ProcessButton(pin);

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

    // Set Tare buttons as inputs
    GPIOSetDir( 1, 5, 0);
    GPIOSetDir( 1, 6, 0);

    // Set toggle lines as inputs
    GPIOSetDir( 1, 2, 0);
    GPIOSetDir( 1, 4, 0);

    // Set 2-bit encoder as inputs
    GPIOSetDir( 0, 11, 0);
    GPIOSetDir( 1, 0, 0);

	// Enter an infinite loop, just incrementing a counter
	volatile static uint16_t sample = 0 ;
	adc_channels adc_data;
    int i = 0;

    int enc1, enc2;

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

		// Do tare button stuff
		ProcessTareButtons();

		//Do toggle stuff
		ProcessToggleSwitch();

		//Do encoder stuff
		ProcessEncoder();
	}
	return 0 ;
}

void ProcessTareButtons()
{
	static int left_last = 0;
	static int right_last = 0;

	int left,right;

	left =  ProcessButton(1,5);
	right = ProcessButton(1,6);

	if (left && !left_last)
		blink_left();

	if (right && !right_last)
		blink_right();

	left_last = left;
	right_last = right;
}

void ProcessToggleSwitch()
{
    static int switch1_last = 0;
    static int switch2_last = 0;
    int switch1, switch2;

    int i = 0;

	//Do toggle stuff
    switch1 = ProcessButton(1,4);
    switch2 = ProcessButton(1,2);

    if (switch1 && !switch1_last)
    	i ^= 1;

    if (switch2 && !switch2_last)
    	i ^= 1;

    switch1_last = switch1;
    switch2_last = switch2;

}


void ProcessEncoder()
{
	static int enc1_last = 0;
	static int enc2_last = 0;

	int enc1, enc2;

	enc1 = ProcessButton(0,11);
	enc2 = ProcessButton(1,0);

	enc1_last = enc1;
	enc2_last = enc2;
}
