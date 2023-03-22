/*
 * stm32f407xx.h
 *
 *  Created on: Mar 4, 2023
 *      Author: jhern
 */

#ifndef INC_STM32F407XX_H_
#define INC_STM32F407XX_H_

#include <stdint.h>

/*******************************START:Processor Specific Details *************************
 *
 * ARM Cortex Mx Processor NVIC ISERx register Addresses
 */

#define NVIC_ISER0					((volatile uint32_t*) 0xE000E100)
#define NVIC_ISER1					((volatile uint32_t*) 0xE000E104)
#define NVIC_ISER2					((volatile uint32_t*) 0xE000E108)
#define NVIC_ISER3					((volatile uint32_t*) 0xE000E10C)

/*
 * ARM Cortex Mx Processor NVIC ICERx register Addresses
 */


#define NVIC_ICER0					((volatile uint32_t*) 0xE000E180)
#define NVIC_ICER1					((volatile uint32_t*) 0xE000E184)
#define NVIC_ICER2					((volatile uint32_t*) 0xE000E188)
#define NVIC_ICER3					((volatile uint32_t*) 0xE000E18C)

/*
 * ARM Cortex Mx Processor Priority Register Address Calculation
 */

#define NVIC_PR_BASE_ADDR ((volatile uint32_t*)0xE000E400)

#define NO_PR_BITS_IMPLEMENTED 		4

/*
 * Base Addresses of Flash and SRAM memories
 */


#define DRV_FLASH_BASEADDR 			0x00000000U		/*!<explain this macro briefly here */
#define DRV_SRAM1_BASEADDR			0x20000000U		/*!<explain this macro briefly here */
#define DRV_SRAM2_BASEADDR			0x2001C000U		/*!<explain this macro briefly here */
#define DRV_ROM						0x1FFF0000U		/*!<explain this macro briefly here */
#define DRV_OTP_AREA_BASEADDR		0X1FFF7800U		/*!<explain this macro briefly here */
#define DRV_SRAM					DRV_SRAM1_BASEADDR

/*AHBx & APBx peripheral bus definitions */
#define DRV_PERIPH_BASEADDR			0x40000000U		/*!<explain this macro briefly here */
#define DRV_APB1PERIPH_BASEADDR		PERIPH_BASEADDR	/*!<explain this macro briefly here */
#define DRV_APB2PERIPH_BASEADDR		0x40010000U		/*!<explain this macro briefly here */
#define DRV_AHB1PERIPH_BASEADDR		0x40020000U		/*!<explain this macro briefly here */
#define DRV_AHB2PERIPH_BASEADDR		0x50000000U		/*!<explain this macro briefly here */

/*AHB1 Peripheral Base Addresses */

#define DRV_GPIOA_BASEADDR			(DRV_AHB1PERIPH_BASEADDR + 0x0000U)
#define DRV_GPIOB_BASEADDR			(DRV_AHB1PERIPH_BASEADDR + 0x0400U)
#define DRV_GPIOC_BASEADDR			(DRV_AHB1PERIPH_BASEADDR + 0x0800U)
#define DRV_GPIOD_BASEADDR			(DRV_AHB1PERIPH_BASEADDR + 0x0C00U)
#define DRV_GPIOE_BASEADDR			(DRV_AHB1PERIPH_BASEADDR + 0x1000U)
#define DRV_GPIOF_BASEADDR			(DRV_AHB1PERIPH_BASEADDR + 0x1400U)
#define DRV_GPIOG_BASEADDR			(DRV_AHB1PERIPH_BASEADDR + 0x1800U)
#define DRV_GPIOH_BASEADDR			(DRV_AHB1PERIPH_BASEADDR + 0x1C00U)
#define DRV_GPIOI_BASEADDR			(DRV_AHB1PERIPH_BASEADDR + 0x2000U)
#define DRV_GPIOJ_BASEADDR			(DRV_AHB1PERIPH_BASEADDR + 0x2400U)
#define DRV_GPIOK_BASEADDR			(DRV_AHB1PERIPH_BASEADDR + 0x2800U)
#define DRV_CRC_BASEADDR			(DRV_AHB1PERIPH_BASEADDR + 0x3000U)
#define DRV_RCC_BASEADDR			(DRV_AHB1PERIPH_BASEADDR + 0x3800U)
#define DRV_FLASHINTREG_BASEADDR	(DRV_AHB1PERIPH_BASEADDR + 0x3C00U)
#define DRV_BKPSRAM_BASEADDR		(DRV_AHB1PERIPH_BASEADDR + 0x4000U)
#define DRV_DMA1_BASEADDR			(DRV_AHB1PERIPH_BASEADDR + 0x6000U)
#define DRV_DMA2_BASEADDR			(DRV_AHB1PERIPH_BASEADDR + 0x6400U)
#define DRV_ETHERNET_MAC_BASEADDR	(DRV_AHB1PERIPH_BASEADDR + 0x8000U)
#define DRV_DMA2D_BASEADDR			(DRV_AHB1PERIPH_BASEADDR + 0xB000U)
#define DRV_USB_OTG_HS_BASEADDR		(DRV_AHB1PERIPH_BASEADDR + 0x20000U)

