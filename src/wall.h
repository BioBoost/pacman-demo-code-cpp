#pragma once

#include "entity.h"
#include "canvas.h"

class Wall : public Entity {

  public:
    Wall(int x, int y);

  public:
    void render(Canvas * canvas);

};