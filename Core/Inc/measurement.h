/*
 * DWT.h
 *
 *  Created on: 13 de fev de 2022
 *      Author: vitor
 */

#ifndef INC_MEASUREMENT_H_
#define INC_MEASUREMENT_H_
//#include "core_cm4.h"
#include "stm32f4xx_hal.h"

#define MEASUREMENT_MAX_SAMPLES 10


//uint32_t dwt_ctrl = 0; /* bit mask for DWT->CTRL */

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

class measurement
{
private:
    DATA measurements[MEASUREMENT_MAX_SAMPLES];
    DATA avg;
    uint8_t position;

public:
    void store_result();
    void compute_statistics();
    void set_position(uint8_t position);
};

void init_dwt();
#endif /* INC_MEASUREMENT_H_ */
