#include "tm4c123gh6pm.h"
#include "GPIO_Driver.h"

//Example of using GPIO_Driver

/* This driver uses the GPIO_Driver library which provides definitions for
   different functions that help to intialize Tiva c  peripherals.
   To use this driver you will also need to use tm4c123gh6pm to map 
   registers correctly.
   this example create polling on a switch on a port F to read data from it.
   depending on this piece of data a led will switch on or off.
   Used pins
   ===========
   Pin F0 as digital input
   Pin F1 as digital output

   History
   =======
   2021/August/07  - First release (Mosad)
*/


bool data;

void main()
{
      //Intializations for pins
      CLK_Enable('F');
  
      GPIO_PORT_UNLOCK('F');
  
      PIN_ANALOG_DIGITAL('F',0,"Digital");
      PIN_ANALOG_DIGITAL('F',1,"Digital");
  
      PIN_FUNCTION_SELECT('F',0,"General I/O");
      PIN_FUNCTION_SELECT('F',1,"General I/O");
  
      PIN_INPUT_OUTPUT('F',0,"Input");
      PIN_INPUT_OUTPUT('F',1,"Output");
  
      PIN_PULLUP_RESISTOR('F',0,"Pullup");
      
        
      
      while(1)
      {
        data = PIN_READ_DIGITAL('F',0);                                          //To Read Switch

        if(data == true)
        {
            PIN_WRITE_DIGITAL('F',1,"HIGH");                                     //To Write Data to a led
        }
        else
        {
            PIN_WRITE_DIGITAL('F',1,"LOW");                                      //To Write Data to a led
        }
      }
}