/*AHB2 Peripheral Base Addresses */
#define DRV_USB_OTG_FS_BASEADDR		(DRV_AHB2PERIPH_BASEADDR + 0x0000U)
#define DRV_DCMI_BASEADDR			(DRV_AHB2PERIPH_BASEADDR + 0x50000U)
#define DRV_CRYP_BASEADDR			(DRV_AHB2PERIPH_BASEADDR + 0x60000U)
#define	DRV_HASH_BASEADDR			(DRV_AHB2PERIPH_BASEADDR + 0x60400U)
#define DRV_RNG_BASEADDR			(DRV_AHB2PERIPH_BASEADDR + 0x60800U)

/*APB1 Peripheral Base Addresses */
#define DRV_TIM2_BASEADDR			(DRV_APB1PERIPH_BASEADDR + 0x0000U)
#define DRV_TIM3_BASEADDR			(DRV_APB1PERIPH_BASEADDR + 0x0400U)
#define DRV_TIM4_BASEADDR			(DRV_APB1PERIPH_BASEADDR + 0x0800U)
#define DRV_TIM5_BASEADDR			(DRV_APB1PERIPH_BASEADDR + 0x0C00U)
#define DRV_TIM6_BASEADDR			(DRV_APB1PERIPH_BASEADDR + 0x1000U)
#define DRV_TIM7_BASEADDR			(DRV_APB1PERIPH_BASEADDR + 0x1400U)
#define DRV_TIM12_BASEADDR			(DRV_APB1PERIPH_BASEADDR + 0x1800U)
#define DRV_TIM13_BASEADDR			(DRV_APB1PERIPH_BASEADDR + 0x1C00U)
#define DRV_TIM14_BASEADDR			(DRV_APB1PERIPH_BASEADDR + 0x2000U)
#define DRV_RTC_BKP_BASEADDR		(DRV_APB1PERIPH_BASEADDR + 0x2800U)
#define DRV_WWDG_BASEADDR			(DRV_APB1PERIPH_BASEADDR + 0x2C00U)
#define DRV_IWDG_BASEADDR			(DRV_APB1PERIPH_BASEADDR + 0x3000U)
#define DRV_I2S2ext_BASEADDR		(DRV_APB1PERIPH_BASEADDR + 0x3400U)
#define DRV_SPI2_I2S2_BASEADDR		(DRV_APB1PERIPH_BASEADDR + 0x3800U)
#define DRV_SPI3_I2S3_BASEADDR		(DRV_APB1PERIPH_BASEADDR + 0x3C00U)
#define DRV_I2S3ext_BASEADDR		(DRV_APB1PERIPH_BASEADDR + 0x4000U)
#define DRV_USART2_BASEADDR			(DRV_APB1PERIPH_BASEADDR + 0x4400U)
#define DRV_USART3_BASEADDR			(DRV_APB1PERIPH_BASEADDR + 0x4800U)
#define DRV_UART4_BASEADDR			(DRV_APB1PERIPH_BASEADDR + 0x4C00U)
#define DRV_UART5_BASEADDR			(DRV_APB1PERIPH_BASEADDR + 0x5000U)
#define DRV_I2C1_BASEADDR			(DRV_APB1PERIPH_BASEADDR + 0x5400U)
#define DRV_I2C2_BASEADDR			(DRV_APB1PERIPH_BASEADDR + 0x5800U)
#define DRV_I2C3_BASEADDR			(DRV_APB1PERIPH_BASEADDR + 0x5C00U)
#define DRV_CAN1_BASEADDR			(DRV_APB1PERIPH_BASEADDR + 0x6400U)
#define DRV_CAN2_BASEADDR			(DRV_APB1PERIPH_BASEADDR + 0x6800U)
#define DRV_PWR_BASEADDR			(DRV_APB1PERIPH_BASEADDR + 0x7000U)
#define DRV_DAC_BASEADDR			(DRV_APB1PERIPH_BASEADDR + 0x7400U)
#define DRV_UART7_BASEADDR			(DRV_APB1PERIPH_BASEADDR + 0x7800U)
#define DRV_UART8_BASEADDR			(DRV_APB1PERIPH_BASEADDR + 0x7C00U)

