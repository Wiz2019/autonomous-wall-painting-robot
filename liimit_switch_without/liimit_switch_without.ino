#include <AccelStepper.h>

const int limitSwitch_1 = 10;

bool switchFlipped = false;
bool previousFlip = true;

AccelStepper stepper=AccelStepper(1,3,6);     //AccelStepper (motorInterfaceType,stepPin,dirPin);

void setup() 
{
  pinMode(limitSwitch_1,INPUT);

  Serial.begin(9600);

  stepper.setMaxSpeed(5000);
  stepper.setAcceleration(1000);
  stepper.setSpeed(2000);
  delay(500);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  stepper.runSpeed();
  if(digitalRead(limitSwitch_1)==HIGH)
  {
    switchFlipped = true;
    previousFlip =! previousFlip;
  }
    flipCheck();   
}

void flipCheck()
{
  if(switchFlipped == true)
  {
    if(previousFlip == true)
    {
      stepper.setSpeed(2000);
    }
    if(previousFlip == false)
    {
      stepper.setSpeed(-2000);
    }
    switchFlipped = false;
  }
}
