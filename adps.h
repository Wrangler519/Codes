#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "pico/stdlib.h"
#include "pico/binary_info.h"
#include "string.h"
#include "pio_i2c.h"


#define WS2812_POWER_PIN 11
#define WS2812_PIN 12
#define PIN_SDA 22
#define PIN_SCL 23
int addr = 0x39;
uint8_t clear_low = 0x94;
// uint8_t clear_high = 0x95;
// const uint8_t red_low = 0x96;
// const uint8_t red_high = 0x97;
// const uint8_t green_low = 0x98;
// const uint8_t green_high = 0x99;
// const uint8_t blue_low = 0x9A;
// const uint8_t blue_high = 0x9B;
uint8_t PDATA = 0x9C;
uint8_t ATIME = 0x81;


uint8_t ALS_TIME = 255;
uint8_t enable_addr = 0x80;

uint8_t gmode_addr = 0xAB;
const uint8_t gmode_val = 1;  //enable gesture

uint8_t GSTATUS = 0xAF;
uint8_t GEXTH = 0xA1;
uint8_t sai_addr = 0x9F;
const uint8_t sai_val = 0b00000000;


uint8_t ges_level_addr = 0xAE;
uint8_t ges_addr = 0xFC;


// bool reserved_addr(uint8_t addr);
// int get_val(int a, int b);
// int apds_init();
// int set_gmode(int gmode_val);
// int set_g_exit_thredshold(int thredshold);
void read_proximity(int32_t* proximity);
// static void read_prox();
// void read_rgbc(int32_t* r, int32_t* g, int32_t* b, int32_t* c);
// void clear_gesture_fifo();
// int read_gesture();
// static inline uint32_t rgbc_u32(uint8_t r, uint8_t g, uint8_t b);
void printI2Cbus();
