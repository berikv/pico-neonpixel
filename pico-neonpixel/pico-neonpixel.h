
#ifndef PICO_NEONPIXEL_H
#define PICO_NEONPIXEL_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>

#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "ws2812.pio.h"


static inline void put_pixel(uint32_t pixel_grb) {
  pio_sm_put_blocking(pio0, 0, pixel_grb << 8u);
}

static inline uint32_t urgb_u32(uint8_t r, uint8_t g, uint8_t b) {
  return ((uint32_t)(r) << 8) |
         ((uint32_t)(g) << 16) |
         (uint32_t)(b);
}

void pixel_init(int pin) {
  PIO pio = pio0;
  int sm = 0;
  uint offset = pio_add_program(pio, &ws2812_program);
  char str[12];

  ws2812_program_init(pio, sm, offset, pin, 800000, true);
}


#ifdef __cplusplus
}
#endif

#endif