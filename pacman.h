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
    PacMan(int x, int y)
      : Entity(x, y) {
    }

  public:
    void render(Canvas * canvas) {
      switch(direction) {
        case Direction::LEFT: canvas->draw_symbol(x(), y(), '>'); break;
        case Direction::RIGHT: canvas->draw_symbol(x(), y(), '<'); break;
        case Direction::UP: canvas->draw_symbol(x(), y(), 'v'); break;
        case Direction::DOWN: canvas->draw_symbol(x(), y(), '^'); break;
      }
    }

    void stop(void) {
      speed = 0;
    }

    void update(void) {
      int x = 0;
      int y = 0;
      next_position(&x, &y);
      Entity::move(x, y);   // move of Entity !

      // switch(direction) {
      //   case Direction::LEFT: _x -= speed; break;
      //   case Direction::RIGHT: _x += speed; break;
      //   case Direction::UP: _y -= speed; break;
      //   case Direction::DOWN: _y+= speed; break;
      // }
    }

    void next_position(int * x, int * y) {
      *x = this->x();
      *y = this->y();
      switch(direction) {
        case Direction::LEFT: *x = this->x() - speed; break;
        case Direction::RIGHT: *x = this->x() + speed; break;
        case Direction::UP: *y = this->y() - speed; break;
        case Direction::DOWN: *y = this->y() + speed; break;
      }
    }

    void down(void) {
      move(Direction::DOWN);
    }

    void up(void) {
      move(Direction::UP);
    }

    void left(void) {
      move(Direction::LEFT);
    }

    void right(void) {
      move(Direction::RIGHT);
    }

  private:
    void move(Direction direction) {
      this->direction = direction;
      speed = 1;
    }

  private:
    int speed = 1;
    Direction direction = Direction::LEFT;
};