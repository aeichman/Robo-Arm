// Note: This is for Arduino Programming, a simplified version of C++

byte directionPin = 5;
byte stepPin = 2;
byte enablePin = 8; // must enable steppers.

int numberOfSteps = 200;     // 200 for Nema17
int pulseWidthMicros = 50;   // microseconds
int millisbetweenSteps = 30; // time between steps in milliseconds

void setup()
{

    Serial.begin(115200);
    Serial.println("Starting StepperTest");

    delay(2000);

    pinMode(directionPin, OUTPUT);
    pinMode(stepPin, OUTPUT);
    pinMode(enablePin, OUTPUT);
    digitalWrite(enablePin, LOW);

    digitalWrite(directionPin, HIGH);
    for (int n = 0; n < numberOfSteps; n++)
    {
        digitalWrite(stepPin, HIGH);
        // delayMicroseconds(pulseWidthMicros); // this line is probably unnecessary
        digitalWrite(stepPin, LOW);

        delay(millisbetweenSteps);
    }

    delay(2000);

    digitalWrite(directionPin, LOW);
    for (int n = 0; n < numberOfSteps; n++)
    {
        digitalWrite(stepPin, HIGH);
        digitalWrite(stepPin, LOW);

        delay(millisbetweenSteps);
    }
}

void loop()
{
}
