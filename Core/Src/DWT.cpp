/*
 * DWT.cpp
 *
 *  Created on: 14 de fev de 2022
 *      Author: vitor
 */

#include "DWT.h"

dwt::dwt()
{
    // TODO Auto-generated constructor stub
    CoreDebug->DEMCR |= DWT_CTRL_EXCTRCENA_Msk; /* enable DWT hardware */

    DWT->CTRL = 0;     /* reset control register */
    DWT->CYCCNT = 0;   /* reset cpu cycle counter register */
    DWT->EXCCNT = 0;   /* reset exception cycle counter register */
    DWT->SLEEPCNT = 0; /* reset sleep cycle counter register */

    DWT->LSUCNT = 0;  /* reset load store counter register */
    DWT->FOLDCNT = 0; /* reset instruction fold counter register */
    DWT->CPICNT = 0;  /* reset cpi counter register */

    dwt_ctrl |= DWT_CTRL_CYCCNTENA_Msk;
    dwt_ctrl |= DWT_CTRL_SLEEPEVTENA_Msk;
    dwt_ctrl |= DWT_CTRL_EXCEVTENA_Msk;

    dwt_ctrl |= DWT_CTRL_LSUEVTENA_Msk;
    dwt_ctrl |= DWT_CTRL_FOLDEVTENA_Msk;
    dwt_ctrl |= DWT_CTRL_CPIEVTENA_Msk;

    this->position = 0;
}

void dwt::start(){
	DWT->CTRL |= dwt_ctrl;
}
void dwt::stop(){
	DWT->CTRL &= ~dwt_ctrl;

}


void dwt::set_position(uint8_t position)
{
    this->position = position;
}
void dwt::store_result()
{
    this->measurements[this->position].cycles = DWT->CYCCNT;
    this->measurements[this->position].sleep_cycles = DWT->SLEEPCNT;
    this->measurements[this->position].exception_cycles = DWT->EXCCNT;

    this->measurements[this->position].lsu_cycles = DWT->LSUCNT;
    this->measurements[this->position].fold_counter = DWT->FOLDCNT;
    this->measurements[this->position].cpi_cycles = DWT->CPICNT;

    this->position++;
}

void dwt::compute_statistics()
{
    for (int position = 0; position < MEASUREMENT_MAX_SAMPLES; position++)
    {
        this->avg.cycles += this->measurements[position].cycles;
        this->avg.sleep_cycles += this->measurements[position].sleep_cycles;
        this->avg.exception_cycles += this->measurements[position].exception_cycles;

        this->avg.lsu_cycles += this->measurements[position].lsu_cycles;
        this->avg.fold_counter += this->measurements[position].fold_counter;
        this->avg.cpi_cycles += this->measurements[position].cpi_cycles;
    }

    this->avg.cycles /= MEASUREMENT_MAX_SAMPLES;
    this->avg.sleep_cycles /= MEASUREMENT_MAX_SAMPLES;
    this->avg.exception_cycles /= MEASUREMENT_MAX_SAMPLES;

    this->avg.lsu_cycles /= MEASUREMENT_MAX_SAMPLES;
    this->avg.fold_counter /= MEASUREMENT_MAX_SAMPLES;
    this->avg.cpi_cycles /= MEASUREMENT_MAX_SAMPLES;
}