/*APB2 Peripheral Base Addresses */
#define DRV_TIM1_BASEADDR			(DRV_APB2PERIPH_BASEADDR + 0x0000U)
#define DRV_TIM8_BASEADDR			(DRV_APB2PERIPH_BASEADDR + 0x0400U)
#define DRV_USART1_BASEADDR			(DRV_APB2PERIPH_BASEADDR + 0x1000U)
#define DRV_USART6_BASEADDR			(DRV_APB2PERIPH_BASEADDR + 0x1400U)
#define DRV_ADC1_BASEADDR			(DRV_APB2PERIPH_BASEADDR + 0x2000U)
#define DRV_ADC2_BASEADDR			(DRV_APB2PERIPH_BASEADDR + 0x2000U)
#define DRV_ADC3_BASEADDR			(DRV_APB2PERIPH_BASEADDR + 0x2000U)
#define DRV_SDIO_BASEADDR			(DRV_APB2PERIPH_BASEADDR + 0x2C00U)
#define DRV_SPI1_BASEADDR			(DRV_APB2PERIPH_BASEADDR + 0x3000U)
#define DRV_SPI4_BASEADDR			(DRV_APB2PERIPH_BASEADDR + 0x3400U)
#define DRV_SYSCFG_BASEADDR			(DRV_APB2PERIPH_BASEADDR + 0x3800U)
#define DRV_EXTI_BASEADDR			(DRV_APB2PERIPH_BASEADDR + 0x3C00U)
#define DRV_TIM9_BASEADDR			(DRV_APB2PERIPH_BASEADDR + 0x4000U)
#define DRV_TIM10_BASEADDR			(DRV_APB2PERIPH_BASEADDR + 0x4400U)
#define DRV_TIM11_BASEADDR			(DRV_APB2PERIPH_BASEADDR + 0x4800U)
#define DRV_SPI5_BASEADDR			(DRV_APB2PERIPH_BASEADDR + 0x5000U)
#define DRV_SPI6_BASEADDR			(DRV_APB2PERIPH_BASEADDR + 0x5400U)
#define DRV_SAI1_BASEADDR			(DRV_APB2PERIPH_BASEADDR + 0x5800U)
#define DRV_LCD_TFT_BASEADDR		(DRV_APB2PERIPH_BASEADDR + 0x6800U)

/* Note: registers of a peripheral are specific to MCU
 * e.g.: Number of registers of SPI peripheral of STM32F4X family of MCUS may be different
 * Compared to number of registers of SPI peripheral of STM32Lx orSTM32F0x family of MCUs
 * Please check your Device RM
 */

/* Structure Section */

/*
 * Peripheral register definition structure for GPIO
 */

