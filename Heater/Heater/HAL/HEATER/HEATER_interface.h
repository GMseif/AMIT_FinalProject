
#ifndef HEATER_INTERFACE_H_
#define HEATER_INTERFACE_H_

#include "STDTYPES.h"
#include "BITMATH.h"

#include "HEATER_config.h"

/* Initialize heater control pin */
void HEATER_voidInit(void);

/* heater on */
void HEATER_voidOn(void);

/* heater off */
void HEATER_voidOff(void);


#endif /* HEATER_INTERFACE_H_ */