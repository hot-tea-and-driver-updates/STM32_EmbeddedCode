/*
 * stm32f407xx_gpio_driver.c
 *
 *  Created on: Mar 5, 2023
 *      Author: jhern
 * This is the GPIO Device Driver Source File, contains driver specific data
 */


#include "stm32f407xx_gpio_driver.h"

/*
 * Peripheral Clock Setup
 */

/******************************************************************
 * @fn				-	GPIO_PeriClockControl
 *
 * @brief			-	This function enables or disables peripheral clock for the given GPIO port.
 *
 * @param[in]		-	Base address of the GPIO peripheral via GPIO_RegDef_t pointer.
 * @param[in]		-	ENABLE or DISABLE macros.
 * @param[in]		-
 *
 * @return			-	None
 *
 * @Note			-	None

 */

void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi){
	if(EnorDi == ENABLE){
		if(pGPIOx == GPIOA){
			GPIOA_PCLK_EN();
		}else if (pGPIOx == GPIOB){
			GPIOB_PCLK_EN();
		}else if (pGPIOx == GPIOC){
			GPIOC_PCLK_EN();
		}else if (pGPIOx == GPIOD){
			GPIOD_PCLK_EN();
		}else if (pGPIOx == GPIOE){
			GPIOE_PCLK_EN();
		}else if (pGPIOx == GPIOF){
			GPIOF_PCLK_EN();
		}else if (pGPIOx == GPIOG){
			GPIOG_PCLK_EN();
		}else if (pGPIOx == GPIOH){
			GPIOH_PCLK_EN();
		}else if (pGPIOx == GPIOI){
			GPIOI_PCLK_EN();
		}
	}else{
		if(pGPIOx == GPIOA){
			GPIOA_PCLK_DI();
		}else if (pGPIOx == GPIOB){
			GPIOB_PCLK_DI();
		}else if (pGPIOx == GPIOC){
			GPIOC_PCLK_DI();
		}else if (pGPIOx == GPIOD){
			GPIOD_PCLK_DI();
		}else if (pGPIOx == GPIOE){
			GPIOE_PCLK_DI();
		}else if (pGPIOx == GPIOF){
			GPIOF_PCLK_DI();
		}else if (pGPIOx == GPIOG){
			GPIOG_PCLK_DI();
		}else if (pGPIOx == GPIOH){
			GPIOH_PCLK_DI();
		}else if (pGPIOx == GPIOI){
			GPIOI_PCLK_DI();
		}
	}
}

/*
 * GPIO Initialization
 */

/******************************************************************
 * @fn				-	GPIO_Init
 *
 * @brief			-	This function initializes a particular GPIO port.
 *
 * @param[in]		-	Base address of the GPIO peripheral via GPIO_RegDef_t pointer.
 * @param[in]		-
 * @param[in]		-
 *
 * @return			-	None
 *
 * @Note			-	None

 */

