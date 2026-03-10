
#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#include "BITMATH.h"
#include "STDTYPES.h"

#include "DIO_register.h"

/* macros for pin direction */
#define DIO_PIN_INPUT   0
#define DIO_PIN_OUTPUT  1

/* macros for port direction */
#define DIO_PORT_INPUT  0
#define DIO_PORT_OUTPUT 1

/* NULL */
#define NULL 0

/* macros for DIO ports ID */
#define DIO_PORTA_ID 0
#define DIO_PORTB_ID 1
#define DIO_PORTC_ID 2
#define DIO_PORTD_ID 3


/* macros for pin numbers */
#define DIO_PIN0 0
#define DIO_PIN1 1
#define DIO_PIN2 2
#define DIO_PIN3 3
#define DIO_PIN4 4
#define DIO_PIN5 5
#define DIO_PIN6 6
#define DIO_PIN7 7

/* macros for pin values */
#define DIO_PIN_LOW  0
#define DIO_PIN_HIGH 1

/* macros for port values */
#define DIO_PORT_LOW  0
#define DIO_PORT_HIGH 1

/* functions for DIO pins */
void DIO_voidSetPinDirection(u8 copy_PortID, u8 copy_PinID, u8 copy_PinDirection);
void DIO_voidSetPinValue(u8 copy_PortID, u8 copy_PinID, u8 copy_PinValue);
void DIO_voidTogglePinValue(u8 copy_PortID, u8 copy_PinID);
u8 DIO_u8GetPinValue(u8 copy_PortID, u8 copy_PinID);
void DIO_voidGetPinValue(u8 copy_PortID, u8 copy_PinID, u8* pu8PinValue);
void DIO_voidActivePinInternalPUR(u8 copy_PortID, u8 copy_PinID);

/* functions for DIO ports */
void DIO_voidSetPortDirection(u8 copy_u8PortId, u8 copy_u8PortDirection);
void DIO_voidSetPortValue(u8 copy_u8PortId, u8 copy_u8PortValue);
void DIO_voidTogglePortValue(u8 copy_u8PortId);
void DIO_voidGetPortValue(u8 copy_u8PortId, u8* pu8PortValue);
void DIO_voidActivePortInternalPUR(u8 copy_PortID);

#endif /* DIO_INTERFACE_H_ */