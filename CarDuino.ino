void setup()  
{ 
  buttons_setup();
  display_setup();
} 

void loop()  
{ 
  buttons_print(); 
  display_loop();
  delay(500);
}

