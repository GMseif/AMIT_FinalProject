
#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_

/* standard libraries */
#include "STDTYPES.h"
#include "BITMATH.h"

/* HAL */
#include "SSD_config.h"

/* SSD ID */
#define SSD_ID1 1
#define SSD_ID2 2

void SSD_voidInit(void);
/* void SSD_voidDisplayDigit(u8 copy_u8SSDId, u8 copy_u8Digit); */
/* void SSD_voidDisplayTwoDigits(u8 copy_u8Digit); */
void SSD_voidDisplayVariable(u8 copy_u8SSDId, u8 copy_u8Variable);

#endif /* SSD_INTERFACE_H_ */