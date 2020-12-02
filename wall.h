#pragma once

#include "entity.h"
#include "canvas.h"

// Overerving = inheritance
class Wall : public Entity {

  public:
    Wall(int x, int y)
      : Entity(x, y) {
    }

  public:
    void render(Canvas * canvas) {
      canvas->draw_symbol(x(), y(), '#');
    }

};