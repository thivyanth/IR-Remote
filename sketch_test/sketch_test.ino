void setup() {
  Serial.begin(9600); // Start the serial communication
  Serial.println("Enter analog pin number (0 to 5):");
}

void loop() {
  if (Serial.available() > 0) {
    int pinNumber = Serial.parseInt(); // Read the pin number from user input
    if (pinNumber >= 0 && pinNumber <= 5) {
      int sensorValue = analogRead(pinNumber); // Read the voltage on the chosen pin
      float voltage = sensorValue * ((3.3/0.648) / 1023.0); // Convert the reading to voltage
      Serial.print("A");
      Serial.print(pinNumber);
      Serial.print(": ");
      Serial.println(voltage); // Print the voltage to the Serial Monitor
    } else {
      Serial.println("Invalid pin number. Please enter a number between 0 to 5:");
    }
    while (Serial.available() > 0) {
      Serial.read(); // Clear the serial buffer
    }
    Serial.println("Enter analog pin number (0 to 5):");
  }
}
