/*
 * bsp.c
 *
 *  Created on: 2021. 7. 4.
 *      Author: baram
 */


#include "bsp.h"


volatile uint32_t systick_ms = 0;




void SysTick_Handler(void)
{
  systick_ms++;
}


bool bspInit(void)
{


  SysTick_Config(SystemCoreClock / 1000); // 1ms

  return true;
}

void delay(uint32_t time_ms)
{
  uint32_t pre_time = systick_ms;

  while(systick_ms-pre_time < time_ms);
}

uint32_t millis(void)
{
  return systick_ms;
}

