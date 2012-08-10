#include "Game.h"
#include "Score.h"
#include "Intro.h"
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
Player player(display);
Intro intro(display);
Score score(display);
Game game(display);

void setup()
{
  display.setup();
}

void loop()
{
  while(true)
  {
    unsigned int playerScore = 0;

    intro.paint();
    delay(3000);

    while (true)
    {
      unsigned long now = millis();

      uint8_t buttonPressed = input.getPressedButton();
      switch (buttonPressed)
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
      
      bool collide = game.didPlayerCollide(player.getPosition());
      if (collide)
      {
        break;
      }

      player.paint();

      int speed = 1000 - (10 * playerScore);
      if (speed < 100)
      {
        speed = 100;
      }

      if ((now - last_updated) > speed)
      {
        game.tick();
        last_updated = now;
        playerScore++;
      }

      delay(20);
    }

    score.paint(playerScore);

    delay(5000);
  }
}

