#ifndef Score_h
#define Score_h

#include "Drawable.h"

class Score : public Drawable
{
  public:
    Score(Display display);

    void paint();
    void paint(unsigned int score);
};

#endif