/*
  Switch an attached LED on or off via serial console.
  
  Circuit:
  * LED: pin 13 + ground
  
  created 23.01.2013
  by fidepus
*/

// pin for the LED:
const int led = 13;

void setup() {
  //initialize serial:
  Serial.begin(9600);
  // make the pin an output:
  pinMode(led, OUTPUT);
  
}

void loop() {
  
  // read any available serial:
  if (Serial.available() > 0) {
    int inByte = Serial.read();
    // we will use switch cases to turn the led on or off
    switch (inByte) {
      // a 1 on the serial console will switch the led on
    case '1':    
      digitalWrite(led, HIGH);
      break;
      // everything else will switch it off
    default:
      digitalWrite(led, LOW);
    }
  }
}
    
