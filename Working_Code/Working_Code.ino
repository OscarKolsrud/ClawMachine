/* LEAVE THIS COPYRIGHT NOTICE INTACT. OTHER USE IS A BREACH OF THE LICENSE GNU GPLv3 AND IS PUNISHABLE BY LAW
 *  
 * CLAW MACHINE MAIN CONTROLLER
 * WRITTEN FOR: ARDUINO MEGA ATMEGA2560
 * 
 * CODE WRITTEN BY: OSCAR KOLSRUD
 * CONTACT: oscar@kolsrudweb.no
 * WEBSITE: kolsrudweb.no
 * DONT CONTACT THE AUTHOR FOR SUPPORT! ASK THE COMMUNITY!
 * 
 * Licensed under GNU GPLv3: https://choosealicense.com/licenses/gpl-3.0/
 * 
 * Project repository: https://github.com/OscarKolsrud/ClawMachine
 */

#include <AccelStepper.h>
#include <MultiStepper.h>

//Work around
//we love our father stalin

//Joystick defines START
const int oppPin = 40;
const int nedPin = 38;
const int venstrePin = 36;
const int hoyrePin = 34;
//Joystick defines END

//Button defines START
const int knappZ1 = 44;
const int knappZ2 = 48;
const int knappStart = 50;
const int knappRTH = 46;
const int resetPin = 20;
//Button defines END

//Limit switch defines START
const int limitX1 = 27;
const int limitX2 = 29;
const int limitY1 = 31;
const int limitY2 = 33;
const int limitZ1 = 25;
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
int limitZ1State = 0;
int limitZ2State = 0;
int knappZ1State = 0;
int knappZ2State = 0;
int knappRTHState = 0;
//Input states END

//States
boolean limitX1RTH = false;
boolean RTH = false;
boolean gameActive = false;
unsigned long gameStart;


//Initiate stepper library START
AccelStepper stepperX1(AccelStepper::DRIVER, 7, 6);
AccelStepper stepperX2(AccelStepper::DRIVER, 7, 6);
AccelStepper stepperX3(AccelStepper::DRIVER, 9, 8);
AccelStepper stepperX4(AccelStepper::DRIVER, 9, 8);
AccelStepper stepperY1(AccelStepper::DRIVER, 5, 4);
AccelStepper stepperY2(AccelStepper::DRIVER, 5, 4);
AccelStepper stepperZ1(AccelStepper::DRIVER, 3, 2);
AccelStepper stepperZ2(AccelStepper::DRIVER, 3, 2);
//Initiate stepper library END



void setup() {
  //pinMode(ledPin, OUTPUT);
  pinMode(oppPin, INPUT);
  pinMode(nedPin, INPUT);
  pinMode(venstrePin, INPUT);
  pinMode(hoyrePin, INPUT);
  pinMode(knappZ1, INPUT);
  pinMode(knappZ2, INPUT);
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
  stepperZ1.setMaxSpeed(1250);
  stepperZ1.setAcceleration(1250);
  stepperZ1.setSpeed(1250);
  stepperZ2.setMaxSpeed(-1250);
  stepperZ2.setAcceleration(-1250);
  stepperZ2.setSpeed(-1250);

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
  limitZ1State = digitalRead(limitZ1);
  knappZ1State = digitalRead(knappZ1);
  knappZ2State = digitalRead(knappZ2);
  knappRTHState = digitalRead(knappRTH);
  knappStartState = digitalRead(knappStart);


if(knappStartState == HIGH && gameActive == false) {
  gameActive = true;
  gameStart = millis();
  }  

if(gameStart+60000 < millis()){
  gameActive = false;
  RTH = true;
  }
  
if(gameActive){
    if (oppState == HIGH && nedState == LOW && limitX1State == LOW) {
      stepperX2.runSpeed();
      stepperX3.runSpeed();
      } 
      if (nedState == HIGH && oppState == LOW && limitX2State == LOW) {
        stepperX1.runSpeed();
        stepperX4.runSpeed();
      } 
      if (venstreState == HIGH && hoyreState == LOW && limitY1State == LOW) {
        stepperY2.runSpeed();
        } 
        if (hoyreState == HIGH && venstreState == LOW && limitY2State == LOW) {
          stepperY1.runSpeed();
          }
          if (knappZ1State == HIGH && knappZ2State == LOW && limitZ1State == LOW) {
            stepperZ1.runSpeed();
          }
          if (knappZ2State == HIGH && knappZ1State == LOW) {
            stepperZ2.runSpeed();
          }
        if (knappRTHState == HIGH){
          RTH = true;
          }
}
          
 if(RTH) {
  if(limitX1State == LOW){
   stepperX2.runSpeed();
   stepperX3.runSpeed();
    }
   if(limitY1State == LOW){
    stepperY2.runSpeed();}
   if(limitZ1State == LOW){
    stepperZ1.runSpeed();
    }
    
   if(limitX1State == HIGH && limitY1State == HIGH && limitZ1State == HIGH){
    RTH = false;
    }
  }


}
