//
//  GradurateStudent.cpp
//  Submission2
//
//  Created by ChristianEnevoldsen on 12/05/15.
//  Copyright (c) 2015 ChristianEnevoldsen. All rights reserved.
//

#include <stdio.h>
#include "GraduateStudent.hpp"

GraduateStudent::GraduateStudent() {}

GraduateStudent::GraduateStudent(std::string name, double fines, double fees, bool fullTime)
: Student(name, fines, fees), fullTime(fullTime) {}

double GraduateStudent::MoneyOwed() const {
  return GetLibraryFines();
}
