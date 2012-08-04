#include "Display.h"
#include "Input.h"
#include "Player.h"

/*------------------------------------------------------------------------------
  Variables
  ----------------------------------------------------------------------------*/

unsigned long last_updated = millis();

Input input(A0);
Drawable** drawables;
Display display;

/*------------------------------------------------------------------------------
  Functions
  ----------------------------------------------------------------------------*/

void setup()
{
  drawables = (Drawable**) malloc( 16 * 2 * sizeof(Drawable) );
  drawables[0] = new Player();
  
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
      drawables[0]->paint();
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
      
      collide = display.display_player( player_getPosition() );

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

