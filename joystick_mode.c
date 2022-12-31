// joystick_mode.c
#include "DCmotor.h"
#include "servo.h"
#include "sound.h"
#include "neopixel.h"
#include "joystick.h"
// #include "adps.h"
// #include "adps.c"


#include <stdio.h>
#include <stdlib.h>
#include "hardware/adc.h"
#include "pico/stdio.h"
#include "hardware/pwm.h"
#include "ws2812.pio.h" 
#include "hardware/gpio.h"
#include "pico/stdlib.h"

int joystick_mode() {
    int32_t proximity;
    int left_right_turn;

        while (true) {
             // get direction from joystick
            left_right_turn = get_joystick();

            // operate dc motor according to joystick direction
            if (left_right_turn == 2){
                //printf("lr turn 2 \n");
                run(3);
                //printf("done run 3\n");
                // turn right wheel on
            }
            else if (left_right_turn == 1) {
                //printf("lr turn 1 \n");
                // turn left wheel on
                run(2);
                //printf("done run 2\n");
            }

            read_proximity(&proximity);
            if(proximity > 200){
                //printf("proxi, return to main\n");
                return 1;
            }
        sleep_ms(100);
        }

}