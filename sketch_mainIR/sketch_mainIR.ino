#include <IRLibRecvPCI.h>
#include <IRLibSendBase.h>
#include <IRLib_HashRaw.h>

#include "./data.h"

#include <SoftwareSerial.h>
// #include "./gamepad_control.hpp"
IRrecvPCI myReceiver(2); // Arduino UNO pin 2 for receiving IR
IRsendRaw mySender;      // For sending IR signals

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
// SoftwareSerial myBluetooth(RX_PIN, TX_PIN);

void setup() {
  Serial.begin(9600);
  myReceiver.enableIRIn();
// 
  myBluetooth.begin(9600);
// 
  Serial.println("Ready to receive IR signals");
  Serial.println("Point the remote controller to the IR receiver and press!");
}

void loop() {
  if (myBluetooth.available()) {
    char command = myBluetooth.read();
    gamepadControl(command);
  }

  if (myReceiver.getResults()) {
    Serial.println("\n\n-------------------------");
    Serial.println("Received IR signal:");

    Serial.print(F("\n#define RAW_DATA_LEN "));
    Serial.println(recvGlobal.recvLength, DEC);

    Serial.print(F("uint16_t rawData[RAW_DATA_LEN]={\n"));
    for (bufIndex_t i = 1; i < recvGlobal.recvLength; i++) {
      Serial.print(recvGlobal.recvBuffer[i], DEC);
      Serial.print(F(", "));
      if ((i % 8) == 0) {
        Serial.print(F("\n"));
      }
    }
    Serial.println(F("1000};"));
    Serial.println("-------------------------");

    myReceiver.enableIRIn();
  }

  // Here, you could call any of your predefined functions like alternateOnOff(), cycleSpeed(), testing()
  // For continuous operation, consider removing or adjusting delays and carefully managing when to send signals
  // Uncomment the functions below as per your testing needs. Remember to avoid running all at once without proper control
  
  // alternateOnOff();
  // cycleSpeed();
  testing();
}

void gamepadControl(char command) {
  switch (command) {
    case FORWARD:
      mySender.send(FanSpeed1, RAW_DATA_LEN, 38);
      Serial.print("Sent Turn ON Speed ");
      Serial.println(1);
      break;
    case RIGHT:
      mySender.send(FanSpeed3, RAW_DATA_LEN, 38);
      Serial.print("Sent Turn ON Speed ");
      Serial.println(3);
      break;
    case BACKWARD:
      mySender.send(FanSpeed4, RAW_DATA_LEN, 38);
      Serial.print("Sent Turn ON Speed ");
      Serial.println(4);
      break;
    case LEFT:
      mySender.send(FanSpeed5, RAW_DATA_LEN, 38);
      Serial.print("Sent Turn ON Speed ");
      Serial.println(5);
      break;
    case CIRCLE:
      mySender.send(FanOnOff, RAW_DATA_LEN, 38);
      Serial.println("Sent Turn ON/OFF");
      break;
    case CROSS:
      Serial.println("Stop/Cross");
      break;
    case TRIANGLE:
      mySender.send(FanSpeedB, RAW_DATA_LEN, 38);
      Serial.print("Sent Turn ON Speed MAX");
      Serial.println(1);
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
      // Serial.println(command);
      break;
  }
}

//function to alternate FanOnOff
unsigned long previousMillis = 0; 
const long interval = 2000; // Example interval for actions

void alternateOnOff() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    mySender.send(HitachiACONOFF, 100, 38);
    Serial.println("Sent Turn ON/OFF");
  }
}


// Assuming FanSpeed array of pointers is defined and initialized as shown previously
unsigned long previousCycleMillis = 0;
const long cycleInterval = 2000; // Interval between speed changes, adjust as needed
int currentSpeedIndex = 0; // To keep track of which speed we're on

void cycleSpeed() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousCycleMillis >= cycleInterval) {
    previousCycleMillis = currentMillis;
    if (currentSpeedIndex < FAN_SPEEDS) {
      mySender.send(FanSpeed[currentSpeedIndex], RAW_DATA_LEN, 38);
      Serial.print("Sent Turn ON Speed ");
      Serial.println(currentSpeedIndex + 1);
      currentSpeedIndex++;
    } else {
      // Reset the speed index after the last speed
      currentSpeedIndex = 0;
    }
  }
}


//function to test IR
unsigned long previousTestMillis = 0;
const long testInterval = 3000; // Interval for testing, adjust as needed

void testing() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousTestMillis >= testInterval) {
    previousTestMillis = currentMillis;
    // Assuming you define FanSpeedB or you can replace it with one of the FanSpeeds
    // mySender.send(FanSpeedB, 68, 38); // Example using FanSpeedB
    mySender.send(FanSpeedB, 68, 38);
    Serial.println("Sent Turn ON MaxSpeed");
  }
}


