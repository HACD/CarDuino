#include <Arduino.h>
#include "Input.h"

Input::Input(uint8_t pin)
{
  this->_buttonPin = pin;
  // set BUTTON_PIN to input and ensure pullup is off
  pinMode( this->_buttonPin, INPUT );
  digitalWrite( this->_buttonPin, LOW );
};

void Input::_readButtonState()
{
  this->_buttonPressed = Input::NO_BUTTON_PRESSED;
  
  unsigned int voltage;
  
  //read the button ADC pin voltage
  voltage = analogRead( this->_buttonPin );

  //sense if the voltage falls within valid voltage windows
  if( voltage < ( Input::_buttonRightADC + Input::_buttonThreshold ) )
  {
    this->_buttonPressed = RIGHT_BUTTON_PRESSED;
  }
  
  else if( 
      voltage >= ( Input::_buttonUpADC - Input::_buttonThreshold ) &&
      voltage <= ( Input::_buttonUpADC + Input::_buttonThreshold ) 
  )
  {
    this->_buttonPressed = UP_BUTTON_PRESSED;
  }
  
  else if( 
      voltage >= ( Input::_buttonDownADC - Input::_buttonThreshold ) &&
      voltage <= ( Input::_buttonDownADC + Input::_buttonThreshold ) 
  )
  {
    this->_buttonPressed = DOWN_BUTTON_PRESSED;
  }
  
  else if( 
      voltage >= ( Input::_buttonLeftADC - Input::_buttonThreshold ) &&
      voltage <= ( Input::_buttonLeftADC + Input::_buttonThreshold ) 
  )
  {
    this->_buttonPressed = LEFT_BUTTON_PRESSED;
  }
  
  else if( 
      voltage >= ( Input::_buttonSelectADC - Input::_buttonThreshold ) &&
      voltage <= ( Input::_buttonSelectADC + Input::_buttonThreshold ) 
  )
  {
    this->_buttonPressed = SELECT_BUTTON_PRESSED;
  }
};

uint8_t Input::getPressedButton()
{
  this->_readButtonState();
  
  return this->_buttonPressed;
};
