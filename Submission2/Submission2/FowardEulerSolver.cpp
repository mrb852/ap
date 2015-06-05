//
//  ForwardEulerSolver.cpp
//  Submission2
//
//  Created by ChristianEnevoldsen on 12/05/15.
//  Copyright (c) 2015 ChristianEnevoldsen. All rights reserved.
//

#include <stdio.h>
#include "FowardEulerSolver.hpp"
#include <vector>

struct Step {
  double time;
  double vel;
};

FowardEulerSolver::FowardEulerSolver(double (*f)(double y, double t))
: right(f) {}

double FowardEulerSolver::RightHandSide(double y, double t) {
  return right(y, t);
}

double FowardEulerSolver::SolveEquation() {

  double h = GetStepSize();
  const int iterations = GetFinalTime() / h + 1;
  std::vector<Step> steps;
  steps.push_back({.time = GetInitialTime(), .vel = getInitialValue()});
  steps.resize(iterations);

  for (int i = 1; i <= iterations; i++) {
    double k = h * RightHandSide(steps[i-1].vel, steps[i-1].time);
    steps[i].time = steps[i-1].time + h;
    steps[i].vel = k + steps[i-1].vel;
  }

  return steps[iterations].vel;

}