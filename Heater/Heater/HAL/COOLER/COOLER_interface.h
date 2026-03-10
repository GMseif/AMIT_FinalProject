
#ifndef COOLER_INTERFACE_H_
#define COOLER_INTERFACE_H_

#include "STDTYPES.h"
#include "BITMATH.h"

#include "COOLER_config.h"

/* Initialize cooler control pin */
void COOLER_voidInit(void);

/* cooler on */
void COOLER_voidOn(void);

/* cooler off */
void COOLER_voidOff(void);


#endif /* COOLER_INTERFACE_H_ */