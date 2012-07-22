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

unsigned int player_getPosition()
{
  return player_position;
}

void player_setPositionLeft()
{
  player_position = PLAYER_POSITION_LEFT;
}

void player_setPositionRight()
{
  player_position = PLAYER_POSITION_RIGHT;
}

void player_display()
{
  ;
}
