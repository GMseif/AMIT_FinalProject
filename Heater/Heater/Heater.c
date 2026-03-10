/* APP */
#include "Heater.h"

/* Global Variables for system */
static u8 static_u8SystemState = SYSTEM_OFF;
static u8 static_u8SettingMode = SETTING_MODE_OFF;
static u8 static_u8HeaterState = HEATER_OFF;
static u8 static_u8CoolerState = COOLER_OFF;
static u8 static_u8SetTemp = DEFAULT_TEMP;
static u8 static_u8CurrentTemp = DEFAULT_TEMP;

/* Average temperature readings */
static u8 static_u8TempReadings[10] = {0};
static u8 static_u8TempIndex = 0;

/* Blinking state for LED and SSD */
static u8 static_u8LEDBlinkState = 0;
static u8 static_u8DisplayBlinkState = 1;

/* Millisecond counter */
static volatile u32 static_u32Millis = 0;

/* Last update times */
static u32 static_u32LastTempUpdate = 0;     
static u32 static_u32LastLEDUpdate = 0;      
static u32 static_u32LastDisplayUpdate = 0;  
static u32 static_u32SettingModeStartTime = 0;

/* System Initialization */
void voidInit(void){
	
	/* Load temperature from EEPROM */
	EEPROM_voidReadByte(EEPROM_ADDRESS, &static_u8SetTemp);
	
	if((static_u8SetTemp < MIN_TEMP) || (static_u8SetTemp > MAX_TEMP)){
		static_u8SetTemp = DEFAULT_TEMP;
		EEPROM_voidWriteByte(EEPROM_ADDRESS, static_u8SetTemp);
	}
	
	/* Heating element LED */
	LED_voidInit(HEATING_LED_PORT, HEATING_LED_PIN);
	
	/* Heating and Cooling elements */
	HEATER_voidInit(); /* Red LED in the simulation */
	COOLER_voidInit(); /* Blue LED in the simulation */
	
	/* Seven Segments */
	SSD_voidInit(); /* The two seven segments */
	
	/* Switches */
	Switch_voidInit(ONOFF_SWITCH_PORT, ONOFF_SWITCH_PIN);
	Switch_voidInit(UP_SWITCH_PORT, UP_SWITCH_PIN);
	Switch_voidInit(DOWN_SWITCH_PORT, DOWN_SWITCH_PIN);
	
	/* ADC */
	ADC_voidInit(ADC_REFERENCE_AVCC); /* AVCC is ADC reference voltage */
	
	/* Timer polling mode */
	TMR0_voidInit();
	TMR0_voidStart();
}

/* Counter milliseconds replacing ISR */
void voidUpdateMillis(void){
	u8 local_u8OverflowFlag;
	
	/* Check if Timer0 overflowed */
	TMR0_u8GetOverflowFlag(&local_u8OverflowFlag);
	
	if(local_u8OverflowFlag == 1){
		/* Clear overflow flag */
		TMR0_voidClearOverflowFlag();
		
		/* Increment millisecond counter */
		static_u32Millis++;
	}
}

/* Get current milliseconds count */
u32 u32GetMillis(void){
	return static_u32Millis;
}

/* system On and Off */
void voidOnOffBehaviour(void){
	
	static u8 static_u8PreviousOnOffState = SWITCH_NOT_PRESSED;
	u8 u8CurrentOnOffState;

	Switch_voidGetStatus(ONOFF_SWITCH_PORT, ONOFF_SWITCH_PIN, ONOFF_SWITCH_CONNECTION, &u8CurrentOnOffState);

	/* Detect button release */
	if((static_u8PreviousOnOffState == SWITCH_PRESSED) && (u8CurrentOnOffState == SWITCH_NOT_PRESSED)){
		/* Toggle system state */
		if(static_u8SystemState == SYSTEM_OFF){
			static_u8SystemState = SYSTEM_ON;
			static_u8SettingMode = SETTING_MODE_OFF;
		}
		else{
			static_u8SystemState = SYSTEM_OFF;
			static_u8SettingMode = SETTING_MODE_OFF;
			
			/* Turn off display and system */
			HEATER_voidOff();
			COOLER_voidOff();
			LED_voidOff(HEATING_LED_PORT, HEATING_LED_PIN, HEATING_LED_CONNECTION);
			DIO_voidSetPinValue(SSD_ENABLE1_PORT, SSD_E1_PIN, DIO_PIN_HIGH);
			DIO_voidSetPinValue(SSD_ENABLE2_PORT, SSD_E2_PIN, DIO_PIN_HIGH);
			
			static_u8HeaterState = HEATER_OFF;
			static_u8CoolerState = COOLER_OFF;
		}
	}
	static_u8PreviousOnOffState = u8CurrentOnOffState;
}

