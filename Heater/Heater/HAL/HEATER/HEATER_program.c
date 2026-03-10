
/* Standard libraries */
#include "STDTYPES.h"
#include "BITMATH.h"

/* MCAL */
#include "DIO_interface.h"

/* HAL */
#include "HEATER_interface.h"

void HEATER_voidInit(void){
	
	DIO_voidSetPinDirection(HEATER_PORT, HEATER_PIN, DIO_PIN_OUTPUT);
	HEATER_voidOff();
}

void HEATER_voidOn(void){
	
	if(HEATER_MODE == HEATER_ACTIVE_LOW){
		DIO_voidSetPinValue(HEATER_PORT, HEATER_PIN, DIO_PIN_LOW);
	}
	else if(HEATER_MODE == HEATER_ACTIVE_HIGH){
		DIO_voidSetPinValue(HEATER_PORT, HEATER_PIN, DIO_PIN_HIGH);
	}
}

void HEATER_voidOff(void){
	
	if(HEATER_MODE == HEATER_ACTIVE_LOW){
		DIO_voidSetPinValue(HEATER_PORT, HEATER_PIN, DIO_PIN_HIGH);
	}
	else if(HEATER_MODE == HEATER_ACTIVE_HIGH){
		DIO_voidSetPinValue(HEATER_PORT, HEATER_PIN, DIO_PIN_LOW);
	}
}