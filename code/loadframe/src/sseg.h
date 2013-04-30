/*
 * sseg.h
 *
 *  Created on: Apr 29, 2013
 *      Author: agoetz
 */

#ifndef SSEG_H_
#define SSEG_H_
#include <stdint.h>


#define LOADC_PORT 2

#define LOADC_SHIFT_OE 9
#define LOADC_SHIFT_SDI 8
#define LOADC_COUNT_MR 10
#define LOADC_SHIFT_CLK 7
#define LOADC_COUNT_CP 11
#define LOADC_SHIFT_LE 5

int sseg_init(void);
void update_display(uint32_t num);


#endif /* SSEG_H_ */
