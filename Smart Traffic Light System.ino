// ---------------- Smart Traffic Light System ----------------
// Components: Arduino Uno, HC-SR04, LEDs, Button, Buzzer
// Author: Nandhika Sri (GitHub Project)
// ------------------------------------------------------------------

#define trigPin 9
#define echoPin 10

// Traffic light pins
int red = 2;
int yellow = 3;
int green = 4;

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // Measure traffic density
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Traffic Distance: ");
  Serial.println(distance);

  // Normal traffic cycle
  digitalWrite(red, HIGH);
  delay(5000);
  digitalWrite(red, LOW);

  digitalWrite(yellow, HIGH);
  delay(2000);
  digitalWrite(yellow, LOW);

  // Green timing depends on traffic
  digitalWrite(green, HIGH);
  if (distance < 20) { // If cars detected close
    delay(7000);  // Longer green
  } else {
    delay(4000);  // Shorter green
  }
  digitalWrite(green, LOW);
}
