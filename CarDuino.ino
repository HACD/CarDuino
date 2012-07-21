/*--------------------------------------------------------------------------------------
  Includes
--------------------------------------------------------------------------------------*/
#include <LiquidCrystal.h>   // include LCD library

/*--------------------------------------------------------------------------------------
  Defines
--------------------------------------------------------------------------------------*/
#define LCD_BACKLIGHT_PIN         3

//some example macros with friendly labels for LCD backlight/pin control, tested and can be swapped into the example code as you like
#define LCD_BACKLIGHT_OFF()     digitalWrite( LCD_BACKLIGHT_PIN, LOW )
#define LCD_BACKLIGHT_ON()      digitalWrite( LCD_BACKLIGHT_PIN, HIGH )
#define LCD_BACKLIGHT(state)    { if( state ){digitalWrite( LCD_BACKLIGHT_PIN, HIGH );}else{digitalWrite( LCD_BACKLIGHT_PIN, LOW );} }

#define BUTTON_UP                 0
#define BUTTON_DOWN               1

/*--------------------------------------------------------------------------------------
  Variables
--------------------------------------------------------------------------------------*/
LiquidCrystal lcd( 8, 9, 4, 5, 6, 7 );   //Pins for the freetronics 16x2 LCD shield. LCD: ( RS, E, LCD-D4, LCD-D5, LCD-D6, LCD-D7 )

/*--------------------------------------------------------------------------------------
  setup()
  Called by the Arduino framework once, before the main loop begins
--------------------------------------------------------------------------------------*/
void setup()
{
   buttons_init();
   
   //lcd backlight control
   digitalWrite( LCD_BACKLIGHT_PIN, HIGH );  //backlight control pin D3 is high (on)
   pinMode( LCD_BACKLIGHT_PIN, OUTPUT );     //D3 is an output
   //set up the LCD number of columns and rows: 
   lcd.begin( 16, 2 );
   //Print some initial text to the LCD.
   lcd.setCursor( 0, 0 );   //top left
   //          1234567890123456
   lcd.print( "Freetronics 16x2" );
   //
   lcd.setCursor( 0, 1 );   //bottom left
   //          1234567890123456
   lcd.print( "Btn:" );
}
/*--------------------------------------------------------------------------------------
  loop()
  Arduino main loop
--------------------------------------------------------------------------------------*/
void loop()
{
  byte button;
  byte timestamp;
   
  buttons_display(lcd, 0, 1);
  
  timestamp = ( (millis() / 1000) % 100 );
  lcd.setCursor( 14, 1 );
  if( timestamp <= 9 )
    lcd.print( " " );
  lcd.print( timestamp, DEC );
}
