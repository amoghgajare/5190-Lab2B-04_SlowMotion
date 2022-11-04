#include <stdio.h> //Standard C library
#include <stdlib.h> //Standard C library
#include "hardware/gpio.h"


int button_pin = 22;

void button_init(int pin){
    button_pin = pin;
    gpio_init(pin);
    gpio_set_dir(pin,GPIO_IN);
}

bool button_get(){
    return gpio_get(button_pin);
}
