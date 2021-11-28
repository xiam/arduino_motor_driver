// Copyright (c) 2014-2015 José Carlos Nieto, https://menteslibres.net/xiam
//
// Permission is hereby granted, free of charge, to any person obtaining
// a copy of this software and associated documentation files (the
// "Software"), to deal in the Software without restriction, including
// without limitation the rights to use, copy, modify, merge, publish,
// distribute, sublicense, and/or sell copies of the Software, and to
// permit persons to whom the Software is furnished to do so, subject to
// the following conditions:
//
// The above copyright notice and this permission notice shall be
// included in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
// LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
// OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
// WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef MOTOR_DRIVER
#define MOTOR_DRIVER

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#define MOTOR_DRIVER_OFF        0 // 0x00
#define MOTOR_DRIVER_FORWARD    1 // 0x01
#define MOTOR_DRIVER_BACKWARD   2 // 0x10

#include <stdint.h>

class MotorDriver {
private:
  uint8_t pinA;
  uint8_t pinB;
  uint8_t status;
  void setModulatedStatus(int status, float speed);
public:
  MotorDriver(uint8_t pinA, uint8_t pinB);
  void Halt();
  void SetSpeed(float speed);
  void Forward(float speed);
  void Backward(float speed);
  float Speed();
};

#endif
