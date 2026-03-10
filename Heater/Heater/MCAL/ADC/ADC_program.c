
#include "BITMATH.h"
#include "STDTYPES.h"

#include "ADC_interface.h"

void ADC_voidInit(ADC_refVolt_t copy_tRefVolt)
{
	switch(copy_tRefVolt)
	{
		case ADC_REFERENCE_AREF:
		CLR_BIT(ADMUX_REG, REFS0);
		CLR_BIT(ADMUX_REG, REFS1);
		break;
		
		case ADC_REFERENCE_AVCC:
		SET_BIT(ADMUX_REG, REFS0);
		CLR_BIT(ADMUX_REG, REFS1);
		break;
		
		case ADC_REFERENCE_INTERNAL:
		SET_BIT(ADMUX_REG, REFS0);
		SET_BIT(ADMUX_REG, REFS1);
		break;
	}
	
	// right adjustment
	CLR_BIT(ADMUX_REG, ADLAR);

	// start conversion
	SET_BIT(ADCSRA_REG, ADSC);

	// disable interrupt
	CLR_BIT(ADCSRA_REG, ADIE);

	// disable auto trigger
	// single conversion mode
	CLR_BIT(ADCSRA_REG, ADATE);

	// set prescaler 128
	SET_BIT(ADCSRA_REG, ADPS0);
	SET_BIT(ADCSRA_REG, ADPS1);
	SET_BIT(ADCSRA_REG, ADPS2);

	// enable ADC
	SET_BIT(ADCSRA_REG, ADEN);
}

void ADC_voidGetDigitalValue(ADC_channelId_t copy_tChannelId, u16* pu16DigitalValue)
{
	if((copy_tChannelId <32) && (pu16DigitalValue != NULL))
	{
		// clear 5 bits 
		ADMUX_REG &= 0b11100000; // 111 no change (0xE0)hexadecimal
		ADMUX_REG |= copy_tChannelId; // set 5 bits to channel id
		SET_BIT(ADCSRA_REG, ADSC);
		// busy wait
		while(GET_BIT(ADCSRA_REG, ADIF) == 0); // wait till flag is raised
		// terminate when conversion ends 
		SET_BIT(ADCSRA_REG, ADIF); // clear flag
		// pass out ADC data
		*pu16DigitalValue = ADC_u16_REG;
	}
	else
	{
		// return error state
	}
}


/* void ADC_voidGetDigitalValue(ADC_channelId_t copy_tChannelId, u16* pu16DigitalValue)
{
	switch(copy_tChannelId)
	{
		case ADC_CHANNEL_0:
		CLR_BIT(ADMUX_REG, MUX4);
		CLR_BIT(ADMUX_REG, MUX3);
		CLR_BIT(ADMUX_REG, MUX2);
		CLR_BIT(ADMUX_REG, MUX1);
		CLR_BIT(ADMUX_REG, MUX0);
		break;
		
		case ADC_CHANNEL_1:
		CLR_BIT(ADMUX_REG, MUX4);
		CLR_BIT(ADMUX_REG, MUX3);
		CLR_BIT(ADMUX_REG, MUX2);
		CLR_BIT(ADMUX_REG, MUX1);
		SET_BIT(ADMUX_REG, MUX0);
		break;
		
		case ADC_CHANNEL_2:
		CLR_BIT(ADMUX_REG, MUX4);
		CLR_BIT(ADMUX_REG, MUX3);
		CLR_BIT(ADMUX_REG, MUX2);
		SET_BIT(ADMUX_REG, MUX1);
		CLR_BIT(ADMUX_REG, MUX0);
		break;
		
		case ADC_CHANNEL_3:
		CLR_BIT(ADMUX_REG, MUX4);
		CLR_BIT(ADMUX_REG, MUX3);
		CLR_BIT(ADMUX_REG, MUX2);
		SET_BIT(ADMUX_REG, MUX1);
		SET_BIT(ADMUX_REG, MUX0);
		break;
		
		case ADC_CHANNEL_4:
		CLR_BIT(ADMUX_REG, MUX4);
		CLR_BIT(ADMUX_REG, MUX3);
		SET_BIT(ADMUX_REG, MUX2);
		CLR_BIT(ADMUX_REG, MUX1);
		CLR_BIT(ADMUX_REG, MUX0);
		break;
		
		case ADC_CHANNEL_5:
		CLR_BIT(ADMUX_REG, MUX4);
		CLR_BIT(ADMUX_REG, MUX3);
		SET_BIT(ADMUX_REG, MUX2);
		CLR_BIT(ADMUX_REG, MUX1);
		SET_BIT(ADMUX_REG, MUX0);
		break;
		
		case ADC_CHANNEL_6:
		CLR_BIT(ADMUX_REG, MUX4);
		CLR_BIT(ADMUX_REG, MUX3);
		SET_BIT(ADMUX_REG, MUX2);
		SET_BIT(ADMUX_REG, MUX1);
		CLR_BIT(ADMUX_REG, MUX0);
		break;
		
		case ADC_CHANNEL_7:
		CLR_BIT(ADMUX_REG, MUX4);
		CLR_BIT(ADMUX_REG, MUX3);
		SET_BIT(ADMUX_REG, MUX2);
		SET_BIT(ADMUX_REG, MUX1);
		SET_BIT(ADMUX_REG, MUX0);
		break;
	}
}
*/