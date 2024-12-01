/*#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Adafruit_Keypad.h>

const byte ROWS = 4; // rows
const byte COLS = 4; // columns
//define the symbols on the buttons of the keypads
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};

//initialize an instance of class NewKeypad
Adafruit_Keypad menukeypad = Adafruit_Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS);

LiquidCrystal_I2C menulcd(0x27,20,4);*/