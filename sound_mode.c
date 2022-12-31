// sound_mode
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

int sound_mode() {
    int prev=0;
    int32_t proximity;
    int sound_result;

    while (true) {
        // get sound from sound sensor and operate servo motor
        sound_result = get_sound();
        if (sound_result == 1) {
            //printf("sound detected\n");
            run(1);
            rotate();
            //printf("run and rotate done\n");
        }

        read_proximity(&proximity);
        if(proximity > 200){
            //printf("proxi, return to main\n");
            return 1;
        }
        sleep_ms(50);
}
}