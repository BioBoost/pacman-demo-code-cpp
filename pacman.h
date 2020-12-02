#pragma once

#include "direction.h"
#include "canvas.h"

// struct Location {
//   int x;
//   int y;
// }

class PacMan {

  public:
    PacMan(int x, int y) {
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
      switch(direction) {
        case Direction::LEFT: _x -= speed; break;
        case Direction::RIGHT: _x += speed; break;
        case Direction::UP: _y -= speed; break;
        case Direction::DOWN: _y+= speed; break;
      }
    }

    void next_position(int * x, int * y) {
      *x = _x;
      *y = _y;
      switch(direction) {
        case Direction::LEFT: *x = _x - speed; break;
        case Direction::RIGHT: *x = _x + speed; break;
        case Direction::UP: *y = _y - speed; break;
        case Direction::DOWN: *y = _y + speed; break;
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
    int _x = 0;
    int _y = 0;

    int speed = 1;

    Direction direction = Direction::LEFT;
};