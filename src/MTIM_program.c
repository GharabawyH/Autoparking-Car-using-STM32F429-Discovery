#include "LSTD_TYPES.h"
#include "MTIM_interface.h"
#include "MTIM_private.h"


void (*MTIM1_UP_CallBack)(void);
void (*MTIM1_ICU_CallBack)(void);
void (*MTIM8_UP_CallBack)(void);
void (*MTIM8_ICU_CallBack)(void);
void (*MTIM2_IRQ_CallBack)(void);
void (*MTIM3_IRQ_CallBack)(void);
void (*MTIM7_IRQ_CallBack)(void);


void MTIM1_Initialize(void)
{
	MTIM1 -> CR1 	= 0x0084;
	MTIM1 -> DIER	= 0x0001;
	MTIM1 -> PSC	= 9999;
	MTIM1 -> ARR	= 9000;
	MTIM1 -> CNT	= 0;
	MTIM1 -> EGR	|=1;
	MTIM1 -> CR1   	|=1;
}

void MTIM2_PWM_Initialize(void)
{
	MTIM2 -> CR1 	= 0x0080;
	MTIM2 -> CCMR1  = 0x6868;
	MTIM2 -> CCMR2  = 0x6868;
	MTIM2 -> CCER	= 0x3333;
	MTIM2 -> PSC	= 179;
	MTIM2 -> ARR	= 20000;
	MTIM2 -> CNT	= 0;
	MTIM2 -> EGR	|=1;
	MTIM2 -> CR1    |=1;
}

void MTIM2_PWM(u32 pulse,u8 channel)
{
	switch(channel)
	{
	case Channel1 : MTIM2 -> CCR1 =pulse ;break;
	case Channel2 : MTIM2 -> CCR2 =pulse ;break;
	case Channel3 : MTIM2 -> CCR3 =pulse ;break;
	case Channel4 : MTIM2 -> CCR4 =pulse ;break;
	}
}

void MTIM3_Initialize(void)
{
	MTIM3 -> CR1 	= 0x0084;
	MTIM3 -> DIER	= 0x0001;
	MTIM3 -> PSC	= 0xFFFE;
	MTIM3 -> ARR	= 0xFFFF;
	MTIM3 -> CNT	= 0;
	MTIM3 -> EGR	|=1;
	MTIM3 -> CR1    |=1;
}

void MTIM7_Initialize(void)
{
	MTIM7 -> CR1 	= 0x0084;
	MTIM7 -> DIER	= 0x0001;
	MTIM7 -> PSC	= 9;
	MTIM7 -> ARR	= 4500;
	MTIM7 -> CNT	= 0;
	MTIM7 -> EGR	|=1;
	MTIM7 -> CR1    |=1;
}

void MTIM1_ICU_Initialize(void)
{
	/*channel 1 configuration */
	//	MTIM1 -> CR1 	= 0x0084;/*Auto reload preload enable , overflow generates update event*/
	//	MTIM1 -> DIER	= 0x0003;/*Update interrupt enable , Capture/Compare ch1 interrupt enable*/
	//	MTIM1 -> CCMR1	= 0x0001;/*CC1 channel is configured as input, IC1 is mapped on TI1*/
	//	MTIM1 -> CCER	= 0x000B;/*Capture occurs at rising edge bit 1 , Capture Enabled*/
	//	MTIM1 -> PSC	= 0;
	//	MTIM1 -> ARR	= 0xFFFF;
	//	MTIM1 -> CR1	|=1;/*Counter enable*/


	/* 4 channels configuration */

	MTIM1 -> CR1 	= 0x0080;/*Auto reload pre-load enable , overflow generates update event*/
	MTIM1 -> DIER	= 0x001F;/*Update interrupt enable , Capture/Compare for all channels interrupt enable*/
	MTIM1 -> CCMR1	= 0x0101;/*CC1 channel is configured as input, IC1 is mapped on TI1 & CC2 channel is configured as input, IC2 is mapped on TI2*/
	MTIM1 -> CCMR2	= 0x0101;/*CC3 channel is configured as input, IC3 is mapped on TI3 & CC4 channel is configured as input, IC4 is mapped on TI4*/
	MTIM1 -> CCER	= 0xBBBB;/*Capture occurs on change , Capture Enabled*/
	MTIM1 -> PSC    = 0;
	MTIM1 -> ARR	= 0xFFFF;
//	MTIM1 -> EGR	|=1;
	MTIM1 -> CR1	|=1 ;/*Counter enable*/
}

