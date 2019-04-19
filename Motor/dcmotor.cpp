#include "dcmotor.h"

DCMotor::DCMotor(int inPin1, int inPin2, int pwmPin, int pwmMin, int pwmMax) {
  _inPin1 = inPin1;
  _inPin2 = inPin2;
  _pwmPin = pwmPin;
  _pwmMin = pwmMin;
  _pwmMax = pwmMax;
  _pwmRange = _pwmMax - pwmMin;
  _pwmPwr = pwmMin;
  _isFwd = true;
  pinMode(_inPin1, OUTPUT);
  pinMode(_inPin2, OUTPUT);
  pinMode(_pwmPin, OUTPUT);
  digitalWrite(_inPin1, LOW);
  digitalWrite(_inPin2, LOW);
  analogWrite(_pwmPin, _pwmPwr);
}

void DCMotor::stop() {
  digitalWrite(_inPin1, LOW);
  digitalWrite(_inPin2, LOW);
}

void DCMotor::setDir(bool isfwd) {
  _isFwd = isfwd;
}

void DCMotor::drive() {
  if (_pwmPwr < _pwmMin) {
    _pwmPwr = _pwmMin;
    analogWrite(_pwmPin, _pwmPwr);
  }
  if (_isFwd) {
    digitalWrite(_inPin1, HIGH);
    digitalWrite(_inPin2, LOW);    
  } else {
    digitalWrite(_inPin1, LOW);
    digitalWrite(_inPin2, HIGH);    
  }
}

void DCMotor::drive(float pwr) {
  this->setPwr(pwr);
  this->drive();
}

void DCMotor::setPwr(float pwr) {
  if(pwr < 0) { pwr = 0; }
  if(pwr > 1) { pwr = 1; }
  int calcPwr = _pwmMin + int(_pwmRange * pwr);
  _pwmPwr = calcPwr;
  analogWrite(_pwmPin, _pwmPwr);
}
