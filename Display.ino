#include <LiquidCrystal.h>

#define LEFT 1
#define RIGHT 0
#define DISPLAY_PLAYER_AVATAR 'o'
#define BLOCKER '#'

#define BLOCKED_LEFT {BLOCKER, ' '}
#define BLOCKED_RIGHT {' ', BLOCKER}
#define NOT_BLOCKED {' ', ' '}

char WHEN_BLOCKED_LEFT[2][2] = { BLOCKED_LEFT, NOT_BLOCKED };
char WHEN_BLOCKED_RIGHT[2][2] = { BLOCKED_RIGHT, NOT_BLOCKED };
char WHEN_NOT_BLOCKED[3][2] = { BLOCKED_LEFT, BLOCKED_RIGHT, NOT_BLOCKED };

LiquidCrystal lcd( 8, 9, 4, 5, 6, 7 );

char validRows[3][2] = 
{
  {' ', ' '},
  {BLOCKER, ' '},
  {' ', BLOCKER}
};

char screen[16][2];

void display(char screen[16][2]) 
{  
  for (int row = 0; row < 15; row++) {    
    lcd.setCursor(row, LEFT);       
    lcd.print(screen[row][0]); 
    
    lcd.setCursor(row, RIGHT);       
    lcd.print(screen[row][1]); 
  } 
}

void display_player(unsigned int playerPosition)
{
  if (playerPosition == 1) {
    lcd.setCursor(15, RIGHT);
    lcd.print(screen[15][1]);  
  }
  else if (playerPosition == 0) {
    lcd.setCursor(15, LEFT);
    lcd.print(screen[15][0]);    
  }
 
  lcd.setCursor(15, playerPosition);
  lcd.print(DISPLAY_PLAYER_AVATAR);  
}

char* getValidRow(char screen[16][2], int previousRowIndex) {
   char* rowBelowUs = screen[previousRowIndex];
   
   if (rowBelowUs[0] == BLOCKER && rowBelowUs[1] == ' ') {
     return WHEN_BLOCKED_LEFT[random(0, 2)];
   } 
   
   if (rowBelowUs[0] == ' ' && rowBelowUs[1] == BLOCKER) {
     return WHEN_BLOCKED_RIGHT[random(0, 2)];
   }
   
   return WHEN_NOT_BLOCKED[random(0, 3)];
}

void shiftAndAppend(char screen[16][2], char* append) {
    for (int row = 15; row > 0; row--) {   
      screen[row][0] = screen[row-1][0]; 
      screen[row][1] = screen[row-1][1]; 
  }
 
  screen[0][0] = append[0];
  screen[0][1] = append[1]; 
}

void display_setup()
{  
  randomSeed(analogRead(0));
  lcd.begin(16, 2);
  initialise();
}

void display_loop()
{
  shiftAndAppend(screen, getValidRow(screen, 0));
  display(screen);
}

void initialise() { 
  for (int row = 0; row < 16; row++) {
     screen[row][LEFT] = ' ';
     screen[row][RIGHT] = ' ';
  }   
}
