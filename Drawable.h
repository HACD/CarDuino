#ifndef Drawable_h
#define Drawable_h

#include "Display.h"

class Drawable
{
  protected:
    Display _display;
    Coordinates _coordinates;
    char** _avatar;
    bool _dirty;
    
  public:
    virtual void paint() = 0;
};

#endif
