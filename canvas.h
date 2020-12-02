#pragma once

#include <iostream>

class Canvas {

  public:
    Canvas(void) {
      clear();
    }

    void clear(void) {
      for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
          screen[x][y] = ' ';
        }
      }
    }

    void draw_symbol(int x, int y, char symbol) {
      screen[x][y] = symbol;
    }

    void output_to_terminal(void) {
      system("clear");
      std::cout << "Pacman field ..." << std::endl;
      for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
          std::cout << screen[x][y];
        }
        std::cout << std::endl;
      }
      std::cout << std::endl;
    }


  private:
    static const unsigned int WIDTH = 30;
    static const unsigned int HEIGHT = 10;

    char screen[WIDTH][HEIGHT];
};