#include <inttypes.h>

/* Switch B: illuminated pushbutton */
#define SWITCH_B_PORT                GPIOE
#define SWITCH_B_CLOCK               RCC_AHB1Periph_GPIOE
#define SWITCH_B_PORT_SOURCE         EXTI_PortSourceGPIOE
#define SWITCH_B_PIN                 GPIO_Pin_2
#define SWITCH_B_PIN_SOURCE          EXTI_PinSource2
#define SWITCH_B_PIN_LINE            EXTI_Line2
#define SWITCH_B_IRQ                 EXTI2_IRQn
#define SWITCH_B_HANDLER             EXTI2_IRQHandler

#define LED_PORT                     GPIOE
#define LED_GREEN                    GPIO_Pin_5
#define LED_RED                      GPIO_Pin_3
#define LED_CLOCK                    RCC_AHB1Periph_GPIOE

#ifdef  USE_FULL_ASSERT
#ifdef __cplusplus
 extern "C" {
#endif
   void assert_failed(uint8_t* file, uint32_t line);
#ifdef __cplusplus
}
#endif
#define assert_param(expr) ((expr) ? (void)0 : assert_failed((uint8_t *)__FILE__, __LINE__))
#endif
