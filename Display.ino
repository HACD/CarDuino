#include <LiquidCrystal.h>

LiquidCrystal lcd( 8, 9, 4, 5, 6, 7 );

char randomCharacters[16] = {'#', '(', ')', '*', '+', '-', ':', ';', '<', '=', '>', '{', '}', '[', ']', '~'};
char newRow[2] = {'A', 'A'};

char screen[16][2] = 
{
      {'0', '1'},
      {'2', '3'},
      {'4', '5'},
      {'6', '7'},
      {'8', '9'},
      {'!', '@'},
      {'#', '$'},
      {'%', '^'},
      {'&', '*'},
      {'(', ')'},
      {'_', '+'},
      {',', '.'},
      {'/', ';'},
      {'<', '>'},
      {'?', '|'},     
      {'!', '!'}
};  

void display_setup()
{  
       lcd.begin(16, 2);
}

void display_loop()
{
   //fillScreenRandomly();
   display(screen);
   shiftAndAppend(screen, newRow);
   delay(500);
}

void fillScreenRandomly() {
  for (int row = 0; row < 16; row++) {    
     for (int column = 0; column < 2; column++) {
        char randomValue = randomCharacters[random(0, 16+1 /* exclusive */)];
        screen[row][column] = randomValue;
     }
  }   
}

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

// when the screen is rotated 90 degrees clockwise, what was (0,0) becomes (1,0)
int toUprightColumn(int horizontalColumn) {
   return horizontalColumn == 0 ? 1 : 0; 
}

void shiftAndAppend(char screen[16][2], char append[2]) {
    for (int row = 0; row < 15; row++) {    
     for (int column = 0; column < 2; column++) {
       int uprightColumn = toUprightColumn(column);
       
       screen[row][column] = screen[row+1][column];  
     }
  }
 
  screen[15][0] = append[0];
  screen[15][1] = append[1]; 
}
