#ifndef Game_h
#define Game_h

#include "Display.h"

class Game
{
  public:
    Game(Display display);
    void tick();
    bool didPlayerCollide(unsigned int);
};

#endif