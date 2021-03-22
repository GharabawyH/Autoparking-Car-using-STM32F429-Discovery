#include "LSTD_TYPES.h"
#include "HILI9341_private.h"
#include "HILI9341_interface.h"
#include "MSTK_interface.h"
#include "MGPIO_interface.h"
#include "MSPI_interface.h"

u16 ILI9341_x;
u16 ILI9341_y;
LCD_ILI931_Options_t ILI9341_Opts;
u8 ILI9341_INT_CalledFromPuts = 0;




void HILI9341_Init(void)
{
	MGPIO_Pin_MODE(PORTC,Pin2,Output);
	MGPIO_Pin_OTYPE(PORTC,Pin2,PushPull);
	MGPIO_Pin_OSPEED(PORTC,Pin2,HS);

	MGPIO_Pin_MODE(PORTD,Pin12,Output);
	MGPIO_Pin_OTYPE(PORTD,Pin12,PushPull);
	MGPIO_Pin_OSPEED(PORTD,Pin12,HS);
	MGPIO_Pin_PullUpOrDown(PORTD,Pin12,PullUp);

	MGPIO_Pin_MODE(PORTD,Pin13,Output);
	MGPIO_Pin_OTYPE(PORTD,Pin13,PushPull);
	MGPIO_Pin_OSPEED(PORTD,Pin13,HS);

	MGPIO_SetPin(PORTC,Pin2_Set);


	HILI9341_SPI_Init();

	HILI9341_InitLCD();	

	ILI9341_x = ILI9341_y = 0;

	ILI9341_Opts.width = ILI9341_WIDTH;
	ILI9341_Opts.height = ILI9341_HEIGHT;
	ILI9341_Opts.orientation = LCD_ILI9341_Portrait;
}

void HILI9341_InitLCD(void)
{

	MGPIO_ClearPin(PORTD,Pin12_Reset);


	HILI9341_SendCommand(ILI9341_RESET);
	/*LCD_ILI9341_Delay(2000000);*/
	MSTK_Delay_us(2000);

	HILI9341_SendCommand(ILI9341_POWERA);
	HILI9341_SendData(0x39);
	HILI9341_SendData(0x2C);
	HILI9341_SendData(0x00);
	HILI9341_SendData(0x34);
	HILI9341_SendData(0x02);
	HILI9341_SendCommand(ILI9341_POWERB);
	HILI9341_SendData(0x00);
	HILI9341_SendData(0xC1);
	HILI9341_SendData(0x30);
	HILI9341_SendCommand(ILI9341_DTCA);
	HILI9341_SendData(0x85);
	HILI9341_SendData(0x00);
	HILI9341_SendData(0x78);
	HILI9341_SendCommand(ILI9341_DTCB);
	HILI9341_SendData(0x00);
	HILI9341_SendData(0x00);
	HILI9341_SendCommand(ILI9341_POWER_SEQ);
	HILI9341_SendData(0x64);
	HILI9341_SendData(0x03);
	HILI9341_SendData(0x12);
	HILI9341_SendData(0x81);
	HILI9341_SendCommand(ILI9341_PRC);
	HILI9341_SendData(0x20);
	HILI9341_SendCommand(ILI9341_POWER1);
	HILI9341_SendData(0x23);
	HILI9341_SendCommand(ILI9341_POWER2);
	HILI9341_SendData(0x10);
	HILI9341_SendCommand(ILI9341_VCOM1);
	HILI9341_SendData(0x3E);
	HILI9341_SendData(0x28);
	HILI9341_SendCommand(ILI9341_VCOM2);
	HILI9341_SendData(0x86);
	HILI9341_SendCommand(ILI9341_MAC);
	HILI9341_SendData(0x48);
	HILI9341_SendCommand(ILI9341_PIXEL_FORMAT);
	HILI9341_SendData(0x55);
	HILI9341_SendCommand(ILI9341_FRC);
	HILI9341_SendData(0x00);
	HILI9341_SendData(0x18);
	HILI9341_SendCommand(ILI9341_DFC);
	HILI9341_SendData(0x08);
	HILI9341_SendData(0x82);
	HILI9341_SendData(0x27);
	HILI9341_SendCommand(ILI9341_3GAMMA_EN);
	HILI9341_SendData(0x00);
	HILI9341_SendCommand(ILI9341_COLUMN_ADDR);
	HILI9341_SendData(0x00);
	HILI9341_SendData(0x00);
	HILI9341_SendData(0x00);
	HILI9341_SendData(0xEF);
	HILI9341_SendCommand(ILI9341_PAGE_ADDR);
	HILI9341_SendData(0x00);
	HILI9341_SendData(0x00);
	HILI9341_SendData(0x01);
	HILI9341_SendData(0x3F);
	HILI9341_SendCommand(ILI9341_GAMMA);
	HILI9341_SendData(0x01);
	HILI9341_SendCommand(ILI9341_PGAMMA);
	HILI9341_SendData(0x0F);
	HILI9341_SendData(0x31);
	HILI9341_SendData(0x2B);
	HILI9341_SendData(0x0C);
	HILI9341_SendData(0x0E);
	HILI9341_SendData(0x08);
	HILI9341_SendData(0x4E);
	HILI9341_SendData(0xF1);
	HILI9341_SendData(0x37);
	HILI9341_SendData(0x07);
	HILI9341_SendData(0x10);
	HILI9341_SendData(0x03);
	HILI9341_SendData(0x0E);
	HILI9341_SendData(0x09);
	HILI9341_SendData(0x00);
	HILI9341_SendCommand(ILI9341_NGAMMA);
	HILI9341_SendData(0x00);
	HILI9341_SendData(0x0E);
	HILI9341_SendData(0x14);
	HILI9341_SendData(0x03);
	HILI9341_SendData(0x11);
	HILI9341_SendData(0x07);
	HILI9341_SendData(0x31);
	HILI9341_SendData(0xC1);
	HILI9341_SendData(0x48);
	HILI9341_SendData(0x08);
	HILI9341_SendData(0x0F);
	HILI9341_SendData(0x0C);
	HILI9341_SendData(0x31);
	HILI9341_SendData(0x36);
	HILI9341_SendData(0x0F);
	HILI9341_SendCommand(ILI9341_SLEEP_OUT);

	/*LCD_ILI9341_Delay(1000000);*/
	MSTK_Delay_us(1000);

	HILI9341_SendCommand(ILI9341_DISPLAY_ON);
	HILI9341_SendCommand(ILI9341_GRAM);
}


