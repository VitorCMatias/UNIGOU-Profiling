/*
 * DWT.h
 *
 *  Created on: 14 de fev de 2022
 *      Author: vitor
 */

#ifndef DWT_H_
#define DWT_H_
#include "stm32f4xx_hal.h"

/*
 *
 * 	#define start_dwt() DWT->CTRL |= dwt_ctrl
 *	#define stop_dwt() DWT->CTRL &= ~dwt_ctrl
 *
 */
#define MEASUREMENT_MAX_SAMPLES 10
struct data
{
    uint32_t cycles;
    uint32_t sleep_cycles;
    uint32_t exception_cycles;

    uint32_t lsu_cycles;
    uint32_t fold_counter;
    uint32_t cpi_cycles;
};
typedef struct data DATA;

class dwt {
private:
    uint32_t dwt_ctrl = 0; /* bit mask for DWT->CTRL */

    DATA measurements[MEASUREMENT_MAX_SAMPLES];
    DATA avg;
    uint8_t position;
public:
	dwt();
	void start();
	void stop();

    void store_result();
    void compute_statistics();
    void set_position(uint8_t position);
};

#endif /* DWT_H_ */
