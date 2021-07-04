/*
 * hw.c
 *
 *  Created on: 2021. 7. 4.
 *      Author: baram
 */


#include "hw.h"





bool hwInit(void)
{
  bspInit();


  ledInit();


  return true;
}
