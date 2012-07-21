/*--------------------------------------------------------------------------------------
  Variables
--------------------------------------------------------------------------------------*/

unsigned long last_updated = millis();


/*--------------------------------------------------------------------------------------
  Functions
--------------------------------------------------------------------------------------*/

void setup()  
{ 
  buttons_setup();
  display_setup();
} 

void loop()  
{ 
  unsigned long now = millis();
  
  buttons_updateState();
  //buttons_print();
  
  if( buttons_isUpPressed() )
  {
    Serial.println("up pressed, moving left");
    player_setPositionLeft();
  }
  else if( buttons_isDownPressed() )
  {
    Serial.println("down pressed, moving right");
    player_setPositionRight();
  }
  
  display_player( player_getPosition() );
  
  if( now - last_updated > 2000 )
  {
    display_loop();
    last_updated = now;
  }
}

