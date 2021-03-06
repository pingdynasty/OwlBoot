#include "gpio.h"

bool getPin(GPIO_TypeDef* port, uint32_t pin){
  return port->IDR & pin;
}

void setPin(GPIO_TypeDef* port, uint32_t pin){
  port->BSRRL = pin;
}

void clearPin(GPIO_TypeDef* port, uint32_t pin){
  port->BSRRH = pin;
}

void configureDigitalInput(GPIO_TypeDef* port, uint32_t pin, GPIOPuPd_TypeDef pull){
  GPIO_InitTypeDef GPIO_InitStructure;
  GPIO_StructInit(&GPIO_InitStructure);
  GPIO_InitStructure.GPIO_Pin = pin;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_PuPd = pull;
  GPIO_Init(port, &GPIO_InitStructure);
}

void configureDigitalOutput(GPIO_TypeDef* port, uint32_t pin){
  GPIO_InitTypeDef GPIO_InitStructure;
  GPIO_StructInit(&GPIO_InitStructure);
  GPIO_InitStructure.GPIO_Pin = pin;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(port, &GPIO_InitStructure);
}
