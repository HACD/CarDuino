#ifndef Player_h
#define Player_h

#include "Drawable.h"

class Player : public Drawable
{
    virtual void paint() = 0;
};

#endif