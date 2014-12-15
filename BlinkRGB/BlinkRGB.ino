/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int ledr = 13;
int ledg = 12;
int ledb = 11;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(ledr, OUTPUT);     
  pinMode(ledg, OUTPUT);     
  pinMode(ledb, OUTPUT);     
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(ledr, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);               // wait for a second
  digitalWrite(ledr, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(ledg, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);               // wait for a second
  digitalWrite(ledg, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(ledb, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);               // wait for a second
  digitalWrite(ledb, LOW);    // turn the LED off by making the voltage LOW
}
