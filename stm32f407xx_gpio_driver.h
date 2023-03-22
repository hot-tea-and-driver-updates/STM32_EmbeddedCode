/*
 * stm32f407xx_gpio_driver.h
 *
 *  Created on: Mar 5, 2023
 *      Author: jhern
 *
 * This is the GPIO Device Driver Header File, contains driver specific data
 */

#ifndef INC_STM32F407XX_GPIO_DRIVER_H_
#define INC_STM32F407XX_GPIO_DRIVER_H_

#include "stm32f407xx.h"		//must include our device specific header file


/*
 * This is a Configuration structure for a GPIO pin, this is like the settings for the pin we're
 * working on.
 */
typedef struct{
	//we use one byte because we only need 4 bits to change 0-15
	uint8_t GPIO_PinNumber;			/*!< possible values from @GPIO_PIN_NUMBERS >*/
	uint8_t GPIO_PinMode;			/*!< possible values from @GPIO_PIN_MODES >*/
	uint8_t GPIO_PinSpeed;			/*!< possible values from @GPIO_PIN_SPEED_MODES >*/
	uint8_t GPIO_PinPuPdControl;	/*!< possible values from @GPIO_PULLUP/DOWN_MODES >*/
	uint8_t GPIO_PinOPType;			/*!< possible values from @GPIO_PIN_OUTPUT_TYPES >*/
	uint8_t GPIO_PinAltFunMode;
}GPIO_PinConfig_t;

/*
 * This is a Handler Structure for a GPIO Pin
 */

typedef struct{
	GPIO_RegDef_t *pGPIOx; /*This holds the base address of the GPIO port to which the pin belongs*/
	GPIO_PinConfig_t GPIO_PinConfig; /*This holds GPIO pin configuration settings */

}GPIO_Handle_t;


/*
 *@GPIO_PIN_NUMBERS
 * GPIO pin numbers
 */

#define GPIO_PIN_NO_0	0
#define GPIO_PIN_NO_1	1
#define GPIO_PIN_NO_2	2
#define GPIO_PIN_NO_3	3
#define GPIO_PIN_NO_4	4
#define GPIO_PIN_NO_5	5
#define GPIO_PIN_NO_6	6
#define GPIO_PIN_NO_7	7
#define GPIO_PIN_NO_8	8
#define GPIO_PIN_NO_9	9
#define GPIO_PIN_NO_10	10
#define GPIO_PIN_NO_11	11
#define GPIO_PIN_NO_12	12
#define GPIO_PIN_NO_13	13
#define GPIO_PIN_NO_14	14
#define GPIO_PIN_NO_15	15


/*
 * @GPIO_PIN_MODES
 * GPIO pin possible input modes
 */

#define GPIO_MODE_IN 		0
#define GPIO_MODE_OUT 		1
#define GPIO_MODE_ALTFN		2
#define GPIO_MODE_ANALOG	3
#define GPIO_MODE_IT_FT		4 // input mode pin configured to send interrupt on falling edge
#define GPIO_MODE_IT_RT		5 // input mode pin configured to send interrupt on rising edge
#define GPIO_MODE_IT_RFT	6 // input mode pin configured to send interrupt on falling/rising


/*
 * @GPIO_PIN_OUTPUT_TYPES
 * GPIO pin possible output types
 */

#define GPIO_OP_TYPE_PP 0
#define GPIO_OP_TYPE_OD	1

/*
 * @GPIO_PIN_SPEED_MODES
 * GPIO pin possible output speed modes
 */

#define GPIO_SPEED_LOW   0
#define GPIO_SPEED_MED   1
#define GPIO_SPEED_HIGH  2
#define GPIO_SPEED_VHIGH 3

/*
 * @GPIO_PULLUP/DOWN_MODES
 * GPIO pin pull-up/down modes
 */

#define GPIO_PUPD_NONE	0
#define GPIO_PUPD_PU	1
#define GPIO_PUPD_PD	2




/**********************************************************************
 * 					APIs supported by this driver
 * For more information about the APIs check the function definitions
 **********************************************************************/

/*
 * Peripheral Clock Setup
 */
//Enable or disables peripheral clock for a given GPIO base address
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi);

/*
 * GPIO Initialization
 */
//User creates a GPIO_Handle_t structure and sends a pointer to this function
void GPIO_Init(GPIO_Handle_t *pGPIOHandle);
void GPIO_Disable(GPIO_RegDef_t *pGPIOx);

/*
 * Data read and write
 */

uint8_t GPIO_ReadInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);
uint16_t GPIO_ReadInputPort(GPIO_RegDef_t *pGPIOx);
void GPIO_WriteOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value);
void GPIO_WriteOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value); //16_t bc 16 pins in a port
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);

/*
 * IRQ Configuration and ISR Handling
 */

void GPIO_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnorDi); //used to configure IRQ number of the GPIO Pin
void GPIO_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPriority);
void GPIO_IRQHandling(uint8_t PinNumber);


#endif /* INC_STM32F407XX_GPIO_DRIVER_H_ */
