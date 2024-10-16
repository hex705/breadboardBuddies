// bbb-buddie
// id / binary switch reading

int buttons[] = {3,4,5,6,7};  // pins for the buttons
bool switchStates[] = {0,0,0,0,0}; // state of each button
byte switchValueInteger = 0;

String names[] = {
      "0","1",
      "jadyn",  //2
      "may",
      "angelo",
      "nicole",
      "kelvin",  //6
      "eamon",
      "jess",
      "vivian",
      "feng", // 10
      "anna",
      "trisha",
      "alex",
      "chloe", //14

};


void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  for (int i : buttons ) pinMode(buttons[i], INPUT);  // set pins to inputs
  // same as:
      //  for (int i = 0; i < 5; i ++){
      //     pinMode(buttons[i], INPUT);
      //  }
  Serial.println("setup complete");
}

void loop() {
  // put your main code here, to run repeatedly:
    readSwitches();
    printSwitches();
    printIntValue();
    printName();
    Serial.println("done");
    delay(2000);
}

void readSwitches(){
    for (int i = 0; i < 5; i ++){
          switchStates[i] =   digitalRead(buttons[i]);     
    }
}


void resetSwitches(){
   for (int i : switchStates) switchStates[i]= 0;
   // same as:
      //  for (int i = 0; i < 5; i ++){
      //   switches[i] = 0;
      //  }
}

void printSwitches(){

       for (int i = 4; i >=0; i--){
        Serial.print (switchStates[i]);
        Serial.print(" ");
       }
       
       Serial.println();
}

void printIntValue(){

  switchValueInteger = switchStates[4];
          for (int i = 3; i>=0; i --){

             switchValueInteger = switchValueInteger << 1;
             switchValueInteger += switchStates[i];
          
            // for fun 
            //  switchValueInteger = switchValueInteger || switchStates[i];

          }


  Serial.print(" int val = ");
  Serial.println(switchValueInteger);

}


void printName(){
   printName(switchValueInteger); // uses global from switches
}

void printName(int theNameIndex){ // uses index of our choice
  if (theNameIndex > 14) theNameIndex = 14;
  Serial.print("name = " );
  Serial.println(names[theNameIndex]);
}
