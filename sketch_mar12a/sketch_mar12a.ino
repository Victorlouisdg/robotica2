// Adafruit Motor shield library
// copyright Adafruit Industries LLC, 2009
// this code is public domain, enjoy!
#include <AFMotor.h> //DO NOT forget to include this library by "Sketch->Include Library->Add ZIP library
//" This library can be downloaded from the Velleman website.

AF_DCMotor motor(2);
void setup() {
  Serial.begin(9600); // set up Serial library at 9600 bps
  Serial.println("Motor test!");
  // turn on motor
  motor.setSpeed(200);
  motor.run(RELEASE);
}
void loop() {
  uint8_t i;

  Serial.print("tick");
  motor.setSpeed(255);  
  motor.run(FORWARD);
}
