// Code libraries included with the program. required to run the program
// These are Arduino.h to be able to use functions for the arduino IDE 
// AND Servo.h to be able to use servos with the arduino.
// This sections #include <Arduino.h> which can be removed to make the program compatable with the arduino IDE.
// This program was coded in Visual Studio Code with PlatformIO
// This program was coded by @randomidiot2887.
#include <Arduino.h>
#include <Servo.h>

// =======================================
// Section of code that contains constant used by the program
// You can alter these lines of code to fit your needs
// Basically a configuration file, but in main.cpp
// DO NOT ALTER THE ORDER OF THESE CONSTANTS. THEY MUST BE IN THE ORDER THEY CURRENTLY ARE IN

// Constant that stores the total number of servos connected to the arduino
// Should be 7 as im intended to use it with 7 servos
const int NUM_SERVOS = 7;
// Servo layout
// - Servo 1 at Pin 3
// - Servo 2 at Pin 4
// - Servo 3 at Pin 5
// - Servo 4 at Pin 6
// - Servo 5 at Pin 7
// - Servo 6 at Pin 8
// - Servo 7 at Pin 9
const int servos[NUM_SERVOS] = {3, 4, 5, 6, 7, 8, 9};
// Constant that stores the maximum angle to which the servos will open to
// Range is from 0 to 180
const int max_servo_open=180;
// Constant that stores the minimum angle to which the servos will open to
// Range is from 0 to 180
const int min_servo_open=0;
// Constant that stores the serial baud to output serial at
const int baud=9600;
// Constant that declares the delay between the switching of servos to try and reduce power draw
const int time=100;
// Constant that contains the delay used by the subroutine blinkStatus()
// Value must be greater then 0. 
// input is in milliseconds. 1 second is equal to 1000 milliseconds
const int debug_led_blink_time = 100;
// Constant that determines for how lonng the arduino should wait in between displaying numbers using the servos
// Value must be greater then zero
// input is in milliseconds. 1 second is equal to 1000 milliseconds
const int wait_number_delay = 2000;
// Constant that determines for how long the arduino should wait in between loops of main() as it goes from number 9 to 0
// Value must be greater then zero
// input is in milliseconds. 1 second is equal to 1000 milliseconds
const int wait_number_loop_delay = 5000;

// =======================================
// Section of code that contains variables used by the program
// You should NOT alter these lines of code

// Object declarations
Servo servo_object[NUM_SERVOS];

// =======================================
// Section of code that contains functions and procedures required to run the code

// Function that acts as the heartbeat of the arduino.
// Can be used to identify the state of initialisation and stuff bym just glancing at the arduino
// Assists in allowing visual debugging during initialisation of arduino
void blinkStatus(int times=1) {
  // Displays debug message notifying the user on how many times the debug led is going to blink
  Serial.print("DEBUG LED: Blinking LED_BUILTIN "); Serial.print(times); Serial.println(" times");
  // Code for blinking the debug LED (LED_BUILTIN) specified amount of times.
  // Depends on constant debug_led_blink_time
  // Uses a FOR loop
  for (int i = 0; i < times; i++) {
    // Turns on the LED
    digitalWrite(LED_BUILTIN, HIGH);
    // Waits for time stated in constant debug_led_blink_time
    delay(debug_led_blink_time);
    // Turns off the LED
    digitalWrite(LED_BUILTIN, LOW);
    // Waits for time stated in constant debug_led_blink_time
    delay(debug_led_blink_time);
    // The code loops for the number of times stated in argument times
  }
}

