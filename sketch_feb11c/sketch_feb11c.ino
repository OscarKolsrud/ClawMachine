#include <AccelStepper.h>

// constants won't change. They're used here to set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

// Define a stepper and the pins it will use
AccelStepper stepper(AccelStepper::DRIVER, 9, 8);

int pos = 3600;

void setup()
{ 
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT); 

}

void loop()
{
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
    digitalWrite(ledPin, LOW);
    stepper.setMaxSpeed(1000);
    stepper.setSpeed(1000);
    stepper.runSpeed();
    } else {
      digitalWrite(ledPin, HIGH);
      stepper.setMaxSpeed(1000);
      stepper.setSpeed(1000);
      stepper.runSpeed();
      }
 
}
