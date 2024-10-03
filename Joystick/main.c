#include "cyhal.h"
#include "cybsp.h"
#include "cy_retarget_io.h"
#include "cy8ckit_028_tft.h"
#include "GUI.h"

/*
cyhal_adc_t         adc_obj;
cyhal_adc_channel_t adc_chan_0_obj;

int32_t adc_out;

const cyhal_adc_channel_config_t channel_config =
{
	.enable_averaging = false,
	.min_acquisition_ns = 220,
	.enabled = true
};
*/

int main(void)
{
    cybsp_init();
    __enable_irq();

    cy_retarget_io_init(CYBSP_DEBUG_UART_TX, CYBSP_DEBUG_UART_RX, CY_RETARGET_IO_BAUDRATE);
	printf("\x1b[2J\x1b[;H");
/*
	cyhal_gpio_init(P10_0, CYHAL_GPIO_DIR_OUTPUT, CYHAL_GPIO_DRIVE_STRONG, false); //GND
	cyhal_gpio_init(P10_1, CYHAL_GPIO_DIR_OUTPUT, CYHAL_GPIO_DRIVE_STRONG, true); //3,3V
	*/

	//cyhal_adc_init(&adc_obj, P10_2, NULL);
	//cyhal_adc_channel_init_diff(&adc_chan_0_obj, &adc_obj, P10_2, CYHAL_ADC_VNEG, &channel_config);

	cy8ckit_028_tft_init (NULL, NULL, NULL, NULL);
	GUI_Init();
	//GUI_SetBkColor(GUI_GREEN);

	for(int i=10; i<150; i++)
	{
		//GUI_SetColor(GUI_BLACK);
		//GUI_FillCircle(100, i-1, 5);
		GUI_SetColor(GUI_GREEN);
		GUI_FillCircle(100, i, 5);
		//cyhal_system_delay_ms(50);
	}
	unsigned int test = GUI_GetPixelIndex(100, 20);
	printf("green = %d\r\n", test);

	GUI_SetColor(GUI_RED);
	for(int i=10; i<150; i++)
	{
		GUI_FillCircle(i, 15, 5);
		unsigned int a = GUI_GetPixelIndex(i+6, 15);
		printf("a = %d\r\n", a);
		if(a == test)
		{
			printf("In if loop\r\n");
			break;
		}
	}
	test = GUI_GetPixelIndex(20, 15);
	printf("red = %d\r\n", test);

	//GUI_DispString("Hello");
	//GUI_HMEM hQR = GUI_QR_Create("https://www.youtube.com/watch?v=dQw4w9WgXcQ", 6, 1, 0);
	//GUI_QR_Draw(hQR, 10, 10);

    for (;;)
    {
    	//adc_out = cyhal_adc_read(&adc_chan_0_obj);
    	//printf("value = %d\r\n", adc_out);
    	//cyhal_system_delay_ms(500);
    }
}
