#ifndef SSD_CONFIG_H_
#define SSD_CONFIG_H_

/* MCAL */
#include "DIO_interface.h"

/* First SSD tens */
#define SSD_DATA1_PORT        DIO_PORTC_ID
#define SSD_ENABLE1_PORT      DIO_PORTC_ID
#define SSD_E1_PIN            DIO_PIN7

/* Second SSD ones */
#define SSD_DATA2_PORT        DIO_PORTD_ID
#define SSD_ENABLE2_PORT      DIO_PORTD_ID
#define SSD_E2_PIN            DIO_PIN7

#endif /* SSD_CONFIG_H_ */