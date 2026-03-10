
#include "STDTYPES.h"
#include "BITMATH.h"

/* MCAL */
#include "DIO_interface.h"

/* HAL */
#include "Switch_interface.h"

void Switch_voidInit(u8 copy_u8SwitchPort, u8 copy_u8SwitchPin){
	
	DIO_voidSetPinDirection(copy_u8SwitchPort, copy_u8SwitchPin, DIO_PIN_INPUT);
}

void Switch_voidGetStatus(u8 copy_u8SwitchPort, u8 copy_u8SwitchPin, u8 copy_u8SwitchConnectionType, u8* pu8SwitchStatus){
	
	u8 local_u8PinValue;
	
	switch(copy_u8SwitchConnectionType){
		
		case SWITCH_FORWARD_CONNECTION:
		DIO_voidGetPinValue(copy_u8SwitchPort, copy_u8SwitchPin, &local_u8PinValue);
		
		switch(local_u8PinValue){
			case DIO_PIN_HIGH:
			*pu8SwitchStatus = SWITCH_PRESSED;
			break;
			
			case DIO_PIN_LOW:
			*pu8SwitchStatus = SWITCH_NOT_PRESSED;
			break;
		}
		break;
		
		case SWITCH_REVERSE_CONNECTION:
		DIO_voidGetPinValue(copy_u8SwitchPort, copy_u8SwitchPin, &local_u8PinValue);
		
		switch(local_u8PinValue){
			case DIO_PIN_HIGH:
			*pu8SwitchStatus = SWITCH_NOT_PRESSED;
			break;
			
			case DIO_PIN_LOW:
			*pu8SwitchStatus = SWITCH_PRESSED;
			break;
		}
		break;
	}
}