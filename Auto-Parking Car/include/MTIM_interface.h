#ifndef _MTIM_INTERFACE_H
#define _MTIM_INTERFACE_H

void MTIM1_Initialize(void);
void MTIM1_ICU_Initialize(void);
void MTIM8_ICU_Initialize(void);
u16 MTIM1_Read_ICU(u8 channel);
u16 MTIM8_Read_ICU(u8 channel);
u8 TIM1_Get_CCI_Flag(void);
u8 TIM8_Get_CCI_Flag(void);
void MTIM1_UP_SetCallBack(void(*Ptr)(void));
void MTIM1_ICU_SetCallBack(void(*Ptr)(void));
void MTIM8_UP_SetCallBack(void(*Ptr)(void));
void MTIM8_ICU_SetCallBack(void(*Ptr)(void));
void MTIM2_IRQ_SetCallBack(void(*Ptr)(void));
void MTIM3_IRQ_SetCallBack(void(*Ptr)(void));

void MTIM2_PWM_Initialize(void);
void MTIM2_PWM(u32 pulse,u8 channel);

void MTIM7_IRQ_SetCallBack(void(*Ptr)(void));

void MTIM3_Initialize(void);
void MTIM7_Initialize(void);




#define Channel1  2  /*timer2 pin A0*/
#define Channel2  4	/*timer2 pin A1*/
#define Channel3  8	/*timer2 pin A2*/
#define Channel4  0x10	/*timer2 pin A3*/

#endif
