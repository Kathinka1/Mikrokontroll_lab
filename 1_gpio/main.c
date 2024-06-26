#include <stdint.h>

#define GPIO ((NRF_GPIO_REGS*)0x50000000)

typedef struct {
	volatile uint32_t RESERVED0[321];
	volatile uint32_t OUT;
	volatile uint32_t OUTSET;
	volatile uint32_t OUTCLR;
	volatile uint32_t IN;
	volatile uint32_t DIR;
	volatile uint32_t DIRSET;
	volatile uint32_t DIRCLR;
	volatile uint32_t LATCH;
	volatile uint32_t DETECTMODE;
	volatile uint32_t RESERVED1[118];
	volatile uint32_t PIN_CNF[32];
} NRF_GPIO_REGS;

void button_init(){ 
	GPIO->PIN_CNF[13] = (3 << 2);
	GPIO->PIN_CNF[14] = (3 << 2);
	// Fill inn the configuration for the remaining buttons
}

int main(){
	button_init();
	// Configure LED Matrix
	for(int i = 17; i <= 20; i++){
		GPIO->DIRSET = (1 << i);
		GPIO->OUTCLR = (1 << i);
	}

	// Configure buttons -> see button_init()

	int sleep = 0;
	int ledOn = 0;
	while(1){
		int btn1 = GPIO->IN & (1<<13);

		/* Check if button 1 is pressed;
		
		 * turn on LED matrix if it is. */
		if (btn1==0)
		{
			ledOn = 1;
		}
		/* Check if button 2 is pressed;
		 * turn off LED matrix if it is. */
		int btn2 = GPIO->IN & (1<<14);
		if (btn2==0) {
			ledOn = 0;
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
	return 0;
}
