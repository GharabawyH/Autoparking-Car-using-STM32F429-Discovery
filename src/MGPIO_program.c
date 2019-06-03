#include "LSTD_TYPES.h"
#include "MGPIO_interface.h"

#include "MGPIO_private.h"



void MGPIO_Initialize(void)
{
	/*Write any configuration here only for testing*/
}


void MGPIO_Pin_MODE(u8 Port , u8 PinNum , u8 Mode)
{
	switch(Port)
	{
		case PORTA:
		{
			switch(Mode)
			{
				case Input	:MGPIOA -> MODER &= ~(3<<(2*PinNum));break;
				default		:MGPIOA -> MODER |= (Mode<<(2*PinNum));break;
			}
			break;
		}
		case PORTB:
		{
			switch(Mode)
			{
				case Input	:MGPIOB -> MODER &= ~(3<<(2*PinNum));break;
				default		:MGPIOB -> MODER |= (Mode<<(2*PinNum));break;
			}
			break;
		}
		case PORTC:
		{
			switch(Mode)
			{
				case Input	:MGPIOC -> MODER &= ~(3<<(2*PinNum));break;
				default		:MGPIOC -> MODER |= (Mode<<(2*PinNum));break;
			}
			break;
		}
		case PORTD:
		{
			switch(Mode)
			{
				case Input	:MGPIOD -> MODER &= ~(3<<(2*PinNum));break;
				default		:MGPIOD -> MODER |= (Mode<<(2*PinNum));break;
			}
			break;
		}
		case PORTE:
		{
			switch(Mode)
			{
				case Input	:MGPIOE -> MODER &= ~(3<<(2*PinNum));break;
				default		:MGPIOE -> MODER |= (Mode<<(2*PinNum));break;
			}
			break;
		}
		case PORTF:
		{
			switch(Mode)
			{
				case Input	:MGPIOF -> MODER &= ~(3<<(2*PinNum));break;
				default		:MGPIOF -> MODER |= (Mode<<(2*PinNum));break;
			}
			break;
		}
		case PORTG:
		{
			switch(Mode)
			{
				case Input	:MGPIOG -> MODER &= ~(3<<(2*PinNum));break;
				default		:MGPIOG -> MODER |= (Mode<<(2*PinNum));break;
			}
			break;
		}
		case PORTH:
		{
			switch(Mode)
			{
				case Input	:MGPIOH -> MODER &= ~(3<<(2*PinNum));break;
				default		:MGPIOH -> MODER |= (Mode<<(2*PinNum));break;
			}
			break;
		}
	}
}

void MGPIO_Pin_OTYPE(u8 Port , u8 PinNum , u8 OutputType)
{
	switch(Port)
	{
		case PORTA:
		{
			switch(OutputType)
			{
				case PushPull	:MGPIOA -> OTYPER &= ~(1<<PinNum);break;
				case OpenDrain	:MGPIOA -> OTYPER |= (1<<PinNum) ;break;
			}
			break;
		}
		case PORTB:
		{
			switch(OutputType)
			{
				case PushPull	:MGPIOB -> OTYPER &= ~(1<<PinNum);break;
				case OpenDrain	:MGPIOB -> OTYPER |= (1<<PinNum) ;break;
			}
			break;
		}
		case PORTC:
		{
			switch(OutputType)
			{
				case PushPull	:MGPIOC -> OTYPER &= ~(1<<PinNum);break;
				case OpenDrain	:MGPIOC -> OTYPER |= (1<<PinNum) ;break;
			}
			break;
		}
		case PORTD:
		{
			switch(OutputType)
			{
				case PushPull	:MGPIOD -> OTYPER &= ~(1<<PinNum);break;
				case OpenDrain	:MGPIOD -> OTYPER |= (1<<PinNum) ;break;
			}
			break;
		}
		case PORTE:
		{
			switch(OutputType)
			{
				case PushPull	:MGPIOE -> OTYPER &= ~(1<<PinNum);break;
				case OpenDrain	:MGPIOE -> OTYPER |= (1<<PinNum) ;break;
			}
			break;
		}
		case PORTF:
		{
			switch(OutputType)
			{
				case PushPull	:MGPIOF -> OTYPER &= ~(1<<PinNum);break;
				case OpenDrain	:MGPIOF -> OTYPER |= (1<<PinNum) ;break;
			}
			break;
		}
		case PORTG:
		{
			switch(OutputType)
			{
				case PushPull	:MGPIOG -> OTYPER &= ~(1<<PinNum);break;
				case OpenDrain	:MGPIOG -> OTYPER |= (1<<PinNum) ;break;
			}
			break;
		}
		case PORTH:
		{
			switch(OutputType)
			{
				case PushPull	:MGPIOH -> OTYPER &= ~(1<<PinNum);break;
				case OpenDrain	:MGPIOH -> OTYPER |= (1<<PinNum) ;break;
			}
			break;
		}
	}
}

