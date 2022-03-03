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
}

void dwt::start(){
	DWT->CTRL |= dwt_ctrl;
}
void dwt::stop(){
	DWT->CTRL &= ~dwt_ctrl;

}
