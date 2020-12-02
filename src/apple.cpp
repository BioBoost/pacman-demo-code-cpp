#include "apple.h"

Apple::Apple(int x, int y)
  : Entity(x, y) {
}

void Apple::render(Canvas * canvas) {
  canvas->draw_symbol(x(), y(), 'o');
}