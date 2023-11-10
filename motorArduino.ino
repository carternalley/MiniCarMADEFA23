#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11); // RX | TX
const int motorPin = 13;
char command = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  BTSerial.begin(9600);
  Serial.begin(9600); // Start serial communication for debugging
}

void loop() {
  if (BTSerial.available()) {
    command = BTSerial.read();

    if (command == '1') {
      digitalWrite(motorPin, HIGH);
      Serial.println("Motor on");
    } 
    else if (command == '0') {
      digitalWrite(motorPin, LOW); 
      Serial.println("Motor off");
    }
  }
}
