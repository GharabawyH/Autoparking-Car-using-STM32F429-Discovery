#ifndef _MI2C_PRIVATE_H_
#define _MI2C_PRIVATE_H_

#include "stm32f4xx.h"
typedef struct
{
	u16 CR1;
	u16 Reserved0;
	u16 CR2;
	u16 Reserved1;
	u16 OAR1;
	u16 Reserved2;
	u16 OAR2;
	u16 Reserved3;
	u16 DR;
	u16 Reserved4;
	u16 SR1;
	u16 Reserved5;
	u16 SR2;
	u16 Reserved6;
	u16 CCR;
	u16 Reserved7;
	u16 TRISE;
	u16 Reserved8;
	u16 FLTR;
}MI2C_Type;



#define MI2C1 ((volatile MI2C_Type*)0x40005400)










#endif
