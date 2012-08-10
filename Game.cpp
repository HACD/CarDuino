#include "Game.h"
#include "Display.h"
#include <Arduino.h>
#include "Player.h"

const char BLOCKER =  '#';

char BLOCKED_LEFT[2] =  { BLOCKER, ' ' };
char BLOCKED_RIGHT[2] = {' ', BLOCKER };
char NOT_BLOCKED[2] = {' ', ' '};

char* WHEN_BLOCKED_LEFT[2] = { BLOCKED_LEFT, NOT_BLOCKED };
char* WHEN_BLOCKED_RIGHT[2] = { BLOCKED_RIGHT, NOT_BLOCKED };
char* WHEN_NOT_BLOCKED[3] = { BLOCKED_LEFT, BLOCKED_RIGHT, NOT_BLOCKED };

Display _display;

Game::Game(Display display) 
{
   _display = display;
}

bool Game::didPlayerCollide(unsigned int playerPosition)
{
  char c = _display.getCharAt(15, playerPosition ^ 1); // TODO: 15 should be Player::RowIndex or something?

  return (c == '#');  // if there is an obstacle here
}

char* getValidRow() {
  const int currentTopRowIndex = 0;

  if (_display.getCharAt(currentTopRowIndex, 0) == BLOCKER && _display.getCharAt(currentTopRowIndex, 1) == ' ') {
    return WHEN_BLOCKED_LEFT[random(0, 2)];
  }

  if (_display.getCharAt(currentTopRowIndex, 0) == ' ' && _display.getCharAt(currentTopRowIndex, 1) == BLOCKER) {
    return WHEN_BLOCKED_RIGHT[random(0, 2)];
  }

  return WHEN_NOT_BLOCKED[random(0, 3)];
}

void Game::tick() 
{
   char* rowToPushToTop = getValidRow();
   _display.prependRow(rowToPushToTop);
   _display.paint();
}