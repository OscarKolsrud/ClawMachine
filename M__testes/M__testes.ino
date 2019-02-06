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

void setup() {
  //Tell the LCD its size
  lcd.begin(16, 2);

}

void loop() {
  // put your main code here, to run repeatedly:

}
