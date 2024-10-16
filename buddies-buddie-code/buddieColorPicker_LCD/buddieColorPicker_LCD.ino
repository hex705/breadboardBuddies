/* uses library 

DFRobot_RGBLCD1602

*/

/*
  this code allows user to select LCD color via 3 pots

  our LCD modules are :
    LCD1602 RGB Module  |  V2.0  | 0x2D 

  you must enter 0x2d // hexidecimal number into the constructor call

  //DFRobot_RGBLCD1602 lcd(0x2D ,16,2);
*/


#include "DFRobot_RGBLCD1602.h"

DFRobot_RGBLCD1602 lcd(/*RGBAddr*/0x2D ,/*lcdCols*/16,/*lcdRows*/2);  //16 characters and 2 lines of show

int r,g,b;

int redPot = A0;
int greenPot = A1;
int bluePot = A2;

void setup() {
  // put your setup code here, to run once:
  	Serial.begin(9600);
    lcd.init();
    // Print a message to the LCD.
    lcd.print("rgb color picker");

    Serial.println("Pot values");

}

void loop() {
  // put your main code here, to run repeatedly:
  readPots();

  lcd.setRGB(r, g, b);
        
        lcd.setCursor(0, 1);
        lcd.print(r);
        
        lcd.setCursor(5, 1);
        lcd.print(g);
        
        lcd.setCursor(10, 1);
        lcd.print(b);
        
        // erase zeros from big numbers
        if ( r < 100) {
          lcd.setCursor(2, 1);
          lcd.print(' ');
        }

        if ( g < 100) {
          lcd.setCursor(7, 1);
          lcd.print(' ');
        }

        if ( b < 100) {
          lcd.setCursor(12, 1);
          lcd.print(' ');
        }
        // remove 0s from Y position 
        if ( r < 10) {
          lcd.setCursor(1, 1);
          lcd.print(' ');
        }

        if ( g < 10) {
          lcd.setCursor(6, 1);
          lcd.print(' ');
        }

        if ( b < 10) {
          lcd.setCursor(11, 1);
          lcd.print(' ');
        }

        // print to serial monitor 
        Serial.print(r);
        Serial.print("\t");
        Serial.print(g);
        Serial.print("\t");
        Serial.print(b);
        Serial.println();

}

void readPots() {

  r = analogRead(redPot)/4;
  g = analogRead (greenPot)/4;
  b = analogRead(bluePot)/4;

}
