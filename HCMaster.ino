#include <SoftwareSerial.h>

SoftwareSerial mySerial (3,2);

int buzz = 9;
int button = 4;
int baca;
int state;

void setup() {
  Serial.begin(9600);
  mySerial.begin(38400);
  pinMode(button, INPUT);
  pinMode(buzz, OUTPUT);
}

void loop() {
    if (mySerial.available ()){
      state = mySerial.read();
      Serial.write(state);
  }
    baca = digitalRead(button);
  if(baca == HIGH){
    mySerial.print("1");
    delay(1000);
    mySerial.print("0");
    }
}