void MGPIO_Pin_OSPEED(u8 Port , u8 PinNum , u8 Speed)
{
	switch(Port)
	{
		case PORTA:
		{
			switch(Speed)
			{
				case LS	:MGPIOA -> OSPEEDR &= ~(3<<(2*PinNum));break;
				default	:MGPIOA -> OSPEEDR |= (Speed<<(2*PinNum));break;
			}
			break;
		}
		case PORTB:
		{
			switch(Speed)
			{
				case LS	:MGPIOB -> OSPEEDR &= ~(3<<(2*PinNum));break;
				default	:MGPIOB -> OSPEEDR |= (Speed<<(2*PinNum));break;
			}
			break;
		}
		case PORTC:
		{
			switch(Speed)
			{
				case LS	:MGPIOC -> OSPEEDR &= ~(3<<(2*PinNum));break;
				default	:MGPIOC -> OSPEEDR |= (Speed<<(2*PinNum));break;
			}
			break;
		}
		case PORTD:
		{
			switch(Speed)
			{
				case LS	:MGPIOD -> OSPEEDR &= ~(3<<(2*PinNum));break;
				default	:MGPIOD -> OSPEEDR |= (Speed<<(2*PinNum));break;
			}
			break;
		}
		case PORTE:
		{
			switch(Speed)
			{
				case LS	:MGPIOE -> OSPEEDR &= ~(3<<(2*PinNum));break;
				default	:MGPIOE -> OSPEEDR |= (Speed<<(2*PinNum));break;
			}
			break;
		}
		case PORTF:
		{
			switch(Speed)
			{
				case LS	:MGPIOF -> OSPEEDR &= ~(3<<(2*PinNum));break;
				default	:MGPIOF -> OSPEEDR |= (Speed<<(2*PinNum));break;
			}
			break;
		}
		case PORTG:
		{
			switch(Speed)
			{
				case LS	:MGPIOG -> OSPEEDR &= ~(3<<(2*PinNum));break;
				default	:MGPIOG -> OSPEEDR |= (Speed<<(2*PinNum));break;
			}
			break;
		}
		case PORTH:
		{
			switch(Speed)
			{
				case LS	:MGPIOH -> OSPEEDR &= ~(3<<(2*PinNum));break;
				default	:MGPIOH -> OSPEEDR |= (Speed<<(2*PinNum));break;
			}
			break;
		}
	}
}


