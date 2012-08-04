#include "Player.h"
#include "Display.h"

/*------------------------------------------------------------------------------
  Defines
  ----------------------------------------------------------------------------*/

// button voltage pin
#define PLAYER_POSITION_LEFT           1
#define PLAYER_POSITION_RIGHT          0


/*------------------------------------------------------------------------------
  Variables
  ----------------------------------------------------------------------------*/

unsigned int player_position = PLAYER_POSITION_LEFT;

unsigned int Player::getPosition()
{
  return player_position;
}

void Player::setPositionLeft()
{
  player_position = PLAYER_POSITION_LEFT;
}

void Player::setPositionRight()
{
  player_position = PLAYER_POSITION_RIGHT;
}

Player::Player(Display display) 
{
   _display = display;
}
  
void Player::paint() 
{
  _coordinates.x = 15;
  _coordinates.y = player_position;

  _display.print(_coordinates, 'o');

  _coordinates.x = 15;
  _coordinates.y = player_position ^ 1;

  _display.print(_coordinates, ' ');
}