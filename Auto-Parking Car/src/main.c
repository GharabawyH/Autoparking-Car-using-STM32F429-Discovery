/*
 * main.c
 *
 *  Created on: Apr 2, 2019
 *      Author: Gharabawy
 */

#include "LSTD_TYPES.h"
#include "RTOS_interface.h"
#include "MPWR_interface.h"
#include "MGPIO_interface.h"
#include "MSTK_interface.h"
#include "MNVK_interface.h"
#include "MTIM_interface.h"
#include "HULTRASONIC_interface.h"
#include "HMOTOR_interface.h"
#include "MTIM_private.h"
#include "MDCMI_interface.h"
#include "MDCMI_private.h"
#include "MDMA_interface.h"
#include "MDMA_private.h"
#include "MSPI_interface.h"
#include "MI2C_interface.h"
#include "HILI9341_interface.h"
#include "HOV7670_interface.h"

volatile u8 MDCMI_FLAG;
volatile u8 Flag2=0;
volatile u8 frame_flag = 0;
volatile u8 x1,x2,x3,x4,x5,x6;
volatile u32 cnt1;
volatile u32 cnt8;
volatile u32 Counter1;
volatile u32 Counter2;
volatile u32 counter3;
volatile u8 Flag;
volatile u8 Flag1;
volatile f64 Result;
volatile f64 result[6];

void TIM1_OV(void)
{
	cnt1++;
	MTIM1 -> SR	   &= ~(1);
}

void TIM8_OV(void)
{
	cnt8++;
	MTIM8 -> SR	   &= ~(1);
}
void camera_task(void)
{
	if(MDCMI_FLAG)
	{
		if(((MDMA2 -> LISR) & 0x800)!= 0)
		{
			MDMA2 ->LIFCR|= 0x800;
			MDMA2 ->S1CR |=0x01;
			// Show camera image
			HILI9341_Rotate(LCD_ILI9341_Orientation_Landscape_1);
			HILI9341_DisplayImage((u16*) frame_buffer);
			MDCMI_FLAG = 0;
		}
	}
	else
	{
		MDCMI-> CR |= 0x1;
		MDCMI_FLAG = 1;
	}
}
void park_Task(void)
{
	if(result[1]<30 && result[2]<30 && Flag2==0)
	{
		HMOTOR_voidRotation(HMOTOR_Forward,5700);
		Flag2++;
	}
	if((result[1]>50)&&(Flag2==1))
	{
		Flag2++;
		MTIM3_Initialize();
	}

	if((result[1]<40)  && (Flag2==2) )
	{
		counter3=MTIM3 -> CNT;
		MSTK_Delay_us(7000000);
		HMOTOR_voidRotation(HMOTOR_Forward,0);

		if(counter3 > 23000)
		{
			Flag2++;
		}
		else
		{
			HMOTOR_voidRotation(HMOTOR_RIGHT,HMOTOR_RIGHT_HALFSPEED);
			MSTK_Delay_us(1000000);
			HMOTOR_voidRotation(HMOTOR_LEFT,HMOTOR_LEFT_FULLSPEED);
			Flag2 = 20;
		}
	}
	if((result[1]<40) && (result[2]<40) && (Flag2==3) )
	{
		/*MSTK_Delay_us(100);*/

		HMOTOR_voidRotation(HMOTOR_RIGHT,HMOTOR_RIGHT_HALFSPEED);
		HMOTOR_voidRotation(HMOTOR_Backward,4500);
		Flag2++;


	}
	if((result[3]<85)&&(Flag2==4))
	{
		HMOTOR_voidRotation(HMOTOR_Backward,0);
		HMOTOR_voidRotation(HMOTOR_LEFT,HMOTOR_LEFT_FULLSPEED);
		HMOTOR_voidRotation(HMOTOR_Backward,4500);
		Flag2++;
	}

	if((result[4]<35)&&(Flag2==5))
	{
		HMOTOR_voidRotation(HMOTOR_Backward,0);
		HMOTOR_voidRotation(HMOTOR_RIGHT,HMOTOR_RIGHT_HALFSPEED);
		HMOTOR_voidRotation(HMOTOR_Forward,6000);
		Flag2++;

	}
	if((result[0]<60)&&(Flag2==6))
	{
		HMOTOR_voidRotation(HMOTOR_Forward,0);
		HMOTOR_voidRotation(HMOTOR_LEFT,HMOTOR_LEFT_HALFSPEED);
		Flag2=7;
	}


}

