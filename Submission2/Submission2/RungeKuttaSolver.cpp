//
//  RungeKuttaSolver.cpp
//  Submission2
//
//  Created by ChristianEnevoldsen on 28/05/15.
//  Copyright (c) 2015 ChristianEnevoldsen. All rights reserved.
//

#include "RungeKuttaSolver.hpp"

RungeKuttaSolver::RungeKuttaSolver(double (*f)(double y, double t))
: right(f) {}

double RungeKuttaSolver::RightHandSide(double y, double t) {
  return right(y, t);
}

double RungeKuttaSolver::SolveEquation() {
  double h = GetStepSize();
  const int iterations = GetFinalTime() / h;
  double t = GetInitialTime();
  double y = getInitialValue();

  for (int i = 1; i <= iterations; ++i) {
    double k1 = h * RightHandSide(t, y);
    double k2 = h * RightHandSide(t + (h/2.0), y + 0.5 * k1);
    double k3 = h * RightHandSide(t + (h/2.0), y + 0.5 * k2);
    double k4 = h * RightHandSide(t + h, y + k3);
    y = y + (1.0/6.0) * (k1 + 2*k2 + 2*k3 + k4);
    t += h;
  }

  return y;
}
