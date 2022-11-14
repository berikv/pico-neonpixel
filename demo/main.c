#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include <pico-neonpixel.h>

const int PIN_TX = 16;

int main() {
  pixel_init(PIN_TX);

  while (true) {
    // OPTION A: uncomment sleep_ms(500) and view the individual colors
    // OPTION B: comment sleep_ms(500) and view the pixels cascading colors
    put_pixel(urgb_u32(0xff, 0, 0));  // Red
    sleep_ms(100);
    put_pixel(urgb_u32(0, 0xff, 0));  // Green
    sleep_ms(100);
    put_pixel(urgb_u32(0, 0, 0xff));  // Blue
    sleep_ms(100);
    put_pixel(urgb_u32(0xff, 0xff, 0));  // Purple
    sleep_ms(500);
    put_pixel(urgb_u32(0, 0xff, 0xff));  // Cyan
    sleep_ms(500);
    put_pixel(urgb_u32(0xff, 0xff, 0xff));  // White
    sleep_ms(500);
    put_pixel(urgb_u32(0, 0, 0));  // Black or off
    sleep_ms(500);

    sleep_ms(1000);
    // Clear all pixels
    for (int i = 0; i <= 60; i++) {
      put_pixel(urgb_u32(0, 0, 0));  // Black or off
    }
    sleep_ms(1000);
  }
}
