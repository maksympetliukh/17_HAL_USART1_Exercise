//
// Created by maksym-petliukh on 4/26/26.
//

#include "main.h"

#include <string.h>

#include "stm32f4xx_hal.h"

void SystemClock_Config(void);
void USART1_Init(void);
void Error_Handler(void);

//USART Handle global variable
UART_HandleTypeDef huart1;

char *tx = "The application is running.\r\n";

int main(void) {
    HAL_Init();
    SystemClock_Config();
    USART1_Init();

    HAL_UART_Transmit(&huart1, (uint8_t*) tx, strlen(tx), HAL_MAX_DELAY);

    while (1);
}

void SystemClock_Config(void) {
    //This application doesn't need SystemClock Configuration
}

void USART1_Init(void) {
    huart1.Instance = USART1;
    huart1.Init.BaudRate = 115200;
    huart1.Init.WordLength = UART_WORDLENGTH_8B;
    huart1.Init.StopBits = UART_STOPBITS_1;
    huart1.Init.Parity = UART_PARITY_NONE;
    huart1.Init.Mode = UART_MODE_TX_RX;
    huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    huart1.Init.OverSampling = DISABLE;

    if ((HAL_UART_Init(&huart1)!= HAL_OK)){
        //There is a problem
        Error_Handler();
    }
}

void Error_Handler(void){while (1);}