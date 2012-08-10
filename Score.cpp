#include "Score.h"
#include "Display.h"
#include <stdio.h>

Score::Score(Display display) 
{
   _display = display;
}

void Score::paint() 
{
  // TODO: This should actually pull the score from somewhere instead of having it passed in.
}
  
void Score::paint(unsigned int score) 
{
  char finalScore[32];
  sprintf(finalScore, "   Score: %d", score);

  _display.clear();
  _display.print(0, 0, "   Game Over");
  _display.print(0, 1, &finalScore[0]);
}