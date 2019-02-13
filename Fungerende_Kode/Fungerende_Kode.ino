#include <AccelStepper.h>
#include <MultiStepper.h>

//Joystick defines START
const int oppPin = 53;
const int nedPin = 51;
const int venstrePin = 49;
const int hoyrePin = 47;
//Joystick defines END

//Button defines START
const int knappZ1 = 34;
const int knappZ2 = 32;
//Button defines END

//Limit switch defines START
const int limitX1 = 42;
const int limitX2 = 40;
const int limitY1 = 38;
const int limitY2 = 36;
//Limit switch defines END

//LED defines START
const int ledPin1 = 11;
//LED defines END

//Input states START
int oppState = 0;
int nedState = 0;
int venstreState = 0;
int hoyreState = 0;
int limitX1State = 0;
int limitX2State = 0;
int limitY1State = 0;
int limitY2State = 0;
//Input states END

//Initiate stepper library START
AccelStepper stepperX1(AccelStepper::DRIVER, 9, 8);
AccelStepper stepperX2(AccelStepper::DRIVER, 9, 8);
AccelStepper stepperX3(AccelStepper::DRIVER, 7, 6);
AccelStepper stepperX4(AccelStepper::DRIVER, 7, 6);
AccelStepper stepperY1(AccelStepper::DRIVER, 5, 4);
AccelStepper stepperY2(AccelStepper::DRIVER, 5, 4);
//Initiate stepper library END
 

void setup() {
  //pinMode(ledPin, OUTPUT);
  pinMode(oppPin, INPUT);
  pinMode(nedPin, INPUT);
  pinMode(venstrePin, INPUT);
  pinMode(hoyrePin, INPUT);
  stepperX1.setMaxSpeed(1250);
  stepperX1.setAcceleration(1250);
  stepperX1.setSpeed(1250);
  stepperX2.setMaxSpeed(-1250);
  stepperX2.setAcceleration(-1250);
  stepperX2.setSpeed(-1250);
  stepperX3.setMaxSpeed(1250);
  stepperX3.setAcceleration(1250);
  stepperX3.setSpeed(1250);
  stepperX4.setMaxSpeed(-1250);
  stepperX4.setAcceleration(-1250);
  stepperX4.setSpeed(-1250);
  stepperY1.setMaxSpeed(1250);
  stepperY1.setAcceleration(1250);
  stepperY1.setSpeed(1250);
  stepperY2.setMaxSpeed(-1250);
  stepperY2.setAcceleration(-1250);
  stepperY2.setSpeed(-1250);
}

void loop() {
  oppState = digitalRead(oppPin);
  nedState = digitalRead(nedPin);
  venstreState = digitalRead(venstrePin);
  hoyreState = digitalRead(hoyrePin);
  limitX1State = digitalRead(limitX1);
  limitX2State = digitalRead(limitX2);
  limitY1State = digitalRead(limitY1);
  limitY2State = digitalRead(limitY2);

    if (oppState == HIGH && nedState == LOW && limitX1State == LOW && limitX2State == LOW) {
      stepperX2.runSpeed();
      stepperX3.runSpeed();
      } 
      if (nedState == HIGH && oppState == LOW && limitX1State == LOW && limitX2State == LOW) {
        stepperX1.runSpeed();
        stepperX4.runSpeed();
      } 
      if (venstreState == HIGH && hoyreState == LOW && limitY1State == LOW && limitY2State == LOW) {
        stepperY2.runSpeed();
        } 
        if (hoyreState == HIGH && venstreState == LOW && limitY1State == LOW && limitY2State == LOW) {
          stepperY1.runSpeed();
          }

}
