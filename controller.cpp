#include "controller.h"

#ifdef __linux__
  #include <stdlib.h>
  #include <string.h>
  #include <unistd.h>
  #include <sys/select.h>
  #include <termios.h>
#endif

namespace Controller {

  // Linux implementation
#ifdef __linux__

struct termios orig_termios;
struct termios new_termios;

// Source: https://stackoverflow.com/questions/448944/c-non-blocking-keyboard-input
// Also see: https://man7.org/linux/man-pages/man3/termios.3.html

void reset_terminal_mode()
{
    tcsetattr(0, TCSANOW, &orig_termios);
}

void set_conio_terminal_mode()
{
    /* take two copies - one for now, one for later */
    tcgetattr(0, &orig_termios);
    memcpy(&new_termios, &orig_termios, sizeof(new_termios));

    /* register cleanup handler, and set the new terminal mode */
    atexit(reset_terminal_mode);
    orig_termios.c_lflag &= ~ECHO;    // HACK FOR ECHO !
    // new_termios.c_lflag &= ~ICANON;
    // new_termios.c_lflag &= ~ECHO; /* turn off ECHO */
    cfmakeraw(&new_termios);    // Act as old Version 7 terminal driver (no echo, char per char)
    tcsetattr(0, TCSANOW, &new_termios);    // TCSANOW — Make the change immediately.
}

int kbhit()
{
    struct timeval tv = { 0L, 0L };
    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(0, &fds);
    return select(1, &fds, NULL, NULL, &tv);
}

int getch()
{
    int r;
    unsigned char c;
    if ((r = read(0, &c, sizeof(c))) < 0) {
        return r;
    } else {
        return c;
    }
}

Key get_key_press(void) {
    set_conio_terminal_mode();

    Key outputKey = Key::NONE;
    if (kbhit()) {
      // Arrow key are two codes: 27 91 and keycode
      int key = getch();
      // std::cout << "Got key pressed: " << key << std::endl;
      if (key == 27 && getch() == 91) {
        key = getch();
        // std::cout << "Got Third key pressed: " << key << std::endl;
        switch (key) {
          case 65: outputKey = Key::UP; break;
          case 66: outputKey = Key::DOWN; break;
          case 67: outputKey = Key::RIGHT; break;
          case 68: outputKey = Key::LEFT; break;
          default: outputKey = Key::UNKNOWN;
        }
      } else {
        switch (key) {
          case 10: outputKey = Key::ENTER; break;
          default: outputKey = Key::UNKNOWN;
        }
      }
    }

    reset_terminal_mode();
    return outputKey;
}

#endif

};