#include "game.h"

#include <unistd.h>       // usleep
#include "controller.h"   // Keyboard input
#include <stdlib.h>       // srand, rand
#include <time.h>         // time

Game::Game(void)
  : pacman(25, 5) {

  srand(time(NULL));

  create_walls();
  create_apples();

  game_loop();
}

void Game::create_walls(void) {
  // (0, 0) is top left
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      if (x == 0 || y == 0 || x == WIDTH-1 || y == HEIGHT-1) {
        walls.push_back(Wall(x, y));
      }
    }
  }
}

void Game::create_apples(void) {
  apples.push_back(Apple(3, 5));
  apples.push_back(Apple(12, 1));
  apples.push_back(Apple(8, 7));
}

void Game::game_loop(void) {
  int counter = 0;
  while (!gameOver) {
    counter++;
    render();
    if (counter >= 5) {
      update();
      counter = 0;
    }
    usleep(100'000);  // 100ms

    // On windows use:
    // #include <windows.h>
    // Sleep(milliseconds)
  }
}

void Game::update(void) {
  process_keyboard_input();
  check_for_collisions_with_walls();

  // Dynamic state changes !!
  pacman.update();

  check_for_collisions_with_apples();

  // Wall, apple = static
}

void Game::render(void) {
  canvas.clear();

  // WALLS
  for(auto wall : walls) {
    // canvas.draw_symbol(wall.x(), wall.y(), '#');
    wall.render(&canvas);
  }

  // PACMAN
  // canvas.draw_symbol(pacman.x(), pacman.y(), '>');
  pacman.render(&canvas);

  // APPLES
  for(auto apple : apples) {
    // canvas.draw_symbol(apple.x(), apple.y(), 'o');
    apple.render(&canvas);
  }

  canvas.output_to_terminal();
}

void Game::check_for_collisions_with_walls(void) {
  int x = 0;
  int y = 0;
  pacman.next_position(&x, &y);

  for(auto wall : walls) {
    if (x == wall.x() && y == wall.y()) {
      pacman.stop();
    }
  }
}

void Game::check_for_collisions_with_apples(void) {
  int appleToEat = -1;
  for (int i = 0; i < apples.size(); i++) {
    if (pacman.x() == apples[i].x() &&
      pacman.y() == apples[i].y()) {
        appleToEat = i;
      }
  }

  if (appleToEat >= 0) {
    apples.erase(apples.begin() + appleToEat);
    apples.push_back(Apple(1+rand()%(WIDTH-2), 1+rand()%(HEIGHT-2)));
  }
}

void Game::process_keyboard_input(void) {
  Controller::Key pressedKey = Controller::get_key_press();

  switch (pressedKey) {
    case Controller::Key::DOWN: pacman.down(); break;
    case Controller::Key::UP: pacman.up(); break;
    case Controller::Key::LEFT: pacman.left(); break;
    case Controller::Key::RIGHT: pacman.right(); break;
  }
}