void MGPIO_Pin_PullUpOrDown(u8 Port , u8 PinNum , u8 UpDown)
{
	switch(Port)
	{
		case PORTA:
		{
			switch(UpDown)
			{
				case Floating	:MGPIOA -> PUPDR &= ~(3<<(2*PinNum));break;
				default			:MGPIOA -> PUPDR |= (UpDown<<(2*PinNum));break;
			}
			break;
		}
		case PORTB:
		{
			switch(UpDown)
			{
				case Floating	:MGPIOB -> PUPDR &= ~(3<<(2*PinNum));break;
				default			:MGPIOB -> PUPDR |= (UpDown<<(2*PinNum));break;
			}
			break;
		}
		case PORTC:
		{
			switch(UpDown)
			{
				case Floating	:MGPIOC -> PUPDR &= ~(3<<(2*PinNum));break;
				default			:MGPIOC -> PUPDR |= (UpDown<<(2*PinNum));break;
			}
			break;
		}
		case PORTD:
		{
			switch(UpDown)
			{
				case Floating	:MGPIOD -> PUPDR &= ~(3<<(2*PinNum));break;
				default			:MGPIOD -> PUPDR |= (UpDown<<(2*PinNum));break;
			}
			break;
		}
		case PORTE:
		{
			switch(UpDown)
			{
				case Floating	:MGPIOE -> PUPDR &= ~(3<<(2*PinNum));break;
				default			:MGPIOE -> PUPDR |= (UpDown<<(2*PinNum));break;
			}
			break;
		}
		case PORTF:
		{
			switch(UpDown)
			{
				case Floating	:MGPIOF -> PUPDR &= ~(3<<(2*PinNum));break;
				default			:MGPIOF -> PUPDR |= (UpDown<<(2*PinNum));break;
			}
			break;
		}
		case PORTG:
		{
			switch(UpDown)
			{
				case Floating	:MGPIOG -> PUPDR &= ~(3<<(2*PinNum));break;
				default			:MGPIOG -> PUPDR |= (UpDown<<(2*PinNum));break;
			}
			break;
		}
		case PORTH:
		{
			switch(UpDown)
			{
				case Floating	:MGPIOH -> PUPDR &= ~(3<<(2*PinNum));break;
				default			:MGPIOH -> PUPDR |= (UpDown<<(2*PinNum));break;
			}
			break;
		}
	}
}

void MGPIO_Pin_Select_AF_Channel_LOW(u8 Port , u8 PinNum, u8 Channel)
{
	switch(Port)
	{
	case PORTA:
	{
		switch(Channel)
		{
		case AF0:MGPIOA	->	AFRL &= ~(1 << (4*PinNum)); break;
		default: MGPIOA	->	AFRL |=  (Channel << (4*PinNum));break;
		}
		break;
	}
	case PORTB:
	{
		switch(Channel)
		{
		case AF0:MGPIOB	->	AFRL &= ~(1 << (4*PinNum)); break;
		default: MGPIOB	->	AFRL |=  (Channel << (4*PinNum));break;
		}
		break;
	}
	case PORTC:
	{
		switch(Channel)
		{
		case AF0:MGPIOC	->	AFRL &= ~(1 << (4*PinNum)); break;
		default: MGPIOC	->	AFRL |=  (Channel << (4*PinNum));break;
		}
		break;
	}
	case PORTD:
	{
		switch(Channel)
		{
		case AF0:MGPIOD	->	AFRL &= ~(1 << (4*PinNum)); break;
		default: MGPIOD	->	AFRL |=  (Channel << (4*PinNum));break;
		}
		break;
	}
	case PORTE:
	{
		switch(Channel)
		{
		case AF0:MGPIOE	->	AFRL &= ~(1 << (4*PinNum)); break;
		default: MGPIOE	->	AFRL |=  (Channel << (4*PinNum));break;
		}
		break;
	}
	case PORTF:
	{
		switch(Channel)
		{
		case AF0:MGPIOF	->	AFRL &= ~(1 << (4*PinNum)); break;
		default: MGPIOF	->	AFRL |=  (Channel << (4*PinNum));break;
		}
		break;
	}
	case PORTG:
	{
		switch(Channel)
		{
		case AF0:MGPIOG	->	AFRL &= ~(1 << (4*PinNum)); break;
		default: MGPIOG	->	AFRL |=  (Channel << (4*PinNum));break;
		}
		break;
	}
	case PORTH:
	{
		switch(Channel)
		{
		case AF0:MGPIOH	->	AFRL &= ~(1 << (4*PinNum)); break;
		default: MGPIOH	->	AFRL |=  (Channel << (4*PinNum));break;
		}
		break;
	}
	}
}

