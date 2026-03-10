
/* Standard libraries */
#include "STDTYPES.h"
#include "BITMATH.h"

/* MCAL */
#include "ADC_interface.h"

/* HAL */
#include "LM35_config.h"
#include "LM35_interface.h"

u8 LM35_u8ReadTemperature(void){
	
	u16 local_u16ADCValue= 0;
	u32 local_u32VoltageMv;
	u8  local_u8Temperature;
	
	/* Get digital value from ADC */
	ADC_voidGetDigitalValue(LM35_ADC_CHANNEL, &local_u16ADCValue);
	
	/* Convert ADC value to voltage in mV 
	   Vin = (ADC × Vref) / 1024           */
    local_u32VoltageMv = ((u32)local_u16ADCValue * LM35_VREF_MV) / 1024;
	
	/* 1 degree every 10mV */
	local_u8Temperature = (u8)(local_u32VoltageMv / 10);
	
	return local_u8Temperature; 
}