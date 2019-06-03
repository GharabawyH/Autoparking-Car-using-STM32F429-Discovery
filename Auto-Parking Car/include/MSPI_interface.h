/*
 * MSPI_interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Bido
 */

#ifndef MSPI_INTERFACE_H_
#define MSPI_INTERFACE_H_



void MSPI5_Initialize_Master(void);
void MSPI5_Initialize_Master_BaudRateUp(void);
u8 MSPI5_Tranceive(u8 Data);

void MSPI6_Initialize_slave(void);
u8 MSPI6_Tranceive(u8 Write);

#define BSY_Flag  0x0080
#define TXE_Flag  0x0002
#define RXNE_Flag 0x0001





#endif /* MSPI_INTERFACE_H_ */
