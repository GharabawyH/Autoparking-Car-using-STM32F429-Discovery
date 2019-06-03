#ifndef _MDMA_PRIVATE_H
#define _MDMA_PRIVATE_H


typedef struct
{
	u32 LISR;
	u32 HISR;
	u32 LIFCR;
	u32 HIFCR;
	u32 S0CR;
	u32 S0NDTR;
	u32 S0PAR;
	u32 S0M0AR;
	u32 S0M1AR;
	u32 S0FCR;
	u32 S1CR;
	u32 S1NDTR;
	u32 S1PAR;
	u32 S1M0AR;
	u32 S1M1AR;
	u32 S1FCR;
	u32 S2CR;
	u32 S2NDTR;
	u32 S2PAR;
	u32 S2M0AR;
	u32 S2M1AR;
	u32 S2FCR;
	u32 S3CR;
	u32 S3NDTR;
	u32 S3PAR;
	u32 S3M0AR;
	u32 S3M1AR;
	u32 S3FCR;
	u32 S4CR;
	u32 S4NDTR;
	u32 S4PAR;
	u32 S4M0AR;
	u32 S4M1AR;
	u32 S4FCR;
	u32 S5CR;
	u32 S5NDTR;
	u32 S5PAR;
	u32 S5M0AR;
	u32 S5M1AR;
	u32 S5FCR;
	u32 S6CR;
	u32 S6NDTR;
	u32 S6PAR;
	u32 S6M0AR;
	u32 S6M1AR;
	u32 S6FCR;
	u32 S7CR;
	u32 S7NDTR;
	u32 S7PAR;
	u32 S7M0AR;
	u32 S7M1AR;
	u32 S7FCR;
}MDMA_Type;




#define MDMA2 ((volatile MDMA_Type*)0x40026400)





#endif