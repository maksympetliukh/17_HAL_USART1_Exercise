//
// Created by maksym-petliukh on 4/26/26.
//

#include "main.h"

#include <string.h>

#include "stm32f4xx_hal.h"

void SystemClock_Config(void);
void USART1_Init(void);
void Error_Handler(void);
uint8_t conv_to_cap(uint8_t data);

//USART Handle global variable
UART_HandleTypeDef huart1;

//user data
char *tx = "The application is running.\r\n";
uint8_t rx;

int main(void) {
    //Required HAL, Clock and USART peripheral initializations
    HAL_Init();
    SystemClock_Config();
    USART1_Init();

    //Transmit the data
    HAL_UART_Transmit(&huart1,  (uint8_t *)tx, strlen(tx), HAL_MAX_DELAY);

    //Receive the data from user's input
    uint8_t rx_buf[100];
    uint32_t count = 0;

    while (1) {
        HAL_UART_Receive(&huart1, &rx, 1, HAL_MAX_DELAY);
        if (rx == '\r') {
            break;
        }else {
            rx_buf[count++] = conv_to_cap(rx);
        }
    }
        rx_buf[count++] = '\r';
        HAL_UART_Transmit(&huart1, rx_buf, count, HAL_MAX_DELAY);
    while (1);

    return 0;
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

//Convert lower-case character into upper-case one
uint8_t conv_to_cap(uint8_t data) {
    if (data >= 'a' && data <= 'z') {
        data -= ('a' - 'A'); //difference between low and upper case is 32 in ASCII table
    }
    return data;
}