/*
 * bsp.h
 *
 *  Created on: 2021. 7. 4.
 *      Author: baram
 */

#ifndef SRC_BSP_BSP_H_
#define SRC_BSP_BSP_H_

#include "def.h"


#include "hal_data.h"


bool bspInit(void);

void delay(uint32_t time_ms);
uint32_t millis(void);

void logPrintf(const char *fmt, ...);

#endif /* SRC_BSP_BSP_H_ */
