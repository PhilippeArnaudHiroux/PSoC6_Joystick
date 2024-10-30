# PSoC6_Joystick

# Conclusion
* The function `GUI_DrawArc()` from the GUI.h library does not allow to draw an arc if the starting grade is greater than the ending grade.
* ADC using HAL only works on the pre definded analog pins.
* When configure ADC in PDL you canot use `cy8ckit_028_tft_init (NULL, NULL, NULL, NULL);` anymore.
Instead you can use the struct below and the fucntion `mtb_st7789v_init8(&tft_pins);`.

```c
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
```