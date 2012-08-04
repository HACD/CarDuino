#ifndef Display_h
#define Display_h

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
    void display_intro();
    bool did_player_collide(unsigned int);
    void display_endGame(unsigned int);
    void print(Coordinates, char);
};

#endif