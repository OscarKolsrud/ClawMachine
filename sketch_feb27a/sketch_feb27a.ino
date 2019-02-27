#include <AccelStepper.h>

// Define a stepper and the pins it will use
AccelStepper stepper(AccelStepper::DRIVER, 7, 6);

int pos = 3600;

void setup()
{  
  pinMode(50, INPUT);
   stepper.setMaxSpeed(10000);
   stepper.setSpeed(8000);  
    
}

void loop()
{
  
  if(digitalRead(50) == HIGH){
    stepper.runSpeed();}
}
