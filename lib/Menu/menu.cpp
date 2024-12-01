#include "menu.h"
//#include "game.h"
#include <Wire.h>
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
byte rowPins[ROWS] = {2, 3, 4, 5}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {6, 7, 8, 9}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Adafruit_Keypad menukeypad = Adafruit_Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

c_menu::c_menu() : menulcd(0x27, 20, 4) , menukeypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS) {}

void c_menu::init() {
    menulcd.init();
    menulcd.backlight();
    menukeypad.begin();
}

void c_menu::showstartmenu() {
    bool showMessage = true; // To toggle the message display
    unsigned long lastBlinkTime = 0; // For controlling the blink timing
    const unsigned long blinkInterval = 1000; // Blink interval in milliseconds

    menulcd.clear(); // Start with a cleared display

    while (true) {
        menukeypad.tick();
        keypadEvent e = menukeypad.read();

        if (e.bit.EVENT == KEY_JUST_PRESSED) { // Check if any key is pressed
            showmodemenu(); // Clear the display immediately
            break; // Exit the loop
        }

        // Control the blinking based on elapsed time
        unsigned long currentTime = millis();
        if (currentTime - lastBlinkTime >= blinkInterval) {
            lastBlinkTime = currentTime; // Update the last blink time
            showMessage = !showMessage; // Toggle the message visibility

            if (showMessage) {
                // Display the start message
                menulcd.setCursor(3, 0);    
                menulcd.print("PRESS ANY KEY");
                menulcd.setCursor(2, 1);  
                menulcd.print("TO START A GAME");
                menulcd.setCursor(17, 3);  
                menulcd.print(":");
            } else {
                menulcd.clear(); // Clear the display for blinking effect
            }
        }
        
        menulcd.setCursor(0, 3);    
        menulcd.print("25");
        menulcd.setCursor(2, 3);    
        menulcd.print("/");
        menulcd.setCursor(3, 3);    
        menulcd.print("11");
        menulcd.setCursor(5, 3);  
        menulcd.print("/");
        menulcd.setCursor(6, 3);    
        menulcd.print("2024");
        menulcd.setCursor(15, 3);  
        menulcd.print("11");
        menulcd.setCursor(18, 3);  
        menulcd.print("30");
    }
}

void c_menu::showmodemenu() {
    menulcd.clear();
    menulcd.setCursor(4, 0);    
    menulcd.print("SELECT MODE:");
    menulcd.setCursor(2, 1);  
    menulcd.print("A - MANUAL");
    menulcd.setCursor(2, 2);  
    menulcd.print("B - AUTOMATIC");
    menulcd.setCursor(0, 3);  
    menulcd.print("# - BACK");
    menulcd.setCursor(15, 3); 
    menulcd.print("11");
    menulcd.setCursor(18, 3);  
    menulcd.print("30");
    menulcd.setCursor(17, 3);  
    menulcd.print(":");

    
    while(true) {
        menukeypad.tick();
        keypadEvent e = menukeypad.read();

        switch((char)e.bit.KEY){
            case 'A' : /*c_game newgame; newgame.startmanualgame();*/ break;
            case 'B' : showsportsmenu(); break;
            case '#' : showstartmenu(); break;
        }
    }
}

void c_menu::showsportsmenu() {
    menulcd.clear();
    menulcd.setCursor(3, 0);    
    menulcd.print("SELECT SPORT:");
    menulcd.setCursor(0, 1);  
    menulcd.print("A - BBALL");
    menulcd.setCursor(11, 1);  
    menulcd.print("FBALL - B");
    menulcd.setCursor(0, 2);  
    menulcd.print("C - HBALL");
    menulcd.setCursor(11, 2);  
    menulcd.print("VBALL - D");
    menulcd.setCursor(0, 3);  
    menulcd.print("# - BACK");
    menulcd.setCursor(15, 3);  
    menulcd.print("11");
    menulcd.setCursor(18, 3);  
    menulcd.print("30");
    menulcd.setCursor(17, 3);  
    menulcd.print(":");

    
    while(true) {
        menukeypad.tick();
        keypadEvent e = menukeypad.read();

        switch((char)e.bit.KEY){
            case 'A' : menulcd.clear(); break;
            case 'B' : menulcd.clear(); break;
            case 'C' : menulcd.clear(); break;
            case 'D' : menulcd.clear(); break;
            case '#' : showmodemenu(); break;
        }
    }
}