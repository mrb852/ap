//
//  Student.cpp
//  Submission2
//
//  Created by ChristianEnevoldsen on 12/05/15.
//  Copyright (c) 2015 ChristianEnevoldsen. All rights reserved.
//

#include "Student.hpp"

Student::Student() {}
Student::Student(std::string name, double fines, double fees)
: name(name), library_fines(fines), tuition_fees(fees) {}

void Student::SetLibraryFines(double amount) {
  if (amount >= 0.0) {
    library_fines = amount;
  }
  library_fines = amount >= 0.0 ? amount : library_fines;
}

double Student::GetLibraryFines() const {
  return library_fines;
}

double Student::MoneyOwed() const {
  return GetLibraryFines() + tuition_fees;
}