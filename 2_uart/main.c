#include <stdint.h>
#include <stdio.h>
#include <sys/types.h>
#include "uart.h"
#include "gpio.h"

void button_init(){ 
	GPIO->PIN_CNF[13] = (3 << 2);
	GPIO->PIN_CNF[14] = (3 << 2);
	// Fill inn the configuration for the remaining buttons
}

ssize_t _write(int fd, const void *buf, size_t count) {
  char * letter = (char *)(buf);
  for(int i = 0; i < count; i++) {
    uart_send(*letter);
    letter++;
  }
  return count;
}


int main() {
  button_init();
  uart_init();
  int ledOn = 0;
  int sleep = 0;

  iprintf("The average grade in TTK%d was in %d was: %c\n\r",4235,2022,'B');

  //Led init
  for(int i = 17; i <= 20; i++){
		GPIO->DIRSET = (1 << i);
		GPIO->OUTCLR = (1 << i);
	}

    while(1){
		  int btn1 = GPIO->IN & (1<<13);
		  int btn2 = GPIO->IN & (1<<14);
      if (!btn1) {
        uart_send('A');
      }
      if (!btn2) {
        uart_send('B');
      }
      if (uart_read() != '\0')
      {
        if (ledOn == 0) {
          ledOn = 1;
        } else {
          ledOn = 0;
        }
      }

      if (ledOn) {
        GPIO->OUTCLR |= (1<<17);
        GPIO->OUTCLR |= (1<<18);
        GPIO->OUTCLR |= (1<<19);
        GPIO->OUTCLR |= (1<<20);
      }
      else {
        GPIO->OUTSET |= (1<<17);
        GPIO->OUTSET |= (1<<18);
        GPIO->OUTSET |= (1<<19);
        GPIO->OUTSET |= (1<<20);
      }
      sleep = 10000;
      while(--sleep); // Delay
    }
} 

