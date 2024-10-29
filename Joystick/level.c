#include "cyhal.h"
#include "GUI.h"
#include "define.h"

//#define LEVEL_DELAY		3000
//#define COLOR_FINISH	GUI_GREEN
//#define COLOR_LEVEL		GUI_BLUE
//#define COLOR_WALL		GUI_RED
//x = 320 - y = 240
/*
 * |------> x = 320
 * |
 * |
 * v y = 240
 *
 * Green = 2016
 * Red = 63488
 */

void levelOne()
{
	GUI_Clear();
	GUI_SetColor(COLOR_LEVEL);
	GUI_SetFont(GUI_FONT_32B_ASCII);
	GUI_DispStringAt("Level 1 ", 100, 10);
	cyhal_system_delay_ms(LEVEL_DELAY);
	GUI_Clear();
	GUI_SetColor(COLOR_WALL);
	GUI_SetPenSize(5);
	GUI_DrawLine(0, 95, 320, 95);
	GUI_DrawLine(0, 145, 320, 145);
	GUI_DrawLine(2, 95, 2, 145);
	GUI_SetColor(COLOR_FINISH);
	GUI_DrawLine(318, 95, 318, 145);
}

void levelTwo()
{
	GUI_Clear();
	GUI_SetColor(COLOR_LEVEL);
	GUI_SetFont(GUI_FONT_32B_ASCII);
	GUI_DispStringAt("Level 2 ", 100, 10);
	cyhal_system_delay_ms(LEVEL_DELAY);
	GUI_Clear();
	GUI_SetColor(COLOR_WALL);
	GUI_SetPenSize(5);
	GUI_DrawLine(2, 30, 2, 70);
	GUI_DrawLine(0, 30, 180, 30);
	GUI_DrawLine(0, 70, 140, 70);
	GUI_DrawLine(180, 30, 180, 170);
	GUI_DrawLine(140, 70, 140, 210);
	GUI_DrawLine(180, 170, 320, 170);
	GUI_DrawLine(140, 210, 320, 210);
	GUI_SetColor(COLOR_FINISH);
	GUI_DrawLine(318, 170, 318, 210);
}

void levelThree()
{
	GUI_Clear();
	GUI_SetColor(COLOR_LEVEL);
	GUI_SetFont(GUI_FONT_32B_ASCII);
	GUI_DispStringAt("Level 3 ", 100, 10);
	cyhal_system_delay_ms(LEVEL_DELAY);
	GUI_Clear();
	GUI_SetColor(COLOR_WALL);
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
	GUI_SetColor(COLOR_FINISH);
	GUI_DrawLine(318, 170, 318, 210);
}

void levelFour()
{
	GUI_Clear();
	GUI_SetColor(COLOR_LEVEL);
	GUI_SetFont(GUI_FONT_32B_ASCII);
	GUI_DispStringAt("Level 4 ", 100, 10);
	cyhal_system_delay_ms(LEVEL_DELAY);
	GUI_Clear();
	GUI_SetColor(COLOR_WALL);
	GUI_SetPenSize(5);
	GUI_DrawLine(2, 2, 2, 42);
	GUI_DrawLine(2, 2, 278, 2);
	GUI_DrawArc(278, 42, 40, 40, 270, 359);
	GUI_DrawArc(278, 42, 40, 40, 0, 90);
	GUI_DrawLine(2, 42, 278, 42);
	GUI_DrawArc(42, 82, 40, 40, 90, 270);
	GUI_DrawLine(42, 82, 278, 82);
	GUI_DrawLine(42, 122, 278, 122);
	GUI_DrawArc(278, 122, 40, 40, 270, 359);
	GUI_DrawArc(278, 122, 40, 40, 0, 90);
	GUI_DrawLine(42, 162, 278, 162);
	GUI_DrawArc(42, 162, 40, 40, 90, 270);
	GUI_DrawLine(2, 202, 278, 202);
	GUI_DrawArc(278, 202, 40, 40, 270, 359);
	GUI_DrawArc(278, 202, 40, 40, 0, 90);
	GUI_AA_DrawLine(2, 238, 290, 238);
	GUI_SetColor(COLOR_FINISH);
	GUI_DrawLine(2, 202, 2, 238);
}

void gameOver()
{
	GUI_Clear();
	GUI_SetColor(COLOR_LEVEL);
	GUI_SetFont(GUI_FONT_32B_ASCII);
	GUI_DispStringAt("GAME OVER!!!", 100, 10);
}

void gameCompleted()
{
	GUI_Clear();
	GUI_SetColor(COLOR_LEVEL);
	GUI_SetFont(GUI_FONT_32B_ASCII);
	GUI_DispStringAt("LEVEL completed!!!", 100, 10);

}
