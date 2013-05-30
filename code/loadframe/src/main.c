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
int ProcessToggleSwitch();
int ProcessEncoder();

int ProcessButton(int port, int bit)
{

#define INTEGRATOR_MAX 100

	static int integrator[3][12];
	static int output[3][12] = {{[0 ... 11] = 1},
								{[0 ... 11] = 1},
								{[0 ... 11] = 1}};
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

void debug_init()
{
	GPIOSetDir( 0, 5, 1);
	GPIOSetValue( 0,5,1);
	GPIOSetDir( 0, 3, 1);
	GPIOSetValue( 0,3,1);
	GPIOSetDir( 0, 4, 1);
	GPIOSetValue( 0,4,1);
}

void ui_init()
{
    // Set setpoint selection buttons as inputs
    GPIOSetDir( 1, 5, 0);
    GPIOSetDir( 1, 6, 0);

    // Set toggle lines as inputs
    GPIOSetDir( 1, 2, 0);
    GPIOSetDir( 1, 4, 0);

    // Set 2-bit encoder as inputs
    GPIOSetDir( 0, 11, 0);
    GPIOSetDir( 1, 0, 0);
}

uint16_t conv_to_voltage(int setpoint)
{
	uint32_t maths;
	uint16_t retval;

//	maths = ((setpoint + 3000) * 65535)/6000;
	maths = (((setpoint + 3000) * (60204 - 6138))/6000)+6138;
	retval = (uint16_t)maths;

	return retval;
}

int conv_to_setpoint(uint16_t voltage)
{
	int maths;
	int retval;
	voltage = 65535 - voltage;

	maths = ((((int)voltage - 8700) * 6000)/(56300 - 8700)-3000);
	retval = (int)maths;

	return retval;
}

int32_t update_manual_sp()
{
	int i;
	adc_channels adc_data;
	uint32_t sum = 0;

    for (i = 0; i < 1024; i++)
    {
		adc_data = adc_read();
		sum += adc_data.lvdt;
    }

    return conv_to_setpoint(sum/1024);
}

int main(void) {
	volatile static uint16_t sample = 0 ;
	adc_channels adc_data;
    const int count = 1024;
    int i = 0;
    int ex_mode = 0, ex_last = 0;

    int mode, mode_last;

    uint32_t sum;
    uint32_t sum2;
    int diff;

    int32_t exec_sp, curr_sp, manual_sp;
    int32_t ex_going;
    int32_t *setpoint, *setpoints[NUM_MODES];

    exec_sp = curr_sp = manual_sp = 0;
    setpoints[MODE_SETPOINT] = &exec_sp;
    setpoints[MODE_MANUAL]   = &manual_sp;
    setpoints[MODE_EXECUTE]  = &curr_sp;

	GPIOInit();
	dac_init();
    adc_init();
    sseg_init();

    debug_init();
    ui_init();

    //initialize manual setpoint to be current LVDT value
    manual_sp = update_manual_sp();

    // seed internal static values of encoder
    ProcessEncoder();

    // determine initial mode
    mode = mode_last = ProcessToggleSwitch();

    while(1)
    {
    	i++;

		// Do UI stuff
		ProcessTareButtons();
		diff = ProcessEncoder();
    	mode = ProcessToggleSwitch();

    	setpoint = setpoints[mode];
    	ex_mode = (mode == MODE_EXECUTE);

    	if (ex_mode && !ex_last)
    		ex_going = manual_sp;

		if (diff && mode == MODE_SETPOINT)
			exec_sp = mod_setpoint(exec_sp, diff);

		if (diff && mode == MODE_MANUAL)
			manual_sp = mod_setpoint(manual_sp, diff);

		adc_data = adc_read();
		sum += adc_data.loadcell;
		sum2 += adc_data.lvdt;

		if (!(i % count))
		{
			sum /= count;
			sum2 /= count;
			curr_sp = conv_to_setpoint(sum2);

			set_mode(LVDT_DISP, !(mode == MODE_EXECUTE));

			SysTick->CTRL &=~1;
			update_display(LVDT_DISP,  *setpoint);
//			update_display(LOADC_DISP, conv_to_voltage(*setpoint));
			update_display(LOADC_DISP, sum2);
			SysTick->CTRL |=1;

			i = sum = sum2 = 0;
		}

		if (!(i % 256))
		{
			if (mode == MODE_MANUAL)
				dac_send(conv_to_voltage(*setpoint));

			if (ex_mode)
			{
				int change = 0;

				if (ex_going < exec_sp)
					change = 100;
				if (ex_going > exec_sp)
					change = -100;

				ex_going += change;

				if (ex_going > 3000)
					ex_going = 3000;

				if (ex_going < -3000)
					ex_going = -3000;

				dac_send(conv_to_voltage(ex_going));
			}
		}

		if (mode != mode_last)
		{
//			if (mode == MODE_MANUAL)
				manual_sp = update_manual_sp();
		}

		mode_last = mode;
		ex_last = ex_mode;
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

int ProcessToggleSwitch()
{
	static int mode;
    int switch1, switch2;

	//Do toggle stuff
    switch1 = ProcessButton(1,4);
    switch2 = ProcessButton(1,2);

    mode = ((switch1 << 1) | switch2);

    return mode;
}

int ProcessEncoder()
{
	static int enc_last = 0;

	int enc;
	int rot_val;

	int rots[4][4] = {{ 0, -1,  1,  0},
					  { 1,  0,  0, -1},
					  {-1,  0,  0,  1},
					  { 0,  1, -1,  0}};

	enc = (ProcessButton(1,0) << 1) | ProcessButton(0,11);

	rot_val = rots[enc_last][enc];

	enc_last = enc;

	return rot_val;
}
