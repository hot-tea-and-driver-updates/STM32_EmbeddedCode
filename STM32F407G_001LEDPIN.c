/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Jordi Hernandez
 * @brief          : Main program body - turns on PIN & LED to read input and change LED STATE
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
#include <stdio.h>
#include <stdint.h>


int main(void)
{
	//0.A Creating variables to hold the memory addresses + their appropiate offsets
	uint32_t *pclockcontrolregister = (uint32_t *) 0x40023830; //RCC base address + offset;
	uint32_t *pPortDModeReg = (uint32_t *) 0x40020C00; //GPIOD base address + offset;
	uint32_t *pPortDOutReg = (uint32_t *) 0x40020C14; // GPIOD base address + offset;
	//0.B
	uint32_t *pPortAModeReg = (uint32_t *) 0x40020000; //GPIOA base address + offset;
	uint32_t *pPortAInReg = (uint32_t *) 0x40020010;  //GPIOA base address + offset;

	//time to start setting up bits
	//1. lets enable the clock for GPIOD, GPIOA peripherals in the AHB1ENR

	*pclockcontrolregister |= (1<<3); //enables port D
	*pclockcontrolregister |= (1<<0); //enables port A

	//2. configure the mode  of the IO pin as output
	//a. enabling PD12 as output
	//clear the 24th and 25th bit positions (look at respective subsections)
	*pPortDModeReg &= ~(3 << 24); //remember, 3 = 11 in binary! we can use this instead

	//make 24th bit position as 1 (SET)-PortD to set pin 12 as output
	*pPortDModeReg |= (1 << 24);

	//.b enabling PA0 as input
	*pPortAModeReg &= ~(3 << 0);

	//c. READ the pin status of the pin PA0 (GPIO INPUT DATA REGISTER)
	//since we only want the first bit of data we can mask to clear the remaining bits
	uint8_t pinStatus = (uint8_t) (*pPortAInReg & 0x1);

	if(pinStatus){
		//turn on LED by SETTING 12th bit of the output data register to make the I/O pin-12 HIGH
		*pPortDOutReg |= (1 << 12);
	}else{
		//turn off LED by SETTING 12th bit of the output data register to make the I/O pin-12 LOW
		*pPortDOutReg &= ~(1 << 12); //use & bit mask to CLEAR the value; (~(1 << 12)) is the bit mask
	}
	while(1);
}
