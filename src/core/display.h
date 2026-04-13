#pragma once

#include <stdbool.h>
#include <stdint.h>

const int WIDTH = 64;
const int HEIGHT = 32;

typedef struct Display {
  uint8_t screen[WIDTH * HEIGHT];
} Display;

void display_clear_screen(Display *self);
