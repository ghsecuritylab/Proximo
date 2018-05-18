/*
 */
#ifndef SK6812_H
#define SK6812_H


#ifdef __cplusplus
extern "C" {
#endif


#include <stdio.h>
#include "nrf_drv_i2s.h"
#include "stdlib.h"
#include "app_error.h"
#include "app_util_platform.h"
#include "bsp.h"


#define I2S_WS2812B_DRIVE_PATTERN_0 ((uint8_t)0x08)   //  Bit pattern for data "0" is "HLLL".
#define I2S_WS2812B_DRIVE_PATTERN_1 ((uint8_t)0x0e)   //  Bit pattern for data "1" is "HHHL".
#define	I2S_WS2812B_DRIVE_BUF_SIZE_PER_LED	(12)      //  buffer size for each LED (8bit * 4 * 3 )

typedef struct
{
    uint8_t   green; // Brightness of green (0 to 255)
    uint8_t   red;   // Brightness of red   (0 to 255)
    uint8_t   blue;  // Brightness of blue  (0 to 255)
} rgb_led_t;


void  ws2812b_drive_set_blank(rgb_led_t * rgb_led, uint16_t num_leds);
void  ws2812b_drive_current_cap(rgb_led_t * led_array, uint16_t num_leds, uint32_t limit);
void  ws2812b_drive_dim(rgb_led_t * led_array, uint16_t num_leds, float dim );
uint32_t ws2812b_drive_calc_current(rgb_led_t * led_array, uint16_t num_leds);
ret_code_t i2s_ws2812b_drive_xfer(rgb_led_t *led_array, uint16_t num_leds, uint8_t drive_pin);
extern void i2s_ws2812b_drive_handler(uint32_t const * p_data_received, uint32_t * p_data_to_send, uint16_t number_of_words);
void i2s_ws2812b_drive_set_buff(rgb_led_t* rgb_led, uint8_t *p_xfer, uint16_t xbuff_length);


#ifdef __cplusplus
}
#endif


#endif
