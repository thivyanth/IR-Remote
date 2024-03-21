#include <IRremote.hpp>

const int RECV_PIN = 11;
const int LED_PIN = LED_BUILTIN; // Built-in LED pin on Arduino
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT); // Set the LED pin as an output
  irrecv.enableIRIn(); // Start the receiver
  Serial.println("IR Receiver Ready");
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    blinkLED(); // Blink the built-in LED
    irrecv.resume(); // Receive the next value
  }
}

void blinkLED() {
  digitalWrite(LED_PIN, HIGH); // Turn the LED on
  delay(500); // Wait for half a second
  digitalWrite(LED_PIN, LOW); // Turn the LED off
  delay(500); // Wait for half a second
}