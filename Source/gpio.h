#ifndef __GPIO_H
#define __GPIO_H

#include "stm32f4xx.h"
#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
 extern "C" {
#endif

   bool getPin(GPIO_TypeDef* port, uint32_t pin);
   void setPin(GPIO_TypeDef* port, uint32_t pin);
   void clearPin(GPIO_TypeDef* port, uint32_t pin);
   void togglePin(GPIO_TypeDef* port, uint32_t pin);
   void configureDigitalInput(GPIO_TypeDef* port, uint32_t pin, GPIOPuPd_TypeDef pull);
   void configureDigitalOutput(GPIO_TypeDef* port, uint32_t pin);
   void configureAnalogInput(GPIO_TypeDef* port, uint32_t pin);
   void configureAnalogOutput(GPIO_TypeDef* port, uint32_t pin);

#ifdef __cplusplus
}
#endif

#endif /* __GPIO_H */
