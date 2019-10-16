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
#include <Servo.h>

//Arduino com START
const int com = 45;
//Arduino com END

//Sleep defines START
const int SleepX1 = 35;
const int SleepX2 = 37;
const int SleepY1 = 39;
const int SleepZ1 = 41; 
//Sleep defines END

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
const int ESP32Button = 53;
const int changeGame = 13;
//Button defines END

//Limit switch defines START
const int limitX1 = 27;
const int limitX2 = 29;
const int limitY1 = 33;
const int limitY2 = 31;
const int limitZ1 = 25;
//Limit switch defines END

//LED defines START
const int relay = 10;
const int buzzer = 11;
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
int knappStartState = 0;
int ESP32State = 0;
int changeGameState = 0;
//Input states END

//States START
boolean limitX1RTH = false;
boolean RTH = false;
boolean ENDMove = false;
boolean gameActive = false;
boolean executeEnd = false;
boolean ZHome = false;
unsigned long gameStart;
unsigned long endSteps;
boolean gameFree = true;
//States END


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

//Init servo
Servo claw;

void setup() {
  //Setup the servo for the claw
  claw.attach(24);
  
  //These are for setting inputs and outputs
  pinMode(relay, OUTPUT);
  pinMode(oppPin, INPUT);
  pinMode(nedPin, INPUT);
  pinMode(venstrePin, INPUT);
  pinMode(hoyrePin, INPUT);
  pinMode(knappZ1, INPUT);
  pinMode(knappZ2, INPUT);
  pinMode(SleepX1, OUTPUT);
  pinMode(SleepX2, OUTPUT);
  pinMode(SleepY1, OUTPUT);
  pinMode(SleepZ1, OUTPUT);
  pinMode(com, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(relay, OUTPUT);
  pinMode(ESP32Button, INPUT);
  //These are configuration for the stepper motors
  stepperX1.setMaxSpeed(-8000);
  stepperX1.setAcceleration(-8000);
  stepperX1.setSpeed(-8000);
  stepperX2.setMaxSpeed(8000);
  stepperX2.setAcceleration(8000);
  stepperX2.setSpeed(8000);
  stepperX3.setMaxSpeed(-8000);
  stepperX3.setAcceleration(-8000);
  stepperX3.setSpeed(-8000);
  stepperX4.setMaxSpeed(8000);
  stepperX4.setAcceleration(8000);
  stepperX4.setSpeed(8000);
  stepperY1.setMaxSpeed(8000);
  stepperY1.setAcceleration(8000);
  stepperY1.setSpeed(8000);
  stepperY2.setMaxSpeed(-8000);
  stepperY2.setAcceleration(-8000);
  stepperY2.setSpeed(-8000);
  stepperZ2.setMaxSpeed(8000);
  stepperZ2.setAcceleration(8000);
  stepperZ2.setSpeed(8000);
  stepperZ1.setMaxSpeed(-8000);
  stepperZ1.setAcceleration(-8000);
  stepperZ1.setSpeed(-8000);
  RTH = true;

  Serial.begin(115200);
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
  knappRTHState = digitalRead(knappRTH);
  knappStartState = digitalRead(knappStart);
  ESP32State = digitalRead(ESP32Button);
  changeGameState = digitalRead(changeGame);

if(changeGameState == HIGH && gameFree == true) {
  gameFree = false;
}

if(knappStartState == HIGH && gameFree == true && gameActive == false && RTH == false) {
  Serial.println("KNAPP startet spillet");
  gameActive = true;
  gameStart = millis();
  }  

if(ESP32State == HIGH && gameActive == false && RTH == false) {
  Serial.println("ESP32 startet spillet");
  gameActive = true;
  gameStart = millis();
  } 

if(gameStart+30000 < millis() && gameActive == true){ 
  gameActive = false;
  RTH = true;
  }

if(gameActive == false && RTH == false){
  digitalWrite(SleepX1, LOW); 
  digitalWrite(SleepX2, LOW);
  digitalWrite(SleepY1, LOW);
  digitalWrite(SleepZ1, LOW);
  digitalWrite(relay, LOW);
} else {
  digitalWrite(SleepX1, HIGH);
  digitalWrite(SleepX2, HIGH);
  digitalWrite(SleepY1, HIGH);
  digitalWrite(SleepZ1, HIGH);
  digitalWrite(relay, HIGH);
} 

if(gameActive){
  digitalWrite(11, HIGH);
    if (oppState == HIGH && nedState == LOW && limitX1State == LOW) {
      //Dette er mot forsiden (bruk dette til hjem)
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
        if (knappRTHState == HIGH){
          ENDMove = true;
          //RTH = true;
          gameActive = false;
          }
}
          
 if(RTH) {
  if(limitX1State == LOW && ZHome){
   stepperX2.runSpeed();
   stepperX3.runSpeed();
    }
   if(limitY2State == LOW && ZHome){
    stepperY1.runSpeed();}
   if(limitZ1State == LOW){
    stepperZ1.runSpeed();
    ZHome = false;
    } else {
      ZHome = true;
    }
    
   if(limitX1State == HIGH && limitY2State == HIGH && limitZ1State == HIGH){ 
    claw.write(0);
    stepperZ1.setCurrentPosition(0);
    stepperZ2.setCurrentPosition(0);
    stepperZ2.setMaxSpeed(8000);
    stepperZ2.setAcceleration(8000);
    stepperZ2.setSpeed(8000);
    stepperZ1.setMaxSpeed(-8000);
    stepperZ1.setAcceleration(-8000);
    stepperZ1.setSpeed(-8000);
    RTH = false;
    gameActive = false;
    }
  }

  if(ENDMove) {
    endSteps = 21000;
    claw.write(0);
    stepperZ2.runToNewPosition(endSteps);
    claw.write(180);
    delay(500);
    RTH= true;
    ENDMove = false;
    //endSteps = endSteps + 21000;
    }
}
