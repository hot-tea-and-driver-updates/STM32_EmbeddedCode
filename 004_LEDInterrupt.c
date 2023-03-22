/*
 * 004_LEDInterrupt.c
 *
 *  Created on: Mar 21, 2023
 *      Author: jhern
 */


#include "Stm32f407xx_gpio_driver.h"
#include <string.h>

#define HIGH ENABLE
#define LOW DISABLE
#define BTN_PRESSED LOW

void delay(void);
void EXTI0_IRQHandler(void);

void delay(void){
	for(uint32_t i = 0; i < 500000/2; i++);
}

int main(void){
	GPIO_Handle_t user_button;
	GPIO_Handle_t LED1;
	memset(&LED1,0,sizeof(LED1));
	memset(&user_button,0,sizeof(user_button));

	LED1.pGPIOx = GPIOD;
	LED1.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_12;
	LED1.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	LED1.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_HIGH;
	LED1.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PUPD_NONE;
	LED1.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;

	GPIO_PeriClockControl(GPIOD, ENABLE);

	GPIO_Init(&LED1);

	user_button.pGPIOx = GPIOD;
	user_button.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_5;
	user_button.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IT_FT;
	user_button.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_HIGH;
	user_button.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PUPD_PU;


	GPIO_Init(&user_button);

	GPIO_WriteOutputPin(GPIOD,GPIO_PIN_NO_12,GPIO_PIN_RESET);

	//IRQ Configurations
	GPIO_IRQPriorityConfig(IRQ_NO_EXTI9_5, NVIC_IRQ_PRIO_15);

	GPIO_IRQInterruptConfig(IRQ_NO_EXTI9_5, ENABLE);

	while(1);

	return 0;
}

void EXTI9_5_IRQHandler(void){
	GPIO_IRQHandling(GPIO_PIN_NO_5);
	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_12);
}
