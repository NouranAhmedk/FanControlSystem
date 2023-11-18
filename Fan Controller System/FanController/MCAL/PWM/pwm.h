/******************************************************************************
 * Module: Pulse width modulation
 * File Name: pwm.h
 * Description: header file for PWM
 * Author: Nouran Ahmed
 *******************************************************************************/

#ifndef MCAL_PWM_PWM_H_
#define MCAL_PWM_PWM_H_

#include "../std_types.h"
#include "../GPIO/gpio.h"

/*
 * Description:
 * Starts the PWM (Pulse Width Modulation) output using Timer0 with the specified duty cycle.
 * The function sets up the necessary configurations and starts generating PWM signals.
 * Parameters:
 * duty_cycle: The duty cycle value for the PWM output. Should be between 0 and 255.
 */
void PWM_Timer0_Start(uint8 duty_cycle);


#endif /* MCAL_PWM_PWM_H_ */
