#ifndef HEATER_H_
#define HEATER_H_

/* Standard libraries */
#include "STDTYPES.h"
#include "BITMATH.h"

/* MCAL */
#include "DIO_interface.h"
#include "ADC_interface.h"
#include "EEPROM_interface.h"
#include "TMR0_interface.h"

/* HAL */
#include "COOLER_interface.h"
#include "HEATER_interface.h"
#include "LM35_interface.h"
#include "LED_interface.h"
#include "Switch_interface.h"
#include "SSD_interface.h"

/* Function Prototypes */
void voidInit(void);
void voidOnOffBehaviour(void);               
void voidTempSetting(void);
void voidHeatingCoolingElements(void); /* Heating element LED implemented inside */
/* void voidHeatingElementLED(void); */
void voidDisplayTemp(void);
void voidUpdateTemp(void);
u8 u8GetSystemState(void);
void voidUpdateMillis(void);
u32 u32GetMillis(void);


/* System State */
#define SYSTEM_ON  1
#define SYSTEM_OFF 0

/* System Setting mode */
#define SETTING_MODE_ON  1
#define SETTING_MODE_OFF 0

/* System definitions */
#define MIN_TEMP      35
#define MAX_TEMP      75
#define DEFAULT_TEMP  60

/* EEPROM */
#define EEPROM_ADDRESS 0x00

/* Elements state */
#define HEATER_OFF 0
#define HEATER_ON  1
#define COOLER_OFF 0
#define COOLER_ON  1

/* ON\OFF Switch */
#define ONOFF_SWITCH_PORT        DIO_PORTA
#define ONOFF_SWITCH_PIN         DIO_PIN6
#define ONOFF_SWITCH_CONNECTION  SWITCH_REVERSE_CONNECTION

/* UP Switch */
#define UP_SWITCH_PORT         DIO_PORTA
#define UP_SWITCH_PIN          DIO_PIN4
#define UP_SWITCH_CONNECTION   SWITCH_REVERSE_CONNECTION

/* DOWN Switch */
#define DOWN_SWITCH_PORT         DIO_PORTA
#define DOWN_SWITCH_PIN          DIO_PIN5
#define DOWN_SWITCH_CONNECTION   SWITCH_REVERSE_CONNECTION

/* Heating Element LED */
#define HEATING_LED_PORT          DIO_PORTB
#define HEATING_LED_PIN           DIO_PIN7
#define HEATING_LED_CONNECTION    LED_FORWARD_CONNECTION

/* SSD */
#define FIRST_SSD   SSD_ID1
#define SECOND_SSD  SSD_ID2

/* Sensor */
#define TEMP_SENSOR_CHANNEL     ADC_CHANNEL_0

#endif /* HEATER_H_ */