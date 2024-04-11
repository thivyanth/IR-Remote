#include <SoftwareSerial.h>

// Define the pins
#define RX_PIN 10
#define TX_PIN 11

// Define command constants
#define FORWARD 'F'
#define BACKWARD 'B'
#define LEFT 'L'
#define RIGHT 'R'
#define CIRCLE 'C'
#define CROSS 'X'
#define TRIANGLE 'T'
#define SQUARE 'S'
#define START 'A'
#define PAUSE 'P'

// Create a software serial object
SoftwareSerial myBluetooth(RX_PIN, TX_PIN);

// void setup() {
//   myBluetooth.begin(9600);  // Set the baud rate for Bluetooth communication
//   Serial.begin(9600);       // Set the baud rate for serial communication to PC
//   // Initialize any other necessary setup code here
// }

// void loop() {
//   if (myBluetooth.available()) {
//     char command = myBluetooth.read();
//     executeCommand(command);
//   }
//   // Continue with other tasks in your main loop
// }

void executeCommand(char command) {
  switch (command) {
    case FORWARD:
      Serial.println("Moving forward");
      break;
    case BACKWARD:
      Serial.println("Moving backward");
      break;
    case LEFT:
      Serial.println("Turning left");
      break;
    case RIGHT:
      Serial.println("Turning right");
      break;
    case CIRCLE:
      Serial.println("Circle");
      break;
    case CROSS:
      Serial.println("Stop/Cross");
      break;
    case TRIANGLE:
      Serial.println("Toggle state");
      break;
    case SQUARE:
      Serial.println("Status info");
      break;
    case START:
      Serial.println("Start");
      break;
    case PAUSE:
      Serial.println("Pause");
      break;
    default:
      Serial.println("Invalid command");
      break;
  }
}
