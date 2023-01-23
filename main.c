/*********************************************************************
*                    SEGGER Microcontroller GmbH                     *
*                        The Embedded Experts                        *
**********************************************************************

-------------------------- END-OF-HEADER -----------------------------

File    : main.c
Purpose : Generic application start

*/

#include <nrf.h>
#include <hal/nrf_gpio.h>
#include "FreeRTOS.h"
#include "task.h"
#include <stdlib.h>
#include <stdio.h>


#define Button_2 12
#define Button_4 25
#define LED_2 14
#define LED_4 16


int main(void) {
 

 nrf_gpio_cfg_output(LED_2);
 nrf_gpio_cfg_output(LED_4);
 nrf_gpio_cfg_input(Button_2, NRF_GPIO_PIN_PULLUP);
 nrf_gpio_cfg_input(Button_4, NRF_GPIO_PIN_PULLUP);


 nrf_gpio_pin_set(LED_2);
 nrf_gpio_pin_set(LED_4);

while(1)
{




if(nrf_gpio_pin_read(Button_2) == 0)
nrf_gpio_pin_clear(LED_2); 

else
nrf_gpio_pin_set(LED_2);


if(nrf_gpio_pin_read(Button_4) == 0)
nrf_gpio_pin_clear(LED_4); 

else
nrf_gpio_pin_set(LED_4);




}


  }

  /*************************** End of file ****************************/
