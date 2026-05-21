#include <Arduino.h>
#include <Servo.h>

// Object declarations
const Servo servo_object[7];
/*
### Servo layout ###
- Servo 1 at Pin 3
- Servo 2 at Pin 4
- Servo 3 at Pin 5
- Servo 4 at Pin 6
- Servo 5 at Pin 7
- Servo 6 at Pin 8
- Servo 7 at Pin 9
# 7 servos are needed for one 7 segment display #
*/
const int servos[7] = {3, 4, 5, 6, 7, 8, 9};
// Constant that stores the maximum angle to which the servos will open to
// Range is from 0 to 180
const int max_servo_open=180;

// Void setup
// Code that runs once the arduino starts up and does not repeat
// Initialises the servos to their appropriate objects and initialises Serial and does the appropriate processes
void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
}
