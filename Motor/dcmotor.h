#ifndef dcmotor_h
#define dcmotor_h

#include <Arduino.h>

class DCMotor {
  public:
    DCMotor(int inPin1, int inPin2, int pwmPin, int pwmMin, int pwmMax);
    void stop();
    void setDir(bool isfwd);
    void drive();
    void drive(float pwr);
    void setPwr(float pwr);
  private:
    int _inPin1;
    int _inPin2;
    int _pwmPin;
    int _pwmMin;
    int _pwmMax;
    int _pwmPwr;
    int _pwmRange;
    bool _isFwd;
};



#endif
