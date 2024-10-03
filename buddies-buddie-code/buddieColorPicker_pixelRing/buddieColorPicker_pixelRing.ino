/* uses library 

Adafruit_NeoPixel

*/

/*

*/

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>  // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1:
#define LED_PIN 8

// How many NeoPixels are attached to the Arduino?
#define LED_COUNT 12

// Declare our NeoPixel strip object:
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);


int r, g, b;

int redPot = A0;
int greenPot = A1;
int bluePot = A2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  Serial.println("Pot values");

  strip.begin();            // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();             // Turn OFF all pixels ASAP
  strip.setBrightness(30);  // Set BRIGHTNESS to about 1/5 (max = 255)
}

void loop() {
  // put your main code here, to run repeatedly:
  readPots();
  setRGBPixels(r, g, b);
   strip.show();  

  // lcd.setRGB(r, g, b);

  //       lcd.setCursor(0, 1);
  //       lcd.print(r);

  //       lcd.setCursor(5, 1);
  //       lcd.print(g);

  //       lcd.setCursor(10, 1);
  //       lcd.print(b);

  //       // erase zeros from big numbers
  //       if ( r < 100) {
  //         lcd.setCursor(2, 1);
  //         lcd.print(' ');
  //       }

  //       if ( g < 100) {
  //         lcd.setCursor(7, 1);
  //         lcd.print(' ');
  //       }

  //       if ( b < 100) {
  //         lcd.setCursor(12, 1);
  //         lcd.print(' ');
  //       }
  //       // remove 0s from Y position
  //       if ( r < 10) {
  //         lcd.setCursor(1, 1);
  //         lcd.print(' ');
  //       }

  //       if ( g < 10) {
  //         lcd.setCursor(6, 1);
  //         lcd.print(' ');
  //       }

  //       if ( b < 10) {
  //         lcd.setCursor(11, 1);
  //         lcd.print(' ');
  //       }

  // print to serial monitor
  Serial.print(r);
  Serial.print("\t");
  Serial.print(g);
  Serial.print("\t");
  Serial.print(b);
  Serial.println();

  delay(50);
}

void readPots() {

  r = analogRead(redPot) / 4;
  g = analogRead(greenPot) / 4;
  b = analogRead(bluePot) / 4;
}

void setRGBPixels(int setRed, int setGrn, int setBlu){
  uint32_t color = strip.Color(setRed, setGrn, setBlu);
  Serial.println(color);
  for (int i = 0; i < strip.numPixels(); i++) {  // For each pixel in strip...
    strip.setPixelColor(i, color);               //  Set pixel's color (in RAM)
  }
}// end fxn 

