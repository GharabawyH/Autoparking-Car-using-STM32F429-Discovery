#ifndef _MGPIO_INTERFACE_H
#define _MGPIO_INTERFACE_H


#define Low						50
#define High					70


#define PORTA					0
#define PORTB					1
#define PORTC					2
#define PORTD					3
#define PORTE					4
#define PORTF					5
#define PORTG					6
#define PORTH					7

#define Pin0					0
#define Pin1					1
#define Pin2					2
#define Pin3					3
#define Pin4					4
#define Pin5					5
#define Pin6					6
#define Pin7					7
#define Pin8					8
#define Pin9					9
#define Pin10					10
#define Pin11					11
#define Pin12					12
#define Pin13					13
#define Pin14					14
#define Pin15					15


#define Pin0_Set					0x0001
#define Pin1_Set					0x0002
#define Pin2_Set					0x0004
#define Pin3_Set					0x0008
#define Pin4_Set					0x0010
#define Pin5_Set					0x0020
#define Pin6_Set					0x0040
#define Pin7_Set					0x0080
#define Pin8_Set					0x0100
#define Pin9_Set					0x0200
#define Pin10_Set					0x0400
#define Pin11_Set					0x0800
#define Pin12_Set					0x1000
#define Pin13_Set					0x2000
#define Pin14_Set					0x4000
#define Pin15_Set					0x8000
#define Pin0_Reset					0x10000
#define Pin1_Reset					0x20000
#define Pin2_Reset					0x40000
#define Pin3_Reset					0x80000
#define Pin4_Reset					0x100000
#define Pin5_Reset					0x200000
#define Pin6_Reset					0x400000
#define Pin7_Reset					0x800000
#define Pin8_Reset					0x1000000
#define Pin9_Reset					0x2000000
#define Pin10_Reset					0x4000000
#define Pin11_Reset					0x8000000
#define Pin12_Reset					0x10000000
#define Pin13_Reset					0x20000000
#define Pin14_Reset					0x40000000
#define Pin15_Reset					0x80000000

/*Mode*/
#define Input	0
#define Output	1
#define AF		2
#define Analog	3

/*Output type*/
#define PushPull	45
#define OpenDrain	30

/*Speed*/
#define	LS	0
#define MS	1
#define HS	2
#define VHS	3

/*Input type*/
#define Floating	0
#define PullUp		1
#define PullDown	2

#define AF0  0
#define AF1  1
#define AF2  2
#define AF3  3
#define AF4  4
#define AF5  5
#define AF6  6
#define AF7  7
#define AF8  8
#define AF9  9
#define AF10 10
#define AF11 11
#define AF12 12
#define AF13 13
#define AF14 14
#define AF15 15


void MGPIO_Pin_MODE(u8 Port , u8 PinNum , u8 Mode);
void MGPIO_Pin_OTYPE(u8 Port , u8 Pin , u8 OutputType);
void MGPIO_Pin_OSPEED(u8 Port , u8 PinNum , u8 Speed);
void MGPIO_Pin_PullUpOrDown(u8 Port , u8 PinNum , u8 UpDown);
void MGPIO_Pin_Select_AF_Channel_LOW(u8 Port , u8 PinNum, u8 Channel);
void MGPIO_Pin_Select_AF_Channel_HIGH(u8 Port , u8 PinNum, u8 Channel);
void MGPIO_SetPin(u8 Port ,u16 Pin);
void MGPIO_ClearPin(u8 Port,u32 Pin);
void MGPIO_AssignPort(u8 Port,u16 Value);
u16 MGPIO_GetPinValue(u8 Port, u16 Pin);
void MGPIO_Pin_Select_AF_Channel_LOW(u8 Port , u8 PinNum, u8 Channel);
void MGPIO_Initialize(void);



#endif
