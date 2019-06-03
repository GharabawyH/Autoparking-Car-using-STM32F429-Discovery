#ifndef _MI2C_INTERFACE_H_
#define _MI2C_INTERFACE_H_
//#include "stm32f4xx.h"

void MI2C_Master_Init(void);
void MI2C_Start(void);
void MI2C_RepStart(void);
void MI2C_Send_Slave_Address_With_Write_Request(u8 Address);
void MI2C_Write_Byte(u8 Data);
void MI2C_Send_Slave_Address_With_Read_Request(u8 Address);
u8 MI2C_readNAck(void);
u8 MI2C_readAck(void);
void MI2C_Stop(void);







#endif
