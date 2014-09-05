#include <Servo.h> 
String readString;
Servo myservo1;  // create servo object to control a servo 

void setup() {
  Serial.begin(9600);
  myservo1.attach(9);  //the pin for the servo control 
  Serial.println("type a number 0-9999 to send servo on pin 9");
}

void loop() {

  while (Serial.available()) {
    delay(3);  //delay to allow buffer to fill 
    if (Serial.available() >0) {
      char c = Serial.read();  //gets one byte from serial buffer
      if (c == char(13) || c == char(10)) {
        int val = readString.toInt();
        Serial.println(val); //see what was received
        myservo1.write(val); // could also use myservo1.writeMicroseconds()
        readString = "";
      }
      else readString += c; //makes the string readString
    } 
  }
}
