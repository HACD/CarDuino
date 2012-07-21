#include <LiquidCrystal.h>

#define TOP_LEFT 1
#define TOP_RIGHT 0
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
     for (int column = 0; column < 2; column++) {
       int uprightColumn = toUprightColumn(column);
       
       lcd.setCursor(row, uprightColumn);       
       lcd.print(screen[row][column]); 
     }
  } 
}

void displayPlayer(unsigned int playerPosition)
{
  Serial.print("player position: " + playerPosition);
  lcd.setCursor(0, playerPosition);
  lcd.print(DISPLAY_PLAYER_AVATAR);
}

// when the screen is rotated 90 degrees clockwise, what was (0,0) becomes (1,0)
int toUprightColumn(int horizontalColumn) {
   return horizontalColumn == 0 ? TOP_LEFT : TOP_RIGHT; 
}

char* getValidRow() {
  return validRows[random(0, 3)];
}

void shiftAndAppend(char screen[16][2], char* append) {
    for (int row = 0; row < 15; row++) {    
     for (int column = 0; column < 2; column++) {
       int uprightColumn = toUprightColumn(column);
       
       screen[row][column] = screen[row+1][column];  
     }
  }
 
  screen[15][0] = append[0];
  screen[15][1] = append[1]; 
}

void display_setup()
{  
       lcd.begin(16, 2);
       initialise();
}

void display_loop(unsigned int playerPosition)
{
   display(screen);
   displayPlayer(playerPosition);
   shiftAndAppend(screen, getValidRow());
}

void initialise() {
  for (int row = 0; row < 16; row++) {
     char* validRow = getValidRow();
     screen[row][TOP_LEFT] = validRow[0];
     screen[row][TOP_RIGHT] = validRow[1];
  }   
}
