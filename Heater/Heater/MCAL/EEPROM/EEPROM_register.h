
#ifndef REGISTERS_H
#define REGISTERS_H

#include "STDTYPES.h"

#define EECR   (*(volatile u8*)0x3C)
#define EEDR   (*(volatile u8*)0x3D)
#define EEAR   (*(volatile u16*)0x3E)

/*
#define EEARL  (*(volatile u16*)0x3E)
#define EEARH  (*(volatile u16*)0x3F)
*/

/* EECR bits */
#define EERE   0
#define EEWE   1
#define EEMWE  2
#define EERIE  3

/* EEAR bits */
#define EEAR0 0
#define EEAR1 1
#define EEAR2 2
#define EEAR3 3
#define EEAR4 4
#define EEAR5 5
#define EEAR6 6
#define EEAR7 7
#define EEAR8 8
#define EEAR9 9


#endif
