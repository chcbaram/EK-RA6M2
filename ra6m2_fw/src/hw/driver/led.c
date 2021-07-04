/*
 * led.c
 *
 *  Created on: 2021. 7. 4.
 *      Author: baram
 */


#include "led.h"


#ifdef _USE_HW_LED



typedef struct
{
  bsp_io_port_pin_t pin;
  bsp_io_level_t    on_state;
  bsp_io_level_t    off_state;
} led_tbl_t;



static const led_tbl_t led_tbl[LED_MAX_CH] =
    {
        {BSP_IO_PORT_01_PIN_06, BSP_IO_LEVEL_HIGH, BSP_IO_LEVEL_LOW},
    };





bool ledInit(void)
{

  for (int i=0; i<LED_MAX_CH; i++)
  {
    ledOff(i);
  }

  return true;
}

void ledOn(uint8_t ch)
{
  if (ch >= LED_MAX_CH) return;

  g_ioport.p_api->pinWrite(g_ioport.p_ctrl, led_tbl[ch].pin, led_tbl[ch].on_state);
}

void ledOff(uint8_t ch)
{
  if (ch >= LED_MAX_CH) return;

  g_ioport.p_api->pinWrite(g_ioport.p_ctrl, led_tbl[ch].pin, led_tbl[ch].off_state);
}

void ledToggle(uint8_t ch)
{
  if (ch >= LED_MAX_CH) return;

  bsp_io_level_t pin_value;

  g_ioport.p_api->pinRead(g_ioport.p_ctrl, led_tbl[ch].pin, &pin_value);

  if (pin_value == led_tbl[ch].on_state)
  {
    ledOff(ch);
  }
  else
  {
    ledOn(ch);
  }
}

#endif
