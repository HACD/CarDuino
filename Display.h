#ifndef Display_h
#define Display_h

class Display
{
  public:
    Display();

    void setup();
    void paint();
    void loop();
    void display_intro();
    bool display_player(unsigned int);
    void display_endGame(unsigned int);
};

#endif