void setup()  
{ 
  buttons_setup();
  display_setup();
} 

void loop()  
{ 
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
  
  display_loop( player_getPosition() );
  delay(500);
}

