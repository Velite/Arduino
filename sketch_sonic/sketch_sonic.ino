#include "Ultrasonic.h"

// sensor connected to:
// Trig - 12, Echo - 13
Ultrasonic ultrasonic(7, 8);

int ledr = 9;
int ledg = 10;
int ledb = 11;

void setup()
{
  pinMode(ledr, OUTPUT);     
  pinMode(ledg, OUTPUT);     
  pinMode(ledb, OUTPUT);
}

void loop()
{
  float dist_cm = ultrasonic.Ranging(CM);       // get distance
  if (dist_cm > 50 || dist_cm < 1)
  {
    digitalWrite (ledb, HIGH);    
    digitalWrite (ledr, LOW);    
    digitalWrite (ledg, LOW);    
  }
  else
  {
    if (dist_cm > 30)
    {
      digitalWrite (ledg, HIGH);    
      digitalWrite (ledr, LOW);    
      digitalWrite (ledb, LOW);    
    }
    else
    {
      if (dist_cm > 10)
      {
        digitalWrite (ledr, HIGH);    
        digitalWrite (ledb, LOW);    
        digitalWrite (ledg, HIGH);    
      }
      else
      {
        digitalWrite (ledr, HIGH);    
        digitalWrite (ledb, LOW);    
        digitalWrite (ledg, LOW);
      }        
    }
  }
  
  delay(100);                                   // arbitary wait time.
}
