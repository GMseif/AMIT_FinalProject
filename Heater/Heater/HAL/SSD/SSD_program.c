
/* standard libraries */
#include "STDTYPES.h"
#include "BITMATH.h"

/* MCAL */
#include "DIO_interface.h"

/* HAL */
#include "SSD_interface.h" 
#include "SSD_config.h"
#include "SSD_private.h"

static u8 PRV_Numbers[10]= {
	 SSD_ZERO, SSD_ONE, SSD_TWO, SSD_THREE, SSD_FOUR,
	 SSD_FIVE, SSD_SIX, SSD_SEVEN, SSD_EIGHT, SSD_NINE
};

void SSD_voidInit(void){
	DIO_voidSetPortDirection(SSD_DATA1_PORT, DIO_PORT_OUTPUT);
	DIO_voidSetPortDirection(SSD_DATA2_PORT, DIO_PORT_OUTPUT);
	
	DIO_voidSetPinDirection(SSD_ENABLE1_PORT, SSD_E1_PIN, DIO_PORT_OUTPUT);
	DIO_voidSetPinDirection(SSD_ENABLE2_PORT, SSD_E2_PIN, DIO_PORT_OUTPUT);
}
/*
void SSD_voidDisplayDigit(u8 copy_u8SSDId, u8 copy_u8Digit){
	if(copy_u8Digit <= 9){
		DIO_voidSetPortValue(SSD_DATA_PORT, PRV_Numbers[copy_u8Digit]);
		
		switch(copy_u8SSDId){
			case SSD_ID1:
			DIO_voidSetPinValue(SSD_ENABLE_PORT, SSD_E1_PIN, DIO_PIN_HIGH);
			break;
			case SSD_ID2:
			DIO_voidSetPinValue(SSD_ENABLE_PORT, SSD_E2_PIN, DIO_PIN_HIGH);
			break;
		}
	}
	else{
		// return error state
	}
}
*/
/*
void SSD_voidDisplayTwoDigits(u8 copy_u8Digit){
	if(copy_u8Digit <= 99){
		u8 local_u8Tens = copy_u8Digit/10;
		u8 local_u8Ones = copy_u8Digit%10;
		
		DIO_voidSetPinValue(SSD_ENABLE_PORT, SSD_E1_PIN, DIO_PIN_HIGH);
		DIO_voidSetPinValue(SSD_ENABLE_PORT, SSD_E2_PIN, DIO_PIN_HIGH);
		DIO_voidSetPortValue(SSD_DATA_PORT, PRV_Numbers[local_u8Tens]);
		DIO_voidSetPinValue(SSD_ENABLE_PORT, SSD_E1_PIN, DIO_PIN_LOW);
		_delay_ms(10);
		DIO_voidSetPinValue(SSD_ENABLE_PORT, SSD_E1_PIN, DIO_PIN_HIGH);
		
		DIO_voidSetPortValue(SSD_DATA_PORT, PRV_Numbers[local_u8Ones]);
		DIO_voidSetPinValue(SSD_ENABLE_PORT, SSD_E2_PIN, DIO_PIN_LOW);
		_delay_ms(10);
		DIO_voidSetPinValue(SSD_ENABLE_PORT, SSD_E2_PIN, DIO_PIN_HIGH);
	}
	else{
		// return error state
	}
	
}
*/

void SSD_voidDisplayVariable(u8 copy_u8SSDId, u8 copy_u8Variable){
	u8 local_u8Value = 0;
	
	if(copy_u8Variable <= 9){
		local_u8Value = PRV_Numbers[copy_u8Variable];
	}
	switch(copy_u8SSDId){
		case SSD_ID1:
		DIO_voidSetPortValue(SSD_DATA1_PORT, local_u8Value);
		DIO_voidSetPinValue(SSD_ENABLE1_PORT, SSD_E1_PIN, DIO_PIN_LOW);
		break;
		case SSD_ID2:
		DIO_voidSetPortValue(SSD_DATA2_PORT, local_u8Value);
		DIO_voidSetPinValue(SSD_ENABLE2_PORT, SSD_E2_PIN, DIO_PIN_LOW);
		break;
	}
}