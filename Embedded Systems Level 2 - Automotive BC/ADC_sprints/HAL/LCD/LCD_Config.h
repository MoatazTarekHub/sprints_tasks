
#ifndef _LCD_CONFIG_H
#define _LCD_CONFIG_H

#define Data_Port    PORT_C  /// PORTA
#define Control_Port   PORT_C   /// PORTD

#define RS   PIN0
#define RW   PIN2
#define EN   PIN1

/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/
/* LCD Data bits mode configuration */
#define  DATA_BITS_MODE 4

/* Use higher 4 bits in the data port */
#if (DATA_BITS_MODE == 4)
#define UPPER_PORT_PINS
#endif

/* LCD Commands */
#define LCD_COM_CLEAR					(uint8_t)(0x01)
#define LCD_COM_HOME					(uint8_t)(0x02)
#define LCD_COM_ENTRYMODE				(uint8_t)(0x06)
#define LCD_COM_DISPLAY_OFF				(uint8_t)(0x08)
#define LCD_COM_DISPLAY_ON				(uint8_t)(0x0C)
#define LCD_COM_DISPLAY_ON_CURSOR_BLINK	(uint8_t)(0x0D)
#define LCD_COM_CURSOR_SHIFT_LEFT		(uint8_t)(0x10)
#define LCD_COM_CURSOR_SHIFT_RIGHT		(uint8_t)(0x14)
#define LCD_COM_DISPLAY_SHIFT_LEFT		(uint8_t)(0x18)
#define LCD_COM_DISPLAY_SHIFT_RIGHT		(uint8_t)(0x1C)
#define LCD_COM_FUNCTION_RESET			(uint8_t)(0x30)
#define LCD_COM_FUNCTION_SET_8BIT		(uint8_t)(0x38)
#define LCD_COM_SET_CURSOR_FIRST_LINE	(uint8_t)(0x80)
#define LCD_COM_SET_CURSOR_SECOND_LINE	(uint8_t)(0xc0)
#define LCD_FIRST_LINE_BASE_ADDRESS		(uint8_t)0x00
#define LCD_SECOND_LINE_BASE_ADDRESS	(uint8_t)0x40
#define TWO_LINE_LCD_Four_BIT_MODE      (uint8_t)(0x28)
#define LCD_MAX_CHAR_PER_LINE			(uint8_t)16
#define Eight_Bit_Mode 					(uint8_t)(0)
#define Four_Bit_Mode 					(uint8_t)(0x02)
#define LCD_MAX_ASCII_CODE 				(uint8_t)127
#define CURSOR_ON                       (uint8_t)0x0E

#endif /* LCD_CONFIG_H_ */


