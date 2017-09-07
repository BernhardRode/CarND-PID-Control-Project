#include "PID.h"

#include <cmath>

using namespace std;

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd)
{
  this->Kp = Kp;
  this->Ki = Ki;
  this->Kd = Kd;

  this->p_error = 0;
  this->i_error = 0;
  this->d_error = 0;

  p = {0.15 * Kp, 0.15 * Ki, 0.15 * Kd};
  dp = {0.15 * Kp, 0.15 * Ki, 0.15 * Kd};
  bestErr = numeric_limits<double>::max();
}

void PID::UpdateError(double cte)
{
  d_error = cte - p_error;
  i_error += cte;
  p_error = cte;

  i_error = fmin(fmax(-100, i_error), 100);
}

double PID::TotalError()
{
  return fmin(
      fmax(
          -1.0,
          -(this->Kp * this->p_error + this->Ki * this->i_error + this->Kd * this->d_error)),
      1.0);
}
