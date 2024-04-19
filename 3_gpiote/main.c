#include <stdint.h>
#include <stdio.h>
#include <sys/types.h>
#include "gpio.h"
#include "gpiote.h"
#include "ppi.h"

void button_init(){ 
	GPIO->PIN_CNF[13] = (3 << 2);
}

int main() {
      //Led init

    button_init();
    GPIOTE_init();
    ppi_init();
    

    while(1) {
    }


}