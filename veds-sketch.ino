#include <Servo.h> 

Servo myservo; 

void setup() {
  myservo.attach(9);
  Serial.begin(9600); 
  myservo.write(); // enter value 

}

void loop() {
}

void serialEvent() {
  while (Serial.available()) {
    char command = Serial.read();
    Serial.flush(); 
    if (command == '0') {
      myservo.write(); //enter value
    }
    if (command == '1') {
      myservo.write(); //enter value
    }
    if (command == '2') {
      myservo.write(); //enter value
    }
  }
}