typedef struct{
	volatile uint32_t MODER;					/*GPIO port mode register  							Address Offset: 0x00 */
	volatile uint32_t OTYPER;					/*GPIO port output type register  					Address Offset: 0x04 */
	volatile uint32_t OSPEEDR;					/*GPIO port output speed register  					Address Offset: 0x08 */
	volatile uint32_t PUPDR;					/*GPIO port pull-up/pull-down register  			Address Offset: 0x0C */
	volatile uint32_t IDR;						/*GPIO port input data register  					Address Offset: 0x10 */
	volatile uint32_t ODR;						/*GPIO port output data register 					Address Offset: 0x14 */
	volatile uint32_t BSRR;						/*GPIO port bit set/reset register  				Address Offset: 0x18 */
	volatile uint32_t LCKR;						/*GPIO port configuration lock register  			Address Offset: 0x1C */
	volatile uint32_t AFR[2];					/*GPIO alternate function registers [0:LOW/1:HIGH]  Address Offset: 0x20/24 */
}GPIO_RegDef_t;

/*
 * Peripheral register definition structure for RCC
 */

typedef struct{
	volatile uint32_t CR;						/*clock control register			  						Offset: 0x00*/
	volatile uint32_t PLLCFGR;					/*PLL configuration register 								Offset: 0x04*/
	volatile uint32_t CFGR;						/*clock configuration register  							Offset: 0x08*/
	volatile uint32_t CIR;						/*clock interrupt register  								Offset: 0x0C*/
	volatile uint32_t AHB1RSTR;					/*AHB1 peripheral reset register  							Offset: 0x10*/
	volatile uint32_t AHB2RSTR;					/*AHB2 peripheral reset register  							Offset: 0x14*/
	volatile uint32_t AHB3RSTR;					/*AHB3 peripheral reset register  							Offset: 0x18*/
	uint32_t RESERVED0;
	volatile uint32_t APB1RSTR;					/*APB1 peripheral reset register  							Offset: 0x20*/
	volatile uint32_t APB2RSTR;					/*APB2 peripheral reset register  							Offset: 0X24*/
	uint32_t RESERVED1[2];
	volatile uint32_t AHB1ENR;					/*AHB1 peripheral clock enable register  					Offset: 0x30*/
	volatile uint32_t AHB2ENR;					/*AHB2 peripheral clock enable register  					Offset: 0x34*/
	volatile uint32_t AHB3ENR;					/*AHB3 peripheral clock enable register  					Offset: 0x38*/
	uint32_t RESERVED2;
	volatile uint32_t APB1ENR;					/*APB2 peripheral clock enable register  					Offset: 0x40*/
	volatile uint32_t APB2ENR;					/*APB2 peripheral clock enable register  				  	Offset: 0x44*/
	uint32_t RESERVED3 [2];
	volatile uint32_t AHB1LPENR;				/*AHB1 peripheral clock enable in low power mode register  	Offset: 0x50*/
	volatile uint32_t AHB2LPENR;				/*AHB2 peripheral clock enable in low power mode register  	Offset: 0x54*/
	volatile uint32_t AHB3LPENR;				/*AHB3 peripheral clock enable in low power mode register  	Offset: 0x58*/
	uint32_t RESERVED4;
	volatile uint32_t APB1LPENR;				/*APB1 peripheral clock enable in low power mode register  	Offset: 0x60*/
	volatile uint32_t APB2LPENR;				/*APB2 peripheral clock enabled in low power mode register 	Offset: 0x64*/
	uint32_t RESERVED5 [2];
	volatile uint32_t BDCR;						/*RCC Backup domain control register  						Offset: 0x70*/
	volatile uint32_t CSR;						/*RCC clock control & status register  						Offset: 0x74*/
	uint32_t RESERVED6 [2];
	volatile uint32_t SSCGR;					/*RCC spread spectrum clock generation register  			Offset: 0x80*/
	volatile uint32_t PLLI2SCFGR;				/*RCC PLLI2S configuration register 					 	Offset: 0x84*/
}RCC_RegDef_t;

