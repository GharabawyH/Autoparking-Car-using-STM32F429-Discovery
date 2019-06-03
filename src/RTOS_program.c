#include "LSTD_TYPES.h"

#include "MTIM_interface.h"

#include "RTOS_interface.h"

#define TasksNumber 11


Task SysTasks[TasksNumber];
static volatile u32 TickCount = 0;

void Scheduler(void);

void RTOS_Initialize(void)
{
	MTIM7_IRQ_SetCallBack(Scheduler);
}


void RTOS_CreateTask(u8 ID , u32 Period , void (*Func)(void))
{
	SysTasks[ID].Periodicity = Period;
	SysTasks[ID].TaskHandler = Func;
}

void Scheduler(void)
{
	u8 LoopCounter;
	TickCount++;
	for (LoopCounter = 0 ; LoopCounter < TasksNumber ; LoopCounter++)
	{
		if((TickCount % SysTasks[LoopCounter].Periodicity)==0)
		{
			SysTasks[LoopCounter].TaskHandler();
		}
	}
}
