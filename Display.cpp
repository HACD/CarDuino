#include "Display.h"
#include <Arduino.h>
#include <LiquidCrystal.h>
#include <stdint.h>

// When rotated 90 degrees clockwise
const unsigned int LEFT_COLUMN_INDEX = 1;
const unsigned int RIGHT_COLUMN_INDEX = 0;

const unsigned int NUMBER_OF_ROWS = 16;
const unsigned int NUMBER_OF_COLUMNS = 2;

LiquidCrystal lcd (8, 9, 4, 5, 6, 7);
char** screen = (char**) malloc(sizeof(int) * NUMBER_OF_ROWS * NUMBER_OF_COLUMNS);

Display::Display() 
{
}

void initialise() {
  for (int row = 0; row < NUMBER_OF_ROWS; row++) {
    screen[row][LEFT_COLUMN_INDEX] = ' ';
    screen[row][RIGHT_COLUMN_INDEX] = ' ';
  }
}

void Display::setup()
{
  randomSeed(analogRead(0));
  lcd.begin(16, 2);
  initialise();
}

void Display::paint() 
{
  for (int row = 0; row < NUMBER_OF_ROWS; row++) {
    lcd.setCursor(row, LEFT_COLUMN_INDEX); 
    lcd.print(screen[row][0]);

    lcd.setCursor(row, RIGHT_COLUMN_INDEX);
    lcd.print(screen[row][1]);
  }
}

void Display::clear()
{
  lcd.setCursor(0, 0);
  lcd.print("                ");
  lcd.setCursor(0, 1);
  lcd.print("                ");
}

// TODO: Somehow distinguish between this overload (which stores in screen) and the overload below which doesn't
void Display::print(Coordinates c, char value) 
{
   screen[c.x][c.y] = value; 

   lcd.setCursor(c.x, c.y);
   lcd.print(value);
}

void Display::print(uint8_t x, uint8_t y, char value[])
{
  lcd.setCursor(x, y);
  lcd.print(value);
}

void Display::prependRow(char* append) {
  // TODO: Where should the 'leave the player alone' logic know? It shouldn't be Display specific...
  for (int row = NUMBER_OF_ROWS - 1 /* we don't want to overwrite the player */; row > 0; row--) {
    screen[row][0] = screen[row-1][0];
    screen[row][1] = screen[row-1][1];
  }

  screen[0][0] = append[0];
  screen[0][1] = append[1];
}

char Display::getCharAt(uint8_t row, uint8_t column)
{
   return screen[row][column];
}