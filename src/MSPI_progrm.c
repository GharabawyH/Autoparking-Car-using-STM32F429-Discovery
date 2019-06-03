/*
 * MSPI_progrm.c

 *
 *  Created on: ??þ/??þ/????
 *      Author: Bido
 */
#include"LSTD_TYPES.h"
#include"MSPI_private.h"
#include"MSPI_interface.h"

void MSPI5_Initialize_Master(void)
{
	(MSPI5 -> CR1) = 0x0324;
	(MSPI5 -> CR1) |= 0x40;
}

void MSPI5_Initialize_Master_BaudRateUp(void)
{
	(MSPI5 -> CR1) &= ~(0x40);
	(MSPI5 -> CR1) = 0x0304;
	(MSPI5 -> CR1) |= 0x40;
}

u8 MSPI5_Tranceive(u8 Write)
{
	u8 Read;
	(MSPI5 -> DR) = (u8)Write;
	while(!((MSPI5 -> SR) & TXE_Flag));
	while(!((MSPI5 -> SR) & RXNE_Flag));
	while(((MSPI5 -> SR)  & BSY_Flag));
	Read = (u8)(MSPI5 -> DR);
	return Read;
}

void MSPI6_Initialize_slave(void)
{
	(MSPI6 -> CR1) = (u16)0x00B0;
	(MSPI6 -> CR1) |= (u16)0x0040;
}
u8 MSPI6_Tranceive(u8 Write)
{
	u8 Read;
	while(!((MSPI6 -> SR)&RXNE_Flag));
	Read = MSPI6 -> DR;
	while(!((MSPI6 -> SR) & TXE_Flag));
	(MSPI6 -> DR) = (u8)Write;
//	while(!((MSPI6 -> SR) & TXE_Flag));
	while(((MSPI6 -> SR)&BSY_Flag));
	return Read;
}
