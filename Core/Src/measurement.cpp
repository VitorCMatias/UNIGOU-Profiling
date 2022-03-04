/*
 * DWT.cpp
 *
 *  Created on: 13 de fev de 2022
 *      Author: vitor
 */

#include "measurement.h"
/*
void measurement::set_position(uint8_t position)
{
    this->position = position;
}
void measurement::store_result()
{
    this->measurements[this->position].cycles = DWT->CYCCNT;
    this->measurements[this->position].sleep_cycles = DWT->SLEEPCNT;
    this->measurements[this->position].exception_cycles = DWT->EXCCNT;

    this->measurements[this->position].lsu_cycles = DWT->LSUCNT;
    this->measurements[this->position].fold_counter = DWT->FOLDCNT;
    this->measurements[this->position].cpi_cycles = DWT->CPICNT;

    this->position++;
}

void measurement::compute_statistics()
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
*/
