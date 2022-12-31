/*
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

//          A2
#include <stdio.h>

#include <stdlib.h>

#include "pico/stdlib.h"
#include "hardware/adc.h"

#define ADC_VREF 3.3
#define ADC_RANGE (1 << 12)
#define ADC_CONVERT (ADC_VREF / (ADC_RANGE - 1))


int get_sound() {   
    // stdio_init_all();

    // adc_init();
    // adc_gpio_init(27);
    // adc_select_input(1);
    adc_select_input(1);
    uint16_t prev_ret = adc_read();
    sleep_ms(200);
    //while(stdio_usb_connected()!=true);
    //printf("in sound\n");
    adc_select_input(1);
    uint16_t cur_ret = adc_read();
    //printf("%d\n", cur_ret);
    //printf("prev: %d cur: %d\n", prev_ret, cur_ret);
    if ( (abs(cur_ret - prev_ret)) >= 100) {
        //printf("sound!!\n");
        return 1;
        //printf("Sound!\n");
    }
    else {
        //printf("no sound\n");
        //printf("wait for sound\n");
        return 0;
    }
    return 0;
    }






//          cd pico/pico-examples/build/led2b
