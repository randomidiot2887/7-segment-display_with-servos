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
// Constant that declares the delay between the switching of servos to try and reduce power draw
const int time=100;

// =======================================
// Section of code that contains functions and procedures required to run the code

// Function that acts as the heartbeat of the arduino.
// Can be used to identify the state of initialisation and stuff bym just glancing at the arduino
// Assists in allowing visual debugging during initialisation of arduino
void blinkStatus(int times) {
  for (int i = 0; i < times; i++) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
    delay(100);
  }
}

// Function that is used to control the servos that spin at a time, handles displaying of numbers
// Used to clean up loop()
// syntax: display_num(number)
// number must be 0 <= number < 10 to display a number on the 7 segment display
// if number is 10, itll be equivelent to clearning the screen
// if number is less then 0 or greater then 10, the procedure WILL BREAK
void display_num(int num=10) {
  // Case that handles the procedures the procedure will run depending on the input
  switch (num) {
    case 10:
      // Resets the servo position of all of them to 0
      // Basically is same as clearning the display of every value
      for (int i=0; i<7; i++) {
        servo_object[i].write(0);
        delay(100);
      }
      break;
    // Values that change the contents of the display
    case 1:
      // Displaying the number 1
      // By enabling servos 2 and 6
      servo_object[0].write(0); delay(time);              // Digit 7
      servo_object[1].write(0); delay(time);              // Digit 7
      servo_object[2].write(max_servo_open); delay(time); // Digit 7
      servo_object[3].write(0); delay(time);              // Digit 7
      servo_object[4].write(0); delay(time);              // Digit 7
      servo_object[5].write(0); delay(time);              // Digit 7
      servo_object[6].write(max_servo_open); delay(time); // Digit 7
      break;
    case 2:
      // Displaying the number 2
      // By enabling servos 1, 2, 3, 4 & 5
      servo_object[0].write(max_servo_open); delay(time); // Digit 1
      servo_object[1].write(max_servo_open); delay(time); // Digit 2
      servo_object[2].write(max_servo_open); delay(time); // Digit 3
      servo_object[3].write(max_servo_open); delay(time); // Digit 4
      servo_object[4].write(max_servo_open); delay(time); // Digit 5
      servo_object[5].write(0); delay(time);              // Digit 6
      servo_object[6].write(0); delay(time);              // Digit 7
      break;
    case 3:
      // Displaying the number 3
      // By enabling servos 1, 2, 3, 5 & 6
      servo_object[0].write(max_servo_open); delay(time); // Digit 1
      servo_object[1].write(max_servo_open); delay(time); // Digit 2
      servo_object[2].write(max_servo_open); delay(time); // Digit 3
      servo_object[3].write(0); delay(time);              // Digit 4
      servo_object[4].write(max_servo_open); delay(time); // Digit 5
      servo_object[5].write(max_servo_open); delay(time); // Digit 6
      servo_object[6].write(0); delay(time);              // Digit 7
      break;
    case 4:
      // Displaying the number 4
      // By enabling servos 2, 3, 6 & 7
      servo_object[0].write(0); delay(time);              // Digit 1
      servo_object[1].write(max_servo_open); delay(time); // Digit 2
      servo_object[2].write(max_servo_open); delay(time); // Digit 3
      servo_object[3].write(0); delay(time);              // Digit 4
      servo_object[4].write(0); delay(time);              // Digit 5
      servo_object[5].write(max_servo_open); delay(time); // Digit 6
      servo_object[6].write(max_servo_open); delay(time); // Digit 7
      break;
    case 5:
      // Displaying the number 5
      // By enabling servos 1, 3, 5, 6 & 7
      servo_object[0].write(max_servo_open); delay(time); // Digit 1
      servo_object[1].write(0); delay(time);              // Digit 2
      servo_object[2].write(max_servo_open); delay(time); // Digit 3
      servo_object[3].write(0); delay(time);              // Digit 4
      servo_object[4].write(max_servo_open); delay(time); // Digit 5
      servo_object[5].write(max_servo_open); delay(time); // Digit 6
      servo_object[6].write(max_servo_open); delay(time); // Digit 7
      break;
    case 6:
      // Displaying the number 6
      // By enabling servos 1, 3, 4, 5, 6 & 7
      servo_object[0].write(max_servo_open); delay(time); // Digit 1
      servo_object[1].write(0); delay(time);              // Digit 2
      servo_object[2].write(max_servo_open); delay(time); // Digit 3
      servo_object[3].write(max_servo_open); delay(time); // Digit 4
      servo_object[4].write(max_servo_open); delay(time); // Digit 5
      servo_object[5].write(max_servo_open); delay(time); // Digit 6
      servo_object[6].write(max_servo_open); delay(time); // Digit 7
      break;
    case 7:
      // Displaying the number 7
      // By enabling servos 1, 2 & 6
      servo_object[0].write(max_servo_open); delay(time); // Digit 1
      servo_object[1].write(max_servo_open); delay(time); // Digit 2
      servo_object[2].write(0); delay(time);              // Digit 3
      servo_object[3].write(0); delay(time);              // Digit 4
      servo_object[4].write(0); delay(time);              // Digit 5
      servo_object[5].write(max_servo_open); delay(time); // Digit 6
      servo_object[6].write(0); delay(time);              // Digit 7
      break;
  }
  // Blinks the debug LED once to help with visual debugging
  blinkStatus(1);
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

// Code that runs as a loop, repeating for as long as the arduino is running
// Is used to toggle the servos to their desired positions
// Dont mess with this after its coded. please?
void loop() {
  // put your main code here, to run repeatedly:
}

