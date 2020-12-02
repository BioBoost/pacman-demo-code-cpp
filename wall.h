#pragma once

#include "canvas.h"

class Wall {

  public:
    Wall(int x, int y) {
      _x = x;
      _y = y;
    }

  public:
    int x() {
      return _x;
    }

    int y() {
      return _y;
    }

    void render(Canvas * canvas) {
      canvas->draw_symbol(x(), y(), '#');
    }

  private:
    int _x = 0;
    int _y = 0;
};