/*
 * Peripheral register definition structure for EXTI
 */

typedef struct{
	volatile uint32_t IMR;					/*GPIO port mode register  							Address Offset: 0x00 */
	volatile uint32_t EMR;					/*GPIO port output type register  					Address Offset: 0x04 */
	volatile uint32_t RTSR;					/*GPIO port output speed register  					Address Offset: 0x08 */
	volatile uint32_t FTSR;					/*GPIO port pull-up/pull-down register  			Address Offset: 0x0C */
	volatile uint32_t SWIER;				/*GPIO port input data register  					Address Offset: 0x10 */
	volatile uint32_t PR;					/*GPIO port output data register 					Address Offset: 0x14 */
}EXTI_RegDef_t;


/*
 * Peripheral register definition structure for SYSCFG
 */

typedef struct{
	volatile uint32_t MEMRMP;				/*SYSCFG memory re-map register						Address Offset: 0x00 */
	volatile uint32_t PMC;					/*peripheral mode configuration register  			Address Offset: 0x04 */
	volatile uint32_t EXTICR[4];			/*external interrupt configuration register 1[0]  	Address Offset: 0x08 */
											/*external interrupt configuration register 2  		Address Offset: 0x0C */
											/*external interrupt configuration register 3  		Address Offset: 0x10 */
											/*external interrupt configuration register 4[3] 	Address Offset: 0x14 */
	uint32_t RESRVED1[2];
	volatile uint32_t CMPCR;				/*Compensation cell control register				Address Offset: 0x20 */
	uint32_t RESERVED2[2];
	volatile uint32_t CFGR;					/*													Address Offset: 0x2C */
}SYSCFG_RegDef_t;


/*
 * Peripheral definitions (Peripheral base addresses typecast to xxx_RegDef_t)
 */
#define GPIOA		((GPIO_RegDef_t*)DRV_GPIOA_BASEADDR)
#define GPIOB		((GPIO_RegDef_t*)DRV_GPIOB_BASEADDR)
#define GPIOC		((GPIO_RegDef_t*)DRV_GPIOC_BASEADDR)
#define GPIOD		((GPIO_RegDef_t*)DRV_GPIOD_BASEADDR)
#define GPIOE		((GPIO_RegDef_t*)DRV_GPIOE_BASEADDR)
#define GPIOF		((GPIO_RegDef_t*)DRV_GPIOF_BASEADDR)
#define GPIOG		((GPIO_RegDef_t*)DRV_GPIOG_BASEADDR)
#define GPIOH		((GPIO_RegDef_t*)DRV_GPIOH_BASEADDR)
#define GPIOI		((GPIO_RegDef_t*)DRV_GPIOI_BASEADDR)

#define RCC 		((RCC_RegDef_t*)DRV_RCC_BASEADDR)

#define EXTI		((EXTI_RegDef_t*)DRV_EXTI_BASEADDR)

#define SYSCFG		((SYSCFG_RegDef_t*)DRV_SYSCFG_BASEADDR)
/*
 * Clock Enable Macros for GPIOx peripherals
 */

#define GPIOA_PCLK_EN()	( RCC->AHB1ENR |= (1 << 0) )
#define GPIOB_PCLK_EN()	( RCC->AHB1ENR |= (1 << 1) )
#define GPIOC_PCLK_EN()	( RCC->AHB1ENR |= (1 << 2) )
#define GPIOD_PCLK_EN()	( RCC->AHB1ENR |= (1 << 3) )
#define GPIOE_PCLK_EN()	( RCC->AHB1ENR |= (1 << 4) )
#define GPIOF_PCLK_EN()	( RCC->AHB1ENR |= (1 << 5) )
#define GPIOG_PCLK_EN()	( RCC->AHB1ENR |= (1 << 6) )
#define GPIOH_PCLK_EN()	( RCC->AHB1ENR |= (1 << 7) )
#define GPIOI_PCLK_EN()	( RCC->AHB1ENR |= (1 << 8) )


/*
 * Clock Enable Macros for I2Cx peripherals
 */

