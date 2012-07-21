/*--------------------------------------------------------------------------------------
  Defines
--------------------------------------------------------------------------------------*/

// button voltage pin
#define PLAYER_POSITION_LEFT           0
#define PLAYER_POSITION_RIGHT          1
#define PLAYER_AVATAR               'o'


/*--------------------------------------------------------------------------------------
  Variables
--------------------------------------------------------------------------------------*/

unsigned int player_position = PLAYER_POSITION_LEFT;

unsigned int player_getPosition()
{
  return player_position;
}

void player_display()
{
  ;
}
