#include "LSTD_TYPES.h"
#include "HOV7670_interface.h"

#include "MDMA_private.h"

#include "MDMA_interface.h"

#include "MDCMI_private.h"





void MDMA2_Channel0_Initialize(void)
{
	MDMA2 -> S0CR   = 0x00035690;
	MDMA2 -> S0FCR	= 0x4;
	MDMA2 -> S0NDTR = 10;
}
void MDMA2_Channel1_Initialize(void)
{
	MDMA2 -> S1CR   = 0x02023400;
	MDMA2 -> S1FCR	= 0x27;
	MDMA2 -> S1NDTR = IMG_ROWS*IMG_COLUMNS*2/4;
	MDMA2 -> S1PAR	= (u32)(&MDCMI->DR);
	MDMA2 -> S1M0AR	= (u32)frame_buffer;
	MDMA2 -> S1CR   |=	0x1;
	MDMA2 -> S1CR   |=	0x10;
}


void MDMA2_Ch0Start(u32*Source,u32*Dest)
{
		MDMA2 -> S0PAR  	 = (u32)Source;
	    MDMA2 -> S0M0AR 	 = (u32)Dest;
		MDMA2 -> S0CR		|=1;
}
