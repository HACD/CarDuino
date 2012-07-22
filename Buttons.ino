/*------------------------------------------------------------------------------
  Defines
  ----------------------------------------------------------------------------*/

// button voltage pin
#define BUTTONS_BUTTON_PIN               A0

// button voltage values
#define BUTTONS_RIGHT_10BIT_ADC           0
#define BUTTONS_UP_10BIT_ADC            145
#define BUTTONS_DOWN_10BIT_ADC          329
#define BUTTONS_LEFT_10BIT_ADC          505
#define BUTTONS_SELECT_10BIT_ADC        741

// button voltage threshold
#define BUTTONS_BUTTON_THRESHOLD        10


/*------------------------------------------------------------------------------
  Variables
  ----------------------------------------------------------------------------*/

byte buttons_leftButtonDown = false;
byte buttons_rightButtonDown = false;
byte buttons_upButtonDown = false;
byte buttons_downButtonDown = false;
byte buttons_selectButtonDown = false;


/*------------------------------------------------------------------------------
  Functions
  ----------------------------------------------------------------------------*/

/**
 * Initialises the button interface
 */
void buttons_setup()
{
  // set BUTTON_PIN to input and ensure pullup is off
  pinMode( BUTTONS_BUTTON_PIN, INPUT );
  digitalWrite( BUTTONS_BUTTON_PIN, LOW );

  // initalise up serial port
  Serial.begin(9600);
  while (!Serial)
  {
    ;
  }
}

/**
 * Button state getter methods
 */
byte buttons_isLeftPressed()
{
  return buttons_leftButtonDown;
}

byte buttons_isRightPressed()
{
  return buttons_rightButtonDown;
}

byte buttons_isUpPressed()
{
  return buttons_upButtonDown;
}

byte buttons_isDownPressed()
{
  return buttons_downButtonDown;
}

byte buttons_isSelectPressed()
{
  return buttons_selectButtonDown;
}

/**
 * Reads and updates the button state
 */
unsigned int buttons_updateState()
{
  unsigned int voltage;

  buttons_rightButtonDown = false;
  buttons_upButtonDown = false;
  buttons_downButtonDown = false;
  buttons_leftButtonDown = false;
  buttons_selectButtonDown = false;

  //read the button ADC pin voltage
  voltage = analogRead( BUTTONS_BUTTON_PIN );

  //sense if the voltage falls within valid voltage windows
  if( voltage < ( BUTTONS_RIGHT_10BIT_ADC + BUTTONS_BUTTON_THRESHOLD ) )
  {
    buttons_rightButtonDown = true;
  }
  else if( voltage >= ( BUTTONS_UP_10BIT_ADC - BUTTONS_BUTTON_THRESHOLD )
        && voltage <= ( BUTTONS_UP_10BIT_ADC + BUTTONS_BUTTON_THRESHOLD ) )
  {
    buttons_upButtonDown = true;
  }
  else if( voltage >= ( BUTTONS_DOWN_10BIT_ADC - BUTTONS_BUTTON_THRESHOLD )
        && voltage <= ( BUTTONS_DOWN_10BIT_ADC + BUTTONS_BUTTON_THRESHOLD ) )
  {
    buttons_downButtonDown = true;
  }
  else if( voltage >= ( BUTTONS_LEFT_10BIT_ADC - BUTTONS_BUTTON_THRESHOLD )
        && voltage <= ( BUTTONS_LEFT_10BIT_ADC + BUTTONS_BUTTON_THRESHOLD ) )
  {
    buttons_leftButtonDown = true;
  }
  else if( voltage >= ( BUTTONS_SELECT_10BIT_ADC - BUTTONS_BUTTON_THRESHOLD )
        && voltage <= ( BUTTONS_SELECT_10BIT_ADC + BUTTONS_BUTTON_THRESHOLD ) )
  {
    buttons_selectButtonDown = true;
  }

  return voltage;
}

/**
 * Writes button state to serial
 */
void buttons_print()
{
  unsigned int voltage = buttons_updateState();

  Serial.print( "Voltage :" );
  Serial.println( voltage );

  Serial.print( "Right Pressed:");
  Serial.println( (buttons_isRightPressed() ? "yep" : "nup") );

  Serial.print( "Up Pressed:");
  Serial.println( (buttons_isUpPressed() ? "yep" : "nup") );

  Serial.print( "Down Pressed:");
  Serial.println( (buttons_isDownPressed() ? "yep" : "nup") );

  Serial.print( "Left Pressed:");
  Serial.println( (buttons_isLeftPressed() ? "yep" : "nup") );

  Serial.print( "Select Pressed:");
  Serial.println( (buttons_isSelectPressed() ? "yep" : "nup") );

  Serial.println();
}
