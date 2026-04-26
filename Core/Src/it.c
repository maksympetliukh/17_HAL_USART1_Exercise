//
// Created by maksym-petliukh on 4/26/26.
//

#include "main.h"
void SysTick_Handler(void) {
    HAL_IncTick();
    HAL_SYSTICK_IRQHandler();
}