#ifndef Drawable_h
#define Drawable_h

#include "Display.h"

class Drawable
{
  public:
		Drawable(Display display);

    virtual void paint() = 0;
};

#endif