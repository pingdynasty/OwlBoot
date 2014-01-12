#include "stm32f4xx.h"
#include "gpio.h"
#include "device.h"
#include "bootloader.h"

typedef  void (*pFunction)(void);
pFunction jumpToApplication;
uint32_t JumpAddress;
#define APPLICATION_ADDRESS        (uint32_t)0x08008000

int main(void) {
  /* initialise pushbutton */
  RCC_AHB1PeriphClockCmd(SWITCH_B_CLOCK, ENABLE);
  configureDigitalInput(SWITCH_B_PORT, SWITCH_B_PIN, GPIO_PuPd_UP);

  /* initialise LEDs */
  RCC_AHB1PeriphClockCmd(LED_CLOCK, ENABLE);
  configureDigitalOutput(LED_PORT, LED_RED|LED_GREEN);
  setLed(RED);

  if(getPin(SWITCH_B_PORT, SWITCH_B_PIN)){
    /* Check Vector Table: Test if user code is programmed starting from address 
       "APPLICATION_ADDRESS" */
    if(((*(__IO uint32_t*)APPLICATION_ADDRESS) & 0x2FFE0000 ) == 0x20000000){
      setLed(GREEN);
    }
      /* Jump to user application */
      JumpAddress = *(__IO uint32_t*) (APPLICATION_ADDRESS + 4);
      jumpToApplication = (pFunction) JumpAddress;
      /* Initialize user application's Stack Pointer */
      __set_MSP(*(__IO uint32_t*) APPLICATION_ADDRESS);
      jumpToApplication();
    /* } */

  }

  jumpToBootloader();

  for(;;);
}

#ifdef USE_FULL_ASSERT
void assert_failed(uint8_t* file, uint32_t line){
  for(;;);
}
#endif
