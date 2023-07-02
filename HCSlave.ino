#include <SoftwareSerial.h>
#include <Servo.h>

SoftwareSerial mySerial (3,2);

Servo myservo;
int state;

void setup() {
  Serial.begin(9600);
  mySerial.begin(38400);
  myservo.attach(5);
  myservo.write(0);
}

void loop() {
  if (mySerial.available ()){
    state = mySerial.read();
    Serial.write(state);
    }  
    if (state == '1'){
      myservo.write(90);
    }
    else if (state == '0'){
      myservo.write(0);
    }
  }
