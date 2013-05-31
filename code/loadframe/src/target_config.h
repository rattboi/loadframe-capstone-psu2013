/*****************************************************************************
 *   target_config.h:  config file for blinky example for NXP LPC11xx Family
 *   Microprocessors
 *
 *   Copyright(C) 2008, NXP Semiconductor
 *   All rights reserved.
 *
 *   History
 *   2010.09.07  ver 1.00    Preliminary version, first Release
 *
******************************************************************************/

#define IO_INPUT 0
#define IO_OUTPUT 1

#define LED_ON 1		// Level to set port to turn on led
#define LED_OFF 0		// Level to set port to turn off led
#define LED_TOGGLE_TICKS 10 // 100 ticks = 1 Hz flash rate

#define LED0_PORT 0
#define LED0_BIT 1

#define LED1_PORT 0
#define LED1_BIT 7

#define LED2_PORT 0
#define LED2_BIT 3

#define LED_PORT LED2_PORT	// Port for led
#define LED_BIT LED2_BIT	// Bit on port for led

#define LCD_SPI_PORT 1

#define LCD_GPIO_PORT 1
#define LCD_CE_BIT 8
#define LCD_CD_BIT 9
#define LCD_RESET_BIT 5
#define LCD_BACKLIGHT_BIT 1

#define UI_PORT_A         0
#define UI_DEBUG_LED_A	  5
#define UI_DEBUG_LED_B	  3
#define UI_DEBUG_LED_C	  4
#define UI_ENC_A 		  11

#define UI_PORT_B 		  1
#define UI_ENC_B 		  0
#define UI_TOGGLE_A		  2
#define UI_TOGGLE_B		  4
#define UI_BUTTON_LEFT    5
#define UI_BUTTON_RIGHT   6

/*********************************************************************************
**                            End Of File
*********************************************************************************/
