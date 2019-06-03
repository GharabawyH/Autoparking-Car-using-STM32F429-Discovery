#ifndef _MDCMI_PRIVATE_H
#define _MDCMI_PRIVATE_H


typedef struct
{
	u32 CR;
	u32 SR;
	u32 RIS;
	u32 IER;
	u32 MIS;
	u32 ICR;
	u32 ESCR;
	u32 ESUR;
	u32 CWSTR;
	u32 CWSIZ;
	u32 DR;
}DCMI_Type;



#define MDCMI ((volatile DCMI_Type*)0x50050000)


#endif