#include "ws2812.pio.h" //Autogenrated library from Pioasm
#include "hardware/pio.h"
//Chip specific Library

#define POWER_PIN 11 //power enable pin of neopixel
#define DATA_PIN 12 //signal pin of neopixel

#define PIO pio0 //PIO module used
#define STATE_MACHINE 0 //PIO state machine used
#define FREQ 800000 //Frequency of data communication with LED
#define IS_RGBW true //RGB

void pixel_init(){

    gpio_init(POWER_PIN);
    gpio_set_dir(POWER_PIN,GPIO_OUT);
    gpio_put(POWER_PIN,1);

    uint offset = pio_add_program(PIO, &ws2812_program);
    ws2812_program_init(PIO, STATE_MACHINE, offset, DATA_PIN , 800000, IS_RGBW);
}

void pixel_set(uint32_t rgb){
    uint grb = (rgb & 0xFF0000)>>8 | (rgb & 0x00FF00)<<8 | (rgb & 0x0000FF);
    pio_sm_put_blocking(PIO, 0, grb << 8u);
}