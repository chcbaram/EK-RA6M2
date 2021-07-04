/*
 * ap.c
 *
 *  Created on: 2021. 7. 4.
 *      Author: baram
 */


#include "ap.h"





void apInit(void)
{
}

void apMain(void)
{

  while(1)
  {
    ledToggle(_DEF_LED1);
    delay(500);
  }
}
