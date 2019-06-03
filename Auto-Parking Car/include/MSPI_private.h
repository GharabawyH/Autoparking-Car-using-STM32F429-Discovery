/*
 * MSPI_private.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Bido
 */

#ifndef MSPI_PRIVATE_H_
#define MSPI_PRIVATE_H_

typedef struct
{
	volatile u16 CR1;
	const u16 Reserved0;
	volatile u16 CR2;
	const u16 Reserved1;
	volatile u16 SR;
	const u16 Reserved2;
	volatile u16 DR;
	const u16 Reserved3;
	volatile u16 CRCPR;
	const u16 Reserved4;
	volatile u16 RXCRCR;
	const u16 Reserved5;
	volatile u16 TXCRCR;
	const u16 Reserved6;
	volatile u16 I2SCFGR;
	const u16 Reserved7;
	volatile u16 I2SPR;

}MSPI_type;

#define MSPI6 ((volatile MSPI_type*)0x40015400)
#define MSPI5 ((volatile MSPI_type*)0x40015000)




#endif /* MSPI_PRIVATE_H_ */
