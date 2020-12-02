#include "entity.h"

Entity::Entity(int x, int y) {
  move(x, y);
}

int Entity::x() {
  return _x;
}

int Entity::y() {
  return _y;
}

void Entity::move(int x, int y) {
  _x = x;
  _y = y;
}