#include "LSTD_TYPES.h"


#include "MPWR_private.h"
#include "MPWR_interface.h"


void MSYSCLK_Initialize(void)
{
	MFLASH -> ACR = 5;/*Set the latency*/

//	MSYSCFG -> CMPCR = 1;

//	while (!((MSYSCFG -> CMPCR) & 0xF00));

	MRCC -> CR	= 0x00010001;/*Enable HSE and HSI*/
	while( ( !(( MRCC -> CR ) & 0x2) ) && ( !(( MRCC -> CR ) & 0x20000) ) );/*Wait till HSI and HSE are ready*/
	MRCC -> CFGR  = 0x00000001;/*Choose HSE as the SYSCLK*/
	MRCC -> PLLCFGR = 0x00415A08;/*PLL input = HSE = 8MHZ*/
								/*VCO input = PLL input / PLLM = 8 / 8 = 1MHZ*/
								/*VCO output = VCO input x PLLN = 1 x 180 = 180MHZ*/
								/*PLL output = VCO output / PLLP = 180 / 2 = 90MHZ*/

	MRCC -> CR	= 0x01010001;	/*Enable PLL , HSE and HSI*/
	while(!(( MRCC -> CR ) & 0x02000000));/*Wait till PLL is ready*/
	

//	MPWR -> CR  = 0x0001C000;/*Enable over-drive mode*/
//	while ( !(( MPWR -> CSR ) & 0x10000) );/*Wait for over-drive to be ready*/
//	MPWR -> CR = 0x0003C000;/*Enable over-drive switching*/
//	while ( !(( MPWR -> CSR ) & 0x20000) );/*Wait for over-drive switching to be ready*/


	MRCC -> CFGR	= 0x80401002;/*SYSCLK = PLL output = 90MHZ*/
								 /*AHB clock = SYSCLK = 90MHZ*/
								 /*APB2 clock = AHB clock / 1 = 90MHZ*/
								 /*APB1 clock = AHB clock / 2 = 45MHZ*/
	while ((MRCC -> CFGR & 0x8)!=8);
}


void MRCC_EnableClock(u32 Peripheral,u8 Bus)
{
	switch(Bus)
	{
	case BUS_AHB1:MRCC -> AHB1ENR|=Peripheral;break;
	case BUS_AHB2:MRCC -> AHB2ENR|=Peripheral;break;
	case BUS_AHB3:MRCC -> AHB3ENR|=Peripheral;break;
	case BUS_APB1:MRCC -> APB1ENR|=Peripheral;break;
	case BUS_APB2:MRCC -> APB2ENR|=Peripheral;break;
	}
}

void MRCC_DisableClock(u32 Peripheral,u8 Bus)
{
	switch(Bus)
	{
	case BUS_AHB1:MRCC -> AHB1ENR&=	~Peripheral;break;
	case BUS_AHB2:MRCC -> AHB2ENR&=	~Peripheral;break;
	case BUS_AHB3:MRCC -> AHB3ENR&=	~Peripheral;break;
	case BUS_APB1:MRCC -> APB1ENR&=	~Peripheral;break;
	case BUS_APB2:MRCC -> APB2ENR&=	~Peripheral;break;
	}
}
