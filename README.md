# HAL Architecture understanding exercise

### What this project is
This project is created to learn the Hardware Abstraction Layer framework, understand the STM32 project hierarchy, architecture and logic. The USART protocol has been picked to show how to build the user application, how to use different HAL APIs in user applications.
This project is developed accordingly to online course [Mastering Microcontroller: Timers, PWM, CAN, Low Power(MCU2)](https://www.udemy.com/course/microcontroller-programming-stm32-timers-pwm-can-bus-protocol/learn) by Kiran Nayak (FastBit Embedded Brain Academy).

### What actually this program does
- initialize HAL
- config System Clock (if it required)
- initialize USART peripheral
- sends initial message to show that the USART peripheral works correctly and the program is ready for work
- receive user data from minicom serial port input
- MCU converts user data string into upper-case one and sends it back to the host (implemented with interrupts and even callback)

### Additional operations
- Receiving Complete Callback implemented
- rewrited stm32f4xx_hal_it.c (it.c)
- rewrited stm32f4xx_hal_msp.c (msp.c)
- USART high and low-level initialization (USART configurations and USART GPIO configurations)

### Used devices
- MCU: **STM32F407VET6**
- CPU: **ARM Cortex-M4**
- Debugger: **WeAct 1.0**
- USART converter: **Embedded WeAct USART converter**

### Used software and documentation
- Programming language: **C**
- Implementation: **HAL**
- IDE: **CLion**
- STM32 Project editor: **STM32CubeMX**
- Reference Manual: **RM0090**
- Serial port: **Minicom**