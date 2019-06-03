#include "LSTD_TYPES.h"


#include "MSTK_interface.h"
#include "MSTK_private.h"

volatile u32 count;
volatile u8 flag;
void (*MSTK_CallBack)(void);



void MSTK_Initialize(void)
{
	MSTK -> CTRL = 7;
	MSTK -> VAL  = 90;
	MSTK -> LOAD = 90;
}

void MSTK_Delay_us(u32 x)
{
	flag = 1;
	count = x;
	while(count);
	flag = 0;
}


void SysTick_Handler(void)
{
	if(flag == 1)
	{
		count--;
	}
}


void MSTK_SetCallBack(void(*ptr)(void))
{
	MSTK_CallBack = ptr;
}
