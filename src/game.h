#pragma once

#include <vector>
#include "pacman.h"
#include "wall.h"
#include "apple.h"
#include "canvas.h"

class Game {

  public:
    Game(void);

  private:
    void create_walls(void);
    void create_apples(void);

  private:
    // While loop that calls update and render
    void game_loop(void);

    // Update the internal state of the entities
    // Check for collisions
    // Handle user keyboard input
    // Should run a steady and known TICK rate.
    void update(void);

    // Drawing on the canvas. In real game engine this
    // is done as fast as possible. Should not have a lower
    // rate then update because then we'll the game objects
    // jump from once place to another
    void render(void);

  private:
    void check_for_collisions_with_walls(void);
    void check_for_collisions_with_apples(void);
    void process_keyboard_input(void);

  private:
    PacMan pacman;
    std::vector<Wall> walls;      // std::vector = Dynamic Array
    std::vector<Apple> apples;

    Canvas canvas;                // Where the game entities are drawn on

    const static int WIDTH = 30;
    const static int HEIGHT = 10;

    bool gameOver = false;
};