// Function that is used to control the servos that spin at a time, handles displaying of numbers
// Used to clean up loop()
// syntax: display_num(number)
// number must be 0 <= number < 10 to display a number on the 7 segment display
// if number is 10, itll be equivelent to clearning the screen
// if number is less then 0 or greater then 10, the procedure WILL BREAK
void display_num(int num=10) {
  // Serial signal for debugging
  // Sends in format "Procedure display_num invoked with paremeter {num}"
  Serial.print("    > Procedure display_num invoked with paremeter "); Serial.println(num);
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
    case 0:
      // Displaying the number 0
      // By enabling servos 1, 2, 4, 5, 6 & 7
      servo_object[0].write(max_servo_open); delay(time); // Digit 1
      servo_object[1].write(max_servo_open); delay(time); // Digit 2
      servo_object[2].write(min_servo_open); delay(time); // Digit 3
      servo_object[3].write(max_servo_open); delay(time); // Digit 4
      servo_object[4].write(max_servo_open); delay(time); // Digit 5
      servo_object[5].write(max_servo_open); delay(time); // Digit 6
      servo_object[6].write(max_servo_open); delay(time); // Digit 7
      break;
    case 1:
      // Displaying the number 1
      // By enabling servos 2 and 6
      servo_object[0].write(min_servo_open); delay(time); // Digit 1
      servo_object[1].write(min_servo_open); delay(time); // Digit 2
      servo_object[2].write(max_servo_open); delay(time); // Digit 3
      servo_object[3].write(min_servo_open); delay(time); // Digit 4
      servo_object[4].write(min_servo_open); delay(time); // Digit 5
      servo_object[5].write(min_servo_open); delay(time); // Digit 6
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
      servo_object[5].write(min_servo_open); delay(time); // Digit 6
      servo_object[6].write(min_servo_open); delay(time); // Digit 7
      break;
    case 3:
      // Displaying the number 3
      // By enabling servos 1, 2, 3, 5 & 6
      servo_object[0].write(max_servo_open); delay(time); // Digit 1
      servo_object[1].write(max_servo_open); delay(time); // Digit 2
      servo_object[2].write(max_servo_open); delay(time); // Digit 3
      servo_object[3].write(min_servo_open); delay(time); // Digit 4
      servo_object[4].write(max_servo_open); delay(time); // Digit 5
      servo_object[5].write(max_servo_open); delay(time); // Digit 6
      servo_object[6].write(min_servo_open); delay(time); // Digit 7
      break;
    case 4:
      // Displaying the number 4
      // By enabling servos 2, 3, 6 & 7
      servo_object[0].write(min_servo_open); delay(time); // Digit 1
      servo_object[1].write(max_servo_open); delay(time); // Digit 2
      servo_object[2].write(max_servo_open); delay(time); // Digit 3
      servo_object[3].write(min_servo_open); delay(time); // Digit 4
      servo_object[4].write(min_servo_open); delay(time); // Digit 5
      servo_object[5].write(max_servo_open); delay(time); // Digit 6
      servo_object[6].write(max_servo_open); delay(time); // Digit 7
      break;
    case 5:
      // Displaying the number 5
      // By enabling servos 1, 3, 5, 6 & 7
      servo_object[0].write(max_servo_open); delay(time); // Digit 1
      servo_object[1].write(min_servo_open); delay(time); // Digit 2
      servo_object[2].write(max_servo_open); delay(time); // Digit 3
      servo_object[3].write(min_servo_open); delay(time); // Digit 4
      servo_object[4].write(max_servo_open); delay(time); // Digit 5
      servo_object[5].write(max_servo_open); delay(time); // Digit 6
      servo_object[6].write(max_servo_open); delay(time); // Digit 7
      break;
    case 6:
      // Displaying the number 6
      // By enabling servos 1, 3, 4, 5, 6 & 7
      servo_object[0].write(max_servo_open); delay(time); // Digit 1
      servo_object[1].write(min_servo_open); delay(time); // Digit 2
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
      servo_object[2].write(min_servo_open); delay(time); // Digit 3
      servo_object[3].write(min_servo_open); delay(time); // Digit 4
      servo_object[4].write(min_servo_open); delay(time); // Digit 5
      servo_object[5].write(max_servo_open); delay(time); // Digit 6
      servo_object[6].write(min_servo_open); delay(time); // Digit 7
      break;
    case 8:
      // Displaying the number 8
      // By enabling all servos
      servo_object[0].write(max_servo_open); delay(time); // Digit 1
      servo_object[1].write(max_servo_open); delay(time); // Digit 2
      servo_object[2].write(max_servo_open); delay(time); // Digit 3
      servo_object[3].write(max_servo_open); delay(time); // Digit 4
      servo_object[4].write(max_servo_open); delay(time); // Digit 5
      servo_object[5].write(max_servo_open); delay(time); // Digit 6
      servo_object[6].write(max_servo_open); delay(time); // Digit 7
      break;
    case 9:
      // Displaying the number 9
      // By enabling servos 1, 2, 3, 5, 6 & 7
      servo_object[0].write(max_servo_open); delay(time); // Digit 1
      servo_object[1].write(max_servo_open); delay(time); // Digit 2
      servo_object[2].write(max_servo_open); delay(time); // Digit 3
      servo_object[3].write(min_servo_open); delay(time); // Digit 4
      servo_object[4].write(max_servo_open); delay(time); // Digit 5
      servo_object[5].write(max_servo_open); delay(time); // Digit 6
      servo_object[6].write(max_servo_open); delay(time); // Digit 7
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
  Serial.begin(baud); Serial.print("SERIAL: Serial has been enabled at "); Serial.print(baud); Serial.println(" Baud");
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
  // Resets the servo positions back to the default position, basically resets the display
  // Uses the display_num subroutine with the number 10 as a parameter
  // 10 refers to the clear screen option
  display_num(10);
  // Prints a message in serial that states the number of servos initialised succesfully
  // Also displays more imformation that notifies the usert that the servo has finished the void setup state
  Serial.print("    > Succesfully initialised "); Serial.print(NUM_SERVOS); Serial.println(" Servos as Servos"); Serial.println("Setup code finished");
} 

// Code that runs as a loop, repeating for as long as the arduino is running
// Is used to toggle the servos to their desired positions
// Dont mess with this after its coded. please?
void loop() {
  // Basically lets make it go through the numbers zero to nine and repeat...
  // Im going to use a for loop here, where it increments from zero to nine then resets back to 0 and repeats.
  for (int i=0; i<10; i++) {
    // Increments the number on the Servo display by one
    // Then waits for 1000ms (1.0s)
    // Then repeats
    display_num(i);
    // Sends a signal via serial used for debugging
    // In format "Made servos display number {i} Succesfully"
    Serial.print("    > Made servos display number "); Serial.print(i); Serial.println(" Succesfully");
    // Displays debug message that informs the user that the arduino is waiting for a certain amount of time between displaying numbers
    // the time is determined in constant wait_number_delay
    Serial.print("    > Waiting for "); Serial.print(wait_number_delay); Serial.println(" milliseconds");
    // Waits for a specific ammount of time
    // Specified in constant wait_number_delay
    delay(wait_number_delay);
  }
  // Sends serial sigmal used for debugging
  // In format "Looping"
  Serial.println("LOOP: Looping");
  // Displays debug message that informs the user that the arduino is waiting for a certain amount of time between loops
  // the time is determined in constant wait_number_loop_delay
  delay(wait_number_loop_delay);
  // Blinks the debug LED once to let the user know it is looping
  blinkStatus(1);
}