void HILI9341_SendCommand(u8 data)
{
	MGPIO_ClearPin(PORTD,Pin13_Reset);
	MGPIO_ClearPin(PORTC,Pin2_Reset);
	MSPI5_Tranceive(data);
	MGPIO_SetPin(PORTC,Pin2_Set);
}

void HILI9341_SendData(u8 data)
{
	MGPIO_SetPin(PORTD,Pin13_Set);
	MGPIO_ClearPin(PORTC,Pin2_Reset);
	MSPI5_Tranceive(data);
	MGPIO_SetPin(PORTC,Pin2_Set);
}


void HILI9341_Fill(u16 color)
{
	unsigned int n, i, j;
	i = color >> 8;
	j = color & 0xFF;
	HILI9341_SetCursorPosition(0, 0, ILI9341_Opts.width - 1, ILI9341_Opts.height - 1);

	HILI9341_SendCommand(ILI9341_GRAM);

	for (n = 0; n < ILI9341_PIXEL; n++)
	{
		HILI9341_SendData(i);
		HILI9341_SendData(j);
	}
}

void HILI9341_DisplayImage(u16 image[ILI9341_PIXEL])
{
	u32 n, i, j;

	HILI9341_SetCursorPosition(0, 0, ILI9341_Opts.width - 1, ILI9341_Opts.height - 1);

	HILI9341_SendCommand(ILI9341_GRAM);

	MGPIO_SetPin(PORTD,Pin13_Set);

	MGPIO_ClearPin(PORTC,Pin2_Reset);


	for (n = 0; n < ILI9341_PIXEL; n++) 
	{
		i = image[n] >> 8;
		j = image[n] & 0xFF;

		MSPI5_Tranceive(i);
		MSPI5_Tranceive(j);
	}
	MGPIO_SetPin(PORTC,Pin2_Set);
}


void HILI9341_SPI_Init(void)
{
	//PIN7 clock
	MGPIO_Pin_MODE(PORTF,Pin7,AF);
	MGPIO_Pin_OTYPE(PORTF,Pin7,PushPull);
	MGPIO_Pin_OSPEED(PORTF,Pin7,HS);
	MGPIO_Pin_PullUpOrDown(PORTA,Pin7,Floating);
	MGPIO_Pin_Select_AF_Channel_LOW(PORTF,Pin7,AF5);

	//PIN8 miso
	MGPIO_Pin_MODE(PORTF,Pin8,AF);
	MGPIO_Pin_OTYPE(PORTF,Pin8,PushPull);
	MGPIO_Pin_OSPEED(PORTF,Pin8,HS);
	MGPIO_Pin_PullUpOrDown(PORTF,Pin8,Floating);
	MGPIO_Pin_Select_AF_Channel_HIGH(PORTF,Pin8,AF5);

	//PIN9 mosi
	MGPIO_Pin_MODE(PORTF,Pin9,AF);
	MGPIO_Pin_OTYPE(PORTF,Pin9,PushPull);
	MGPIO_Pin_OSPEED(PORTF,Pin9,HS);
	MGPIO_Pin_PullUpOrDown(PORTA,Pin9,Floating);
	MGPIO_Pin_Select_AF_Channel_HIGH(PORTF,Pin9,AF5);

	MSPI5_Initialize_Master();
}

void HILI9341_SPI_SendMulti(u8 *dataOut, u8 *dataIn, u16 count)
{
	u8 i;
	for (i = 0; i < count; i++)
	{
		dataIn[i] = MSPI5_Tranceive(dataOut[i]);
	}
}

void HILI9341_SPI_WriteMulti(u8 *dataOut, u16 count)
{
	u16 i;
	for (i = 0; i < count; i++)
	{
		MSPI5_Tranceive(dataOut[i]);
	}
}

void HILI9341_SPI_ReadMulti(u8 *dataIn, u8 dummy, u16 count)
{
	u16 i;
	for (i = 0; i < count; i++)
	{
		dataIn[i] = MSPI5_Tranceive(dummy);
	}
}

void HILI9341_SPI_BaudRateUp(void)
{
	MSPI5_Initialize_Master_BaudRateUp();
}
