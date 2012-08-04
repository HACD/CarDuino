#include "Drawable.h"

Drawable::Drawable()
{
  ;
};

Drawable::Drawable(Display display, Coordinates coordinates, int rate, String avatar)
{
  this->_display = display;
  this->_coordinates = coordinates;
  this->_rate = rate;
  this->_avatar = avatar;
  
  this->_dirty = false;
};