/* Setting temperature up and down */
void voidTempSetting(void){
	static u8 static_u8UpPreviousState = SWITCH_NOT_PRESSED;
	static u8 static_u8DownPreviousState = SWITCH_NOT_PRESSED;
	u8 local_u8UpCurrentState;
	u8 local_u8DownCurrentState;
	
	Switch_voidGetStatus(UP_SWITCH_PORT, UP_SWITCH_PIN, UP_SWITCH_CONNECTION, &local_u8UpCurrentState);
	Switch_voidGetStatus(DOWN_SWITCH_PORT, DOWN_SWITCH_PIN, DOWN_SWITCH_CONNECTION, &local_u8DownCurrentState);
	
	/* Detect UP button release */
	if((static_u8UpPreviousState == SWITCH_PRESSED) && (local_u8UpCurrentState == SWITCH_NOT_PRESSED)){
		/* Enter setting mode and start countdown */
		if(static_u8SettingMode == SETTING_MODE_OFF){
			static_u8SettingMode = SETTING_MODE_ON;
			static_u32SettingModeStartTime = u32GetMillis();
		}
		
		/* Increase temperature */
		if(static_u8SetTemp < MAX_TEMP){
			static_u8SetTemp += 5;
			EEPROM_voidWriteByte(EEPROM_ADDRESS, static_u8SetTemp);
		}
		
		/* Reset countdown */
		static_u32SettingModeStartTime = u32GetMillis();
	}
	
	/* Detect DOWN button release */
	if((static_u8DownPreviousState == SWITCH_PRESSED) && (local_u8DownCurrentState == SWITCH_NOT_PRESSED)){
		/* Enter setting mode */
		if(static_u8SettingMode == SETTING_MODE_OFF){
			static_u8SettingMode = SETTING_MODE_ON;
			static_u32SettingModeStartTime = u32GetMillis();
		}
		
		/* Decrease temperature */
		if(static_u8SetTemp > MIN_TEMP){
			static_u8SetTemp -= 5;
			EEPROM_voidWriteByte(EEPROM_ADDRESS, static_u8SetTemp);
		}
		
		/* Reset timeout */
		static_u32SettingModeStartTime = u32GetMillis();
	}
	
	/* Exit setting mode after 5 seconds countdown */
	if(static_u8SettingMode == SETTING_MODE_ON){
		if((u32GetMillis() - static_u32SettingModeStartTime) >= 5000){
			static_u8SettingMode = SETTING_MODE_OFF;
		}
	}
	
	static_u8UpPreviousState = local_u8UpCurrentState;
	static_u8DownPreviousState = local_u8DownCurrentState;
}

/* Heating and cooling with Heating element LED inside */
void voidHeatingCoolingElements(void){
	static u32 static_u32LastLEDToggle = 0;
	u32 local_u32CurrentTime = u32GetMillis();
	
	if(static_u8SystemState == SYSTEM_OFF){
		LED_voidOff(HEATING_LED_PORT, HEATING_LED_PIN, HEATING_LED_CONNECTION);
		return;
	}

	/* Turn ON heater if current temp < (set temp - 5) */
	if(static_u8CurrentTemp < (static_u8SetTemp - 5)){
		COOLER_voidOff();
		HEATER_voidOn();
		static_u8HeaterState = HEATER_ON;
		static_u8CoolerState = COOLER_OFF;
	}
	/* Turn ON cooler if current temp > (set temp + 5) */
	else if(static_u8CurrentTemp > (static_u8SetTemp + 5)){
		HEATER_voidOff();
		COOLER_voidOn();
		static_u8HeaterState = HEATER_OFF;
		static_u8CoolerState = COOLER_ON;
	}
	else{
		HEATER_voidOff();
		COOLER_voidOff();
		static_u8HeaterState = HEATER_OFF;
		static_u8CoolerState = COOLER_OFF;
	}
	/* LED */
	
	/* If Heater ON toggle LED every 1 second */
	if(static_u8HeaterState == HEATER_ON){
		if((local_u32CurrentTime - static_u32LastLEDToggle) >= 1000){
			static_u32LastLEDToggle = local_u32CurrentTime;
			LED_voidToggle(HEATING_LED_PORT, HEATING_LED_PIN);
		}
	}
	/* If Cooler ON LED stay ON */
	else if(static_u8CoolerState == COOLER_ON){
		LED_voidOn(HEATING_LED_PORT, HEATING_LED_PIN, HEATING_LED_CONNECTION);
	}
	/* If Heater and cooler OFF LED OFF */
	else{
		LED_voidOff(HEATING_LED_PORT, HEATING_LED_PIN, HEATING_LED_CONNECTION);
	}
}
/* Heating element LED 
void voidHeatingElementLED(void){
	u32 local_u32CurrentTime = u32GetMillis();
	
	if(static_u8SystemState == SYSTEM_OFF){
		LED_voidOff(HEATING_LED_PORT, HEATING_LED_PIN, HEATING_LED_CONNECTION);
		return;
	}
	
	/* Update LED every second
	if((local_u32CurrentTime - static_u32LastLEDUpdate) >= 1000){
		static_u32LastLEDUpdate = local_u32CurrentTime;
		static_u8LEDBlinkState = (!static_u8LEDBlinkState);
	}
	
	/* Blink when heater is on 
	if(static_u8HeaterState == HEATER_ON){
		if(static_u8LEDBlinkState == 1){
			LED_voidOn(HEATING_LED_PORT, HEATING_LED_PIN, HEATING_LED_CONNECTION);
		}
		else{
			LED_voidOff(HEATING_LED_PORT, HEATING_LED_PIN, HEATING_LED_CONNECTION);
		}
	}
	/* Stay on when cooler is on 
	else if(static_u8CoolerState == COOLER_ON){
		LED_voidOn(HEATING_LED_PORT, HEATING_LED_PIN, HEATING_LED_CONNECTION);
	}
	else{
		LED_voidOff(HEATING_LED_PORT, HEATING_LED_PIN, HEATING_LED_CONNECTION);
	}
}
*/
	
