#ifndef PID_H
#define PID_H

class PID {
 public:
  /**
   * Constructor
   */
  PID();

  /**
   * Destructor.
   */
  virtual ~PID();

  /**
   * Initialize PID.
   * @param (Kp_, Ki_, Kd_) The initial PID coefficients
   */
  void Init(double, double, double);

  /**
   * Update the PID error variables given cross track error.
   * @param cte The current cross track error
   */
  void UpdateError(double);

  /**
   * Calculate the total PID error.
   * @output The total PID error
   */
  double TotalError();

  double SetRef(double);

  // double GetP(void);
  // double GetI(void);
  // double GetD(void);

  // double GetPerr(void);
  // double GetIerr(void);
  // double GetDerr(void);


  void SetP(double);
  void SetI(double);
  void SetD(double);

  void SetMin(double);
  void SetMax(double);

 private:
  /**
   * PID Errors
   */
  double p_error_{0.0};
  double i_error_{0.0};
  double d_error_{0.0};

  /**
   * PID Coefficients
   */ 
  double Kp_{0.0};
  double Ki_{0.0};
  double Kd_{0.0};

  double ref_{0.0};
  double err_{0.0};
  double errPre_{0.0};
  double errSum_{0.0};


  double max_{1.0};
  double min_{-1.0};

};

#endif  // PID_H