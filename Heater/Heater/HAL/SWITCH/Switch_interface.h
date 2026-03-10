
#ifndef SWITCH_INTERFACE_H_
#define SWITCH_INTERFACE_H_

#include "STDTYPES.h"
#include "BITMATH.h"

/* Switch connection type */
#define SWITCH_FORWARD_CONNECTION 0
#define SWITCH_REVERSE_CONNECTION 1

/* Switch status */
#define SWITCH_PRESSED     1
#define SWITCH_NOT_PRESSED 0

/* Function prototypes */
void Switch_voidInit(u8 copy_u8SwitchPort, u8 copy_u8SwitchPin);
void Switch_voidGetStatus(u8 copy_u8SwitchPort, u8 copy_u8SwitchPin, u8 copy_u8SwitchConnectionType, u8* pu8SwitchStatus);

#endif /* SWITCH_INTERFACE_H_ */