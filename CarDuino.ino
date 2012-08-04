#include "Input.h"
#include "Display.h"

/*------------------------------------------------------------------------------
  Variables
  ----------------------------------------------------------------------------*/

unsigned long last_updated = millis();

Input input(A0);

/*------------------------------------------------------------------------------
  Functions
  ----------------------------------------------------------------------------*/

void setup()
{
  display_setup();
}

void loop()
{
  while(true)
  {
    unsigned int score = 0;
    bool collide = false;

    display_intro();
    delay(3000);

    while(!collide)
    {
      unsigned long now = millis();

      uint8_t buttonPressed = input.getPressedButton();

      switch( buttonPressed )
      {
        case Input::DOWN_BUTTON_PRESSED :
          player_setPositionLeft();
        break;
        case Input::UP_BUTTON_PRESSED :
          player_setPositionRight();
        break;
        default:
          ;
        break;
      }
      
      collide = display_player( player_getPosition() );

      if(collide)
      {
        break;
      }

      int speed = 1000 - (10 * score);
      if( speed < 100)
      {
        speed = 100;
      }

      if( now - last_updated > speed )
      {
        display_loop();
        last_updated = now;

        score++;
      }

      delay(20);
    }

    display_endGame( score );

    delay(5000);
  }
}

