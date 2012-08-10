#include <Arduino.h>
#include "Input.h"

Input::Input(uint8_t pin)
{
  _buttonPin = pin;

  // set BUTTON_PIN to input and ensure pullup is off
  pinMode(_buttonPin, INPUT);
  digitalWrite(_buttonPin, LOW);
};

void Input::_readButtonState()
{
  _buttonPressed = Input::NO_BUTTON_PRESSED;
  
  //read the button ADC pin voltage
  unsigned int voltage = analogRead(_buttonPin);

  //sense if the voltage falls within valid voltage windows
  if (voltage < (_buttonRightADC + _buttonThreshold))
  {
    _buttonPressed = RIGHT_BUTTON_PRESSED;
  }
  else if (voltage >= (_buttonUpADC - _buttonThreshold) && voltage <= (_buttonUpADC + _buttonThreshold))
  {
    _buttonPressed = UP_BUTTON_PRESSED;
  }
  else if (voltage >= (_buttonDownADC - _buttonThreshold) && voltage <= (_buttonDownADC + _buttonThreshold))
  {
    _buttonPressed = DOWN_BUTTON_PRESSED;
  }
  else if (voltage >= (_buttonLeftADC - _buttonThreshold) &&voltage <= (_buttonLeftADC + _buttonThreshold))
  {
    _buttonPressed = LEFT_BUTTON_PRESSED;
  }
  else if (voltage >= (_buttonSelectADC - _buttonThreshold) && voltage <= (_buttonSelectADC + _buttonThreshold ) )
  {
    _buttonPressed = SELECT_BUTTON_PRESSED;
  }
};

uint8_t Input::getPressedButton()
{
  _readButtonState();
  
  return _buttonPressed;
};