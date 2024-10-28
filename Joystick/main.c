#include "cyhal.h"
#include "cybsp.h"
#include "cy_retarget_io.h"
#include "cy8ckit_028_tft.h"
#include "GUI.h"

//Include from level.c
void levelOne();
void levelTwo();
void levelThree();
void levelFour();

//Include from adc.c
void init_adc(void);
int x_value(void);
int y_value(void);

void draw();

int x = 100;
int y = 100;

bool game = false;

const mtb_st7789v_pins_t tft_pins =
{
	.db08 = CY8CKIT_028_TFT_PIN_DISPLAY_DB8,
	.db09 = CY8CKIT_028_TFT_PIN_DISPLAY_DB9,
	.db10 = CY8CKIT_028_TFT_PIN_DISPLAY_DB10,
	.db11 = CY8CKIT_028_TFT_PIN_DISPLAY_DB11,
	.db12 = CY8CKIT_028_TFT_PIN_DISPLAY_DB12,
	.db13 = CY8CKIT_028_TFT_PIN_DISPLAY_DB13,
	.db14 = CY8CKIT_028_TFT_PIN_DISPLAY_DB14,
	.db15 = CY8CKIT_028_TFT_PIN_DISPLAY_DB15,
	.nrd = CY8CKIT_028_TFT_PIN_DISPLAY_NRD,
	.nwr = CY8CKIT_028_TFT_PIN_DISPLAY_NWR,
	.dc = CY8CKIT_028_TFT_PIN_DISPLAY_DC,
	.rst = CY8CKIT_028_TFT_PIN_DISPLAY_RST
};
int main(void)
{
    cybsp_init();
    __enable_irq();

    cy_retarget_io_init(CYBSP_DEBUG_UART_TX, CYBSP_DEBUG_UART_RX, CY_RETARGET_IO_BAUDRATE);
	printf("\x1b[2J\x1b[;H");
	printf("Joystick\r\n");
	init_adc();

	mtb_st7789v_init8(&tft_pins);
	GUI_Init();
/*
	levelOne();
	levelTwo();
	levelThree();
	levelFour();
*/

	for (;;)
    {
		printf("X = %d - Y = %d\r\n", x_value(), y_value());
		draw();
    }
}

void draw()
{
	GUI_SetColor(GUI_BLUE);
	if(x_value() < -1000) //x right
	{
		x++;
	}
	else if(x_value() > 1000) //x left
	{
		x--;
	}

	if(y_value() < -1000) //y up
	{
		y--;
	}
	else if(y_value() > 1000)//y down
	{
		y++;
	}

	if(x_value() < -1000 && y_value() < -1000) //Right top
	{
		x++;
		y--;
	}
	else if(x_value() < -1000 && y_value() > 1000) //Right bottom
	{
		x++;
		y++;
	}
	else if(x_value() > 1000 && y_value() > 1000) //Left bottom
	{
		x--;
		y++;
	}
	else if(x_value() > 1000 && y_value() < -1000) //Left top
	{
		x--;
		y--;
	}

	GUI_FillCircle(x, y, 5);
}
