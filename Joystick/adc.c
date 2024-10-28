#include "cyhal.h"
#include "cybsp.h"
#include "cy_retarget_io.h"

int32_t adc_x;
int32_t adc_y; // Output voor het tweede kanaal

void init_adc(void)
{
	Cy_SysAnalog_Init(&ADC_AREF_config);
	Cy_SysAnalog_Enable();
	Cy_SAR_Init(ADC_PDL_HW, &ADC_PDL_config);
	Cy_SAR_Enable(ADC_PDL_HW);
	cyhal_gpio_init(P13_5, CYHAL_GPIO_DIR_OUTPUT, CYHAL_GPIO_DRIVE_STRONG, true); //Make pin P13_6 a VCC pin (3,3V)
}

int x_value(void)
{
	Cy_SAR_StartConvert(ADC_PDL_HW, CY_SAR_START_CONVERT_SINGLE_SHOT);
	return Cy_SAR_GetResult32(ADC_PDL_HW, 0);
}

int y_value(void)
{
	Cy_SAR_StartConvert(ADC_PDL_HW, CY_SAR_START_CONVERT_SINGLE_SHOT);
	return Cy_SAR_GetResult32(ADC_PDL_HW, 1);
}

