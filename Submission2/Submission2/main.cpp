//
//  main.cpp
//  Submission2
//
//  Created by ChristianEnevoldsen on 12/05/15.
//  Copyright (c) 2015 ChristianEnevoldsen. All rights reserved.
//

#include <iostream>
#include "OutOfRangeException.hpp"
#include "FileNotOpenException.hpp"
#include "FowardEulerSolver.hpp"
#include "ComplexNumber.hpp"
#include "RungeKuttaSolver.hpp"

using namespace std;

double f(double y, double t) {
  return t + y;
}


int main(int argc, const char * argv[]) {
  RungeKuttaSolver solver = RungeKuttaSolver(f);
  solver.SetInitialValue(0.0);
  solver.SetStepSize(0.1);
  solver.SetTimeInterval(0, 1);
  double d = solver.SolveEquation();
  cout << d << endl;
}
