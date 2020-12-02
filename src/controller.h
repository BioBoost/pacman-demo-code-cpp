#pragma once

namespace Controller {

  enum class Key {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    ENTER,
    UNKNOWN,
    NONE
  };

  extern Key get_key_press(void);

};