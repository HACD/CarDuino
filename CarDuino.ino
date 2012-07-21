void setup()  
{ 
  display_setup();
  
  // declare pin 9 to be an output:
  pinMode(led, OUTPUT);
} 

void loop()  
{ 
   display_loop();  
  
  // set the brightness of pin 9:
  analogWrite(led, brightness);    

  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade: 
  if (brightness == 0 || brightness == 255) 
  {
    fadeAmount = -fadeAmount ; 
  }     
  // wait for 30 milliseconds to see the dimming effect    
  delay(30);                            
}
