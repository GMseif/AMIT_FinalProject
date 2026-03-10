
/* Standard libraries */ 
#include "STDTYPES.h"
#include "BITMATH.h"

/* MCAL */
#include "DIO_interface.h"

/* HAL */
#include "COOLER_interface.h"

void COOLER_voidInit(void){
	
	DIO_voidSetPinDirection(COOLER_PORT, COOLER_PIN, DIO_PIN_OUTPUT);
	COOLER_voidOff();
}

void COOLER_voidOn(void){
	
	if(COOLER_MODE == COOLER_ACTIVE_LOW){
		DIO_voidSetPinValue(COOLER_PORT, COOLER_PIN, DIO_PIN_LOW);
	}
	else if(COOLER_MODE == COOLER_ACTIVE_HIGH){
		DIO_voidSetPinValue(COOLER_PORT, COOLER_PIN, DIO_PIN_HIGH);
	}
}

void COOLER_voidOff(void){
	
	if(COOLER_MODE == COOLER_ACTIVE_LOW){
		DIO_voidSetPinValue(COOLER_PORT, COOLER_PIN, DIO_PIN_HIGH);
	}
	else if(COOLER_MODE == COOLER_ACTIVE_HIGH){
		DIO_voidSetPinValue(COOLER_PORT, COOLER_PIN, DIO_PIN_LOW);
	}
}