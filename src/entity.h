#pragma once

class Entity {

  public:
    Entity(int x, int y);

  public:
    int x();
    int y();
  
  public:
    void move(int x, int y);

  private:
    int _x = 0;
    int _y = 0;
};