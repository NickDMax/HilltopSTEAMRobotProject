#include "dcmotor.h"

const int in1 = 3;
const int in2 = 4;
const int in3 = 7;
const int in4 = 8;

const int pwmIn1 = 5;
const int pwmIn2 = 9;

DCMotor motorRight(in1, in2, pwmIn1, 70, 250);
DCMotor motorLeft(in4, in3, pwmIn2, 70, 250);


const int D2 = 2;
const bool FWD = false;
const bool BCK = true;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(D2, INPUT);
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  
}

void holdOnObsticle() {
    int valueD2 = digitalRead(D2);
    while(valueD2 == false) { 
      valueD2 = digitalRead(D2);
      motorRight.stop();
      motorLeft.stop();
    }
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  float motorPwr = 0.1 +                                                                                            sensorValue/1024.0;
  delay(10+sensorValue);                       // wait for a second
  motorRight.setDir(FWD);
  motorRight.drive(motorPwr);
  motorLeft.setDir(FWD);
  motorLeft.drive(motorPwr);
  Serial.println(motorPwr);
  holdOnObsticle();
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(10+sensorValue);                       // wait for a second
  holdOnObsticle();
}
