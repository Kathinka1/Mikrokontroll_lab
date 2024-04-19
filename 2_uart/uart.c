#include "uart.h"
#include "gpio.h"

#define UART_INT_RX  (8)
#define UART_INT_TX  (6)

void uart_init(){
    GPIO->PIN_CNF[UART_INT_RX] = 1;  
	GPIO->PIN_CNF[UART_INT_TX] = 0; 

    
    UART->PSELTXD = 6;
    UART->PSELRXD = 8;

    UART->BAUDRATE = 0x00275000;
    UART->PSELRTS = 0xFFFFFFFF;
    UART->PSELCTS = 0xFFFFFFFF;
    UART->ENABLE = 4;
    UART->TASKS_STARTRX = 1;
}

void uart_send(char letter) {
    UART->TASKS_STARTTX = 1;
    UART->TXD = letter;
    while (UART->EVENTS_TXDRDY != 1);
    UART->EVENTS_TXDRDY = 0;
    UART->TASKS_STOPTX = 1;     
}

char uart_read() {
    if (UART->EVENTS_RXDRDY)
    {
        char c = UART->RXD;
        UART->EVENTS_RXDRDY = 0;

        return c;
    }
    return '\0';
}