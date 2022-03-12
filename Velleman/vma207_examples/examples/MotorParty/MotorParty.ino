// Adafruit Motor shield library
// copyright Adafruit Industries LLC, 2009
// this code is public domain, enjoy!

#include <AFMotor.h>
#include <Servo.h> 

// DC motor on M2
AF_DCMotor motor(2);
// DC hobby servo
Servo servo1;
Servo servo2;
// Stepper motor on M3+M4 48 steps per revolution
AF_Stepper stepper(48, 2);

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Motor party!");
  
  // turn on servo
  servo1.attach(9);
  servo2.attach(10);
   
  // turn on motor #2
  motor.setSpeed(200);
  motor.run(RELEASE);
}

int i;

// Test the DC motor, stepper and servo ALL AT ONCE!
void loop() {
  motor.run(FORWARD);
  for (i=0; i<255; i++) {
    servo1.write(i);
    motor.setSpeed(i);  
    stepper.step(1, FORWARD, INTERLEAVE);
    Serial.println("delay 10");
    delay(10);
 }
 
  for (i=255; i!=0; i--) {
    servo1.write(i-255);
    motor.setSpeed(i);  
    stepper.step(1, BACKWARD, INTERLEAVE);
    Serial.println("delay 5");
    delay(5);
 }
 
  motor.run(BACKWARD);
  for (i=0; i<255; i++) {
    servo1.write(i);
    motor.setSpeed(i);
    Serial.println("delay 40");  
    delay(40);
    stepper.step(1, FORWARD, DOUBLE);
 }
 
  for (i=255; i!=0; i--) {
    servo1.write(i-255);
    motor.setSpeed(i);  
    stepper.step(1, BACKWARD, DOUBLE);
    Serial.println("delay 3");
    delay(3);
 }
  motor.run(FORWARD);
  for (i=0; i<255; i++) {
    servo2.write(i);
    motor.setSpeed(i);  
    stepper.step(1, FORWARD, INTERLEAVE);
    Serial.println("servo 2 delay 10");
    delay(10);
 }
 
  for (i=255; i!=0; i--) {
    servo2.write(i-255);
    motor.setSpeed(i);  
    stepper.step(1, BACKWARD, INTERLEAVE);
    Serial.println("servo 2 delay 5");
    delay(5);
 }
 
  motor.run(BACKWARD);
  for (i=0; i<255; i++) {
    servo2.write(i);
    motor.setSpeed(i);
    Serial.println("servo 2 delay 40");  
    delay(40);
    stepper.step(1, FORWARD, DOUBLE);
 }
 
  for (i=255; i!=0; i--) {
    servo2.write(i-255);
    motor.setSpeed(i);  
    stepper.step(1, BACKWARD, DOUBLE);
    Serial.println("servo 2 delay 3");
    delay(3);
 }
}
