#ifndef _HILI9341_INTERFACE_H
#define _HILI9341_INTERFACE_H




// LCD settings
#define ILI9341_WIDTH 				240
#define ILI9341_HEIGHT				320
#define ILI9341_PIXEL				76800
 
// Colors
#define ILI9341_COLOR_WHITE			0xFFFF
#define ILI9341_COLOR_BLACK			0x0000
#define ILI9341_COLOR_RED			0xF800
#define ILI9341_COLOR_GREEN			0x07E0
#define ILI9341_COLOR_GREEN2		0xB723
#define ILI9341_COLOR_BLUE			0x001F
#define ILI9341_COLOR_BLUE2			0x051D
#define ILI9341_COLOR_YELLOW		0xFFE0
#define ILI9341_COLOR_ORANGE		0xFBE4
#define ILI9341_COLOR_CYAN			0x07FF
#define ILI9341_COLOR_MAGENTA		0xA254
#define ILI9341_COLOR_GRAY			0x7BEF
#define ILI9341_COLOR_BROWN			0xBBCA

// Commands
#define ILI9341_RESET			0x01
#define ILI9341_SLEEP_OUT		0x11
#define ILI9341_GAMMA			0x26
#define ILI9341_DISPLAY_OFF		0x28
#define ILI9341_DISPLAY_ON		0x29
#define ILI9341_COLUMN_ADDR		0x2A
#define ILI9341_PAGE_ADDR		0x2B
#define ILI9341_GRAM			0x2C
#define ILI9341_MAC				0x36
#define ILI9341_PIXEL_FORMAT	0x3A
#define ILI9341_WDB				0x51
#define ILI9341_WCD				0x53
#define ILI9341_RGB_INTERFACE	0xB0
#define ILI9341_FRC				0xB1
#define ILI9341_BPC				0xB5
#define ILI9341_DFC				0xB6
#define ILI9341_POWER1			0xC0
#define ILI9341_POWER2			0xC1
#define ILI9341_VCOM1			0xC5
#define ILI9341_VCOM2			0xC7
#define ILI9341_POWERA			0xCB
#define ILI9341_POWERB			0xCF
#define ILI9341_PGAMMA			0xE0
#define ILI9341_NGAMMA			0xE1
#define ILI9341_DTCA			0xE8
#define ILI9341_DTCB			0xEA
#define ILI9341_POWER_SEQ		0xED
#define ILI9341_3GAMMA_EN		0xF2
#define ILI9341_INTERFACE		0xF6
#define ILI9341_PRC				0xF7

// Select orientation for LCD
typedef enum {
	LCD_ILI9341_Orientation_Portrait_1,
	LCD_ILI9341_Orientation_Portrait_2,
	LCD_ILI9341_Orientation_Landscape_1,
	LCD_ILI9341_Orientation_Landscape_2
} LCD_ILI9341_Orientation_t;

// Orientation, Used private
typedef enum {
	LCD_ILI9341_Landscape,
	LCD_ILI9341_Portrait
} LCD_ILI9341_Orientation;

// LCD options, Used private
typedef struct {
	
	u16 width;
	u16 height;

	LCD_ILI9341_Orientation orientation; // 1 = portrait; 0 = landscape
} LCD_ILI931_Options_t;



extern void HILI9341_Init(void);
extern void HILI9341_InitLCD(void);
extern void HILI9341_SendData(u8 data);
extern void HILI9341_SendCommand(u8 data);

extern void HILI9341_Fill(u16 color);
extern void HILI9341_DisplayImage(u16 image[ILI9341_PIXEL]);
extern void HILI9341_Rotate(LCD_ILI9341_Orientation_t orientation);


extern void HILI9341_SPI_Init(void);
extern void HILI9341_SPI_SendMulti(u8 *dataOut, u8 *dataIn, u16 count);
extern void HILI9341_SPI_WriteMulti(u8 *dataOut, u16 count);
extern void HILI9341_SPI_ReadMulti(u8 *dataIn, u8 dummy, u16 count);
extern void HILI9341_SPI_BaudRateUp(void);


#endif
