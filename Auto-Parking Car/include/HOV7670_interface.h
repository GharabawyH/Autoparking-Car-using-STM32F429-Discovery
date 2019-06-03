
#ifndef HOV7670_INTERFACE_H
#define HOV7670_INTERFACE_H



void HOV7670_Initialize(void);
void HOV7670_WriteByte(u8 address,u8 reg, u8 data);
u8 HOV7670_ReadByte(u8 address , u8 reg);
void HOV7670_Configure(void);

// SCCB write address
#define SCCB_REG_ADDR 			0x01

// OV7670 camera settings
#define OV7670_REG_NUM 			122
#define OV7670_WRITE_ADDR 		0x42

// Image settings
#define IMG_ROWS   				320
#define IMG_COLUMNS   			240

// Image buffer
extern volatile u16 frame_buffer[IMG_ROWS*IMG_COLUMNS];

#endif
