const int button = 2;
const int led = 13;
int counter;
int buttonState = 0;

void setup() {
  Serial.begin(9600);
  pinMode(button, INPUT);
  Serial.print("INIT: Pin used for INPUT: ");
  Serial.println(button);
  pinMode(led, OUTPUT);
  Serial.print("INIT: Pin used for OUTPUT: ");
  Serial.println(led);
  Serial.println("INIT: Setup complete.");
}

void loop()
{
  if (digitalRead(button) == HIGH) {
      Serial.println("Button state is HIGH");
    for (counter = 0; counter < 3; ++counter) {
      digitalWrite(led, HIGH);
      delay(250);
      Serial.print("LED blink index: ");
      Serial.println(counter);
      digitalWrite(led, LOW);
      delay(250);
    }
    if (digitalRead(button) == LOW) {
      Serial.println("Button state is LOW");
    }
  }
}
