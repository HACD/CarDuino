#include "Intro.h"
#include "Display.h"

Intro::Intro(Display display) 
{
   _display = display;
}
  
void Intro::paint() 
{
  _display.clear();
  _display.print(0, 0, "    CarDuino");
  _display.print(0, 1, "  Insert Coin");
}