int redLED = 13;
int greenLED = 2;

void setup() {
  Serial.begin(9600); 
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
}

void serialEvent() {
  while (Serial.available()) {
    char command = Serial.read();
    Serial.flush(); // Clear the serial buffer
    if (command == '0') {
      digitalWrite(redLED, HIGH);
      digitalWrite(greenLED, LOW);
    }
    if (command == '1') {
      digitalWrite(redLED, LOW);
      digitalWrite(greenLED, HIGH);
    }
    if (command == '2') {
      digitalWrite(redLED, LOW);
      digitalWrite(greenLED, LOW); 
    }
  }
}

