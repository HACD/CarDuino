#include "Display.h"
#include "Player.h"
#include "Intro.h"
#include "Score.h"
#include "Game.h"
#include "Input.h"

unsigned long last_updated = millis();

Input _input(A0);
Display _display;
Player _player(_display);
Intro _intro(_display);
Score _score(_display);
Game _game(_display, _display);

void setup()
{
  _display.setup();
}

void handleInput() 
{
  uint8_t buttonPressed = _input.getPressedButton();
  switch (buttonPressed)
  {
    case Input::DOWN_BUTTON_PRESSED :
      _player.setPositionLeft();
      break;

    case Input::UP_BUTTON_PRESSED :
      _player.setPositionRight();
      break;

    default:
      break;
  }
}

unsigned int calculateSpeed(unsigned int playerScore) 
{
  unsigned int speed = 1000 - (10 * playerScore);
  if (speed < 100)
  {
    speed = 100;
  }

  return speed;
}

void loop()
{
  while(true)
  {
    unsigned int playerScore = 0;

    _intro.paint();
    delay(3000);

    while (true)
    {
      unsigned long now = millis();

      handleInput();
      
      if (_game.didPlayerCollide())
        break;

      _player.paint();

      if ((now - last_updated) > calculateSpeed(playerScore))
      {
        _game.tick();
        last_updated = now;
        playerScore++;
      }

      delay(20);
    }

    _score.paint(playerScore);

    delay(5000);
  }
}

