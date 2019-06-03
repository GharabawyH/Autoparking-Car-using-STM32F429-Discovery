#ifndef _MTIM_PRIVATE_H
#define _MTIM_PRIVATE_H

/*typedef struct
{
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 SMCR;
	volatile u32 DIER;
	volatile u32 SR;
	volatile u32 EGR;
	volatile u32 CCMR1;
	volatile u32 CCMR2;
	volatile u32 CCER;
	volatile u32 CNT;
	volatile u32 PSC;
	volatile u32 ARR;
	volatile u32 RCR;
	volatile u32 CCR1;
	volatile u32 CCR2;
	volatile u32 CCR3;
	volatile u32 CCR4;
	volatile u32 BDTR;
	volatile u32 DCR;
	volatile u32 DMAR;
}MTIMER_Type;


#define MTIM1	((volatile MTIMER_Type*)0x40010000)
#define MTIM8	((volatile MTIMER_Type*)0x40010400)
#define MTIM2	((volatile MTIMER_Type*)0x40000000)
#define MTIM3	((volatile MTIMER_Type*)0x40000400)
#define MTIM7	((volatile MTIMER_Type*)0x40001400)*/

typedef struct
{
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 SMCR;
	volatile u32 DIER;
	volatile u32 SR;
	volatile u32 EGR;
	volatile u32 CCMR1;
	volatile u32 CCMR2;
	volatile u32 CCER;
	volatile u32 CNT;
	volatile u32 PSC;
	volatile u32 ARR;
	volatile u32 RCR;
	volatile u32 CCR1;
	volatile u32 CCR2;
	volatile u32 CCR3;
	volatile u32 CCR4;
	volatile u32 BDTR;
	volatile u32 DCR;
	volatile u32 DMAR;
}MTIMER1_8_Type;

typedef struct
{
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 SMCR;
	volatile u32 DIER;
	volatile u32 SR;
	volatile u32 EGR;
	volatile u32 CCMR1;
	volatile u32 CCMR2;
	volatile u32 CCER;
	volatile u32 CNT;
	volatile u32 PSC;
	volatile u32 ARR;
	const u32 Reserved0;
	volatile u32 CCR1;
	volatile u32 CCR2;
	volatile u32 CCR3;
	volatile u32 CCR4;
	const    u32 Reserved1;
	volatile u32 DCR;
	volatile u32 DMAR;
	volatile u32 OR;
}MTIMER2_3_4_5_Type;


typedef struct
{
	volatile u32 CR1;
	volatile u32 CR2;
	const u32 Reserved0;
	volatile u32 DIER;
	volatile u32 SR;
	volatile u32 EGR;
	const u32 Reserved1;
	const u32 Reserved2;
	const u32 Reserved3;
	volatile u32 CNT;
	volatile u32 PSC;
	volatile u32 ARR;
}MTIMER6_7_Type;



#define MTIM1	((volatile MTIMER1_8_Type*)0x40010000)
#define MTIM8	((volatile MTIMER1_8_Type*)0x40010400)
#define MTIM2	((volatile MTIMER2_3_4_5_Type*)0x40000000)
#define MTIM3	((volatile MTIMER2_3_4_5_Type*)0x40000400)
#define MTIM4	((volatile MTIMER2_3_4_5_Type*)0x40000800)
#define MTIM5	((volatile MTIMER2_3_4_5_Type*)0x40000C00)
#define MTIM6	((volatile MTIMER6_7_Type*)0x40001000)
#define MTIM7	((volatile MTIMER6_7_Type*)0x40001400)









#endif
