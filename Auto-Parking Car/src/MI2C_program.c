#include"LSTD_TYPES.h"
#include "MI2C_interface.h"
#include "MI2C_private.h"


void MI2C_Master_Init(void)
{
	MI2C1 -> CR1 &= ~(0x1);/*Disable I2C Peripheral*/
	MI2C1 -> CR2 = 0x2D;/*Write PCLK1 = 45MHZ to FREQ[5:0]*/
	MI2C1 -> CCR = 0xC026;/*Clear F/S bit to enable Sm , Reset Duty bit , Write CCR[11:0]=117 (75Hexa) */
	/*T_high=CCR*TPCLK1 , T_low=2*CCR*TPCLK1*/
	MI2C1 -> TRISE = 0xF;/*T_rise for High Speed mode = (((PCLK1/1000000)*300)/1000)+1*/
	MI2C1 -> CR1 = 0x1;/*Enable I2C Peripheral */
}

void MI2C_Start(void)
{
	while(((MI2C1 -> SR2) & 0x2));/*Wait for Busy bit to reset : (no communication ongoing on the bus)*/
	/*This bit is Set by hardware on detection of SDA or SCL low */
	MI2C1 -> CR1 |= 0x100;/*Send the start bit*/
	while(!((MI2C1 -> SR1) & 1));/*Waiting for SB bit to set*/
	while(!((MI2C1 -> SR2) & 0x1));/*Waiting for MSL bit to set to check for Master Mode*/
}

void MI2C_RepStart(void)
{
	while(!((MI2C1 -> SR2) & 0x2));/*Wait for Busy bit to set : ( communication ongoing on the bus)*/
	/*This bit is Set by hardware on detection of SDA or SCL low */
	MI2C1 -> CR1 = 0x101;/*Send the start bit*/
	while(!((MI2C1 -> SR1) & 1));/*Waiting for SB bit to set*/
	while(!((MI2C1 -> SR2) & 0x1));/*Waiting for MSL bit to set to check for Master Mode*/
}

void MI2C_Send_Slave_Address_With_Write_Request(u8 Address)
{
	while(!((MI2C1 -> SR2) & 0x2));/*Wait for Busy bit to set : (communication ongoing on the bus)*/
	/*This bit is Set by hardware on detection of SDA or SCL low */
	MI2C1 -> DR = Address ;/*Write the address of EEPROM 24C08 to data register[7:1]*/
	while((MI2C1 -> SR1 & 0x400));/*wait for ACK*/
	while(!(MI2C1 -> SR1 & 2));/*Wait for ADDR bit to set*/
	while(!((MI2C1 -> SR2) & 0x1));/*Waiting for MSL bit to set to check Master Mode*/
	while((MI2C1 -> SR1 & 2));/*Wait for ADDR bit to reset*/
}

void MI2C_Write_Byte(u8 Data)
{
	while(!((MI2C1 -> SR2) & 0x2));/*Wait for Busy bit to set : (communication ongoing on the bus)*/
	/*This bit is Set by hardware on detection of SDA or SCL low */
	while(!(MI2C1 -> SR1 & 0x80));/*Wait for TxE (Data register is empty)*/
	MI2C1 -> DR = Data;/*Write data to the selected address*/
	while(!(MI2C1 -> SR1 & 0x80));/*Wait for TxE (Data register is empty)*/
	while((MI2C1 -> SR1 & 0x400));/*Wait for ACK*/
	while(!(MI2C1 -> SR1 & 0x84));/*Wait for TxE (Data register is empty)*/
//	while(!(MI2C1 -> SR1 & 0x4));/*Wait for TxE (Data register is empty)*/
	while(!((MI2C1 -> SR2) & 0x1));/*Waiting for MSL bit to set to check Master Mode*/
}

void MI2C_Send_Slave_Address_With_Read_Request(u8 Address)
{
	while(!((MI2C1 -> SR2) & 0x2));/*Wait for Busy bit to set : (communication ongoing on the bus)*/
	/*This bit is Set by hardware on detection of SDA or SCL low */
	MI2C1 -> DR = Address;
	while((MI2C1 -> SR1 & 0x400));/*Wait for ACK*/
	while(!(MI2C1 -> SR1 & 2));/*Wait for ADDR bit to set*/
	while(!((MI2C1 -> SR2) & 0x1));/*Waiting for MSL bit to set to check Master Mode*/
	while((MI2C1 -> SR1 & 2));/*Wait for ADDR bit to reset*/
}

u8 MI2C_readNAck(void)
{
	while(!((MI2C1 -> SR2) & 0x2));/*Wait for Busy bit to set : (communication ongoing on the bus)*/
	/*This bit is Set by hardware on detection of SDA or SCL low */
	MI2C1 -> CR1 &= ~(0xC00);
	while(!(MI2C1 -> SR1 & 0x40));
	return (u8)MI2C1 -> DR;
	while((MI2C1 -> SR1 & 0x40));
	while(!(MI2C1 -> SR1 & 0x400));/*Wait for NACK*/
	while(!((MI2C1 -> SR2) & 0x1));/*Waiting for MSL bit to set to check Master Mode*/
}


u8 MI2C_readAck(void)
{
	while(!((MI2C1 -> SR2) & 0x2));/*Wait for Busy bit to set : (communication ongoing on the bus)*/
	/*This bit is Set by hardware on detection of SDA or SCL low */
	MI2C1 -> CR1 |= 0x400;/*Enable Ack for more data*/
	while(!(MI2C1 -> SR1 & 0x40));
	return (u8)MI2C1 -> DR;
	while((MI2C1 -> SR1 & 0x40));
	while((MI2C1 -> SR1 & 0x400));/*Wait for ACK*/
	while(!((MI2C1 -> SR2) & 0x1));/*Waiting for MSL bit to set to check Master Mode*/
}
void MI2C_Stop(void)
{
	while(!((MI2C1 -> SR2) & 0x2));/*Wait for Busy bit to set : (communication ongoing on the bus)*/
	/*This bit is Set by hardware on detection of SDA or SCL low */
	MI2C1 -> CR1 |= 0x200;/*send stop condition*/
	//	while(!((MI2C1 -> SR1) & 0x10));
	while(((MI2C1 -> SR2) & 0x1));/*Wait for MSL to reset indicating stop is recognized and turned into slave mode*/
}
