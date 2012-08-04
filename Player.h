#ifndef Player_h
#define Player_h

#include "Drawable.h"

class Player : public Drawable
{
  public:
    Player(Display display);

    virtual void paint();
    unsigned int getPosition();
    void setPositionLeft();
    void setPositionRight();
};

#endif