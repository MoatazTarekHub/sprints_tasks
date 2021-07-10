/*
 *  Author: El-Gharib
 *  Created on: 17/2/2021
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

typedef enum
{
    PORTA_ID = 0,
    PORTB_ID,
    PORTC_ID,
    PORTD_ID

} EN_portname_t;

typedef enum
{
    PIN0 = 0,
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7
} EN_pinnum_t;

typedef enum
{
    INPUT = 0,
    OUTPUT
} EN_Direction_t;

typedef enum
{
    LOW = 0,
    HIGH
} EN_initValue_t;

typedef struct ST_DIO_config_t
{
    EN_portname_t portname;
    EN_pinnum_t pin_no;
    EN_Direction_t Direction;
    EN_initValue_t state;
} ST_DIO_config_t;

void DIO_voidInit(ST_DIO_config_t *Port);
void DIO_write(EN_portname_t port,EN_pinnum_t pin, EN_initValue_t data);
int DIO_read(EN_portname_t port,EN_pinnum_t pin);
void DIO_toggle(EN_portname_t port,EN_pinnum_t pin);






void DIO_voidSetPinValue(ST_DIO_config_t *Port);
void DIO_voidSetPinDirection(ST_DIO_config_t *port);
EN_initValue_t DIO_u8GetPinValue(ST_DIO_config_t *Port);

void DIO_voidTogPin(ST_DIO_config_t *Port);

void DIO_voidSetPortDirection(ST_DIO_config_t *Port);
void DIO_voidSetPortValue(ST_DIO_config_t *Port);
void DIO_voidInpullUp(ST_DIO_config_t *Port);

#endif /* DIO_INTERFACE_H_ */
