
#ifndef EEPROM_INTERFACE_H
#define EEPROM_INTERFACE_H

#include "STDTYPES.h"
#include "BITMATH.h"

/* Write one byte to EEPROM */
void EEPROM_voidWriteByte(u16 copy_u16Address, u8 copy_u8Data);

/* Read one byte from EEPROM */
void EEPROM_voidReadByte(u16 copy_u16Address, u8* pu8ReturnedData);

#endif
