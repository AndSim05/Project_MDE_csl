#ifndef _GAME_H_
#define _GAME_H_

#include <Wire.h>                  // Required for I2C communication
#include <LiquidCrystal_I2C.h>     // Include the LCD library
#include <Adafruit_Keypad.h>       // Include the keypad library
#include "menu.h"

class c_game : c_menu 
{
public:
    c_game();                   // Constructor
    void init();                // Method to initialize menu
    void showgameinfo();       // Method to show start menu
    void startmanualgame();
    void startautomaticgame();
};

#endif