#include "LSTD_TYPES.h"

#include "MPWR_interface.h"


#include "MGPIO_interface.h"

#include "MTIM_interface.h"
#include"MSTK_interface.h"


#include"HMOTOR_private.h"

#include "HMOTOR_interface.h"
void HMOTOR_voidInitialize(void)
{
	MTIM2_PWM_Initialize();
	/*MRCC_EnableClock(PERIPHERAL_APB1_TIM2,BUS_APB1);*/
	MGPIO_Pin_MODE(PORTA,Pin15,AF);
	MGPIO_Pin_OTYPE(PORTA,Pin15,PushPull);
	MGPIO_Pin_Select_AF_Channel_HIGH(PORTA,Pin15,AF1);
	MGPIO_Pin_MODE(PORTB,Pin3,AF);
	MGPIO_Pin_OTYPE(PORTA,Pin3,PushPull);
	MGPIO_Pin_Select_AF_Channel_LOW(PORTB,Pin3,AF1);
	MGPIO_Pin_MODE(PORTB,Pin10,AF);
	MGPIO_Pin_OTYPE(PORTA,Pin10,PushPull);
	MGPIO_Pin_Select_AF_Channel_HIGH(PORTB,Pin10,AF1);
	MGPIO_Pin_MODE(PORTB,Pin11,AF);
	MGPIO_Pin_OTYPE(PORTA,Pin11,PushPull);
	MGPIO_Pin_Select_AF_Channel_HIGH(PORTB,Pin11,AF1);
}
void HMOTOR_voidRotation(u8 Dir,u16 speed)
{
	switch(Dir)
	{
	case HMOTOR_Forward :MTIM2_PWM(speed,Channel1);break;
	case HMOTOR_Backward:MTIM2_PWM(speed,Channel2);break;
	case HMOTOR_LEFT :
	{
		MTIM2_PWM(speed,Channel3);
		MSTK_Delay_us(1000000);
		MTIM2_PWM(0,Channel3);

		break;
	}
	case HMOTOR_RIGHT:
	{
		MTIM2_PWM(speed,Channel4);
		MSTK_Delay_us(500000);
		MTIM2_PWM(0,Channel4);

		break;
	}

	}
}
