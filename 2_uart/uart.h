#pragma once
#include <stdint.h>

#define UART ((NRF_UART_REG*)0x40002000)

typedef struct{
    volatile uint32_t TASKS_STARTRX;
    volatile uint32_t TASKS_STOPRX;
    volatile uint32_t TASKS_STARTTX;
    volatile uint32_t TASKS_STOPTX;
    volatile uint32_t RESERVEDO[3];
    volatile uint32_t TASKS_SUSPEND;
    volatile uint32_t RESERVEDO1[56];
    volatile uint32_t EVENTS_CTS;
    volatile uint32_t EVENTS_NCTS;
    volatile uint32_t EVENTS_RXDRDY;
    volatile uint32_t RESERVEDO2[4];
    volatile uint32_t EVENTS_TXDRDY;
    volatile uint32_t RESERVEDO3;
    volatile uint32_t EVENTS_ERROR;
    volatile uint32_t RESERVEDO7 [7];
    volatile uint32_t EVENTS_RXTO;
    volatile uint32_t RESERVEDO4[238];
    volatile uint32_t ENABLE;
    volatile uint32_t RESERVEDO5;
    volatile uint32_t PSELRTS;
    volatile uint32_t PSELTXD;
    volatile uint32_t PSELCTS;
    volatile uint32_t PSELRXD;
    volatile uint32_t RXD;
    volatile uint32_t TXD;
    volatile uint32_t RESERVEDO6;
    volatile uint32_t BAUDRATE;
}NRF_UART_REG;

void uart_init();

void uart_send(char letter);

char uart_read();