#include "PID.h"

#include <cmath>

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd)
{
  this->Kp = Kp;
  this->Ki = Ki;
  this->Kd = Kd;

  // cout << "Initialization..." << endl;
  // cout << "Ki" << Ki << endl;
  // cout << "Kd" << Kd << endl;
  // cout << "Kp" << Kp << endl;

  p_error = 0;
  i_error = 0;
  d_error = 0;

  // dp = {0.15 * Kp, 0.15 * Ki, 0.15 * Kd};
  // bestErr = std::numeric_limits<double>::max();
}

void PID::UpdateError(double cte)
{
  d_error = cte - p_error;
  i_error += cte;
  p_error = cte;
}

double PID::TotalError()
{
  // std::cout << "Kp: " << Kp << " Ki: " << Ki << " Kd: " << Kd << std::endl;
  return -Kp * p_error - Kd * d_error - Ki * i_error;
}
