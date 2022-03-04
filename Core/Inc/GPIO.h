/*
 * GPIO.h
 *
 *  Created on: Feb 12, 2022
 *      Author: vitor
 */

#ifndef GPIO_H_
#define GPIO_H_


#include "stm32f4xx_hal.h"
#include "cmsis_os.h"


class GPIO {
private:
	GPIO_TypeDef *port;
	uint16_t pin;
public:
	GPIO(GPIO_TypeDef * port_address, uint16_t pin_address);
	void write(GPIO_PinState state);
	bool read();
	void toogle(uint32_t time_hight, uint32_t time_low);
	void toogle();


};

#endif /* GPIO_H_ */
