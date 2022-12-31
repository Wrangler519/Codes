/*
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "pico/stdlib.h"

// const uint tb1_PIN = 29 ;  //A0   
// const uint tb2_PIN = 28 ;  //A1
// const uint pwm1_PIN = 27;  //A2
// const uint pwm2_PIN = 26;  //A3

const uint tb1_PIN = 5 ;  //A0  Rx   
const uint tb2_PIN = 6 ;  //A1  SCK
const uint pwm1_PIN = 4;  //A2  MI
const uint pwm2_PIN = 3;  //A3  MO

void init_motor_6612(){
    gpio_init(tb1_PIN);
    gpio_init(tb2_PIN);
    gpio_init(pwm1_PIN);
    gpio_init(pwm2_PIN);

    gpio_set_dir(tb1_PIN, GPIO_OUT);
    gpio_set_dir(tb2_PIN, GPIO_OUT);
    gpio_set_dir(pwm1_PIN, GPIO_OUT);
    gpio_set_dir(pwm2_PIN, GPIO_OUT);
    
    gpio_put(tb1_PIN, 1); 
    gpio_put(tb2_PIN, 0);

    gpio_put(pwm1_PIN, 0); 
    gpio_put(pwm2_PIN, 0);
}

/*
drive tb6612 to make it run in direction
1 -- front
2 -- left
3 -- right

1 second each time
*/
void run(int dir){
    if(dir == 1){       // dir = 1, run both wheels
        gpio_put(pwm1_PIN, 1); 
        gpio_put(pwm2_PIN, 1);
        sleep_ms(1000);
        gpio_put(pwm1_PIN, 0); 
        gpio_put(pwm2_PIN, 0);
        
    }
    if(dir == 2){       // dir = 2, rum pwm2
        gpio_put(pwm1_PIN, 0); 
        gpio_put(pwm2_PIN, 1);
        sleep_ms(1000);
        gpio_put(pwm1_PIN, 0); 
        gpio_put(pwm2_PIN, 0);
    }
    if(dir == 3){       // dir = 3, run pwm1
        gpio_put(pwm1_PIN, 1); 
        gpio_put(pwm2_PIN, 0);
        sleep_ms(1000);
        gpio_put(pwm1_PIN, 0); 
        gpio_put(pwm2_PIN, 0);
    }
}