void HULTRASONIC_Task(void)
{

	if(Flag1==0)
	{
		if(x1==0)
		{
			HULTRASONIC1_SendTrigger();
			x1++;
		}
		if(x1==3)
		{
			Result = HULTRASONIC_CalculateDistance();
			result[0]=HULTRASONIC_CalculateDistance();
			x1=0;
			Flag1=1;
		}
	}
	if(Flag1==1)
	{
		if(x2==0)
		{
			HULTRASONIC2_SendTrigger();
			x2++;
		}
		if(x2==3)
		{
			Result = HULTRASONIC_CalculateDistance();
			result[1]=HULTRASONIC_CalculateDistance();
			x2=0;
			Flag1=2;
		}

	}
	if(Flag1==2)
	{
		if(x3==0)
		{
			HULTRASONIC3_SendTrigger();
			x3++;
		}
		if(x3==3)
		{
			Result = HULTRASONIC_CalculateDistance();
			result[2]=HULTRASONIC_CalculateDistance();
			x3=0;
			Flag1=3;
		}
	}
	if(Flag1==3)
	{
		if(x4==0)
		{
			HULTRASONIC4_SendTrigger();
			x4++;
		}
		if(x4==3)
		{
			Result = HULTRASONIC_CalculateDistance();
			result[3]=HULTRASONIC_CalculateDistance();
			x4=0;
			Flag1=4;
		}
	}
	if(Flag1==4)
	{
		if(x5==0)
		{
			HULTRASONIC5_SendTrigger();
			x5++;
		}
		if(x5==3)
		{
			Result = HULTRASONIC_CalculateDistance();
			result[4]=HULTRASONIC_CalculateDistance();
			x5=0;
			Flag1=0;
		}
	}
	park_Task();
//	camera_task();
}

void Task1(void)
{
	Flag=TIM1_Get_CCI_Flag();
	if(Flag==1)
	{
		if(x1==1)
		{
			cnt1=0;
			Counter1 = MTIM1_Read_ICU(Channel1);
			x1++;
		}
		else if(x1==2)
		{
			Counter2 = (cnt1*65535) +MTIM1_Read_ICU(Channel1);
			x1++;
		}
	}
	if(Flag==2)
	{
		if(x2==1)
		{
			cnt1=0;
			Counter1 = MTIM1_Read_ICU(Channel2);
			x2++;
		}
		else if(x2==2)
		{
			Counter2 = (cnt1*65535) +MTIM1_Read_ICU(Channel2);
			x2++;
		}
	}
	if(Flag==3)
	{
		if(x3==1)
		{
			cnt1=0;
			Counter1 = MTIM1_Read_ICU(Channel3);
			x3++;
		}
		else if(x3==2)
		{
			Counter2 = (cnt1*65535) +MTIM1_Read_ICU(Channel3);
			x3++;
		}
	}
	if(Flag==4)
	{
		if(x4==1)
		{
			cnt1=0;
			Counter1 = MTIM1_Read_ICU(Channel4);
			x4++;
		}
		else if(x4==2)
		{
			Counter2 = (cnt1*65535) + MTIM1_Read_ICU(Channel4);
			x4++;
		}
	}
	MTIM1 -> SR	   &= ~(0x1E);
}
void Task2(void)
{
	Flag = TIM8_Get_CCI_Flag();
	if(Flag==5)
	{
		if(x5==1)
		{
			cnt1=0;
			Counter1 = MTIM8_Read_ICU(Channel1);
			x5++;
		}
		else if(x5==2)
		{
			Counter2 = (cnt1*65535) + MTIM8_Read_ICU(Channel1);
			x5++;
		}
	}
	if(Flag==6)
	{
		if(x6==1)
		{
			cnt1=0;
			Counter1 = MTIM8_Read_ICU(Channel2);
			x6++;
		}
		else if(x6==2)
		{
			Counter2 = (cnt1*65535) + MTIM8_Read_ICU(Channel2);
			x6++;
		}
	}
	MTIM8 -> SR	   &= ~(0x1E);
}

