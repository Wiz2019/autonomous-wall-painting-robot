// Random.pde
// -*- mode: C++ -*-
//
// Make a single stepper perform random changes in speed, position and acceleration
//
// Copyright (C) 2009 Mike McCauley
// $Id: Random.pde,v 1.1 2011/01/05 01:51:01 mikem Exp mikem $
 
#include <AccelStepper.h>
long posi; 
int pos1;
// Define a stepper and the pins it will use
AccelStepper stepper; // Defaults to AccelStepper::FULL4WIRE (4 pins) on 2, 3, 4, 5
  
void setup()
{  
  Serial.begin(9600);
  stepper.setMaxSpeed(10000);
  stepper.setAcceleration(800);
  stepper.setCurrentPosition(0);
  stepper.moveTo(1000);
}
 
void loop()
{
  posi = stepper.distanceToGo();
  pos1 = stepper.currentPosition();
  Serial.println(pos1);
    if (posi <= 500)
    {
      stepper.moveTo(500);
//      stepper.moveTo(0);
    }
    stepper.run();
}
