#ifndef _MENU_H_
#define _MENU_H_

//#include "game.h"
#include <Wire.h>                  // Required for I2C communication
#include <LiquidCrystal_I2C.h>     // Include the LCD library
#include <Adafruit_Keypad.h>       // Include the keypad library

class c_game;

class c_menu {
protected:
    LiquidCrystal_I2C menulcd;  // Declare the menulcd object as a private member of the class
    Adafruit_Keypad menukeypad;

public:
    c_menu();                   // Constructor
    void init();                // Method to initialize menu
    void showstartmenu();       // Method to show start menu
    void showmodemenu();
    void showsportsmenu();
};

#endif