#ifndef Intro_h
#define Intro_h

#include "Drawable.h"

class Intro : public Drawable
{
  public:
    Intro(Display display);

    void paint();
};

#endif