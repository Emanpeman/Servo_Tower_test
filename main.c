/*********************************************************************
*                    SEGGER Microcontroller GmbH                     *
*                        The Embedded Experts                        *
**********************************************************************

-------------------------- END-OF-HEADER -----------------------------

File    : main.c
Purpose : Generic application start

*/

#define BOARD_PCA10056

#include <nrf.h>
#include <hal/nrf_gpio.h>
#include "FreeRTOS.h"
#include "task.h"
//#include "boards.h"
#include <stdlib.h>
#include <stdio.h>

#define LED_2 14
#define LED_4 16


void blinky_led4(void * pvParameters);
void blinky_led2(void * pvParameters);

void blinky_led2(void * pvParameters)
{ 
  nrf_gpio_cfg_output(LED_2);
  while(true)
  {
  
    //nrf_gpio_pin_toggle(LED_2);
    nrf_gpio_pin_set(LED_2);
    //vTaskDelay(200);

  }
}

void blinky_led4(void * pvParameters)
{ 

  while(true)
  {
    
    nrf_gpio_pin_toggle(LED_4);
    //vTaskDelay(1);
  }
}
 
int main(void) {
  BaseType_t x = 0;
  int k;
 
  x = xTaskCreate(blinky_led2, "blink_2", configMINIMAL_STACK_SIZE, NULL, 0, NULL);

//xTaskCreate(blinky_led4, "LED4", 4094, NULL, 5, NULL);
switch (x) {
case pdPASS:
  k = 1;
  break;
case pdFAIL:
  k = 1;
case errCOULD_NOT_ALLOCATE_REQUIRED_MEMORY:
  k = 1;
  break;
}

  vTaskStartScheduler();


  while (true) {
  }
 
 }

  /*************************** End of file ****************************/
