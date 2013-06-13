/*
 * sseg.h
 *
 *  Created on: Apr 29, 2013
 *      Author: agoetz
 */

#ifndef SSEG_H_
#define SSEG_H_
#include <stdint.h>

#define LOADC_DISP 0
#define LVDT_DISP  1

#define NUM_MODES     7
#define MODE_SETPOINT 0
#define MODE_EXECUTE  1
#define MODE_MANUAL   2
#define MODE_UNUSED   3
#define MODE_SPEED    4
#define MODE_SPEED_2  5
#define MODE_SPEED_3  6

#define MAGIC_SET_NUM   123456
#define MAGIC_SPEED_NUM 123457

#define BLINK_RATE 250

#define LOADC_PORT 2

#define LOADC_SHIFT_OE  9
#define LOADC_SHIFT_SDI 8
#define LOADC_COUNT_MR  10
#define LOADC_SHIFT_CLK 7
#define LOADC_COUNT_CP  11
#define LOADC_SHIFT_LE  5

#define LVDT_PORT 3

#define LVDT_SHIFT_OE  3
#define LVDT_SHIFT_SDI 2
#define LVDT_COUNT_MR  4
#define LVDT_SHIFT_CLK 1
#define LVDT_COUNT_CP  5
#define LVDT_SHIFT_LE  0

int  sseg_init(void);
void update_display(uint32_t disp, int32_t num);
void set_mode(int disp, int mode);
void blink_left();
void blink_right();
int  mod_setpoint(int setpoint, int diff);
int  get_blink_digit(int disp);
#endif /* SSEG_H_ */
