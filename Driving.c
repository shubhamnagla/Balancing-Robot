#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <softPwm.h>

#define RANGE	100
#define INITIAL_VALUE 0

void init_motors()
{
  wiringPiSetup();
  softPwmCreate(0, INITIAL_VALUE, RANGE);
  softPwmCreate(2, INITIAL_VALUE, RANGE);
  pinMode(3, OUTPUT);
  digitalWrite(3, HIGH);
  softPwmCreate(5, INITIAL_VALUE, RANGE);
  softPwmCreate(4, INITIAL_VALUE, RANGE);
  pinMode(6, OUTPUT);
  digitalWrite(6, HIGH);
}

void stop_motors()
{
  pinMode(0, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  digitalWrite(0, LOW);
  digitalWrite(2, LOW);

  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(6, OUTPUT);
  digitalWrite(5, LOW);
  digitalWrite(4, LOW);
}

double left_speed;
double right_speed;

void motors(double speed, double left_offset, double right_offset)
{
  left_speed = speed + left_offset;
  right_speed = speed + right_offset;

  // left motor
  if (left_speed < 0)  {
    softPwmWrite(0, (int) -left_speed);
    softPwmWrite(2, 0);
  }
  else
  if (left_speed > 0)  {
    softPwmWrite(2, (int) left_speed);
    softPwmWrite(0, 0);
  }

  // right motor
  if (right_speed < 0)  {
    softPwmWrite(5, (int) -right_speed);
    softPwmWrite(4, 0);
  }
  else
  if (right_speed > 0)  {
    softPwmWrite(4, (int) right_speed);
    softPwmWrite(5, 0);
  }
}
