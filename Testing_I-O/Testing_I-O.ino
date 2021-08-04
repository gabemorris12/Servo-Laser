#include <ClearPathMotorSD.h>
#include <ClearPathStepGen.h>

ClearPathMotorSD X;
ClearPathStepGen machine(&X);

void setup() {
  
  X.attach(22, 23, 24, 25);  // Direction/A is pin 22, Step/B is pin 23, Enable is pin 24, HLFB is pin 25

  X.setMaxVel(20000);  // Value between 2 and 100,000 steps/sec
  X.setMaxAccel(50000);  // Value between 4000 and 2,000,000 steps/sec^2

  X.enable();  // Homimg will automatically occur at this call. Be sure to account for its moving.

  delay(100);

  machine.Start();

  Serial.begin(9600);
}

void loop() {
  X.move(800);
  while (!X.readHLFB() or !X.commandDone()) {
    Serial.println("Moving");
  }
  Serial.println("Move Done");
  delay(5000);
  X.move(-800);
  while (!X.readHLFB() or !X.commandDone()) {
    Serial.println("Moving");
  }
  Serial.println("Move Done");
  delay(5000);

  // Some fun
//  X.setMaxVel(50000);
//  X.move(10000);
//  while (!X.commandDone()) {
//    
//  }
//  delay(20);
//  X.move(-20000);
//  while (!X.commandDone()) {
//    
//  }
//  delay(20);
//  X.setMaxVel(80000);
//  X.move(30000);
//  while (!X.commandDone()) {
//    
//  }
//  delay(20);
//  X.setMaxVel(20000);
}
