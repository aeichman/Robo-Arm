#include <AccelStepper.h>

#define X_STEP_PIN 54
#define X_DIR_PIN 55
#define X_ENABLE_PIN 38

#define POTENTIOMETER_PIN A5

#define STEPS_PER_REV 200

AccelStepper stepper(AccelStepper::DRIVER, X_STEP_PIN, X_DIR_PIN);

void mySetup()
{
  stepper.setMaxSpeed(1000);
  stepper.setAcceleration(100);

  pinMode(X_ENABLE_PIN, OUTPUT);
  digitalWrite(X_ENABLE_PIN, LOW);

  stepper.setCurrentPosition(0);
}

void setup()
{
  mySetup();
}

void loop()
{
  int potValue = analogRead(POTENTIOMETER_PIN);

  int targetPosition = map(potValue, 0, 1023, 0, STEPS_PER_REV);

  stepper.moveTo(targetPosition);

  if (stepper.distanceToGo() != 0)
  {
    stepper.run();
  }
}