#define I2C1_PLCK_EN()	( RCC->APB1ENR |= (1 << 21))
#define I2C2_PLCK_EN()	( RCC->APB1ENR |= (1 << 22))
#define I2C3_PLCK_EN()	( RCC->APB1ENR |= (1 << 23))

/*
 * Clock Enable Macros for SPIx peripherals
 */

#define SPI1_PCLK_EN() ( RCC->APB2ENR |= (1 << 12))
#define SPI2_PCLK_EN() ( RCC->APB1ENR |= (1 << 14))
#define SPI3_PCLK_EN() ( RCC->APB1ENR |= (1 << 15))

/*
 * Clock Enable Macros for USARTx/UARTx peripherals
 */
#define USART1_PCLK_EN() ( RCC->APB2ENR |= (1 << 4))
#define USART2_PCLK_EN() ( RCC->APB1ENR |= (1 << 17))
#define USART3_PCLK_EN() ( RCC->APB1ENR |= (1 << 18))
#define UART4_PCLK_EN()  ( RCC->APB1ENR |= (1 << 19))
#define UART5_PCLK_EN()  ( RCC->APB1ENR |= (1 << 20))
#define USART6_PCLK_EN() ( RCC->APB2ENR |= (1 << 5))


/*
 * Clock Enable Macros for SYSCFG peripherals
 */

#define SYSCFG_PCLK_EN() ( RCC->APB2ENR |= (1 << 14))

/*
 * Clock Disable Macros for GPIOx peripherals
 */

#define GPIOA_PCLK_DI()	( RCC->AHB1ENR &= ~(1 << 0) )
#define GPIOB_PCLK_DI()	( RCC->AHB1ENR &= ~(1 << 1) )
#define GPIOC_PCLK_DI()	( RCC->AHB1ENR &= ~(1 << 2) )
#define GPIOD_PCLK_DI()	( RCC->AHB1ENR &= ~(1 << 3) )
#define GPIOE_PCLK_DI()	( RCC->AHB1ENR &= ~(1 << 4) )
#define GPIOF_PCLK_DI()	( RCC->AHB1ENR &= ~(1 << 5) )
#define GPIOG_PCLK_DI()	( RCC->AHB1ENR &= ~(1 << 6) )
#define GPIOH_PCLK_DI()	( RCC->AHB1ENR &= ~(1 << 7) )
#define GPIOI_PCLK_DI()	( RCC->AHB1ENR &= ~(1 << 8) )

/*
 * Macros to reset GPIO peripherals
 */

#define GPIOA_REG_RESET()	do{( RCC->AHB1RSTR |= (1 << 0) ); (RCC->AHB1RSTR &= ~(1 << 0)); }while(0) //c coding idiom that allows several line macro to execute exactly once
#define GPIOB_REG_RESET()	do{( RCC->AHB1RSTR |= (1 << 1) ); (RCC->AHB1RSTR &= ~(1 << 1)); }while(0)
#define GPIOC_REG_RESET()	do{( RCC->AHB1RSTR |= (1 << 2) ); (RCC->AHB1RSTR &= ~(1 << 2)); }while(0)
#define GPIOD_REG_RESET()	do{( RCC->AHB1RSTR |= (1 << 3) ); (RCC->AHB1RSTR &= ~(1 << 3)); }while(0)
#define GPIOE_REG_RESET()	do{( RCC->AHB1RSTR |= (1 << 4) ); (RCC->AHB1RSTR &= ~(1 << 4)); }while(0)
#define GPIOF_REG_RESET()	do{( RCC->AHB1RSTR |= (1 << 5) ); (RCC->AHB1RSTR &= ~(1 << 5)); }while(0)
#define GPIOG_REG_RESET()	do{( RCC->AHB1RSTR |= (1 << 6) ); (RCC->AHB1RSTR &= ~(1 << 6)); }while(0)
#define GPIOH_REG_RESET()	do{( RCC->AHB1RSTR |= (1 << 7) ); (RCC->AHB1RSTR &= ~(1 << 7)); }while(0)
#define GPIOI_REG_RESET()	do{( RCC->AHB1RSTR |= (1 << 8) ); (RCC->AHB1RSTR &= ~(1 << 8)); }while(0)


