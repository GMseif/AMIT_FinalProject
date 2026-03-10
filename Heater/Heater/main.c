/*
main.c
Electric Water Heater System
Seif El-deen Mohamed     hseif14h@gmail.com
Kamel saeed              kamelsaeed703@gmail.com 
 */

/* Standard Libraries */
#include "STDTYPES.h"
#include "BITMATH.h"

/* APP */
#include "Heater.h"

int main(void)
{
	/* System initialize */
	voidInit();
	
	while(1)
	{
		/* Time update for timer0 polling */ 
		voidUpdateMillis();
		
		/* On Off button to toggle system state */
		voidOnOffBehaviour();

		if(u8GetSystemState() == SYSTEM_ON)
		{
			/* Set temperature from up and down buttons */
			voidTempSetting();
			/* Update temperature reading from sensor */
			voidUpdateTemperature();
			/* Heating and cooling logic with element LED */
			voidHeatingCoolingElements();
			/* system display seven segments */
			voidDisplayTemp();
		}

	}
	
	return 0;
}