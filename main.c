#include "rcc.h"
#include "gpio.h"

void delay(int ms);

int main() {

    // enable clocking on port B
    RCC->AHB1ENR |= GPIOB_CLOCK_ENABLE;

    // set all pins as output
    GPIOB->MODER = 0b01010101010101010101010101010101;

    // seting all pins B's port to high state
    GPIOB->ODR = 0xFFFFFFFF;
    while (1) {
        GPIOB->ODR = ~GPIOB->ODR;
        delay(1100);
    }

    return 0;
}
