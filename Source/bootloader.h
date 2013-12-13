#ifndef __BOOTLOADER_H
#define __BOOTLOADER_H

#include <stdint.h>
#include <stdbool.h>
#include "stm32f4xx.h"
#include "device.h"

typedef enum {
  NONE  = 0,
  GREEN = LED_GREEN,
  RED   = LED_RED
}  LedPin;

void setLed(LedPin led);
bool isPushButtonPressed();

/* Jump to the internal STM32 bootloader. The way this works is that we
 * set a magic number in memory that our startup code looks for (see startup_stm32f4xx.s).
 * RAM is preserved across system reset, so when it finds this magic number, it will go
 * to the bootloader code rather than the application code.
 */
void jumpToBootloader(void);

#endif /* __BOOTLOADER_H */
