#include "cyhal.h"
#include "cy_retarget_io.h"

#define X_PIN	P10_0
#define Y_PIN	P10_1

cyhal_adc_t         adc_obj;
cyhal_adc_channel_t adc_chan_x_obj;
cyhal_adc_channel_t adc_chan_y_obj; // Tweede ADC-kanaal

int32_t adc_x;
int32_t adc_y; // Output voor het tweede kanaal

void init_adc(void)
{
	cyhal_adc_init(&adc_obj, X_PIN, NULL); //X_PIN or Y_Pin, it does not matter

	const cyhal_adc_channel_config_t channel_config =
	{
			.enable_averaging = false,
			.min_acquisition_ns = 220,
			.enabled = true
	};

	cyhal_adc_channel_init_diff(&adc_chan_x_obj, &adc_obj, X_PIN, CYHAL_ADC_VNEG, &channel_config);
	cyhal_adc_channel_init_diff(&adc_chan_y_obj, &adc_obj, Y_PIN, CYHAL_ADC_VNEG, &channel_config);

	cyhal_gpio_init(P6_3, CYHAL_GPIO_DIR_OUTPUT, CYHAL_GPIO_DRIVE_STRONG, false); //Make pin P6_3 a GND pin (0V)
	cyhal_gpio_init(P13_6, CYHAL_GPIO_DIR_OUTPUT, CYHAL_GPIO_DRIVE_STRONG, true); //Make pin P13_6 a VCC pin (3,3V)
}

int x_value(void)
{
	return cyhal_adc_read(&adc_chan_x_obj);
}

int y_value(void)
{
	return cyhal_adc_read(&adc_chan_y_obj);
}
