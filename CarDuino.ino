#include "Display.h"
#include "Input.h"
#include "Player.h"

/*------------------------------------------------------------------------------
  Variables
  ----------------------------------------------------------------------------*/

unsigned long last_updated = millis();

Input input(A0);
Display display;
Player player(display);

/*------------------------------------------------------------------------------
  Functions
  ----------------------------------------------------------------------------*/

void setup()
{
  display.setup();
}

void loop()
{
  while(true)
  {
    unsigned int score = 0;
    bool collide = false;

    display.display_intro();
    delay(3000);

    while(!collide)
    {
      unsigned long now = millis();

      uint8_t buttonPressed = input.getPressedButton();

      switch( buttonPressed )
      {
        case Input::DOWN_BUTTON_PRESSED :
          player.setPositionLeft();
        break;
        case Input::UP_BUTTON_PRESSED :
          player.setPositionRight();
        break;
        default:
          ;
        break;
      }
      
      collide = display.did_player_collide( player.getPosition() );
      player.paint();

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
        display.loop();
        last_updated = now;

        score++;
      }

      delay(20);
    }

    display.display_endGame( score );

    delay(5000);
  }
}

