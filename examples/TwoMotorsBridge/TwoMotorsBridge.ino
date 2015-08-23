#include "MotorDriver.h"

#define DRV8833_AIN1_PIN 6
#define DRV8833_AIN2_PIN 5

#define DRV8833_BIN1_PIN 10
#define DRV8833_BIN2_PIN 9

#define SERIAL_BAUD_RATE 115200

MotorDriver *motorA;
MotorDriver *motorB;

void setup()
{
  Serial.begin(SERIAL_BAUD_RATE);

  motorA = new MotorDriver(DRV8833_AIN1_PIN, DRV8833_AIN2_PIN);
  motorB = new MotorDriver(DRV8833_BIN1_PIN, DRV8833_BIN2_PIN);
}

void loop()
{
  Serial.println("Waiting 2s...");
  delay(2000);

  Serial.println("Going forward, max speed.");
  motorA->Forward(1.0f);
  motorB->Forward(1.0f);
  delay(2000);

  Serial.println("Reducing speed 80%.");
  motorA->SetSpeed(0.8f);
  motorB->SetSpeed(0.8f);
  delay(2000);

  Serial.println("Reducing speed 50%.");
  motorA->SetSpeed(0.5f);
  motorB->SetSpeed(0.5f);
  delay(2000);

  Serial.println("Go clockwise!");
  motorA->Forward(1.0f);
  motorB->Backward(1.0f);
  delay(2000);

  Serial.println("Go counterclockwise!");
  motorA->Backward(1.0f);
  motorB->Forward(1.0f);
  delay(2000);

  Serial.println("Stop!");
  motorA->Halt();
  motorB->Halt();
  delay(2000);
}
