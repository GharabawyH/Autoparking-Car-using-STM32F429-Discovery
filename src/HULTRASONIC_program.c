#include "LSTD_TYPES.h"
#include "MPWR_interface.h"
#include "MGPIO_interface.h"
#include "HULTRASONIC_interface.h"
#include "HULTRASONIC_private.h"
#include "MSTK_interface.h"
#include "MTIM_interface.h"

extern volatile  u16 Counter1;
extern volatile  u16 Counter2;
volatile f64 Result;

void HULTRASONIC1_voidInitialize(void)
{
	MGPIO_Pin_MODE(PORTF,Pin0,Output);
	MGPIO_Pin_MODE(PORTF,Pin1,Output);
	MGPIO_Pin_MODE(PORTA,Pin3,Output);
	MGPIO_Pin_MODE(PORTA,Pin5,Output);
	MGPIO_Pin_MODE(PORTA,Pin7,Output);
	MGPIO_Pin_MODE(PORTE,Pin9,Input);

	MGPIO_Pin_MODE(PORTE,Pin9,AF);
	MGPIO_Pin_PullUpOrDown(PORTE,Pin9,PullDown);
	MGPIO_Pin_Select_AF_Channel_HIGH(PORTE,Pin9,AF1);
	MGPIO_Pin_MODE(PORTE,Pin11,AF);
	MGPIO_Pin_PullUpOrDown(PORTE,Pin11,PullDown);
	MGPIO_Pin_Select_AF_Channel_HIGH(PORTE,Pin11,AF1);
	MGPIO_Pin_MODE(PORTE,Pin13,AF);
	MGPIO_Pin_PullUpOrDown(PORTE,Pin13,PullDown);
	MGPIO_Pin_Select_AF_Channel_HIGH(PORTE,Pin13,AF1);
	MGPIO_Pin_MODE(PORTE,Pin14,AF);
	MGPIO_Pin_PullUpOrDown(PORTE,Pin14,PullDown);
	MGPIO_Pin_Select_AF_Channel_HIGH(PORTE,Pin14,AF1);
	MGPIO_Pin_MODE(PORTC,Pin6,AF);
	MGPIO_Pin_PullUpOrDown(PORTC,Pin6,PullDown);
	MGPIO_Pin_Select_AF_Channel_LOW(PORTC,Pin6,AF3);
	MTIM1_ICU_Initialize();
	MTIM8_ICU_Initialize();

}
void HULTRASONIC1_SendTrigger(void)
{
	MGPIO_SetPin(PORTF ,Pin0_Set);
	MSTK_Delay_us(10);
	MGPIO_ClearPin(PORTF,Pin0_Reset);
}
void HULTRASONIC2_SendTrigger(void)
{
	MGPIO_SetPin(PORTF ,Pin1_Set);
	MSTK_Delay_us(10);
	MGPIO_ClearPin(PORTF,Pin1_Reset);
}
void HULTRASONIC3_SendTrigger(void)
{
	MGPIO_SetPin(PORTA ,Pin3_Set);
	MSTK_Delay_us(10);
	MGPIO_ClearPin(PORTA,Pin3_Reset);
}
void HULTRASONIC4_SendTrigger(void)
{
	MGPIO_SetPin(PORTA ,Pin5_Set);
	MSTK_Delay_us(10);
	MGPIO_ClearPin(PORTA,Pin5_Reset);
}
void HULTRASONIC5_SendTrigger(void)
{
	MGPIO_SetPin(PORTA ,Pin7_Set);
	MSTK_Delay_us(10);
	MGPIO_ClearPin(PORTA,Pin7_Reset);
}

f64 HULTRASONIC_CalculateDistance(void)
{
	Result = Counter2-Counter1;
	Result = (Result*17150)/(180000000);

	return Result;
}
