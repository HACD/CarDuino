#ifndef Game_h
#define Game_h

#include "Display.h"
#include "Player.h"

class Game
{
  protected:
    Display _display;
    Player _player;

  public:
    Game(Display display, Player player);
    void tick();
    bool didPlayerCollide();
};

#endif