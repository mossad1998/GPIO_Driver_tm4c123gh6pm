#include "tm4c123gh6pm.h"
#include "GPIO_Driver.h"

//Example of using GPIO_Driver

/* This driver uses the GPIO_Driver library which provides definitions for
   different functions that help to intialize Tiva c  peripherals.
   To use this driver you will also need to use tm4c123gh6pm to map 
   registers correctly.
   this example toggle a led from port f every 1ms.
   Used pins
   ===========
   Pin F1 as digital output

   History
   =======
   2021/August/07  - First release (Mosad)
   mo.eldibani@gmail.com
*/


bool data;
void delayMs(int n);

void main()
{
  
      //Intializations for pins
      CLK_Enable('F');
  
      GPIO_PORT_UNLOCK('F');
  
      PIN_ANALOG_DIGITAL('F',1,"Digital");
  
      PIN_FUNCTION_SELECT('F',1,"General I/O");
  
      PIN_INPUT_OUTPUT('F',1,"Output");
  
      while(1)
      {
            PIN_WRITE_DIGITAL('F',1,"HIGH");                                     //To turn the led On
            delayMs(1);
            PIN_WRITE_DIGITAL('F',1,"LOW");                                      //To turn the led Off
            delayMs(1);
      }
}

void delayMs(int n)                                                              //Do nothing for 1 ms
{
  int i, j;
  for(i = 0 ; i < n; i++)
  for(j = 0; j < 3180; j++)
  {}
}
