#include "Drawable.h"

Drawable::Drawable()
{
};

Drawable::Drawable(Display display, Coordinates coordinates, int rate, String avatar)
{
  _display = display;
  _coordinates = coordinates;
  _rate = rate;
  _avatar = avatar;
  
  _dirty = false;
};