#ifndef Drawable_h
#define Drawable_h

#include <WString.h>
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
    int _rate;
    String _avatar;
    bool _dirty;
    
  public:
    Drawable();
    Drawable(Display display, Coordinates coordinates, int rate, String avatar);

    virtual void paint() = 0;
};

#endif

