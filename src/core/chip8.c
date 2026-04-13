#include "chip8.h"
#include "display.h"
#include <stdint.h>

void chip8_cpu_cycle(Chip8 *chip8) {
  // fetch
  int16_t opcode = chip8->memory[chip8->pc] << 8 | chip8->memory[chip8->pc + 1];
  chip8->pc += 2;

  int8_t x = (opcode & 0x0f00) >> 8;
  int8_t y = (opcode & 0x00f0) >> 4;
  // int8_t n = (opcode & 0x000f);
  int8_t nn = (opcode & 0x00ff);
  int16_t nnn = (opcode & 0x0FFF);

  // decode & execute
  switch ((opcode & 0xF000) >> 12) {
  case 0:

    switch (opcode & 0x00FF) {
    case 0xE0: {
      display_clear_screen(chip8->display);
      break;
    }
    case 0xEE: {
      chip8->sp--;
      chip8->pc = chip8->stack[chip8->sp];
      break;
    }
    }

    break;
  case 1:
    chip8->pc = opcode & 0x0FFF;
    break;
  case 2: // 2NNNN
    chip8->stack[chip8->sp] = chip8->pc;
    chip8->sp++;
    chip8->pc = opcode & 0x0FFF;
    break;
  case 3: // 3XNN
    if (chip8->V[x] == nn) {
      chip8->pc += 2;
    }
    break;
  case 4: // 4XNN
    if (chip8->V[x] != nn) {
      chip8->pc += 2;
    }
    break;
  case 5: // 5XY0
    if (chip8->V[x] == chip8->V[y]) {
      chip8->pc += 2;
    }
    break;
  case 6: // 6XNN
    chip8->V[x] = nn;
    break;
  case 7: // 7XNN - ADD
    chip8->V[x] = nn + chip8->V[x];
    break;
  case 9: // 9XY0
    if (chip8->V[x] != chip8->V[y]) {
      chip8->pc += 2;
    }
    break;
  default:
    return;
  }
}
