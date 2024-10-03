#include "cyhal.h"
#include "cybsp.h"
#include "cy_retarget_io.h"
#include "cy8ckit_028_tft.h"
#include "GUI.h"

#define LEVEL_DELAY	3000
//x = 320 - y = 240
/*
 * |------> x = 320
 * |
 * |
 * v y = 240
 */

void levelOne();
void levelTwo();
void levelThree();

int main(void)
{
    cybsp_init();
    __enable_irq();

    cy_retarget_io_init(CYBSP_DEBUG_UART_TX, CYBSP_DEBUG_UART_RX, CY_RETARGET_IO_BAUDRATE);
	printf("\x1b[2J\x1b[;H");

	cy8ckit_028_tft_init (NULL, NULL, NULL, NULL);
	GUI_Init();

	int x = GUI_GetScreenSizeX();
	int y = GUI_GetScreenSizeY();

	printf("x = %d - y = %d\r\n", x, y);

	levelOne();
	levelTwo();
	levelThree();

	for (;;)
    {}
}

void levelOne()
{
	GUI_SetColor(GUI_BLUE);
	GUI_SetFont(GUI_FONT_32B_ASCII);
	GUI_DispStringAt("Level 1 ", 100, 10);
	cyhal_system_delay_ms(LEVEL_DELAY);
	GUI_Clear();

	GUI_SetPenSize(5);
	GUI_DrawLine(0, 95, 320, 95);
	GUI_DrawLine(0, 145, 320, 145);
	GUI_DrawLine(2, 95, 2, 145);
	GUI_SetColor(GUI_GREEN);
	GUI_DrawLine(318, 95, 318, 145);

	cyhal_system_delay_ms(LEVEL_DELAY);
	GUI_Clear();
}

void levelTwo()
{
	GUI_SetColor(GUI_BLUE);
	GUI_SetFont(GUI_FONT_32B_ASCII);
	GUI_DispStringAt("Level 2 ", 100, 10);
	cyhal_system_delay_ms(LEVEL_DELAY);
	GUI_Clear();

	GUI_SetPenSize(5);
	GUI_DrawLine(2, 30, 2, 70);
	GUI_DrawLine(0, 30, 180, 30);
	GUI_DrawLine(0, 70, 140, 70);
	GUI_DrawLine(180, 30, 180, 170);
	GUI_DrawLine(140, 70, 140, 210);
	GUI_DrawLine(180, 170, 320, 170);
	GUI_DrawLine(140, 210, 320, 210);
	GUI_SetColor(GUI_GREEN);
	GUI_DrawLine(318, 170, 318, 210);

	cyhal_system_delay_ms(LEVEL_DELAY);
	GUI_Clear();
}

void levelThree()
{
	GUI_SetColor(GUI_BLUE);
	GUI_SetFont(GUI_FONT_32B_ASCII);
	GUI_DispStringAt("Level 3 ", 100, 10);
	cyhal_system_delay_ms(LEVEL_DELAY);
	GUI_Clear();

	GUI_SetPenSize(5);
	GUI_DrawLine(2, 30, 2, 70);
	GUI_DrawLine(0, 30, 320, 30);
	GUI_DrawLine(0, 70, 280, 70);

	GUI_DrawLine(318, 30, 318, 110);
	GUI_DrawLine(2, 130, 2, 210);

	GUI_DrawLine(318, 110, 40, 170);
	GUI_DrawLine(2, 130, 280, 70);

	GUI_DrawLine(40, 170, 320, 170);
	GUI_DrawLine(0, 210, 320, 210);

	GUI_SetColor(GUI_GREEN);
	GUI_DrawLine(318, 170, 318, 210);
}
