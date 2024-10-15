#include <Servo.h>

Servo lrservo;
Servo udservo;

const int ehome = 90; // Home position for servo (midpoint)
const int lhome = 90; // Home position for servo (midpoint)

void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP); // Button for up/down servo
  pinMode(3, INPUT_PULLUP); // Button for left/right servo
  pinMode(4, INPUT_PULLUP); // Button for left/right servo
  
  lrservo.attach(8);
  udservo.attach(9);

  lrservo.write(ehome);
  udservo.write(lhome);
}

void loop() {
  // Check button states and set angles accordingly
  int lrAngle = ehome; // Default to home position
  int udAngle = lhome; // Default to home position
  
  // Up/Down control
  if (!digitalRead(2)) { // Button 2 pressed
    udAngle = 40; // Move to up position
    Serial.println("lids down");

  }
  
  // Left/Right control
  if (!digitalRead(3)) { // Button 3 pressed
    lrAngle = 130; // Move to right position
    Serial.println("looking left");
  }

  // Additional control (if needed)
  if (!digitalRead(4)) { // Button 4 pressed
    lrAngle = 50; // Move to left position
    Serial.println("looking right");
  }

  // Write angles to servos
  lrservo.write(lrAngle);
  udservo.write(udAngle);

  delay(100); // Simple debounce
}
