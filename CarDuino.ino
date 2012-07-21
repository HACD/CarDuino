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
  while(true) 
  {
    unsigned int score = 0;
    bool collide = false;
    
    display_intro();
    delay(3000);
    
    while(!collide)
    {
      unsigned long now = millis();
      
      buttons_updateState();
      //buttons_print();
      
      if( buttons_isDownPressed() )
      {
        player_setPositionLeft();
      }
      else if( buttons_isUpPressed() )
      {
        player_setPositionRight();
      }
      
      collide = display_player( player_getPosition() );
      
      if(collide)
      {
        break;
      }
      
      int speed = 1000 - (10 * score);
      if( speed < 100)
      {
        speed = 100;
      }
      
      if( now - last_updated > speed )
      {
        display_loop();
        last_updated = now;
        
        score++;
      }
      
      delay(20);
    }
    
    display_endGame( score );
    
    delay(5000);
  }
}

