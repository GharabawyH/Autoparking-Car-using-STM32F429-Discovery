#include "LSTD_TYPES.h"
#include"MDMA_interface.h"
#include "MDCMI_private.h"
#include "MDCMI_interface.h"


void MDCMI_Init(void)
{
	MDCMI-> CR = 0x00A0;
	MDCMI-> CR |= 0x4000;
	/*MDCMI-> CR |= 0x1;*/
}
