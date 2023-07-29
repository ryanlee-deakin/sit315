const int sensor = 2;
const long sensorLimit = 19000;
const int led = 13;
int counter;
int buttonState = 0;

// function readUltrasonicDistance is example code
// from public domain (http://www.arduino.cc/en/Tutorial/Ping)
long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  Serial.print("INIT: Pin used for OUTPUT: ");
  Serial.println(led);
  Serial.println("INIT: Setup complete.");
}

void loop()
{
  // sense echo travel time in microseconds
  long echoReading = readUltrasonicDistance(sensor,sensor);
  // trigger LED if sensor detects echo returning under sensorLimit value
  if (echoReading < sensorLimit) {
    Serial.print("Echo reading is: ");
    Serial.println(echoReading);
    for (counter = 0; counter < 3; ++counter) {
      digitalWrite(led, HIGH);
      delay(250);
      Serial.print("LED blink index: ");
      Serial.println(counter);
      digitalWrite(led, LOW);
      delay(250);
    }
  }
}
