
#include "STDTYPES.h"
#include "BITMATH.h"

#include "EEPROM_interface.h"
#include "EEPROM_register.h"

void EEPROM_voidWriteByte(u16 copy_u16Address, u8 copy_u8Data){
	
	/* Wait for completion of previous write */
	while (GET_BIT(EECR, EEWE));

	/* Set EEPROM address */
	EEAR = copy_u16Address;

	/* Set EEPROM data */
	EEDR = copy_u8Data;

	/* Enable write */
	SET_BIT(EECR, EEMWE);

	/* Start write */
	SET_BIT(EECR, EEWE);
}

void EEPROM_voidReadByte(u16 copy_u16Address, u8* pu8ReturnedData)
{
	/* Set EEPROM address */
	EEAR = copy_u16Address;

	/* Start EEPROM read */
	SET_BIT(EECR, EERE);

	/* Read data */
	*pu8ReturnedData = EEDR;
}


