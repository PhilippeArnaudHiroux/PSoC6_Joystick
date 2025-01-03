# PSoC6_Joystick
This is a project using the PSoC 6 to create a game on the TFT-shield.</br>
[Video](https://youtu.be/qmMelWHsCIE)

## How it works
The game consists of different levels. You have to complete a course with the joystick. If you touch the red line you go back to level 1. If you touch the green line you go to the next level.

## Conclusion
* The function `GUI_DrawArc()` from the GUI.h library does not allow to draw an arc if the starting grade is greater than the ending grade.
* ADC using HAL only works on the pre definded analog pins.
* When configure ADC in PDL you canot use `cy8ckit_028_tft_init (NULL, NULL, NULL, NULL);` anymore.
Instead you can use the struct below and the fucntion `mtb_st7789v_init8(&tft_pins);`. This function only initializes the pins to control the display. The light sensor, motion sensor, audio, ... can not be used with this function.
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

# Source
## ModusToolbox documentation
* [HAL](https://infineon.github.io/mtb-hal-cat1/html/group__group__hal__rtc.html)
* [TFT-display](https://infineon.github.io/display-tft-st7789v/html/index.html)

## Infineon documentation
* [Modustoolbox level 2](https://github.com/Infineon/training-modustoolbox-level2-psoc)
* [TFT-display](https://github.com/Infineon/display-tft-st7789v)

