#include <AccelStepper.h>

#define X_STEP_PIN 54
#define X_DIR_PIN 55
#define X_ENABLE_PIN 38

#define Y_STEP_PIN 60
#define Y_DIR_PIN 61
#define Y_ENABLE_PIN 56
#define Y_LIMIT_PIN 14

#define Z_STEP_PIN 46
#define Z_DIR_PIN 48
#define Z_ENABLE_PIN 62

#define E1_STEP_PIN 26
#define E1_DIR_PIN 28
#define E1_ENABLE_PIN 24

#define E2_STEP_PIN 36
#define E2_DIR_PIN 34
#define E2_ENABLE_PIN 30

// Define the potentiometer pins
#define X_POT_PIN A5
#define Y_POT_PIN A10
#define Z_POT_PIN A11
#define E1_POT_PIN A12
#define E2_POT_PIN A4

#define STEPS_PER_REV_X 6400
#define STEPS_PER_REV_Y 15000
#define STEPS_PER_REV_Z 6400
#define STEPS_PER_REV_E1 6400
#define STEPS_PER_REV_E2 3200

AccelStepper stepperX(AccelStepper::DRIVER, X_STEP_PIN, X_DIR_PIN);
AccelStepper stepperY(AccelStepper::DRIVER, Y_STEP_PIN, Y_DIR_PIN);
AccelStepper stepperZ(AccelStepper::DRIVER, Z_STEP_PIN, Z_DIR_PIN);
AccelStepper stepperE1(AccelStepper::DRIVER, E1_STEP_PIN, E1_DIR_PIN);
AccelStepper stepperE2(AccelStepper::DRIVER, E2_STEP_PIN, E2_DIR_PIN);

void mySetup()
{

    stepperX.setMaxSpeed(3000);     // Maximum speed in steps per second
    stepperX.setAcceleration(2000); // Acceleration in steps per second^2
    stepperY.setMaxSpeed(25000);
    stepperY.setAcceleration(4000);
    stepperZ.setMaxSpeed(3000);
    stepperZ.setAcceleration(1000);
    stepperE1.setMaxSpeed(3000);
    stepperE1.setAcceleration(1000);
    stepperE2.setMaxSpeed(3000);
    stepperE2.setAcceleration(1000);

    pinMode(X_ENABLE_PIN, OUTPUT);
    digitalWrite(X_ENABLE_PIN, LOW);
    pinMode(Y_ENABLE_PIN, OUTPUT);
    digitalWrite(Y_ENABLE_PIN, LOW);
    pinMode(Z_ENABLE_PIN, OUTPUT);
    digitalWrite(Z_ENABLE_PIN, LOW);
    pinMode(E1_ENABLE_PIN, OUTPUT);
    digitalWrite(E1_ENABLE_PIN, LOW);
    pinMode(E2_ENABLE_PIN, OUTPUT);
    digitalWrite(E2_ENABLE_PIN, LOW);

    // Set the initial positions of the stepper motors to 0 Change possible for homing
    stepperX.setCurrentPosition(0);
    stepperY.setCurrentPosition(0);
    stepperZ.setCurrentPosition(0);
    stepperE1.setCurrentPosition(0);
    stepperE2.setCurrentPosition(0);
}

void setup()
{
    mySetup();
}

void loop()
{
    int xPotValue = analogRead(X_POT_PIN);
    int yPotValue = analogRead(Y_POT_PIN);
    int zPotValue = analogRead(Z_POT_PIN);
    int e1PotValue = analogRead(E1_POT_PIN);
    int e2PotValue = analogRead(E2_POT_PIN);

    int xTargetPosition = map(xPotValue, 0, 1023, 0, STEPS_PER_REV_X);
    int yTargetPosition = map(yPotValue, 0, 1023, 0, STEPS_PER_REV_Y);
    int zTargetPosition = map(zPotValue, 0, 1023, 0, STEPS_PER_REV_Z);
    int e1TargetPosition = map(e1PotValue, 0, 1023, 0, STEPS_PER_REV_E1);
    int e2TargetPosition = map(e2PotValue, 0, 1023, 0, STEPS_PER_REV_E2);

    stepperX.moveTo(xTargetPosition);
    stepperY.moveTo(yTargetPosition);
    stepperZ.moveTo(zTargetPosition);
    stepperE1.moveTo(e1TargetPosition);
    stepperE2.moveTo(e2TargetPosition);

    if (stepperX.distanceToGo() != 0)
    {
        stepperX.run();
    }

    if (stepperY.distanceToGo() != 0)
    {
        if (digitalRead(Y_LIMIT_PIN) == HIGH)
        {
            stepperY.move(-40);
            stepperY.runToPosition();
        }
        else
        {
            stepperY.run();
        }
    }

    if (stepperZ.distanceToGo() != 0)
    {
        stepperZ.run();
    }

    if (stepperE1.distanceToGo() != 0)
    {
        stepperE1.run();
    }

    if (stepperE2.distanceToGo() != 0)
    {
        stepperE2.run();
    }
}