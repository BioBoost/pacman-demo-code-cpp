#pragma once

#include "canvas.h"
#include "entity.h"

// Class Apple inherits from class Entity
// Entity = Base class or super class
// Apple = Child class or sub class
//
// Inheritance allows us to inherit the
// attributes and methods of the base class.
// Do note that private members are however not
// accessible. Only public and protected members.
class Apple : public Entity  {

  public:
    Apple(int x, int y);

  public:
    void render(Canvas * canvas);
};