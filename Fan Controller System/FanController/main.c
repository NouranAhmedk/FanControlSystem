/******************************************************************************
 * Project: Fan Controller System
 * File Name: main.c
 * Description: Application layer
 * Author: Nouran Ahmed
 *******************************************************************************/

#include "MCAL/GPIO/gpio.h"
#include "HAL/LCD/lcd.h"
#include "MCAL/ADC/adc.h"
#include "HAL/DC_MOTOR/motor.h"

int main(void) {
	uint8 temp = 0;
	ADC_ConfigType ADC_ConfigType = { Internal_2_56V, DF_8 };
	/*Initialization for the modules*/
	ADC_init(&ADC_ConfigType);
	LCD_init();
	DcMotor_Init();
	LCD_displayStringRowColumn(0, 3, "FAN is OFF ");
	LCD_displayStringRowColumn(1, 3, "Temp =    C");

	while (1) {
		/*get the temperature value */
		temp = LM35_getTemperature();
		LCD_moveCursor(1, 10);
		if (temp >= 100) {
			LCD_integerToString(temp);
		} else {
			LCD_integerToString(temp);
			/* In case the digital value is two or one digits print space in the next digit place */
			LCD_displayCharacter(' ');
		}

		/*Display ON/OFF */
		LCD_moveCursor(0, 10);
		/* If the temperature is less than 30C turn off the fan*/
		if (temp < 30) {
			LCD_displayStringRowColumn(0, 10, "OFF");
			DcMotor_Rotate(STOP, 0);
		}
		/* If the temperature is greater than or equal 30C turn on the fan with 25% of its
		 * maximum speed.
		 */
		else if (temp >= 30 && temp < 60) {
			LCD_displayStringRowColumn(0, 10, "ON ");
			DcMotor_Rotate(CW, 25);
		}
		/* If the temperature is greater than or equal 30C turn on the fan with 25% of its
		 * maximum speed.
		 */
		else if (temp >= 30 && temp < 60) {
			LCD_displayStringRowColumn(0, 10, "ON ");
			DcMotor_Rotate(CW, 25);
		}
		/* If the temperature is greater than or equal 60C turn on the fan with 50% of its
		 * maximum speed.
		 */
		else if (temp >= 60 && temp < 90) {
			LCD_displayStringRowColumn(0, 10, "ON ");
			DcMotor_Rotate(CW, 50);
		}
		/* If the temperature is greater than or equal 90C turn on the fan with 75% of its
		 * maximum speed.
		 */
		else if (temp >= 90 && temp < 120) {
			LCD_displayStringRowColumn(0, 10, "ON ");
			DcMotor_Rotate(CW, 75);
		}
		/* If the temperature is greater than or equal 120C turn on the fan with 100% of its
		 * maximum speed.
		 */
		else if (temp >= 120) {
			LCD_displayStringRowColumn(0, 10, "ON ");
			DcMotor_Rotate(CW, 100);
		}

	}
	return 0;
}
