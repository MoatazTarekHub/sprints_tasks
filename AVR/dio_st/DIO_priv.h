/*
 * DIO_priv.h
 *
 *  Created on: Feb 17, 2021
 *      Author: Elgharib
 */

#ifndef DIO_PRIV_H_
#define DIO_PRIV_H_

#define DDRA  *((uint8_t*)0x3A)
#define DDRB  *((uint8_t*)0x37)
#define DDRC  *((uint8_t*)0x34)
#define DDRD  *((uint8_t*)0x31)


#define PORTA  *((uint8_t*)0x3B)
#define PORTB  *((uint8_t*)0x38)
#define PORTC  *((uint8_t*)0x35)
#define PORTD  *((uint8_t*)0x32)

#define PINA  *((volatile uint8_t*)0x39)
#define PINB  *((volatile uint8_t*)0x36)
#define PINC  *((volatile uint8_t*)0x33)
#define PIND  *((volatile uint8_t*)0x30)

#endif /* DIO_PRIV_H_ */