void MGPIO_Pin_Select_AF_Channel_HIGH(u8 Port , u8 PinNum, u8 Channel)
{
	volatile u8 x = PinNum - 8;
	switch(Port)
	{
	case PORTA:
	{
		switch(Channel)
		{
		case AF0:MGPIOA	->	AFRH &= ~(1 << (4*x)); break;
		default: MGPIOA	->	AFRH |=  (Channel << (4*x));break;
		}
		break;
	}
	case PORTB:
	{
		switch(Channel)
		{
		case AF0:MGPIOB	->	AFRH &= ~(1 << (4*x)); break;
		default: MGPIOB	->	AFRH |=  (Channel << (4*x));break;
		}
		break;
	}
	case PORTC:
	{
		switch(Channel)
		{
		case AF0:MGPIOC	->	AFRH &= ~(1 << (4*x)); break;
		default: MGPIOC	->	AFRH |=  (Channel << (4*x));break;
		}
		break;
	}
	case PORTE:
	{
		switch(Channel)
		{
		case AF0:MGPIOE	->	AFRH &= ~(1 << (4*x)); break;
		default: MGPIOE	->	AFRH |=  (Channel << (4*x));break;
		}
		break;
	}
	case PORTF:
	{
		switch(Channel)
		{
		case AF0:MGPIOF	->	AFRH &= ~(1 << (4*x)); break;
		default: MGPIOF	->	AFRH |=  (Channel << (4*x));break;
		}
		break;
	}
	case PORTG:
	{
		switch(Channel)
		{
		case AF0:MGPIOG	->	AFRH &= ~(1 << (4*x)); break;
		default: MGPIOG	->	AFRH |=  (Channel << (4*x));break;
		}
		break;
	}
	case PORTH:
	{
		switch(Channel)
		{
		case AF0:MGPIOH	->	AFRH &= ~(1 << (4*x)); break;
		default: MGPIOH	->	AFRH |=  (Channel << (4*x));break;
		}
		break;
	}
	}

}

void MGPIO_SetPin(u8 Port ,u16 Pin)
{
	Pin &= 0x0000FFFF;
	switch (Port)
	{
	case PORTA:MGPIOA->BSRR=Pin;break;
	case PORTB:MGPIOB->BSRR=Pin;break;
	case PORTC:MGPIOC->BSRR=Pin;break;
	case PORTD:MGPIOD->BSRR=Pin;break;
	case PORTE:MGPIOE->BSRR=Pin;break;
	case PORTF:MGPIOF->BSRR=Pin;break;
	case PORTG:MGPIOG->BSRR=Pin;break;
	case PORTH:MGPIOH->BSRR=Pin;break;
	}
}

void MGPIO_ClearPin(u8 Port,u32 Pin)
{
	Pin &= 0xFFFF0000;
	switch(Port)
	{
	case PORTA:MGPIOA->BSRR=Pin;break;
	case PORTB:MGPIOB->BSRR=Pin;break;
	case PORTC:MGPIOC->BSRR=Pin;break;
	case PORTD:MGPIOD->BSRR=Pin;break;
	case PORTE:MGPIOE->BSRR=Pin;break;
	case PORTF:MGPIOF->BSRR=Pin;break;
	case PORTG:MGPIOG->BSRR=Pin;break;
	case PORTH:MGPIOH->BSRR=Pin;break;
	}
}

void MGPIO_AssignPort(u8 Port,u16 Value)
{
	switch(Port)
	{
	case PORTA:MGPIOA->ODR=Value;break;
	case PORTB:MGPIOB->ODR=Value;break;
	case PORTC:MGPIOC->ODR=Value;break;
	case PORTD:MGPIOD->ODR=Value;break;
	case PORTE:MGPIOE->ODR=Value;break;
	case PORTF:MGPIOF->ODR=Value;break;
	case PORTG:MGPIOG->ODR=Value;break;
	case PORTH:MGPIOH->ODR=Value;break;
	}
}
u16 MGPIO_GetPinValue(u8 Port, u16 Pin)
{
	volatile u16 value;
	switch (Port)
	{
	case PORTA:value=(MGPIOA->IDR&Pin);if(value)value=1;break;
	case PORTB:value=(MGPIOB->IDR&Pin);if(value)value=1;break;
	case PORTC:value=(MGPIOC->IDR&Pin);if(value)value=1;break;
	case PORTD:value=(MGPIOD->IDR&Pin);if(value)value=1;break;
	case PORTE:value=(MGPIOE->IDR&Pin);if(value)value=1;break;
	case PORTF:value=(MGPIOF->IDR&Pin);if(value)value=1;break;
	case PORTG:value=(MGPIOG->IDR&Pin);if(value)value=1;break;
	case PORTH:value=(MGPIOH->IDR&Pin);if(value)value=1;break;
	}
	return value;
}