/*
 * Clock Disable Macros for I2Cx peripherals
 */

#define I2C1_PLCK_DI()	( RCC->APB1ENR &= ~(1 << 21))
#define I2C2_PLCK_DI()	( RCC->APB1ENR &= ~(1 << 22))
#define I2C3_PLCK_DI()	( RCC->APB1ENR &= ~(1 << 23))

/*
 * Clock Disable Macros for SPIx peripherals
 */

#define SPI1_PCLK_DI() ( RCC->APB2ENR &= ~(1 << 12))
#define SPI2_PCLK_DI() ( RCC->APB1ENR &= ~(1 << 14))
#define SPI3_PCLK_DI() ( RCC->APB1ENR &= ~(1 << 15))


/*
 * Clock Disable Macros for USARTx peripherals
 */

#define USART1_PCLK_DI() ( RCC->APB2ENR &= ~(1 << 4))
#define USART2_PCLK_DI() ( RCC->APB1ENR &= ~(1 << 17))
#define USART3_PCLK_DI() ( RCC->APB1ENR &= ~(1 << 18))
#define UART4_PCLK_DI()  ( RCC->APB1ENR &= ~(1 << 19))
#define UART5_PCLK_DI()  ( RCC->APB1ENR &= ~(1 << 20))
#define USART6_PCLK_DI() ( RCC->APB2ENR &= ~(1 << 5))

/*
 * Clock Disable Macros for SYSCFG peripherals
 */

#define SYSCFG_PCLK_DI() ( RCC->APB2ENR &= ~(1 << 14))

/*
 *	GPIO Base to corresponding digit (0, 1, 2, etc)
 */

#define GPIO_BASEADDR_TO_CODE(x)	((x == GPIOA) ? 0 :\
									(x == GPIOB) ? 1 :\
									(x == GPIOC) ? 2 :\
									(x == GPIOD) ? 3 :\
									(x == GPIOE) ? 4 :\
									(x == GPIOF) ? 5 :\
									(x == GPIOG) ? 6 :\
									(x == GPIOH) ? 7 :0)


/*
 * 	IRQ(Interrupt Request) Numbers of STM32F407X MCU
 * 	NOTE: update these macros with validvalues according to your MCU
 * 	TODO: You may complete this list for other peripherals
 */

#define IRQ_NO_EXTI0		6
#define IRQ_NO_EXTI1		7
#define IRQ_NO_EXTI2		8
#define IRQ_NO_EXTI3		9
#define IRQ_NO_EXTI4		10
#define IRQ_NO_EXTI9_5		23
#define IRQ_NO_EXTI15_10	40

/*
 * 	IRQ Priority Values of STM32F407X MCU
 */

#define NVIC_IRQ_PRIO_0		0
#define NVIC_IRQ_PRIO_1		1
#define NVIC_IRQ_PRIO_2		2
#define NVIC_IRQ_PRIO_3		3
#define NVIC_IRQ_PRIO_4		4
#define NVIC_IRQ_PRIO_5		5
#define NVIC_IRQ_PRIO_6		6
#define NVIC_IRQ_PRIO_7		7
#define NVIC_IRQ_PRIO_8		8
#define NVIC_IRQ_PRIO_9		9
#define NVIC_IRQ_PRIO_10	10
#define NVIC_IRQ_PRIO_11	11
#define NVIC_IRQ_PRIO_12	12
#define NVIC_IRQ_PRIO_13	13
#define NVIC_IRQ_PRIO_14	14
#define NVIC_IRQ_PRIO_15	15


/*
 * Generic Macros
 */

#define ENABLE 			1
#define DISABLE 		0
#define SET 			ENABLE
#define RESET			DISABLE
#define GPIO_PIN_SET	SET
#define GPIO_PIN_RESET	RESET


#endif /* INC_STM32F407XX_H_ */
