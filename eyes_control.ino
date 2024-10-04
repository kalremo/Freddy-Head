#include <Servo.h>

Servo lrservo;
Servo udservo;

const int ehome = 90; // Home position for servo (midpoint)
const int lhome = 90; // Home position for servo (midpoint)

void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP); // Button for left/right servo
  pinMode(3, INPUT_PULLUP); // Button for up/down servo
  pinMode(4, INPUT_PULLUP); // Button for additional control (if needed)
  
  lrservo.attach(8);
  udservo.attach(9);

  lrservo.write(ehome);
  udservo.write(lhome);
}

void loop() {
  // Check button states and set angles accordingly
  int lrAngle = ehome; // Default to home position
  int udAngle = lhome; // Default to home position

  // Left/Right control
  if (!digitalRead(2)) { // Button 2 pressed
    lrAngle = 180; // Move to right position
  }

  // Up/Down control
  if (!digitalRead(4)) { // Button 3 pressed
    udAngle = 0; // Move to up position
  }

  // Additional control (if needed)
  if (!digitalRead(3)) { // Button 4 pressed
    lrAngle = 0; // Move to left position
  }

  // Write angles to servos
  lrservo.write(lrAngle);
  udservo.write(udAngle);

  delay(100); // Simple debounce
}
