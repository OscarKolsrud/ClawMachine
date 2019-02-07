/* Arduino powered claw machine
 * 
 * Code written by: Oscar Sortland Kolsrud
 * 
 * Version: v0.1
 * 
 */

//Accellstepper stepper library (May be removed if not used)
#include <AccelStepper.h>
#include <MultiStepper.h>
//Arduino standard stepper library (May be removed if not used)
#include <Stepper.h>
//LCD control library
#include <LiquidCrystal.h>
//Library for servo control
#include <Servo.h>


//Initialization code

//LCD init start
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
//LCD init end


//Button defines
const int buttonForward = 31;
const int buttonBackward = 32;
const int buttonLeft = 33;
const int buttonRight = 34;
const int buttonUp = 35;
const int buttonDown = 36;

//Status LEDs
const int statusLED1 = 37;
const int statusLED2 = 38;
const int statusLED3 = 39;
const int statusLED4 = 40;
const int statusLED5 = 41;
const int statusLED6 = 42;
const int statusLED7 = 43;
const int statusLED8 = 44;

//Stepper defines

//Other defines

void setup() {
  //Set the clock
  setTime(01,01,00,9,9,1999);
  //Tell the LCD its size
  lcd.begin(16, 2);
  //set pinModes
  pinMode(buttonForward, INPUT);
  pinMode(buttonBackward, INPUT);
  pinMode(buttonLeft, INPUT);
  pinMode(buttonRight, INPUT);
  pinMode(buttonUp, INPUT);
  pinMode(buttonDown, INPUT);
  pinMode(statusLED1, OUTPUT);
  pinMode(statusLED2, OUTPUT);
  pinMode(statusLED3, OUTPUT);
  pinMode(statusLED4, OUTPUT);
  pinMode(statusLED5, OUTPUT);
  pinMode(statusLED6, OUTPUT);
  pinMode(statusLED7, OUTPUT);
  pinMode(statusLED8, OUTPUT);

  //set to include the internal resistor
  pinMode(buttonForward, INPUT_PULLUP);
  pinMode(buttonBackward, INPUT_PULLUP);
  pinMode(buttonLeft, INPUT_PULLUP);
  pinMode(buttonRight, INPUT_PULLUP);
  pinMode(buttonUp, INPUT_PULLUP);
  pinMode(buttonDown, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:

}


void  runGame() {
  //Code to be run when game is run
  
}
