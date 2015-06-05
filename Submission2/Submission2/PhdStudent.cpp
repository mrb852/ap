//
//  PhdStudent.cpp
//  Submission2
//
//  Created by ChristianEnevoldsen on 12/05/15.
//  Copyright (c) 2015 ChristianEnevoldsen. All rights reserved.
//

#include <stdio.h>
#include "PhdStudent.hpp"

PhdStudent::PhdStudent(std::string name, double fines, double fees, bool fullTime)
: GraduateStudent(name, 0.0, 0.0, fullTime) {}

double PhdStudent::MoneyOwed() const {
  return 0.0;
}