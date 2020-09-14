#include "PID.h"
#include "math.h"
#include <cmath> 

using namespace std;
/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */

  this->SetP(Kp);
  this->SetI(Ki);
  this->SetD(Kd);
}

void PID::UpdateError(double input) {
  /**
   * TODO: Update PID errors based on cte.
   */

  errPre_ = err_;
	err_ = input - ref_;
	errSum_ = errSum_ + err_;

	p_error_ = Kp_* err_;
	i_error_ = Ki_ * errSum_;
	d_error_ = Kd_* (err_ - errPre_);
}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */

  double total_err = - p_error_ - d_error_ - i_error_;
  total_err = fmax( fmin(total_err, max_), min_);
  return total_err;
}

double PID::SetRef(double ref){

  ref_ = ref;
}

void PID::SetMax(double max){

  this->max_ = max;
}

void PID::SetMin(double min){

  this->min_ = min;
}

void PID::SetP(double Kp){

  this->Kp_ = Kp;
}

void PID::SetI(double Ki){

  this->Ki_ = Ki;
}

void PID::SetD(double Kd){

  this->Kd_ = Kd;
}