void main(void)
{
	/*MRCC_EnableClock(PERIPHERAL_APB1_PWR,BUS_APB1);*/
	MSYSCLK_Initialize();
	MRCC_EnableClock(PERIPHERAL_AHB1_GPIOA,BUS_AHB1);
	MRCC_EnableClock(PERIPHERAL_AHB1_GPIOB,BUS_AHB1);
	MRCC_EnableClock(PERIPHERAL_AHB1_GPIOC,BUS_AHB1);
	MRCC_EnableClock(PERIPHERAL_AHB1_GPIOD,BUS_AHB1);
	MRCC_EnableClock(PERIPHERAL_AHB1_GPIOE,BUS_AHB1);
	MRCC_EnableClock(PERIPHERAL_AHB1_GPIOF,BUS_AHB1);
	MRCC_EnableClock(PERIPHERAL_APB1_I2C1,BUS_APB1);
	MRCC_EnableClock(PERIPHERAL_AHB2_DCMI,BUS_AHB2);
	MRCC_EnableClock(PERIPHERAL_AHB1_DMA2,BUS_AHB1);
	MRCC_EnableClock(PERIPHERAL_APB2_SPI5,BUS_APB2);

	MRCC_EnableClock(PERIPHERAL_APB2_TIM1,BUS_APB2);
	MRCC_EnableClock(PERIPHERAL_APB2_TIM8,BUS_APB2);
	MRCC_EnableClock(PERIPHERAL_APB1_TIM2,BUS_APB1);
	MRCC_EnableClock(PERIPHERAL_APB1_TIM7,BUS_APB1);
	MRCC_EnableClock(PERIPHERAL_APB1_TIM3,BUS_APB1);

	MGPIO_Pin_MODE(PORTA,Pin6,AF);
	MGPIO_Pin_OTYPE(PORTA,Pin6,PushPull);
	MGPIO_Pin_OSPEED(PORTA,Pin6,HS);
	MGPIO_Pin_PullUpOrDown(PORTA,Pin6,PullUp);
	MGPIO_Pin_Select_AF_Channel_LOW(PORTA,Pin6,AF13);

	MGPIO_Pin_MODE(PORTA,Pin4,AF);
	MGPIO_Pin_OTYPE(PORTA,Pin4,PushPull);
	MGPIO_Pin_OSPEED(PORTA,Pin4,HS);
	MGPIO_Pin_PullUpOrDown(PORTA,Pin4,PullUp);
	MGPIO_Pin_Select_AF_Channel_LOW(PORTA,Pin4,AF13);

	MGPIO_Pin_MODE(PORTA,Pin9,AF);
	MGPIO_Pin_OTYPE(PORTA,Pin9,PushPull);
	MGPIO_Pin_OSPEED(PORTA,Pin9,HS);
	MGPIO_Pin_PullUpOrDown(PORTA,Pin9,PullUp);
	MGPIO_Pin_Select_AF_Channel_HIGH(PORTA,Pin9,AF13);

	MGPIO_Pin_MODE(PORTC,Pin7,AF);
	MGPIO_Pin_OTYPE(PORTC,Pin7,PushPull);
	MGPIO_Pin_OSPEED(PORTC,Pin7,HS);
	MGPIO_Pin_PullUpOrDown(PORTC,Pin7,PullUp);
	MGPIO_Pin_Select_AF_Channel_LOW(PORTC,Pin7,AF13);

	MGPIO_Pin_MODE(PORTC,Pin8,AF);
	MGPIO_Pin_OTYPE(PORTC,Pin7,PushPull);
	MGPIO_Pin_OSPEED(PORTC,Pin7,HS);
	MGPIO_Pin_PullUpOrDown(PORTC,Pin6,PullUp);
	MGPIO_Pin_Select_AF_Channel_HIGH(PORTC,Pin8,AF13);

	/*MGPIO_Pin_MODE(PORTC,Pin9,AF);
	MGPIO_Pin_OTYPE(PORTC,Pin9,PushPull);
	MGPIO_Pin_OSPEED(PORTC,Pin9,HS);
	MGPIO_Pin_PullUpOrDown(PORTC,Pin9,PullUp);
	MGPIO_Pin_Select_AF_Channel_HIGH(PORTC,Pin9,AF13);*/

	MGPIO_Pin_MODE(PORTE,Pin1,AF);
	MGPIO_Pin_OTYPE(PORTE,Pin1,PushPull);
	MGPIO_Pin_OSPEED(PORTE,Pin1,HS);
	MGPIO_Pin_Select_AF_Channel_LOW(PORTE,Pin1,AF13);

	MGPIO_Pin_MODE(PORTE,Pin4,AF);
	MGPIO_Pin_OTYPE(PORTE,Pin4,PushPull);
	MGPIO_Pin_OSPEED(PORTE,Pin4,HS);
	MGPIO_Pin_PullUpOrDown(PORTE,Pin4,PullUp);
	MGPIO_Pin_Select_AF_Channel_LOW(PORTE,Pin4,AF13);

	MGPIO_Pin_MODE(PORTE,Pin5,AF);
	MGPIO_Pin_OTYPE(PORTE,Pin5,PushPull);
	MGPIO_Pin_OSPEED(PORTE,Pin5,HS);
	MGPIO_Pin_PullUpOrDown(PORTE,Pin5,PullUp);
	MGPIO_Pin_Select_AF_Channel_LOW(PORTE,Pin5,AF13);

	MGPIO_Pin_MODE(PORTE,Pin6,AF);
	MGPIO_Pin_OTYPE(PORTE,Pin6,PushPull);
	MGPIO_Pin_OSPEED(PORTE,Pin6,HS);
	MGPIO_Pin_PullUpOrDown(PORTE,Pin6,PullUp);
	MGPIO_Pin_Select_AF_Channel_LOW(PORTE,Pin6,AF13);

	MGPIO_Pin_MODE(PORTB,Pin7,AF);
	MGPIO_Pin_OTYPE(PORTB,Pin7,PushPull);
	MGPIO_Pin_OSPEED(PORTB,Pin7,HS);
	MGPIO_Pin_PullUpOrDown(PORTB,Pin7,PullUp);
	MGPIO_Pin_Select_AF_Channel_LOW(PORTB,Pin7,AF13);

	MGPIO_Pin_MODE(PORTB,Pin6,AF);
	MGPIO_Pin_OTYPE(PORTB,Pin6,PushPull);
	MGPIO_Pin_OSPEED(PORTB,Pin6,HS);
	MGPIO_Pin_PullUpOrDown(PORTB,Pin6,PullUp);
	MGPIO_Pin_Select_AF_Channel_LOW(PORTB,Pin6,AF13);

	/*MGPIO_Pin_MODE(PORTA,Pin8,AF);
	MGPIO_Pin_OTYPE(PORTA,Pin8,PushPull);
	MGPIO_Pin_Select_AF_Channel_HIGH(PORTA,Pin8,AF0);*/

	MGPIO_Pin_MODE(PORTC,Pin9,AF);
	MGPIO_Pin_OTYPE(PORTC,Pin9,PushPull);
	MGPIO_Pin_Select_AF_Channel_HIGH(PORTC,Pin9,AF0);

	MGPIO_Pin_MODE(PORTB,Pin8,AF);
	MGPIO_Pin_OTYPE(PORTB,Pin8,OpenDrain);
	MGPIO_Pin_Select_AF_Channel_HIGH(PORTB,Pin8,AF4);
	MGPIO_Pin_PullUpOrDown(PORTB,Pin8,PullUp);

	MGPIO_Pin_MODE(PORTB,Pin9,AF);
	MGPIO_Pin_OTYPE(PORTB,Pin9,OpenDrain);
	MGPIO_Pin_Select_AF_Channel_HIGH(PORTB,Pin9,AF4);
	MGPIO_Pin_PullUpOrDown(PORTB,Pin9,PullUp);


	MSTK_Initialize();

	//MNVK_EnableInt(57);
	//MNVK_SetPriority(57,0);
	MNVK_EnableInt(TIM7_IRQ_ID);

	HOV7670_Initialize();
	MDCMI_Init();
	MDMA2_Channel1_Initialize();
	HILI9341_Init();

	// LCD init page
	HILI9341_Rotate(LCD_ILI9341_Orientation_Landscape_2);
	HILI9341_Fill(ILI9341_COLOR_BLACK);

	HILI9341_Puts(20, 55, "Configuring camera", &LCD_Font_16x26, ILI9341_COLOR_WHITE, ILI9341_COLOR_BLACK);
	HILI9341_DrawRectangle(99, 110, 221, 130, ILI9341_COLOR_WHITE);

	// OV7670 configuration*/
	HOV7670_Configure();

	HILI9341_Puts(100, 165, "Success", &LCD_Font_16x26, ILI9341_COLOR_WHITE, ILI9341_COLOR_BLACK);


	// LCD welcome page
	HILI9341_Fill(ILI9341_COLOR_BLACK);
	HILI9341_Puts(60, 110, "MTE project", &LCD_Font_16x26, ILI9341_COLOR_WHITE, ILI9341_COLOR_BLUE);
	MSTK_Delay_us(1000000);
	
	HILI9341_SPI_BaudRateUp();

	MTIM1_ICU_SetCallBack(Task1);
	MTIM1_UP_SetCallBack(TIM1_OV);
	MTIM8_UP_SetCallBack(TIM8_OV);
	MTIM8_ICU_SetCallBack(Task2);

	RTOS_Initialize();

	RTOS_CreateTask(0,500,HULTRASONIC_Task);
	RTOS_CreateTask(1,11,camera_task);

	MNVK_EnableInt(TIM1_CC_ID);
	MNVK_EnableInt(TIM1_UP_TIM10_ID);

	MNVK_EnableInt(TIM8_CC_ID);
	MNVK_EnableInt(TIM8_UP_TIM13_ID);
	MNVK_EnableInt(TIM7_IRQ_ID);
	MNVK_SetPriority(TIM7_IRQ_ID,0x20);


	HMOTOR_voidInitialize();
	HULTRASONIC1_voidInitialize();

	MTIM2_PWM_Initialize();

	MTIM7_Initialize();
	while(1)
	{

	}
}

