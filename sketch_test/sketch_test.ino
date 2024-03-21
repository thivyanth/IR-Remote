#include <IRremote.hpp>

#define IR_RECEIVE_PIN 2
#define IR_SEND_PIN 3


void setup() {
  Serial.begin(9600);
  // Start the receiver, with ENABLE_LED_FEEDBACK using the onboard LED
  // to indicate when an IR message is received.
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
  Serial.println(F("IR Receiver started"));
}

void loop() {
  if (IrReceiver.decode()) {
    // Print the hexadecimal value of the decoded IR signal
    Serial.print(F("Decoded Raw Data (HEX): "));
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
    
    // Print a short result of the received IR data
    Serial.print(F("Decoded Data: "));
    IrReceiver.printIRResultShort(&Serial);
    Serial.println();
    
    // Print the statement required to send this data
    Serial.println(F("To Send This IR Signal:"));
    IrReceiver.printIRSendUsage(&Serial);
    Serial.println();

    IrReceiver.resume(); // Prepare to receive the next IR signal
  }
  delay(100); // Small delay to prevent overwhelming the serial output
}

// IRsend myIrSender;

// void setup() {
//   Serial.begin(9600);
//   // No specific setup required for IRsend
// }

// void loop() {
//   // Send the NEC IR signal
//   // The myIrSender.sendNEC function takes two arguments: the data to send and the number of bits
//   Serial.println(F("Sending NEC IR signal..."));
//   myIrSender.sendNEC(0x708FF300, 32);
  
//   // Wait for 5 seconds before sending it again
//   delay(1000);
// }
