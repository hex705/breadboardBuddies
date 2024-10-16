// bbb-buddie
// id / binary switch reading


// variables for the LCD

#include "DFRobot_RGBLCD1602.h"
DFRobot_RGBLCD1602 lcd(/*RGBAddr*/ 0x2D, /*lcdCols*/ 16, /*lcdRows*/ 2);  //16 characters and 2 lines of show
int r, g, b = 30;

int buttons[] = { 3, 4, 5, 6, 7 };        // pins for the buttons
bool switchStates[] = { 0, 0, 0, 0, 0 };  // state of each button
byte switchValueInteger = 0;

String names[15] = {
  "empty    ", 
  "empty    ",
  "jadyn    ",  //2
  "may      ",
  "angelo   ",
  "nicole   ",
  "kelvin   ",  //6
  "eamon    ",
  "jess     ",
  "vivian   ",
  "feng     ",  // 10
  "anna     ",
  "trisha   ",
  "alex     ",
  "chloe    "  //14
};

int lcdColors[15][3] = {
  { 0, 0, 0 },  //0
  { 0, 0, 0 },
  { 255, 41, 31 },
  { 14, 38, 4 },
  { 24, 3, 64 },
  { 170, 77, 255 },
  { 18, 165, 5 },
  { 74, 0, 1 },
  { 173, 12, 2 },
  { 58, 65, 28 },
  { 255, 62, 46 },
  { 199, 85, 9 },
  { 255, 59, 2 },
  { 69, 4, 25 },
  { 255, 88, 0 }
} ; // end array or arrays

void
setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  for (int i : buttons) pinMode(buttons[i], INPUT);  // set pins to inputs
  // same as:
  //  for (int i = 0; i < 5; i ++){
  //     pinMode(buttons[i], INPUT);
  //  }
  // start LCD
  lcd.init();
  // Print a message to the LCD.
  lcd.print("BBB Buddie");
  Serial.println("setup complete");
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setRGB(lcdColors[switchValueInteger][0], lcdColors[switchValueInteger][1], lcdColors[switchValueInteger][2]);
  readSwitches();
  printSwitches();
  printIntValue();
  printName();
  lcd.setCursor(0, 1);
  lcd.print(names[switchValueInteger]);
  Serial.println("done");
  delay(2000);
}

void readSwitches() {
  for (int i = 0; i < 5; i++) {
    switchStates[i] = digitalRead(buttons[i]);
  }
}


void resetSwitches() {
  for (int i : switchStates) switchStates[i] = 0;
  // same as:
  //  for (int i = 0; i < 5; i ++){
  //   switches[i] = 0;
  //  }
}

void printSwitches() {

  for (int i = 4; i >= 0; i--) {
    Serial.print(switchStates[i]);
    Serial.print(" ");
  }

  Serial.println();
}

void printIntValue() {

  switchValueInteger = switchStates[4];
  for (int i = 3; i >= 0; i--) {

    switchValueInteger = switchValueInteger << 1;
    switchValueInteger += switchStates[i];

    // for fun
    //  switchValueInteger = switchValueInteger || switchStates[i];
  }


  Serial.print(" int val = ");
  Serial.println(switchValueInteger);
}


void printName() {
  printName(switchValueInteger);  // uses global from switches
}

void printName(int theNameIndex) {  // uses index of our choice
  if (theNameIndex > 14) theNameIndex = 14;
  Serial.print("name = ");
  Serial.println(names[theNameIndex]);
}
