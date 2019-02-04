#include <AccelStepper.h>

// Define two steppers and the pins they will use
AccelStepper stepper1(AccelStepper::DRIVER, 9, 8);
AccelStepper stepper2(AccelStepper::DRIVER, 7, 6);

int pos1 = 3600;
int pos2 = 5678;

void setup()
{  
  //Stepper 1 setup
  stepper1.setMaxSpeed(3000);
  stepper1.setAcceleration(1000);
  //Stepper 2 setup
  stepper2.setMaxSpeed(2000);
  stepper2.setAcceleration(800);
}

void loop()
{
  if (stepper1.distanceToGo() == 0)
  {
     pos1 = -pos1; 
    stepper1.moveTo(pos1);
  }
  if (stepper2.distanceToGo() == 0)
  {
    pos2 = -pos2;
    stepper2.moveTo(pos2);
  }
  stepper1.run();
  stepper2.run();
}