/* System display seven segments */
void voidDisplayTemp(void){
	u8 local_u8Tens;
	u8 local_u8Ones;
	u32 local_u32CurrentTime = u32GetMillis();
	
	/* Turn off display when system is off */
	if(static_u8SystemState == SYSTEM_OFF){
		DIO_voidSetPinValue(SSD_ENABLE1_PORT, SSD_E1_PIN, DIO_PIN_HIGH);
		DIO_voidSetPinValue(SSD_ENABLE2_PORT, SSD_E2_PIN, DIO_PIN_HIGH);
		return;
	}
	
	/* Update display blink state every second */
	if((local_u32CurrentTime - static_u32LastDisplayUpdate) >= 1000){
		static_u32LastDisplayUpdate = local_u32CurrentTime;
		static_u8DisplayBlinkState = (!static_u8DisplayBlinkState);
	}
	
	/* Display set temp with blinking when setting mode on */
	if(static_u8SettingMode == SETTING_MODE_ON){
		if(static_u8DisplayBlinkState == 1){
			local_u8Tens = static_u8SetTemp / 10;
			local_u8Ones = static_u8SetTemp % 10;
			SSD_voidDisplayVariable(FIRST_SSD, local_u8Tens);
			SSD_voidDisplayVariable(SECOND_SSD, local_u8Ones);
		}
		else{
			DIO_voidSetPinValue(SSD_ENABLE1_PORT, SSD_E1_PIN, DIO_PIN_HIGH);
			DIO_voidSetPinValue(SSD_ENABLE2_PORT, SSD_E2_PIN, DIO_PIN_HIGH);
		}
	}
	/*  Display current temp when setting mode off */
	else{
		local_u8Tens = static_u8CurrentTemp / 10;
		local_u8Ones = static_u8CurrentTemp % 10;
		SSD_voidDisplayVariable(FIRST_SSD, local_u8Tens);
		SSD_voidDisplayVariable(SECOND_SSD, local_u8Ones);
	}
}

/* Reading temp and calculating average */
void voidUpdateTemperature(void){
	u16 local_u16ADCValue;
	u32 local_u32Sum = 0;
	u32 local_u32CurrentTime = u32GetMillis();
	u8 i;
	
	/* Update temperature reading every 100ms */
	if((local_u32CurrentTime - static_u32LastTempUpdate) >= 100){
		static_u32LastTempUpdate = local_u32CurrentTime;
		
		/* Read ADC and convert to temperature */
		ADC_voidGetDigitalValue(TEMP_SENSOR_CHANNEL, &local_u16ADCValue);
		/* Temp sensor send 10mV for every 1 degree temp and reference AVCC is 5000mV */
		u8 local_u8NewReading = (u8)((local_u16ADCValue * 500UL) / 1024);
		
		/* Store in circular buffer */
		static_u8TempReadings[static_u8TempIndex] = local_u8NewReading;
		static_u8TempIndex = (static_u8TempIndex + 1) % 10;
		
		/* Calculate average of last 10 readings */
		for(i = 0; i < 10; i++){
			local_u32Sum += static_u8TempReadings[i];
		}
		
		static_u8CurrentTemp = (u8)(local_u32Sum / 10);
	}
}

/* Get system state on or off */
u8 u8GetSystemState(void){
	return static_u8SystemState;
}