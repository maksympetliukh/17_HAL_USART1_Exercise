//
// Created by maksym-petliukh on 4/26/26.
//

#include "msp.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx_ll_gpio.h"

void HAL_MspInit(void) {
    //1. Set up priority grouping of the ARM Cortex-M4 CPU
    HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);//Actually not required because NVIC_PRIORITYGROUP4 - default velue
    //2. Enable required system exceptions to the ARM Cortex-M4 CPU
    SCB->SHCSR |= 0x7 << 16; /*Place 1 1 1 into 16th, 17th and 18th bits that enables MEMFAULTENA,
                                                                                      BUSFAULTENA,
                                                                                      USGFAULTENA
                                                                                      system exceptions*/
    //3. Configure the priority for the system exceptions
    //We need not configure it because it's already set with 0 (highest priority)
    HAL_NVIC_SetPriority(MemoryManagement_IRQn, 0, 0);
    HAL_NVIC_SetPriority(BusFault_IRQn, 0, 0);
    HAL_NVIC_SetPriority(UsageFault_IRQn, 0, 0);
}

void HAL_UART_MspInit(UART_HandleTypeDef* huart) {
    //Low-level initialization for USART1 peripheral
    GPIO_InitTypeDef gpio_usart;

    //1. Enable the clock
    __HAL_RCC_USART1_CLK_ENABLE();
    __HAL_RCC_GPIOA_CLK_ENABLE();

    //2. Do the pin muxing cofigurations
    gpio_usart.Pin = GPIO_PIN_9; //USART1 TX
    gpio_usart.Mode = GPIO_MODE_AF_PP;
    gpio_usart.Alternate = GPIO_AF7_USART1;
    gpio_usart.Pull = GPIO_PULLUP;
    gpio_usart.Speed = GPIO_SPEED_FREQ_LOW;

    HAL_GPIO_Init(GPIOA, &gpio_usart);

    gpio_usart.Pin = GPIO_PIN_10; //USART1 RX
    HAL_GPIO_Init(GPIOA, &gpio_usart);

    //3. Enable the IRQ and set up the priority
    HAL_NVIC_EnableIRQ(USART1_IRQn);
    HAL_NVIC_SetPriority(USART1_IRQn, 15, 0);
}