void GPIO_Init(GPIO_Handle_t *pGPIOHandle){

	uint32_t temp = 0; //temp register

	//1. Configure the mode of the GPIO pin
	if((pGPIOHandle->GPIO_PinConfig.GPIO_PinMode) <= GPIO_MODE_ANALOG){
		/*temp = the value of our mode, shifted into the correct register bits (each pin is 2 bits wide), so we shift
		 *left by the pin number * 2, which will give us the correct pin to set the mode of.
		 *i.e if pinmode is 3 and our pin is 10, we want to shift 3 << 2 * 10 so 3 << 20 (which will give us our 10th pin register)
		 *this will be used as the (3 << 20) which is then used to set the bits.
		 */
		temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
		pGPIOHandle->pGPIOx->MODER &= ~(0x3 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
		pGPIOHandle->pGPIOx->MODER |= temp;
	}else{
		//let us make sure that the GPIO pin is configured as input before setting interrupt mode
		//pGPIOHandle->pGPIOx->MODER &= ~(0x3 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));

		//this part relates to interrupt mode.
		if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_IT_FT){
			//1.Configure (Enable) the FTSR
			EXTI->FTSR |= ( 1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
			//Clear (DISABLE) the corresponding RTSR bit (since we just want falling edge trigger)
			EXTI->RTSR &= ~( 1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);


		}else if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_IT_RT){
			//2.Configure the RTSR
			EXTI->RTSR |= ( 1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
			//Clear the corresponding RTSR bit (since we just want falling edge trigger)
			EXTI->FTSR &= ~( 1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);

		}else if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_IT_RFT){
			//3.Configure the RTFRSR
			EXTI->FTSR |= ( 1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
			EXTI->RTSR |= ( 1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);

		}

		//2. configure the GPIO port selection in SYSCFG_EXTICR
		uint8_t temp1 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber / 4;
		uint8_t temp2 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber % 4;
		uint8_t portcode = GPIO_BASEADDR_TO_CODE(pGPIOHandle->pGPIOx);
		SYSCFG_PCLK_EN();
		SYSCFG->EXTICR[temp1] = portcode << (temp2 * 4);



		//3. enable the exti interrupt delivery using IMR (interrupt mask register) corresponding to the pin # provided
		//the mask register masks (ignores) an interrupt until the corresponding line of the EXTI has been enabled.
		EXTI->IMR |= (1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);

	}
	temp = 0;

	//2. Configure the speed of the GPIO pin
	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinSpeed << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->OSPEEDR  &= ~(0x3 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->OSPEEDR |= temp;

	temp = 0;

	//3. Configure the pin-up/pull-down resistor of the GPIO pin
	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinPuPdControl << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->PUPDR  &= ~(0x3 << (2* pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->PUPDR |= temp;
	temp = 0;

	//4. Configure the output type of the pin
	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinOPType << (pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->OTYPER  &= ~(0x1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
	pGPIOHandle->pGPIOx->OTYPER |= temp;
	temp = 0;

	//5. Configure the alternate function mode of the pin
	if((pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_ALTFN)){
		uint8_t temp1, temp2;
		temp1 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber / 8;
		temp2 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber % 8;
		pGPIOHandle->pGPIOx->AFR[temp1] &= ~(0xF << (4 * temp2));
		pGPIOHandle->pGPIOx->AFR[temp1] |= (pGPIOHandle->GPIO_PinConfig.GPIO_PinAltFunMode << (4 * temp2));
	}
}


/******************************************************************
 * @fn				-	GPIO_Disable
 *
 * @brief			-	This function disables a particular GPIO port.
 *
 * @param[in]		-	Base address of the GPIO peripheral via GPIO_RegDef_t pointer.
 * @param[in]		-
 * @param[in]		-
 *
 * @return			-	None
 *
 * @Note			-	None

 */

void GPIO_Disable(GPIO_RegDef_t *pGPIOx){
		if(pGPIOx == GPIOA){
			GPIOA_REG_RESET();
		}else if (pGPIOx == GPIOB){
			GPIOB_REG_RESET();
		}else if (pGPIOx == GPIOC){
			GPIOC_REG_RESET();
		}else if (pGPIOx == GPIOD){
			GPIOD_REG_RESET();
		}else if (pGPIOx == GPIOE){
			GPIOE_REG_RESET();
		}else if (pGPIOx == GPIOF){
			GPIOF_REG_RESET();
		}else if (pGPIOx == GPIOG){
			GPIOG_REG_RESET();
		}else if (pGPIOx == GPIOH){
			GPIOH_REG_RESET();
		}else if (pGPIOx == GPIOI){
			GPIOI_REG_RESET();
		}
}

/*
 * Data read and write
 */

/******************************************************************
 * @fn				-	GPIO_ReadInputPin
 *
 * @brief			-	This function reads the value at a particular input pin.
 *
 * @param[in]		-	Base address of the GPIO peripheral.
 * @param[in]		-	Pin number of GPIO port to read from.
 * @param[in]		-
 *
 * @return			-	8 bit value from input pin, 0 or 1.
 *
 * @Note			-	None

 */

uint8_t GPIO_ReadInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber){
	uint8_t value;
	value = (uint8_t) ((pGPIOx->IDR >> PinNumber) & (0x00000001));
	return value;
}

/******************************************************************
 * @fn				-	GPIO_ReadInputPort
 *
 * @brief			-	This function reads the value at a particular input port.
 *
 * @param[in]		-	Base address of the GPIO peripheral.
 * @param[in]		-	GPIO port to read from.
 * @param[in]		-
 *
 * @return			-	16 bit value from input port.
 *
 * @Note			-	None

 */
uint16_t GPIO_ReadInputPort(GPIO_RegDef_t *pGPIOx){
	uint16_t value;
	value = (uint16_t) pGPIOx->IDR;
	return value;
}

/******************************************************************
 * @fn				-	GPIO_WriteOutputPin
 *
 * @brief			-	This function allows the user to write a value to a particular output pin.
 *
 * @param[in]		-	Base address of the GPIO peripheral.
 * @param[in]		-	Pin number of GPIO port to write to.
 * @param[in]		-	Value to write, 0 or 1.
 *
 * @return			-	None
 *
 * @Note			-	None

 */

void GPIO_WriteOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value){
	if(Value == GPIO_PIN_SET){
		pGPIOx->ODR &= ~(1 << PinNumber); //clears respective pin bit field
		pGPIOx->ODR |= (1 << PinNumber);  //writes 1 to pin
	}else{
		pGPIOx->ODR &= ~(1 << PinNumber); //writes 0 to pin
	}
}

/******************************************************************
 * @fn				-	GPIO_WriteOutputPort
 *
 * @brief			-	This function allows the user to write a value to a particular output port.
 *
 * @param[in]		-	Base address of the GPIO peripheral.
 * @param[in]		-	16 bit value to write.
 * @param[in]		-
 *
 * @return			-	None
 *
 * @Note			-	16 bits are used for write value because there exists 16 pins within a port.

 */

void GPIO_WriteOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value){
	pGPIOx->ODR = Value;
}

/******************************************************************
 * @fn				-	GPIO_ToggleOutputPin
 *
 * @brief			-	This function toggles the value of a pin (on/off).
 *
 * @param[in]		-	Base address of the GPIO peripheral.
 * @param[in]		-	Pin number of a GPIO port to toggle on or off.
 * @param[in]		-
 *
 * @return			-	None
 *
 * @Note			-	None

 */

void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber){
	pGPIOx->ODR ^= (1 << PinNumber);
}

/*
 * IRQ Configuration and ISR Handling
 */


/******************************************************************
 * @fn				-	GPIO_IRQInterruptConfig
 *
 * @brief			-	This function configures the IRQ of a particular GPIO pin.
 *
 * @param[in]		- 	IRQ Number of a particular port.
 * @param[in]		-	IRQ Priority level to set interrupt to.
 * @param[in]		-	ENABLE or DISABLE macros.
 *
 * @return			-	None
 *
 * @Note			-	None

 */
void GPIO_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnorDi){ //used to configure IRQ number of the GPIO Pin
	if(EnorDi == ENABLE){
		if(IRQNumber <= 31){
			//program ISER0 register
			*NVIC_ISER0 |= (1 << IRQNumber);

		}else if(IRQNumber > 31 && IRQNumber < 64){
			//program ISER1 register
			*NVIC_ISER1 |= (1 << (IRQNumber % 32));

		}else if(IRQNumber >= 64 && IRQNumber < 96){
			//program ISER2 register
			*NVIC_ISER2 |= (1 << (IRQNumber % 32));
		}
	}else{ //disable the following IRQ numbers within the register
		if(IRQNumber <= 31){
			//program ISER0 register
			*NVIC_ICER0 |= (1 << IRQNumber);
		}else if(IRQNumber > 31 && IRQNumber < 64){
			//program ISER1 register
			*NVIC_ICER1 |= (1 << (IRQNumber % 32));
		}else if(IRQNumber >= 64 && IRQNumber < 96){
			//program ISER2 register
			*NVIC_ICER2 |= (1 << (IRQNumber % 32));
		}
	}
}

/******************************************************************
 * @fn				-	GPIO_IRQPriorityConfig
 *
 * @brief			-	This function configures the IRQ of a particular GPIO pin.
 *
 * @param[in]		- 	IRQ Number of a particular port.
 * @param[in]		-	IRQ Priority level to set interrupt to.
 * @param[in]		-
 *
 * @return			-	None
 *
 * @Note			-	None

 */

void GPIO_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPriority){
	//1. first lets find out the ipr register
	uint8_t iprx = IRQNumber / 4;				//correct IPR register for corresponding IRQ number
	uint8_t iprx_section = (IRQNumber % 4);		//correct IPR section within IPR register

	/*shifting the value of our IRQpriority by
	 * (8 (register bit width) * corresponding section) +
	 * (8 - NO_PR_BITS_IMPLEMENTED), which is 4 in STM32 case
	 *	the latter value allows us to shift our value to the index [8:5] of a IRQ subsection*/
	uint8_t shift_amount = (8 * iprx_section) + (8 - NO_PR_BITS_IMPLEMENTED);

	//NVIC_PR_BASE_ADDR+iprx does address calculation by adding 4 (which would go onto next 32 bits)
	(*(NVIC_PR_BASE_ADDR+(iprx))) |= (IRQPriority << (shift_amount));
}

/******************************************************************
 * @fn				-	GPIO_IRQHandling
 *
 * @brief			-	This function handles the IRQ when an interrupt occurs at a given pin.
 * 						Specifically, it clears a pending interrupt.
 *
 * @param[in]		-	Pin number of a GPIO port.
 * @param[in]		-
 * @param[in]		-
 *
 * @return			-	None
 *
 * @Note			-	None

 */

void GPIO_IRQHandling(uint8_t PinNumber){
	//clear the exti pr register
	if(EXTI->PR & (1 << PinNumber)){
		//clear pending register bit
		EXTI->PR |= ( 1 << PinNumber);
	}
}
