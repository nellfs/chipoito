#pragma once

#include "display.h"
#include <stdint.h>

typedef struct Chip8 {
  Display *display;

  uint8_t memory[4096];

  uint16_t stack[16];

  int16_t pc;
  int16_t i;

  uint8_t sp;

  uint8_t V[16];
} Chip8;

void chip8_cpu_cycle(Chip8 *self);
