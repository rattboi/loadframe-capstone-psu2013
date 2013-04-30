/*
 * sseg.c
 *
 *  Created on: Apr 29, 2013
 *      Author: agoetz
 */

#include "sseg.h"
#include "gpio.h"

void disp_off(void) {
	GPIOSetValue(LOADC_PORT,LOADC_SHIFT_OE,1);
}
void sendval(char value) {
	int i;
	GPIOSetValue(LOADC_PORT,LOADC_SHIFT_OE,0);
	for (i = 0; i < 8; i++) {
		GPIOSetValue(LOADC_PORT,LOADC_SHIFT_SDI, value & 1);
		value = value >> 1;
		GPIOSetValue(LOADC_PORT,LOADC_SHIFT_CLK, 1);
		GPIOSetValue(LOADC_PORT,LOADC_SHIFT_CLK, 0);
	}
	GPIOSetValue(LOADC_PORT,LOADC_SHIFT_LE, 1);
	GPIOSetValue(LOADC_PORT,LOADC_SHIFT_LE, 0);
}

int sseg_init(void) {
    GPIOInit();


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
	int i;
	const int delay_cycles = 0;
	for(;;) {
		disp_off();
		GPIOSetValue(LOADC_PORT, LOADC_COUNT_CP,0);
		GPIOSetValue(LOADC_PORT, LOADC_COUNT_CP,1);
		sendval(255);
		for(i = 0; i <delay_cycles; i++);
		disp_off();
		GPIOSetValue(LOADC_PORT, LOADC_COUNT_CP,0);
		GPIOSetValue(LOADC_PORT, LOADC_COUNT_CP,1);
		sendval(255);
		for(i = 0; i < delay_cycles; i++);
		disp_off();
		GPIOSetValue(LOADC_PORT, LOADC_COUNT_CP,0);
		GPIOSetValue(LOADC_PORT, LOADC_COUNT_CP,1);
		sendval(255);
		for(i = 0; i < delay_cycles; i++);
		disp_off();
		GPIOSetValue(LOADC_PORT, LOADC_COUNT_CP,0);
		GPIOSetValue(LOADC_PORT, LOADC_COUNT_CP,1);
		sendval(255);
		for(i = 0; i < delay_cycles; i++);
		disp_off();
		GPIOSetValue(LOADC_PORT, LOADC_COUNT_MR,1);
		GPIOSetValue(LOADC_PORT, LOADC_COUNT_MR,0);
		sendval(255);
		for(i = 0; i < delay_cycles; i++);
	}




	return 0;
}
