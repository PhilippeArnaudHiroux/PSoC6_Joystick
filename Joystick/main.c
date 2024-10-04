#include "cyhal.h"
#include "cybsp.h"
#include "cy_retarget_io.h"
#include "cy8ckit_028_tft.h"
#include "GUI.h"

void levelOne();
void levelTwo();
void levelThree();
void levelFour();

int main(void)
{
    cybsp_init();
    __enable_irq();

    cy_retarget_io_init(CYBSP_DEBUG_UART_TX, CYBSP_DEBUG_UART_RX, CY_RETARGET_IO_BAUDRATE);
	printf("\x1b[2J\x1b[;H");

	cy8ckit_028_tft_init (NULL, NULL, NULL, NULL);
	GUI_Init();

	levelOne();
	levelTwo();
	levelThree();
	levelFour();

	for (;;)
    {}
}
