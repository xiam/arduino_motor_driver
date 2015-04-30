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

#include "MotorDriver.h"

MotorDriver::MotorDriver(uint8_t pinA, uint8_t pinB)
{
  this->pinA = pinA;
  this->pinB = pinB;

  pinMode(this->pinA, OUTPUT);
  pinMode(this->pinB, OUTPUT);
}

void MotorDriver::Forward(float speed)
{
  this->setModulatedStatus(MAKERWORKSHOP_MOTOR_DRIVER_FORWARD, speed);
}

void MotorDriver::Backward(float speed)
{
  this->setModulatedStatus(MAKERWORKSHOP_MOTOR_DRIVER_BACKWARD, speed);
}

void MotorDriver::Halt()
{
  this->setModulatedStatus(MAKERWORKSHOP_MOTOR_DRIVER_OFF, 0);
}

void MotorDriver::SetSpeed(float speed)
{
  this->setModulatedStatus(this->status, speed);
}

void MotorDriver::setModulatedStatus(int status, float speed)
{
  int amount = speed*255;

  this->status = status;

  if (this->status & MAKERWORKSHOP_MOTOR_DRIVER_FORWARD) {
    analogWrite(this->pinB, LOW);
    analogWrite(this->pinA, amount);
  } else if (this->status & MAKERWORKSHOP_MOTOR_DRIVER_BACKWARD) {
    analogWrite(this->pinA, LOW);
    analogWrite(this->pinB, amount);
  } else {
    analogWrite(this->pinA, LOW);
    analogWrite(this->pinB, LOW);
  }
}
