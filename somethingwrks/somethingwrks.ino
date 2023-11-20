// ConstantSpeed.pde
// -*- mode: C++ -*-
//
// Shows how to run AccelStepper in the simplest,
// fixed speed mode with no accelerations
/// \author  Mike McCauley (mikem@airspayce.com)
// Copyright (C) 2009 Mike McCauley
// $Id: ConstantSpeed.pde,v 1.1 2011/01/05 01:51:01 mikem Exp mikem $

#include <AccelStepper.h>

AccelStepper stepper1=AccelStepper(1,3,6); // Defaults to AccelStepper::FULL4WIRE (4 pins) on 2, 3, 4, 5
AccelStepper stepper2=AccelStepper(1,4,7); //Z axis

int x,y;

void setup()
{ 
  Serial.begin(9600); 
  
   stepper1.setMaxSpeed(800);
   stepper1.setSpeed(0);
   stepper1.setAcceleration(800);

   stepper2.setMaxSpeed(3200);
   stepper2.setSpeed(0);  
   stepper2.setAcceleration(3200);
}

void loop()
{  
  
    Serial.print("enter x value");
    while (Serial.available() == 0) {
  }
    x = Serial.parseInt();
   
    Serial.print("enter y value");
    while (Serial.available() == 0) {
  }
    y = Serial.parseInt();
  
   stepper1.moveTo(x);   //(-) left direction of x-axis
   stepper2.moveTo(-y);    //(+) down direction of y-axis
   stepper1.run();
   stepper2.run();

}
