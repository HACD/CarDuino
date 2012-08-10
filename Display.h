#ifndef Display_h
#define Display_h

#include <stdint.h>

typedef struct co_ordinates_t 
{
  int x;
  int y;
} Coordinates;

typedef char** Board;

class Display
{
  public:
    Display();

    void setup();
    void paint();
    void clear();
    void print(Coordinates, char);
    void print(uint8_t x, uint8_t y, char[]);
    void prependRow(char* append);
    char getCharAt(uint8_t row, uint8_t column);
};

#endif