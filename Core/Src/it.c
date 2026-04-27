//
// Created by maksym-petliukh on 4/26/26.
//

#include "main.h"
#include "usart.h"

void SysTick_Handler(void) {
    HAL_IncTick();
    HAL_SYSTICK_IRQHandler();
}

//USART IRQ Handler
void USART1_IRQHandler(void) {
    HAL_UART_IRQHandler(&huart1);
}
