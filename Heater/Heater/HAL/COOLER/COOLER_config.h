
#ifndef COOLER_CONFIG_H_
#define COOLER_CONFIG_H_

#include "STDTYPES.h"
#include "BITMATH.h"

#include "DIO_interface.h"

/* Activation method */
#define COOLER_ACTIVE_LOW  0
#define COOLER_ACTIVE_HIGH 1

// #define COOLER_MODE COOLER_ACTIVE_LOW
#define COOLER_MODE COOLER_ACTIVE_HIGH

#define COOLER_PORT DIO_PORTB_ID
#define COOLER_PIN  DIO_PIN5


#endif /* COOLER_CONFIG_H_ */