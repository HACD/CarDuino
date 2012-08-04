#ifndef Drawable_h
#define Drawable_h

#include "Display.h"

typedef struct co_ordinates_t 
{
  int x;
  int y;
} Coordinates;

class Drawable
{
  private:
    Display _display;
    Coordinates _coordinates;
    char** _avatar;
    bool _dirty;
    
  public:
    Drawable(Display display);

    virtual void paint() = 0;
};

#endif
