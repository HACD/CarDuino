//Board = Arduino Uno
#define ARDUINO 101
#define __AVR_ATmega328P__
#define F_CPU 16000000L
#define __cplusplus
#define __attribute__(x)
#define __inline__
#define __asm__(x)
#define __extension__
#define __ATTR_PURE__
#define __ATTR_CONST__
#define __inline__
#define __asm__ 
#define __volatile__
#define __builtin_va_list
#define __builtin_va_start
#define __builtin_va_end
#define __DOXYGEN__
#define prog_void
#define PGM_VOID_P int
#define NOINLINE __attribute__((noinline))

typedef unsigned char byte;
extern "C" void __cxa_pure_virtual() {}

//already defined in arduno.h
//already defined in arduno.h
 void buttons_setup()  ;
 byte buttons_isLeftPressed()  ;
 byte buttons_isRightPressed()  ;
 byte buttons_isUpPressed()  ;
 byte buttons_isDownPressed()  ;
 byte buttons_isSelectPressed()  ;
 unsigned int buttons_updateState()  ;
 void buttons_print()  ;
 void display(char screen[16][2])  ;
 bool display_player(unsigned int playerPosition)  ;
 void display_intro()  ;
 void display_endGame(unsigned int score)  ;
 void display_clear()  ;
 void shiftAndAppend(char screen[16][2], char* append)  ;
 void display_setup()  ;
 void display_loop()  ;
 void initialise()  ;
 unsigned int player_getPosition()  ;
 void player_setPositionLeft()  ;
 void player_setPositionRight()  ;
 void player_display()  ;

#include "C:\Users\Michael\Desktop\Arduino\arduino-1.0.1-windows\arduino-1.0.1\hardware\arduino\variants\standard\pins_arduino.h" 
#include "C:\Users\Michael\Desktop\Arduino\arduino-1.0.1-windows\arduino-1.0.1\hardware\arduino\cores\arduino\Arduino.h"
#include "C:\Users\Michael\Documents\GitHub\CarDuino\CarDuino.ino" 
#include "C:\Users\Michael\Documents\GitHub\CarDuino\Buttons.ino"
#include "C:\Users\Michael\Documents\GitHub\CarDuino\Display.ino"
#include "C:\Users\Michael\Documents\GitHub\CarDuino\Player.ino"
