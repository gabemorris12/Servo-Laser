#include <ClearPathMotorSD.h>
#include <ClearPathStepGen.h>

ClearPathMotorSD X;
ClearPathStepGen machine(&X);

void setup() {
  
  X.attach(22, 23, 24, 25);  // Direction/A is pin 22, Step/B is pin 23, Enable is pin 24, HLFB is pin 25

  X.setMaxVel(20);  // Value between 2 and 100,000 steps/sec
  X.setMaxAccel(50000);  // Value between 4000 and 2,000,000 steps/sec^2

  X.enable();

  delay(100);

  machine.Start();
}

void loop() {

  X.move(8000);

  while (X.readHLFB()) {
    
  }

  delay(20);

  X.move(-8000);

  while (X.readHLFB()) {
    
  }

  delay(20);
}
