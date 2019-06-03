#ifndef _MPWRT_PRIVATE_H
#define _MPWRT_PRIVATE_H


typedef struct
{
	volatile u32 CR;
	volatile u32 CSR;
}MPWR_Type;

typedef struct
{
	volatile u32 ACR;
	volatile u32 KEYR;
	volatile u32 OPTKEYR;
	volatile u32 SR;
	volatile u32 CR;
	volatile u32 OPTCR;
	volatile u32 OPTCR1;
}MFLASH_Type;

typedef struct
{
	volatile u32 CR;
	volatile u32 PLLCFGR;
	volatile u32 CFGR;
	volatile u32 CIR;
	volatile u32 AHB1RSTR;
	volatile u32 AHB2RSTR;
	volatile u32 AHB3RSTR;
	volatile u32 Reserved0;
	volatile u32 APB1RSTR;
	volatile u32 APB2RSTR;
	volatile u32 Reserved1;
	volatile u32 Reserved2;
	volatile u32 AHB1ENR;
	volatile u32 AHB2ENR;
	volatile u32 AHB3ENR;
	volatile u32 Reserved3;
	volatile u32 APB1ENR;
	volatile u32 APB2ENR;
	volatile u32 Reserved4;
	volatile u32 Reserved5;
	volatile u32 AHB1LPENR;
	volatile u32 AHB2LPENR;
	volatile u32 AHB3LPENR;
	volatile u32 Reserved6;
	volatile u32 APB1LPENR;
	volatile u32 APB2LPENR;
	volatile u32 Reserved7;
	volatile u32 Reserved8;
	volatile u32 BDCR;
	volatile u32 CSR;
	volatile u32 Reserved9;
	volatile u32 Reserved10;
	volatile u32 SSCGR;
	volatile u32 PLLI2SCFGR;
}MRCC_Type;

typedef struct
{
	volatile u32 MEMRMP;
	volatile u32 PMC;
	volatile u32 EXTICR1;
	volatile u32 EXTICR2;
	volatile u32 EXTICR3;
	volatile u32 EXTICR4;
	volatile u32 CMPCR;
}MSYSCFG_Type;

#define MSYSCFG	((volatile MSYSCFG_Type*)0x40013800)

#define	MRCC	((volatile MRCC_Type*)0x40023800)

#define MFLASH 	((volatile MFLASH_Type*)0x40023C00)

#define MPWR 	((volatile MPWR_Type*)0x40007000)









#endif
