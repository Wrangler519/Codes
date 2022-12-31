//          A2, A3-xaxis
#include <stdio.h>

#include <stdlib.h>

#include "pico/stdlib.h"
#include "hardware/adc.h"

int get_joystick() {   
    uint16_t x_axis_prev;
    uint16_t x_axis_cur;

    // get prev value
    adc_select_input(0);
    x_axis_prev = adc_read();

    // *** May be sleep here
    sleep_ms(1000);
    // get cur value
    adc_select_input(0);
    x_axis_cur = adc_read();

    if (((x_axis_prev - x_axis_cur) >= 1000) && (x_axis_cur <= 500)) {
        return 1;
        //printf("left\n");
    }
    else if (((x_axis_cur - x_axis_prev) >= 1000) && (x_axis_cur >= 2000)) {
        return 2;
        //printf("right\n");
    }
    else {
        //printf("no input\n");
    }

    //sleep_ms(100);

    return 0;
}
