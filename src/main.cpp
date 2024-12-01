#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <Adafruit_Keypad.h>
#include <Wire.h>
#include "menu.h"
#include "common.h"

c_menu menu;

void setup() {

  //menu.init();
  //menu.showstartmenu();
  Serial.begin(9600);
  Serial.setTimeout(10);
}

void loop() {
  //menu.showstartmenu();
  //delay(10000);
  String received_data = Serial.readString();
  Serial.print(received_data);

}

