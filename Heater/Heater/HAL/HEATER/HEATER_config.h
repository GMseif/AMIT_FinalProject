
#ifndef HEATER_CONFIG_H_
#define HEATER_CONFIG_H_

#include "STDTYPES.h"
#include "BITMATH.h"

#include "DIO_interface.h"

/* Activation method */
#define HEATER_ACTIVE_LOW  0
#define HEATER_ACTIVE_HIGH 1

// #define HEATER_MODE HEATER_ACTIVE_LOW
#define HEATER_MODE HEATER_ACTIVE_HIGH

#define HEATER_PORT DIO_PORTB_ID
#define HEATER_PIN  DIO_PIN6


#endif /* HEATER_CONFIG_H_ */