#include <Servo.h>

Servo myServo;

// Motor driver pins (L298N)
int ENA = 6;
int IN1 = 7;
int IN2 = 2;

int ENB = 3;
int IN3 = 5;
int IN4 = 4;

// Ultrasonic pins
int trigPin = 8;
int echoPin = 9;

long duration, distance;

void setup() {
  Serial.begin(9600);

  // Motor pins
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  // Ultrasonic pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Servo setup
  myServo.attach(11);
  myServo.write(90); // center position

  // Set initial motor speed
  analogWrite(ENA, 200);  // Right motor speed
  analogWrite(ENB, 200);  // Left motor speed
}

void loop() {
  distance = getDistance();
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance > 30) {
    moveForward();  // Path clear
  } else if (distance > 0) {
    stopMotors();
    delay(100);

    // Scan surroundings
    int leftDist = lookLeft();
    int rightDist = lookRight();

    // Small reverse to avoid obstacle
    moveBackward();
    delay(400);
    stopMotors();

    // Decide turn
    if (leftDist > rightDist) {
      turnLeft();
      delay(500);
    } else {
      turnRight();
      delay(500);
    }
    stopMotors();
  }

  delay(50);
}

// === Distance function ===
long getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH, 20000); // 20ms timeout
  if (duration == 0) return 999;  // no echo case
  return duration / 58.2;  // cm
}

// === Movement functions ===
void moveForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void moveBackward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void turnLeft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);  // Right motor backward
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);   // Left motor forward
}

void turnRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);   // Right motor forward
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);  // Left motor backward
}

void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

// === Servo scanning ===
int lookLeft() {
  myServo.write(150);
  delay(400);
  int dist = getDistance();
  myServo.write(90);
  delay(200);
  return dist;
}

int lookRight() {
  myServo.write(30);
  delay(400);
  int dist = getDistance();
  myServo.write(90);
  delay(200);
  return dist;
}






