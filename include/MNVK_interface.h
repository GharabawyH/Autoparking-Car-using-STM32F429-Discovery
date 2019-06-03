#ifndef _MNVK_INTERFACE_H
#define _MNVK_INTERFACE_H


void MNVK_EnableInt(u8 ID);
void MNVK_DisableInt(u8 ID);
void MNVK_SetPendingFlag(u8 ID);
void MNVK_ClearPendingFlag(u8 ID);
void MNVK_SetPriority(u8 ID , u32 Priority);

#define EXT0_INT_ID  			6
#define EXT1_INT_ID  			7
#define TIM1_UP_TIM10_ID		25
#define TIM1_TRG_COM_TIM11_ID 	26
#define TIM1_CC_ID  			27
#define TIM8_UP_TIM13_ID		44
#define TIM8_CC_ID				46
#define TIM2_IRQ_ID				28
#define TIM7_IRQ_ID				55


#endif
