#ifndef Input_h
#define Input_h

#include <stdint.h>
#include <pins_arduino.h>

class Input 
{
  private:
    static const int _buttonRightADC = 0;
    static const int _buttonUpADC = 145;
    static const int _buttonDownADC = 329;
    static const int _buttonLeftADC = 505;
    static const int _buttonSelectADC = 741;
    static const int _buttonThreshold = 10;
    
    uint8_t _buttonPressed;
    uint8_t _buttonPin;
    
    void _readButtonState();
  
  public:
    static const uint8_t NO_BUTTON_PRESSED = 0;
    static const uint8_t RIGHT_BUTTON_PRESSED = 1;
    static const uint8_t UP_BUTTON_PRESSED = 2;
    static const uint8_t DOWN_BUTTON_PRESSED = 3;
    static const uint8_t LEFT_BUTTON_PRESSED = 4;
    static const uint8_t SELECT_BUTTON_PRESSED = 5;

    Input(uint8_t pin);
    uint8_t getPressedButton();
  
};

#endif