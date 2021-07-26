/*
 * Uart_Interface.h
 *
 *  Created on: Dec 21, 2020
 *      Author: Al Badr
 */

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

#include "DataTypes.h"

void UART_Init(uint32_t BoudRate);
void UART_Transmite_String(uint8_t *str);
void UART_Transmite(uint8_t Data);
void UART_Recive_String(uint8_t *str);
uint8_t UART_Recive(void);

#endif /* UART_INTERFACE_H_ */
