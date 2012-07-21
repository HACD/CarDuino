#include <LiquidCrystal.h>

#define LEFT 1
#define RIGHT 0
#define DISPLAY_PLAYER_AVATAR 'o'

LiquidCrystal lcd( 8, 9, 4, 5, 6, 7 );

char randomCharacters[16] = {'#', '(', ')', '*', '+', '-', ':', ';', '<', '=', '>', '{', '}', '[', ']', '~'};
char validRows[3][2] = 
{
  {' ', ' '},
  {'#', ' '},
  {' ', '#'}
};

char screen[16][2];

void display(char screen[16][2]) 
{  
  for (int row = 0; row < 16; row++) {    
    lcd.setCursor(row, LEFT);       
    lcd.print(screen[row][0]); 
    
    lcd.setCursor(row, RIGHT);       
    lcd.print(screen[row][1]); 
  } 
}

void display_player(unsigned int playerPosition)
{
  Serial.print("player position: " + playerPosition);
    
  // repaint obstacles
  lcd.setCursor(15, LEFT);
  lcd.print(screen[15][0]);
  
  lcd.setCursor(15, RIGHT);
  lcd.print(screen[15][1]);
  
  // paint player position
  lcd.setCursor(15, playerPosition);
  lcd.print(DISPLAY_PLAYER_AVATAR);
}

char* getValidRow() {
  return validRows[random(0, 3)];
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
       lcd.begin(16, 2);
       initialise();
}

void display_loop()
{
  shiftAndAppend(screen, getValidRow()); 
  display(screen);
}

void initialise() {
  for (int row = 0; row < 16; row++) {
     char* validRow = getValidRow();
     screen[row][LEFT] = validRow[0];
     screen[row][RIGHT] = validRow[1];
  }   
}
