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
#include "target_config.h"

#define SP_MAX 3000 
#define SP_MIN -3000
 
#define RAM_MIN 6138 
#define RAM_MAX 60204

#define LVDT_MIN 8700
#define LVDT_MAX 56300

// Variable to store CRP value in. Will be placed automatically
// by the linker when "Enable Code Read Protect" selected.
// See crp.h header for more information
__CRP const unsigned int CRP_WORD = CRP_NO_CRP ;

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

void ProcessSetpointButtons()
{
	static int left_last = 0;
	static int right_last = 0;

	int left,right;

	left =  ProcessButton(UI_PORT_B, UI_BUTTON_LEFT);
	right = ProcessButton(UI_PORT_B, UI_BUTTON_RIGHT);

	if (left && !left_last)
		blink_left();

	if (right && !right_last)
		blink_right();

	left_last = left;
	right_last = right;
}

int ProcessToggleSwitch()
{
    return ((ProcessButton(UI_PORT_B, UI_TOGGLE_B) << 1) | ProcessButton(UI_PORT_B, UI_TOGGLE_A));
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

	enc = (ProcessButton(UI_PORT_B, UI_ENC_B) << 1) | ProcessButton(UI_PORT_A, UI_ENC_A);

	rot_val = rots[enc_last][enc];

	enc_last = enc;

	return rot_val;
}

void debug_init()
{
	GPIOSetDir(   UI_PORT_A, UI_DEBUG_LED_A, LED_ON);
	GPIOSetValue( UI_PORT_A, UI_DEBUG_LED_A, LED_ON);
	GPIOSetDir(   UI_PORT_A, UI_DEBUG_LED_B, LED_ON);
	GPIOSetValue( UI_PORT_A, UI_DEBUG_LED_B, LED_ON);
	GPIOSetDir(   UI_PORT_A, UI_DEBUG_LED_C, LED_ON);
	GPIOSetValue( UI_PORT_A, UI_DEBUG_LED_C, LED_ON);
}

void ui_init()
{
    // Set setpoint selection buttons as inputs
    GPIOSetDir( UI_PORT_B, UI_BUTTON_LEFT,  IO_INPUT);
    GPIOSetDir( UI_PORT_B, UI_BUTTON_RIGHT, IO_INPUT);

    // Set toggle lines as inputs
    GPIOSetDir( UI_PORT_B, UI_TOGGLE_A, IO_INPUT);
    GPIOSetDir( UI_PORT_B, UI_TOGGLE_B, IO_INPUT);

    // Set 2-bit encoder as inputs
    GPIOSetDir( UI_PORT_A, UI_ENC_A,  IO_INPUT);
    GPIOSetDir( UI_PORT_B, UI_ENC_B,  IO_INPUT);
}

uint16_t ram_sp_to_voltage(int setpoint)
{
	uint32_t maths;
	uint16_t retval;

	maths = (((setpoint + SP_MAX) * (RAM_MAX - RAM_MIN))/(SP_MAX - SP_MIN))+RAM_MIN;
	retval = (uint16_t)maths;

	return retval;
}

int lvdt_voltage_to_sp(uint16_t voltage)
{
	int maths;
	int retval;
	voltage = 65535 - voltage; //invert voltage

    maths = ((((int)voltage - 8700) * 6000)/(56300 - 8700)-3000);

//	maths = ((((int)voltage - LVDT_MIN) * (SP_MAX - SP_MIN))/(LVDT_MAX - LVDT_MIN) - SP_MAX);
	retval = (int)maths;

	return retval;
}

int mod_setpoint(int setpoint, int diff)
{
	int i;
	int mult = 1;
	int num_digits = get_blink_digit(LVDT_DISP);

	for ( i = 0; i < num_digits; i++)
		mult *= 10;

	if (diff == -1) {
		if (setpoint + (diff * mult) >= SP_MIN)
			return setpoint + (diff * mult);
		else
			return SP_MIN;
	}

	if (diff == 1) {
		if (setpoint + (diff * mult) <= SP_MAX)
			return setpoint + (diff * mult);
		else
			return SP_MAX;
	}

	return setpoint;
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

    return lvdt_voltage_to_sp(sum/1024);
}

int main(void) {
	const int EX_STEP = 1;
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
		ProcessSetpointButtons();
		diff = ProcessEncoder();
    	mode = ProcessToggleSwitch();

    	setpoint = setpoints[mode];
    	ex_mode = (mode == MODE_EXECUTE);

    	if (ex_mode && !ex_last)
    		ex_going = manual_sp;

    	if (diff)
    		*setpoint = mod_setpoint(*setpoint, diff);

/*		if (diff && mode == MODE_SETPOINT)
			exec_sp = mod_setpoint(exec_sp, diff);

		if (diff && mode == MODE_MANUAL)
			manual_sp = mod_setpoint(manual_sp, diff);
*/

		adc_data = adc_read();
		sum += adc_data.loadcell;
		sum2 += adc_data.lvdt;

		if (!(i % count)) {
			sum /= count;
			sum2 /= count;
			curr_sp = lvdt_voltage_to_sp(sum2);

			set_mode(LVDT_DISP, !(mode == MODE_EXECUTE));

			SysTick->CTRL &=~1;
			update_display(LVDT_DISP,  *setpoint);
//			update_display(LOADC_DISP, conv_to_voltage(*setpoint));
//			update_display(LOADC_DISP, sum2);

			if (!(mode == MODE_SETPOINT))
				update_display(LOADC_DISP, sum);
			else
				update_display(LOADC_DISP, MAGIC_SET_NUM);
			SysTick->CTRL |=1;

			i = sum = sum2 = 0;
		}

		if (!(i % 256)) {
			if (mode == MODE_MANUAL)
				dac_send(ram_sp_to_voltage(*setpoint));

			if (ex_mode) {
				int change = 0;

				change = exec_sp - ex_going;

				if (change < -EX_STEP)
					change = -EX_STEP;

				if (change > EX_STEP)
					change = EX_STEP;

				ex_going += change;

				if (ex_going > SP_MAX)
					ex_going = SP_MAX;

				if (ex_going < SP_MIN)
					ex_going = SP_MIN;

				manual_sp = ex_going;
				dac_send(ram_sp_to_voltage(ex_going));
			}
		}

		mode_last = mode;
		ex_last = ex_mode;
	}
	return 0 ;
}
