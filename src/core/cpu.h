#pragma once

#include <stdint.h>

typedef struct Cpu {
  int8_t memory[4096];
  int16_t pc;
  int16_t i;
  int16_t stack[];
} Cpu;

int16_t cpu_fetch(Cpu *self);
int16_t cpu_decode(int16_t instruction);
int16_t cpu_execute();
