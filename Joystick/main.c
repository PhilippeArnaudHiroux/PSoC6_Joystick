#include "cyhal.h"
#include "cybsp.h"
#include "cy_retarget_io.h"
#include "GUI.h"
#include "define.h"

//Include from tft.c
void tftInit();
void levelOne();
void levelTwo();
void levelThree();
void levelFour();
void gameOver();
void gameCompleted();

//Include from adc.c
void init_adc(void);
int x_value(void);
int y_value(void);

void draw(int x, int y);
int game = false;
int statement = 0;

int main(void)
{
    cybsp_init();
    __enable_irq();

    cy_retarget_io_init(CYBSP_DEBUG_UART_TX, CYBSP_DEBUG_UART_RX, CY_RETARGET_IO_BAUDRATE);
	printf("\x1b[2J\x1b[;H");
	printf("Joystick\r\n");
	init_adc();
	tftInit();
/*
	levelOne();
	draw(20, 120);
	levelTwo();
	draw(20, 50);
	levelThree();
	draw(20, 50);
	levelFour();
	draw(20, 22);
*/
	for (;;)
	{
		switch(statement)
		{
			case 0:
				levelOne();
				draw(20, 120);
				break;
			case 1:
				levelTwo();
				draw(20, 50);
				break;
			case 2:
				levelThree();
				draw(20, 50);
				break;
			case 3:
				levelFour();
				draw(20, 22);
				break;
			default:
				statement = 0;
				break;
		}
	}
}

void draw(int x, int y)
{
	GUI_SetColor(GUI_BLUE);
	while(game == false)
	{
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

		GUI_FillCircle(x, y, CIRCLE_SIZE);
		cyhal_system_delay_ms(10);

		if(GUI_GetPixelIndex(x+(CIRCLE_SIZE+1), y) == COLOR_GREEN || GUI_GetPixelIndex(x-(CIRCLE_SIZE+1), y) == COLOR_GREEN || GUI_GetPixelIndex(x, y+(CIRCLE_SIZE+1)) == COLOR_GREEN || GUI_GetPixelIndex(x, y-(CIRCLE_SIZE+1)) == COLOR_GREEN)
		{
			gameCompleted();
			game = true;
			cyhal_system_delay_ms(2000);
			statement++;
		}
		if(GUI_GetPixelIndex(x+(CIRCLE_SIZE+1), y) == COLOR_RED || GUI_GetPixelIndex(x-(CIRCLE_SIZE+1), y) == COLOR_RED || GUI_GetPixelIndex(x, y+(CIRCLE_SIZE+1)) == COLOR_RED || GUI_GetPixelIndex(x, y-(CIRCLE_SIZE+1)) == COLOR_RED)
		{
			gameOver();
			game = true;
			statement = 0;
		}
	}
	game = false;
}
