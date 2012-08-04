#ifndef Obstacle_h
#define Obstacle_h

#include "Drawable.h"

class Obstacle : public Drawable
{
    virtual void paint() = 0;
};

#endif