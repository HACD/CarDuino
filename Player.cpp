#include "Player.h"
#include "Display.h"

const unsigned int PLAYER_POSITION_LEFT = 1;
const unsigned int PLAYER_POSITION_RIGHT  = 0;

unsigned int _player_position = PLAYER_POSITION_LEFT;

Player::Player() 
{
}

Player::Player(Display display) 
{
   _display = display;
}

unsigned int Player::getPosition()
{
  return _player_position;
}

void Player::setPositionLeft()
{
  _player_position = PLAYER_POSITION_LEFT;
}

void Player::setPositionRight()
{
  _player_position = PLAYER_POSITION_RIGHT;
}
  
void Player::paint() 
{
  _coordinates.x = 15;
  _coordinates.y = _player_position;

  _display.print(_coordinates, 'o');

  _coordinates.x = 15;
  _coordinates.y = _player_position ^ 1;

  _display.print(_coordinates, ' ');
}