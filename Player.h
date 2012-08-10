#ifndef Player_h
#define Player_h

#include "Drawable.h"

class Player : public Drawable
{
  public:
    Player(); // TODO: This shouldn't be required, but how to we have an instance field without the default constructor?
    Player(Display display);

    void paint();
    unsigned int getPosition();
    void setPositionLeft();
    void setPositionRight();
};

#endif