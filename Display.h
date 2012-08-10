#ifndef Display_h
#define Display_h

#include <stdint.h>

typedef struct co_ordinates_t 
{
  int x;
  int y;
} Coordinates;

class Display
{
  public:
    Display();

    void setup();
    void paint();
    void loop();
    void clear();
    bool did_player_collide(unsigned int);
    void print(Coordinates, char);
    void print(uint8_t x, uint8_t y, char[]);
};

#endif