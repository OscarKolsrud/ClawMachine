#include <AccelStepper.h>
#include <MultiStepper.h>

const int buttonPin1 = 2;
const int buttonPin2 = 3;
const int buttonPin3 = 4;
const int buttonPin4 = 5;
const int ledPin = 13;

int buttonState1 = 0;
int buttonState2 = 0;
int buttonState3 = 0;
int buttonState4 = 0;

AccelStepper stepper1(AccelStepper::DRIVER, 9, 8);
AccelStepper stepper2(AccelStepper::DRIVER, 9, 8);
int pos = 3600; 

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(buttonPin4, INPUT);
  stepper1.setMaxSpeed(1250);
  stepper1.setAcceleration(1250);
  stepper1.setSpeed(1250);
  stepper2.setMaxSpeed(-1250);
  stepper2.setAcceleration(-1250);
  stepper2.setSpeed(-1250);
}

void loop() {
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);
  buttonState4 = digitalRead(buttonPin4);
  if  (buttonState1 == HIGH && buttonState2 == LOW && buttonState4 == LOW && buttonState3 == LOW) {
    digitalWrite(ledPin, LOW);
    stepper1.runSpeed();
    } else if (buttonState1 == LOW && buttonState2 == LOW && buttonState4 == HIGH && buttonState3 == LOW) {
    digitalWrite(ledPin, HIGH);
    stepper2.runSpeed();
    }

}
