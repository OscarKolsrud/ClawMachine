// Include needed libraries
#include <LiquidCrystal.h>

// Initialize the LCD library
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Button inputs
const int startProgramPIN = 8;

// Read button inputs
int startProgram;

void setup() {
  pinMode(startProgram, INPUT);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
}

void loop() {
  startProgram = digitalRead(startProgramPIN);
  if (startProgram == HIGH) {
    lcd.display();
    lcd.clear();
    lcd.print("Knapp trykket");
    } else {
    lcd.noDisplay();
      }
}
