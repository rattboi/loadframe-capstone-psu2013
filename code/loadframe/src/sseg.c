/*
 * sseg.c
 *
 *  Created on: Apr 29, 2013
 *      Author: agoetz
 */

#include "sseg.h"
#include "driver_config.h"
#include "gpio.h"
#include "LPC11xx.h"
#include "core_cm0.h"

#define  NUM_DIGS 5
#define  NUM_DISPLAYS 2

typedef struct { uint8_t PORT;
				 uint8_t SHIFT_OE;
			     uint8_t SHIFT_SDI;
			     uint8_t SHIFT_CLK;
			     uint8_t SHIFT_LE;
			     uint8_t COUNT_CP;
			     uint8_t COUNT_MR;
			     uint8_t mode;
			     uint8_t blink_digit;
			     uint32_t setpoint;
} SSEG;

SSEG sseg[NUM_DISPLAYS] = {
		{ LOADC_PORT,
		    LOADC_SHIFT_OE,
		    LOADC_SHIFT_SDI,
		    LOADC_SHIFT_CLK,
		    LOADC_SHIFT_LE,
		    LOADC_COUNT_CP,
		    LOADC_COUNT_MR,
			0,
			0,
			0},
		{ LVDT_PORT,
		    LVDT_SHIFT_OE,
		    LVDT_SHIFT_SDI,
		    LVDT_SHIFT_CLK,
		    LVDT_SHIFT_LE,
		    LVDT_COUNT_CP,
		    LVDT_COUNT_MR,
			0,
			0,
			0}
};

uint8_t writebuf [NUM_DISPLAYS][NUM_DIGS];

void disp_off(uint32_t disp) {
	GPIOSetValue(sseg[disp].PORT,sseg[disp].SHIFT_OE,1);
}

void sendval(uint32_t disp, char value) {
	int i;

	GPIOSetValue(sseg[disp].PORT,sseg[disp].SHIFT_OE,0);
	for (i = 0; i < 8; i++) {
		GPIOSetValue(sseg[disp].PORT,sseg[disp].SHIFT_SDI, !!(value & 0x80));
		value = value << 1;
		GPIOSetValue(sseg[disp].PORT,sseg[disp].SHIFT_CLK, 1);
		GPIOSetValue(sseg[disp].PORT,sseg[disp].SHIFT_CLK, 0);
	}
	GPIOSetValue(sseg[disp].PORT,sseg[disp].SHIFT_LE, 1);
	GPIOSetValue(sseg[disp].PORT,sseg[disp].SHIFT_LE, 0);
}

//converts a bcd number to 7seg value
//segment ordering: .gfedcba
uint8_t bcdto7seg(int8_t num)
{
	if (num < 0)
		num *= -1;

	switch(num)
	{
	case 0:
		return 0x3f;
		break;
	case 1:
		return 0x06;
		break;
	case 2:
		return 0b01011011;
		break;
	case 3:
		return 0x4f;
		break;
	case 4:
		return 0b01100110;
		break;
	case 5:
		return 0b01101101;
		break;
	case 6:
		return 0b01111101;
		break;
	case 7:
		return 0b00000111;
		break;
	case 8:
		return 0b01111111;
		break;
	case 9:
		return 0b01100111;
		break;
	default:
		return 0x40;
	}
}

void update_display(uint32_t disp, int32_t num){
	int i;

	if (num < 0)
		writebuf[disp][4] = 0x40;
	else
		writebuf[disp][4] = 0x00;


	for(i = 0; i < NUM_DIGS; i++)
	{
		if (i == NUM_DIGS - 1 && disp == 1)
			continue;

		writebuf[disp][i] = bcdto7seg(num % 10);
		if(i == 3 && disp ==1)
			writebuf[disp][i] |= 0x80;
		num /= 10;
	}
}

void blink_left()
{
	if (sseg[1].blink_digit < NUM_DIGS - 2)
		sseg[1].blink_digit++;
}

void blink_right()
{
	if (sseg[1].blink_digit > 0)
		sseg[1].blink_digit--;
}

void set_mode(int disp, int mode)
{
	sseg[disp].mode = mode;
}

int mod_setpoint(int setpoint, int diff)
{
	int mult = 1;
	int i;

	for ( i = 0; i < sseg[1].blink_digit; i++)
		mult *= 10;

	if (diff == -1)
		if (setpoint + (diff * mult) >= -3000)
			return setpoint + (diff * mult);
		else
			return -3000;

	if (diff == 1)
		if (setpoint + (diff * mult) <= 3000)
			return setpoint + (diff * mult);
		else
			return 3000;

	return setpoint;
}

void SysTick_Handler(void) {
	static int character = 0;
	static int blinkrate = 0;
	int i;

	for (i = 0; i < NUM_DISPLAYS; i++)
	{
		disp_off(i);

		if (character == 0)
		{
			GPIOSetValue(sseg[i].PORT, sseg[i].COUNT_MR,1);
			GPIOSetValue(sseg[i].PORT, sseg[i].COUNT_MR,0);
		}
		else
		{
			GPIOSetValue(sseg[i].PORT, sseg[i].COUNT_CP,0);
			GPIOSetValue(sseg[i].PORT, sseg[i].COUNT_CP,1);
		}
		if (sseg[i].mode && sseg[i].blink_digit == character && blinkrate > 250)
			sendval(i, 0);
		else
			sendval(i, writebuf[i][character]);
	}

	character = ++character%5;
	blinkrate = ++blinkrate%500;
}

int sseg_init(void) {
	int i;

    GPIOInit();

    for (i = 0; i < NUM_DISPLAYS; i++)
    {
		GPIOSetDir  (sseg[i].PORT, sseg[i].SHIFT_OE, 1);
		GPIOSetValue(sseg[i].PORT, sseg[i].SHIFT_OE,0);

		GPIOSetDir  (sseg[i].PORT, sseg[i].SHIFT_SDI, 1);
		GPIOSetValue(sseg[i].PORT, sseg[i].SHIFT_SDI,1);

		GPIOSetDir  (sseg[i].PORT, sseg[i].SHIFT_CLK, 1);
		GPIOSetValue(sseg[i].PORT, sseg[i].SHIFT_CLK,0);

		GPIOSetDir  (sseg[i].PORT, sseg[i].SHIFT_LE, 1);
		GPIOSetValue(sseg[i].PORT, sseg[i].SHIFT_LE,0);

		GPIOSetDir  (sseg[i].PORT, sseg[i].COUNT_MR, 1);
		GPIOSetValue(sseg[i].PORT, sseg[i].COUNT_MR,0);
		GPIOSetValue(sseg[i].PORT, sseg[i].COUNT_MR,1);
		GPIOSetValue(sseg[i].PORT, sseg[i].COUNT_MR,0);

		GPIOSetDir(sseg[i].PORT, sseg[i].COUNT_CP, 1);

		update_display(i, 0xfffff);
    }

    SysTick->LOAD = 8000000 / 150 - 1;
    SysTick->VAL = 0;
    SysTick->CTRL = SysTick_CTRL_ENABLE_Msk |
            SysTick_CTRL_TICKINT_Msk |
            SysTick_CTRL_CLKSOURCE_Msk;

	return 0;
}
