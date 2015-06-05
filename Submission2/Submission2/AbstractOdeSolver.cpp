//
//  AbstractOdeSolver.cpp
//  Submission2
//
//  Created by ChristianEnevoldsen on 12/05/15.
//  Copyright (c) 2015 ChristianEnevoldsen. All rights reserved.
//

#include <stdio.h>
#include "AbstractOdeSolver.hpp"

void AbstractOdeSolver::SetStepSize(double h) {
  stepSize = h;
}

void AbstractOdeSolver::SetTimeInterval(double t0, double t1) {
  initialTime = t0; finalTime = t1;
}

void AbstractOdeSolver::SetInitialValue(double y0) {
  initialValue = y0;
}