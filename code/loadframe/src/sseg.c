/*
 * sseg.c
 *
 *  Created on: Apr 29, 2013
 *      Author: agoetz
 */

#include "sseg.h"
#include "gpio.h"
#include "LPC11xx.h"
#include "core_cm0.h"

#define  NUM_DIGS 5
#define  NUM_DISPLAYS 2

uint8_t writebuf [NUM_DISPLAYS][NUM_DIGS];

void disp_off(uint32_t disp) {
	switch (disp)
	{
	case LOADC_DISP:
		GPIOSetValue(LOADC_PORT,LOADC_SHIFT_OE,1);
		break;
	case LVDT_DISP:
		GPIOSetValue(LVDT_PORT,LVDT_SHIFT_OE,1);
		break;
	}
}
void sendval(uint32_t disp, char value) {
	int i;
	switch (disp)
	{
	case LOADC_DISP:
		GPIOSetValue(LOADC_PORT,LOADC_SHIFT_OE,0);
		for (i = 0; i < 8; i++) {
			GPIOSetValue(LOADC_PORT,LOADC_SHIFT_SDI, !!(value & 0x80));
			value = value << 1;
			GPIOSetValue(LOADC_PORT,LOADC_SHIFT_CLK, 1);
			GPIOSetValue(LOADC_PORT,LOADC_SHIFT_CLK, 0);
		}
		GPIOSetValue(LOADC_PORT,LOADC_SHIFT_LE, 1);
		GPIOSetValue(LOADC_PORT,LOADC_SHIFT_LE, 0);
		break;
	case LVDT_DISP:
		GPIOSetValue(LVDT_PORT,LVDT_SHIFT_OE,0);
		for (i = 0; i < 8; i++) {
			GPIOSetValue(LVDT_PORT,LVDT_SHIFT_SDI, !!(value & 0x80));
			value = value << 1;
			GPIOSetValue(LVDT_PORT,LVDT_SHIFT_CLK, 1);
			GPIOSetValue(LVDT_PORT,LVDT_SHIFT_CLK, 0);
		}
		GPIOSetValue(LVDT_PORT,LVDT_SHIFT_LE, 1);
		GPIOSetValue(LVDT_PORT,LVDT_SHIFT_LE, 0);
		break;
	}
}

//converts a bcd number to 7seg value
//segment ordering: .gfedcba
uint8_t bcdto7seg(uint8_t num) {
	switch(num){
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

void update_display(uint32_t disp, uint32_t num){
	int i;
	if (num < (1 << 16))
		for(i = 0; i < NUM_DIGS; i++) {
			writebuf[disp][i] = bcdto7seg(num % 10);
			num /= 10;
		}
	else
		for(i = 0; i < NUM_DIGS; i++)
			writebuf[disp][i] = bcdto7seg(0xff);
}

void SysTick_Handler(void) {
	static int character;

	disp_off(LOADC_DISP);
	disp_off(LVDT_DISP);

	switch (character) {
	case 1:
	case 2:
	case 3:
	case 4:
		GPIOSetValue(LOADC_PORT, LOADC_COUNT_CP,0);
		GPIOSetValue(LOADC_PORT, LOADC_COUNT_CP,1);
		GPIOSetValue(LVDT_PORT, LVDT_COUNT_CP,0);
		GPIOSetValue(LVDT_PORT, LVDT_COUNT_CP,1);
	break;
	case 0:
		GPIOSetValue(LOADC_PORT, LOADC_COUNT_MR,1);
		GPIOSetValue(LOADC_PORT, LOADC_COUNT_MR,0);
		GPIOSetValue(LVDT_PORT, LVDT_COUNT_MR,1);
		GPIOSetValue(LVDT_PORT, LVDT_COUNT_MR,0);
	}
	sendval(LOADC_DISP, writebuf[LOADC_DISP][character]);
	sendval(LVDT_DISP,  writebuf[LVDT_DISP][character]);
	character = ++character%5;
}

int sseg_init(void) {
    GPIOInit();

    // Set up Load Cell display I/O dirs
    GPIOSetDir(LOADC_PORT, LOADC_SHIFT_OE, 1);
    GPIOSetValue(LOADC_PORT, LOADC_SHIFT_OE,0);

	GPIOSetDir(LOADC_PORT, LOADC_SHIFT_SDI, 1);
    GPIOSetValue(LOADC_PORT, LOADC_SHIFT_SDI,1);

	GPIOSetDir(LOADC_PORT, LOADC_SHIFT_CLK, 1);
	GPIOSetValue(LOADC_PORT, LOADC_SHIFT_CLK,0);

	GPIOSetDir(LOADC_PORT, LOADC_SHIFT_LE, 1);
	GPIOSetValue(LOADC_PORT, LOADC_SHIFT_LE,0);

	GPIOSetDir(LOADC_PORT, LOADC_COUNT_MR, 1);
	GPIOSetValue(LOADC_PORT, LOADC_COUNT_MR,0);
	GPIOSetValue(LOADC_PORT, LOADC_COUNT_MR,1);
	GPIOSetValue(LOADC_PORT, LOADC_COUNT_MR,0);

	GPIOSetDir(LOADC_PORT, LOADC_COUNT_CP, 1);

    // Set up LVDT display I/O dirs
    GPIOSetDir(LVDT_PORT, LVDT_SHIFT_OE, 1);
    GPIOSetValue(LVDT_PORT, LVDT_SHIFT_OE,0);

	GPIOSetDir(LVDT_PORT, LVDT_SHIFT_SDI, 1);
    GPIOSetValue(LVDT_PORT, LVDT_SHIFT_SDI,1);

	GPIOSetDir(LVDT_PORT, LVDT_SHIFT_CLK, 1);
	GPIOSetValue(LVDT_PORT, LVDT_SHIFT_CLK,0);

	GPIOSetDir(LVDT_PORT, LVDT_SHIFT_LE, 1);
	GPIOSetValue(LVDT_PORT, LVDT_SHIFT_LE,0);

	GPIOSetDir(LVDT_PORT, LVDT_COUNT_MR, 1);
	GPIOSetValue(LVDT_PORT, LVDT_COUNT_MR,0);
	GPIOSetValue(LVDT_PORT, LVDT_COUNT_MR,1);
	GPIOSetValue(LVDT_PORT, LVDT_COUNT_MR,0);

	GPIOSetDir(LVDT_PORT, LVDT_COUNT_CP, 1);

	update_display(LOADC_DISP, 0xfffff);
	update_display(LVDT_DISP,  0xfffff);
	SysTick_Handler();

    SysTick->LOAD = 8000000 / 60 - 1;
    SysTick->VAL = 0;
    SysTick->CTRL = SysTick_CTRL_ENABLE_Msk |
            SysTick_CTRL_TICKINT_Msk |
            SysTick_CTRL_CLKSOURCE_Msk;

	return 0;
}
