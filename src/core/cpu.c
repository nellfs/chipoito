#include "cpu.h"
#include <stdint.h>

int16_t cpu_fetch(Cpu *self) {
  int16_t instruction =
      self->memory[self->pc] << 8 | self->memory[self->pc + 1];
  self->pc += 2;
  return instruction;
}

int16_t cpu_decode(int16_t instruction) {
  int8_t x = (instruction & 0x0f00) >> 8;
  int8_t y = (instruction & 0x00f0) >> 4;
  int8_t n = (instruction & 0x000f);
  int8_t nn = (instruction & 0x00ff);
  int16_t nnn = (instruction & 0x0fff);

  return 1;
}