void MTIM8_ICU_Initialize(void)
{
	MTIM8 -> CR1 	= 0x0080;/*Auto reload pre-load enable , overflow generates update event*/
	MTIM8 -> DIER	= 0x0007;/*Update interrupt enable , Capture/Compare for all channels interrupt enable*/
	MTIM8 -> CCMR1	= 0x0101;/*CC1 channel is configured as input, IC1 is mapped on TI1 & CC2 channel is configured as input, IC2 is mapped on TI2*/
	MTIM8 -> CCER	= 0x00BB;/*Capture occurs on change , Capture Enabled*/
	MTIM8 -> PSC    = 0;
	MTIM8 -> ARR	= 0xFFFF;
//	MTIM8 -> EGR	|=1;
	MTIM8 -> CR1	|=1 ;/*Counter enable*/
}


u16 MTIM1_Read_ICU(u8 channel)
{
	u16 Registervalue=0;
	switch(channel)
	{
	case Channel1 :Registervalue = MTIM1 -> CCR1; break;
	case Channel2 :Registervalue = MTIM1 -> CCR2; break;
	case Channel3 :Registervalue = MTIM1 -> CCR3; break;
	case Channel4 :Registervalue = MTIM1 -> CCR4; break;
	}
	return Registervalue;
}

u16 MTIM8_Read_ICU(u8 channel)
{
	u16 Registervalue=0;
	switch(channel)
	{
	case Channel1 :Registervalue = MTIM8 -> CCR1; break;
	case Channel2 :Registervalue = MTIM8 -> CCR2; break;
	case Channel3 :Registervalue = MTIM8 -> CCR3; break;
	case Channel4 :Registervalue = MTIM8 -> CCR4; break;
	}
	return Registervalue;
}

u8 TIM1_Get_CCI_Flag(void)
{
	u8 value=0;
	switch(	MTIM1 -> SR & 0x1E)
	{
	case Channel1 : value=1;break;
	case Channel2 : value=2;break;
	case Channel3 : value=3;break;
	case Channel4 : value=4;break;
	}
	return value;
}

u8 TIM8_Get_CCI_Flag(void)
{
	u8 value=0;
	switch(	MTIM8 -> SR & 0x6)
	{
	case Channel1 : value=5;break;
	case Channel2 : value=6;break;
	case Channel3 : value=7;break;
	case Channel4 : value=8;break;
	}
	return value;
}

void MTIM1_UP_SetCallBack(void(*Ptr)(void))
{
	MTIM1_UP_CallBack = Ptr;
}

void MTIM1_ICU_SetCallBack(void(*Ptr)(void))
{
	MTIM1_ICU_CallBack = Ptr;
}
void MTIM8_UP_SetCallBack(void(*Ptr)(void))
{
	MTIM8_UP_CallBack = Ptr;
}

void MTIM8_ICU_SetCallBack(void(*Ptr)(void))
{
	MTIM8_ICU_CallBack = Ptr;
}
void MTIM2_IRQ_SetCallBack(void(*Ptr)(void))
{
	MTIM2_IRQ_CallBack = Ptr;
}
void MTIM3_IRQ_SetCallBack(void(*Ptr)(void))
{
	MTIM3_IRQ_CallBack = Ptr;
}

void MTIM7_IRQ_SetCallBack(void(*Ptr)(void))
{
	MTIM7_IRQ_CallBack = Ptr;
}
void TIM1_UP_TIM10_IRQHandler(void)
{
	MTIM1_UP_CallBack();
	MTIM1 -> SR	   &= ~(1);
}

void TIM1_CC_IRQHandler(void)
{
	MTIM1_ICU_CallBack();
	MTIM1 -> SR	   &= ~(0x1E);
}

void TIM8_UP_TIM13_IRQHandler(void)
{
	MTIM8_UP_CallBack();
	MTIM8 -> SR	   &= ~(1);
}

void TIM8_CC_IRQHandler(void)
{
	MTIM8_ICU_CallBack();
	MTIM8 -> SR	   &= ~(0x1E);
}

void TIM2_IRQHandler(void)
{
	MTIM2_IRQ_CallBack();
}
void TIM3_IRQHandler(void)
{
	MTIM3_IRQ_CallBack();
	MTIM3 -> SR	   &= ~(1);
}


void TIM7_IRQHandler(void)
{
	MTIM7_IRQ_CallBack();
	MTIM7 -> SR	   &= ~(1);
	MTIM7 -> EGR	|=1;
}
