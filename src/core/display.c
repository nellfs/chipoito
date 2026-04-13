#include "display.h"

void display_clear_screen(Display *self) {
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      self->screen[y * WIDTH + x] = 0;
    }
  }
}
