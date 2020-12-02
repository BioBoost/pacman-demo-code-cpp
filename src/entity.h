#pragma once

class Entity {

  public:
    Entity(int x, int y) {
      move(x, y);
    }

  public:
    int x() {
      return _x;
    }

    int y() {
      return _y;
    }

    void move(int x, int y) {
      _x = x;
      _y = y;
    }
  
  // public:
  //   virtual void render(void) = 0;
  //   virtual void update(Canvas * canvas) = 0;

  private:
    int _x = 0;
    int _y = 0;
};