#include "pacman.h"

// struct Location {
//   int x;
//   int y;
// }

PacMan::PacMan(int x, int y)
  : Entity(x, y) {
}

void PacMan::render(Canvas * canvas) {
  switch(direction) {
    case Direction::LEFT: canvas->draw_symbol(x(), y(), '>'); break;
    case Direction::RIGHT: canvas->draw_symbol(x(), y(), '<'); break;
    case Direction::UP: canvas->draw_symbol(x(), y(), 'v'); break;
    case Direction::DOWN: canvas->draw_symbol(x(), y(), '^'); break;
  }
}

void PacMan::stop(void) {
  speed = 0;
}

void PacMan::update(void) {
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

void PacMan::next_position(int * x, int * y) {
  *x = this->x();
  *y = this->y();
  switch(direction) {
    case Direction::LEFT: *x = this->x() - speed; break;
    case Direction::RIGHT: *x = this->x() + speed; break;
    case Direction::UP: *y = this->y() - speed; break;
    case Direction::DOWN: *y = this->y() + speed; break;
  }
}

void PacMan::down(void) {
  move(Direction::DOWN);
}

void PacMan::up(void) {
  move(Direction::UP);
}

void PacMan::left(void) {
  move(Direction::LEFT);
}

void PacMan::right(void) {
  move(Direction::RIGHT);
}

void PacMan::move(Direction direction) {
  this->direction = direction;
  speed = 1;
}
