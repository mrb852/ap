//
//  Matrix2x2.cpp
//  Submission2
//
//  Created by ChristianEnevoldsen on 12/05/15.
//  Copyright (c) 2015 ChristianEnevoldsen. All rights reserved.
//

#include <iostream>
#include "Matrix2x2.hpp"

Matrix2x2::Matrix2x2() : val00(0), val01(0), val10(0), val11(0) {}

Matrix2x2::Matrix2x2(const Matrix2x2& other)
: val00(other.val00), val01(other.val01), val10(other.val10), val11(other.val11) {}

Matrix2x2::Matrix2x2(double a, double b, double c, double d) :
val00(a), val01(b), val10(c), val11(d) {}

double Matrix2x2::CalcDeterminant() const {
  return val00 * val11 - val10 * val01;
}

Matrix2x2 Matrix2x2::CalcInverse() const {
  double det = CalcDeterminant();
  Matrix2x2 res(Getval11(), -Getval01(), -Getval10(), Getval00());
  res.MultScalar(1.0/det);
  return res;
}

Matrix2x2& Matrix2x2::operator=(const Matrix2x2& z) {
  val00 = z.val00; val01 = z.val01; val10 = z.val10; val11 = z.val11;
  return *this;
}

Matrix2x2 Matrix2x2::operator-() const {
  return Matrix2x2(-val00, -val01, -val10, -val11);
}

Matrix2x2 Matrix2x2::operator+(const Matrix2x2& z) const {
  return Matrix2x2(val00 + z.val00, val01 + z.val01, val10 + z.val10, val11 + z.val11);
}

Matrix2x2 Matrix2x2::operator-(const Matrix2x2& z) const {
  return Matrix2x2(val00 - z.val00, val01 - z.val01, val10 - z.val10, val11 - z.val11);
}

void Matrix2x2::MultScalar(double scalar) {
  val00 *= scalar; val01 *= scalar; val10 *= scalar; val11 *= scalar;
}

//non mandatory
void Matrix2x2::Print() const {
  std::cout << "[" << Getval00() << ",\t" << Getval01() << "]\n"
    << "[" << Getval10() << ",\t" << Getval11() << "]\n";
}
