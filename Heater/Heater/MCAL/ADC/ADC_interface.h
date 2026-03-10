
#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#include "BITMATH.h"
#include "STDTYPES.h"

#include "ADC_register.h" 

#define NULL ((void *)0)

// enum for reference voltage
typedef enum
{
	ADC_REFERENCE_AVCC,
	ADC_REFERENCE_AREF,
	ADC_REFERENCE_INTERNAL
}ADC_refVolt_t;

// enum for channel number as single ended input
typedef enum
{
	ADC_CHANNEL_0,
	ADC_CHANNEL_1,
	ADC_CHANNEL_2,
	ADC_CHANNEL_3,
	ADC_CHANNEL_4,
	ADC_CHANNEL_5,
	ADC_CHANNEL_6,
	ADC_CHANNEL_7
}ADC_channelId_t;

// functions prototypes
void ADC_voidInit(ADC_refVolt_t copy_tRefVolt);
void ADC_voidGetDigitalValue(ADC_channelId_t copy_tChannelId, u16* pu16DigitalValue);

#endif /* ADC_INTERFACE_H_ */