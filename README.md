Arduino-Ultrasonic-HC-SR04
==========================

Latest Ultrasonic HC-SR04 

Sample arduino code:

// Ultrasonic - Library for HR-SC04 Ultrasonic Ranging Module.
// Rev 1.0 (04/2013)
// A.R.Dayal


#include <Ultrasonic.h>

Ultrasonic ultrasonic(5,6); // (Trig PIN,Echo PIN)

void setup() {
  Serial.begin(9600);
  pinMode(4, OUTPUT); // VCC pin
  pinMode(7, OUTPUT); // GND ping
  digitalWrite(4, HIGH); // VCC +5V mode  
  digitalWrite(7, LOW);  // GND mode
}

void loop()
{
  Serial.print(ultrasonic.Ranging(CM)); // CM INC,FT or MM
  Serial.println(" cm" );
  Serial.println(ultrasonic.Duration())
  delay(100);
}
