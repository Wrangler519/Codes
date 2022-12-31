// project.c
#include "DCmotor.h"
#include "servo.h"
#include "sound.h"
#include "neopixel.h"
#include "joystick.h"
// #include "adps.h"
#include "adps.c"
#include "sound_mode.c"
#include "joystick_mode.c"


#include <stdio.h>
#include <stdlib.h>
#include "hardware/adc.h"
#include "pico/stdio.h"
#include "hardware/pwm.h"
#include "ws2812.pio.h" 
#include "hardware/gpio.h"
#include "pico/stdlib.h"

#define PINS 29         //A0---servo


int main() {

    int32_t proximity;
    uint16_t x_axis_prev;

    // init all
    stdio_init_all();

    // init sound sensor---A2
    adc_init();
    adc_gpio_init(27);
    adc_select_input(1);

    // init servo motor---A0
    gpio_init(PINS);
    gpio_set_dir(PINS, true);
    
    int sound_result;

    // light up LED
    neopixel_init();
    neopixel_set_rgb(0x0000ff00);       //green
    sleep_ms(10);

    // init joystick
    adc_init();
    adc_gpio_init(26);      // A3
    adc_select_input(0);

    //init PIO i2c for adps9960
    printI2Cbus();

    //init DC motoer driver tb6612
    init_motor_6612();

    int left_right_turn;    // 1=left, 2=right

    uint16_t x_axis_cur;
    int count = 0;
    int rest;
    int returned;

    read_proximity(&proximity);
    if (proximity > 200) {
        count += 1;
    }
    //while(stdio_usb_connected()!=true);

    // odd number: sound mode; even number: joystick mode
    while (true) {
        // joystick mode---RED;     sound mode---blue
            rest = count % 2;
            if (rest == 0){
                //("rest = 0, set red\n");
                neopixel_set_rgb(0x00ff0000);
                //printf("enter joystickmode\n");
                returned = joystick_mode();
                //printf("exited joystickmode\n");
                if (returned == 1) {
                    //printf("joystick done\n");
                    count += 1;
                    neopixel_set_rgb(0x00000000);
                }
            }
            else {
                //printf("rest = 1, set blue\n");
                neopixel_set_rgb(0x000000ff);
                //printf("enter sound mode \n");
                returned = sound_mode();
                //printf("exited soundmode\n");
                if (returned == 1) {
                    //printf("sound mode done\n");
                    count += 1;
                    neopixel_set_rgb(0x00000000);
                }

            }
            sleep_ms(300);

        }
}