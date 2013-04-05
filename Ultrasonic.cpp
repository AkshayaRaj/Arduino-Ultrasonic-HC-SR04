#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#include "Ultrasonic.h"

Ultrasonic::Ultrasonic(int TP, int EP)
{
   pinMode(TP,OUTPUT);
   pinMode(EP,INPUT);
   Trig_pin=TP;
   Echo_pin=EP;
   Time_out=3000;  // 30ms 5 metros // 3ms 50cm
}

Ultrasonic::Ultrasonic(int TP, int EP, long TO)
{
   pinMode(TP,OUTPUT);
   pinMode(EP,INPUT);
   Trig_pin=TP;
   Echo_pin=EP;
   Time_out=TO;
}

long Ultrasonic::Timing()
{
  digitalWrite(Trig_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig_pin, LOW);
  duration = pulseIn(Echo_pin,HIGH,Time_out);
  if ( duration == 0 ) {duration = Time_out;}
  return duration;
}

long Ultrasonic::Duration(){
     Timing();     
     return duration;
     
     }


long Ultrasonic::Ranging(int sys)
{
  Timing();
  if (sys) {
  distacne_cm = duration /29 / 2 ;
  return distacne_cm;
  } else {
  distance_inc = duration / 74 / 2;
  return distance_inc; }
}
