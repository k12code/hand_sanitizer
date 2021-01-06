const int trigPin = D6;
const int echoPin = D7;
const int pumpPin = D2;

long duration, cm;

void setup() {
  Serial.begin (115200);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);

  // Convert the time into a distance
  cm = (duration / 2) / 29.1;   // divide by 29.1 or multiply by 0.0343

  Serial.print(cm);
  Serial.print(" cm");
  Serial.println();

  if (cm < 10) {
    analogWrite(pumpPin, 1023);
    delay(500);
    analogWrite(pumpPin, 0);
    delay(3000);
  }

  delay(250);
}
