#include "bootloader.h"
#include "gpio.h"
#include "device.h"

/* Magic number to store in memory before reset to tell the device to
 * enter system bootloader.
 */
const uint32_t bootloaderMagicNumber = 0xF00B4400;

void setLed(LedPin led){
  clearPin(LED_PORT, led ^ (LED_RED|LED_GREEN));
  setPin(LED_PORT, led);
}

/* Jump to the internal STM32 bootloader. The way this works is that we
 * set a magic number in memory that our startup code looks for (see startup_stm32f4xx.s).
 * RAM is preserved across system reset, so when it finds this magic number, it will go
 * to the bootloader code rather than the application code.
 */
void jumpToBootloader(void){
  uint16_t i;
  volatile uint32_t delayCounter;

  /* Blink LEDs */
  for(i = 0; i < 3; i++) {
    setLed(NONE);
    for(delayCounter = 0; delayCounter < 2000000; delayCounter++);
    setLed(RED);
    for(delayCounter = 0; delayCounter < 2000000; delayCounter++);
  }

  /* This address within first 64k of memory: seemed to be problems with higher
   * locations. Note that this must match what's in startup.s
   */
  *((unsigned long *)0x2000FFF0) = bootloaderMagicNumber;

  NVIC_SystemReset();

  /* Shouldn't get here */
  for(;;);
}
