#pragma once

#include "entity.h"
#include "direction.h"
#include "canvas.h"

// struct Location {
//   int x;
//   int y;
// }

class PacMan : public Entity {

  public:
    PacMan(int x, int y);

  public:
    void render(Canvas * canvas);
    void update(void);

  public:
    void next_position(int * x, int * y);

  public:
    void stop(void);
    void down(void);
    void up(void);
    void left(void);
    void right(void);

  private:
    void move(Direction direction);

  private:
    int speed = 1;
    Direction direction = Direction::LEFT;
};