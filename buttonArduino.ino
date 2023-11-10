#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11); // RX | TX
const int buttonPin = 2;
int buttonState = 0;


void setup() 
{
  // put your setup code here, to run once:
  pinMode(buttonPin, INPUT);
  BTSerial.begin(9600); // Default baud rate of HC-05/06
  Serial.begin(9600);   // Start serial communication for debugging
}

void loop() 
{
   buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) 
  {
    // When the button is pressed, send the command
    BTSerial.write('1'); // Sending '1' will be our signal to turn on the LED
    Serial.println("Button pressed!");
  } else 
  {
    // You might want to send a different command when the button is not pressed
    BTSerial.write('0'); // Sending '0' will be our signal to turn off the LED
  }

  delay(100);
}
