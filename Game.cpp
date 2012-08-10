#include "Game.h"
#include "Display.h"
#include <Arduino.h>
#include "Player.h"

const char BLOCKER = '#';

char BLOCKED_LEFT[2] =  { BLOCKER, ' ' };
char BLOCKED_RIGHT[2] = {' ', BLOCKER };
char NOT_BLOCKED[2] = {' ', ' '};

char* WHEN_BLOCKED_LEFT[2] = { BLOCKED_LEFT, NOT_BLOCKED };
char* WHEN_BLOCKED_RIGHT[2] = { BLOCKED_RIGHT, NOT_BLOCKED };
char* WHEN_NOT_BLOCKED[3] = { BLOCKED_LEFT, BLOCKED_RIGHT, NOT_BLOCKED };

Game::Game(Display display, Player player) 
{
   _display = display;
   _player = player;
}

bool Game::didPlayerCollide()
{
  unsigned int playerPosition = _player.getPosition() == 1 ? 0 : 1;
  char characterWhereAvatarIs = _display.getCharAt(15, playerPosition); // TODO: 15 should be Player::RowIndex or something?

  return (characterWhereAvatarIs == '#');  // if there is an obstacle here
}

char* getValidRow(Display display) {
  const int currentTopRowIndex = 0;

  if (display.getCharAt(currentTopRowIndex, 0) == BLOCKER && display.getCharAt(currentTopRowIndex, 1) == ' ') {
    return WHEN_BLOCKED_LEFT[random(0, 2)];
  }

  if (display.getCharAt(currentTopRowIndex, 0) == ' ' && display.getCharAt(currentTopRowIndex, 1) == BLOCKER) {
    return WHEN_BLOCKED_RIGHT[random(0, 2)];
  }

  return WHEN_NOT_BLOCKED[random(0, 3)];
}

void Game::tick() 
{
   char* rowToPushToTop = getValidRow(_display);
   _display.prependRow(rowToPushToTop);
   _display.paint();
}