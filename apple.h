#pragma once

#include "canvas.h"
#include "entity.h"

class Apple : public Entity  {

  public:
    Apple(int x, int y);

  public:
    void render(Canvas * canvas);
};