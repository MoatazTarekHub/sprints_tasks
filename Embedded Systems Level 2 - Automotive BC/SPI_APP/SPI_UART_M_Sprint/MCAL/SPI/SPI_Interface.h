/*
 * SPI_Interfacing.h
 *
 *  Created on: Dec 23, 2020
 *      Author: Al Badr
 */

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

void SPI_SlaveInit(void);
void SPI_MasterInit(void);

void SPI_MasterTransmit(uint8_t cData);
void SPI_Transmite_String(uint8_t *str);

uint8_t SPI_SlaveReceive(void);
void SPI_Recive_String(uint8_t *str);

#endif /* SPI_INTERFACE_H_ */
