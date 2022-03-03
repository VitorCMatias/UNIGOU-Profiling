/*
 * DWT.h
 *
 *  Created on: 14 de fev de 2022
 *      Author: vitor
 */

#ifndef DWT_H_
#define DWT_H_
#include "stm32f4xx_hal.h"

/*#define start_dwt() DWT->CTRL |= dwt_ctrl
#define stop_dwt() DWT->CTRL &= ~dwt_ctrl*/


class dwt {
private:
    uint32_t dwt_ctrl = 0; /* bit mask for DWT->CTRL */
public:
	dwt();
	void start();
	void stop();
};

#endif /* DWT_H_ */
