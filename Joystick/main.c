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

int main(void)
{
    cybsp_init();
    __enable_irq();

    cy_retarget_io_init(CYBSP_DEBUG_UART_TX, CYBSP_DEBUG_UART_RX, CY_RETARGET_IO_BAUDRATE);
	printf("\x1b[2J\x1b[;H");
	init_adc();

	cy8ckit_028_tft_init (NULL, NULL, NULL, NULL);
	GUI_Init();

	levelOne();
	levelTwo();
	levelThree();
	levelFour();

	for (;;)
    {
		//printf("X = %d\t\t - Y = %d\r\n", x_value(), y_value());
    }
}
