#include <Arduino.h>
#include <Servo.h>

// Object declarations
Servo servo_object[7];
// Servo layout
// - Servo 1 at Pin 3
// - Servo 2 at Pin 4
// - Servo 3 at Pin 5
// - Servo 4 at Pin 6
// - Servo 5 at Pin 7
// - Servo 6 at Pin 8
// - Servo 7 at Pin 9
const int servos[7] = {3, 4, 5, 6, 7, 8, 9};
// Constant that stores the total number of servos connected to the arduino
// Should be 7 as im intended to use it with 7 servos
const int NUM_SERVOS = 7;
// Constant that stores the maximum angle to which the servos will open to
// Range is from 0 to 180
const int max_servo_open=180;
// Constant that stores the serial baud to output serial at
const int baud=9600;
//
// =======================================
//
// Section of code that contains functions and procedures required to run the code
// 
// Function that acts as the heartbeat of the arduino.
// Can be used to identify the state of initialisation and stuff by just glancing at the arduino
// Assists in allowing visual debugging during initialisation of arduino
void blinkStatus(int times) {
  for (int i = 0; i < times; i++) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
    delay(100);
  }
}
// =================================
// Void setup
// Code that runs once the arduino starts up and does not repeat
// Initialises the servos to their appropriate objects and initialises Serial and does the appropriate processes
void setup() {
  // Initialising serial at 9600 baud and informs user of it and what baud it is currently using
  Serial.begin(baud); Serial.print("Serial has been enabled at "); Serial.print(baud); Serial.println(" Baud");
  // Initialising Built in LED of the arduino as an output to use as a debug LED (kind of like a heartbeat) to identify if the arduino is initialising properly
  // To be able to figure out what is happening without having to take the entire arduino apert
  pinMode(LED_BUILTIN, OUTPUT);
  // Initialising servos for the 7 segment display
  // Uses a for loop and initialises each servo one by one
  for (int servo=0; servo < NUM_SERVOS; servo++) {
    servo_object[servo].attach(servos[servo]);
    blinkStatus(1);
  }
  blinkStatus(10);
  // Prints a message in serial that states the number of servos initialised succesfully
  // Also displays more imformation that notifies the usert that the servo has finished the void setup state
  Serial.print("Succesfully initialised "); Serial.print(NUM_SERVOS); Serial.println(" Servos as Servos"); Serial.println("Setup code finished");
  blinkStatus(1);
} 

void loop() {
  // put your main code here, to run repeatedly:
}

