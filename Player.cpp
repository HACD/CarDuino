#include "Player.h"
#include <HardwareSerial.h>

Player::Player()
{
  // initalise up serial port
  Serial.begin(9600);
  while (!Serial)
  {
    ;
  }
};
  
void Player::paint() 
{
  Serial.println("Player::paint()");
}
