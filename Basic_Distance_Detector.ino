/* Keanu Arendze
   Project: Basic Distance Detector
   Date Created: 08 July 2016
*/
const int trigPin = 7;// Sonar Trigger
const int echoPin = 6;// Sonar Echo
const int Green = 8; // Green Led
const int Orange = 9;// Orange Led
const int Red = 10;// Red Led
const int Buzz = 11;

void setup() {

  pinMode(Green, OUTPUT);
  pinMode(Orange, OUTPUT);
  pinMode(Red, OUTPUT);
  pinMode(Buzz, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

}

void loop() {
  
  int distance = getDistance();
  digitalWrite(Red, false);
  digitalWrite(Orange, false);
  
  tone(Buzz, 0);

  if (distance > 60) {

    digitalWrite(Red, false);
    digitalWrite(Orange, false);
    digitalWrite(Green, true);

  }
  else if (distance < 50) {

    digitalWrite(Orange, true);
    digitalWrite(Red, false);
    digitalWrite(Green, false);
    tone(Buzz, 500, 1000);

    if (distance < 30) {

      digitalWrite(Orange, false);
      digitalWrite(Red, true);
      tone(Buzz, 1500, 1000);

    }

  }
}

int getDistance() {

  long duration, distance;

  digitalWrite(trigPin, LOW);

  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);

  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = (duration / 2) / 29.1;

  Serial.println(distance);

  return distance;


}
