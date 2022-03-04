/*
 * GPIO.cpp
 *
 *  Created on: Feb 12, 2022
 *      Author: vitor
 */

#include "GPIO.h"


GPIO::GPIO(GPIO_TypeDef *port_address, uint16_t pin_address) :port(port_address), pin(pin_address) {}

void GPIO::write(GPIO_PinState state) {
	/*Escre em um pino de GPIO*/
	HAL_GPIO_WritePin(this->port, this->pin, state);
}

bool GPIO::read() {
	/*Le os dados de uma GPIO*/
	return (bool) HAL_GPIO_ReadPin(this->port, this->pin);
}

void GPIO::toogle(uint32_t time_hight, uint32_t time_low) {
	/*Faz com que um pino fique oscilando entre alto e baixo, por padrão essa isso acontece a cada 1s*/
	HAL_GPIO_WritePin(this->port, this->pin, GPIO_PIN_SET);
	osDelay(time_hight);
	HAL_GPIO_WritePin(this->port, this->pin, GPIO_PIN_RESET);
	osDelay(time_low);
}

void GPIO::toogle() {
	/*Faz com que um pino fique oscilando entre alto e baixo, por padrão essa isso acontece a cada 1s*/
	const uint32_t time_hight = 1000;
	const uint32_t time_low = 1000;

	HAL_GPIO_WritePin(this->port, this->pin, GPIO_PIN_SET);
	osDelay(time_hight);
	HAL_GPIO_WritePin(this->port, this->pin, GPIO_PIN_RESET);
	osDelay(time_low);
}

