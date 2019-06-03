#ifndef _MGPIO_PRIVATE_H
#define _MGPIO_PRIVATE_H

typedef struct
{
	volatile u32 MODER;
	volatile u32 OTYPER;
	volatile u32 OSPEEDR;
	volatile u32 PUPDR;
	volatile u32 IDR;
	volatile u32 ODR;
	volatile u32 BSRR;
	volatile u32 LCKR;
	volatile u32 AFRL;
	volatile u32 AFRH;
}MGPIO_Type;


#define MGPIOA ((volatile MGPIO_Type*)0x40020000)
#define MGPIOB ((volatile MGPIO_Type*)0x40020400)
#define MGPIOC ((volatile MGPIO_Type*)0x40020800)
#define MGPIOD ((volatile MGPIO_Type*)0x40020C00)
#define MGPIOE ((volatile MGPIO_Type*)0x40021000)
#define MGPIOF ((volatile MGPIO_Type*)0x40021400)
#define MGPIOG ((volatile MGPIO_Type*)0x40021800)
#define MGPIOH ((volatile MGPIO_Type*)0x40021C00)







#endif
