/*
 * Uart_Config.h
 *
 *  Created on: Dec 21, 2020
 *      Author: Al Badr
 */

#ifndef UART_CONFIG_H_
#define UART_CONFIG_H_
#ifndef F_CPU
#define F_CPU   8000000
#endif



#define BAUD_PRESCALE (((1000000/ (  UART_BAUDRATE * 8UL))) - 1)

/*UART Modes*/
#define Asynchronous_Normal_Mode       1
#define Asynchronous_Double_Speed_Mode 2
#define Synchronous_Master_Mode        3

#define UART_Mode  Asynchronous_Normal_Mode


/*baud rate menu */
#define  Baud_Rate_100    100
#define  Baud_Rate_200    200
#define  Baud_Rate_300    300
#define  Baud_Rate_1200   1200
#define  Baud_Rate_2400   2400
#define  Baud_Rate_4800   4800
#define  Baud_Rate_9600   9600
#define  Baud_Rate_19200  19200
#define  Baud_Rate_38400  38400
#define  Baud_Rate_57600  57600
#define  Baud_Rate_115200 115200

#define UART_BAUDRATE          Baud_Rate_9600

/*choose clock polarity*/
#define Rising  1
#define Falling 0

#define clock_polarity_TXD Rising

/*choose number of stop bit*/
#define  two  2
#define  one  1
#define Num_of_Stop_bit  one

/*choose num of character size */
#define five  5
#define six    6
#define seven  7
#define eight  8
#define nine   9

#define character_size eight

#define disable_parity 0
#define odd_parity    1
#define even_parity   2

#define parity_bit    disable_parity


#endif /* UART_CONFIG_H_ */
