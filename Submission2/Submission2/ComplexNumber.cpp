//
//  ComplexNumber.cpp
//  Submission2
//
//  Created by ChristianEnevoldsen on 12/05/15.
//  Copyright (c) 2015 ChristianEnevoldsen. All rights reserved.
//

#include "ComplexNumber.hpp"
#include <math.h>
#include <cmath>
#include <complex>

ComplexNumber::ComplexNumber() {}
ComplexNumber::ComplexNumber(double x, double y) : mRealPart(x), mImaginaryPart(y) {}

double ComplexNumber::CalculateModulus() const {
  return sqrt(mRealPart * mRealPart + mImaginaryPart * mImaginaryPart);
}

double ComplexNumber::CalculateArgument() const {
  double x = mRealPart;
  double y = mImaginaryPart;
  std::complex<double> c(x, y);
  std::complex<double> p = std::arg(c);
  return p.imag();
}

ComplexNumber ComplexNumber::CalculatePower(double n) const {
  double x = mRealPart;
  double y = mImaginaryPart;
  std::complex<double> c(x, y);
  std::complex<double> p = pow(c, (int)n);
  return ComplexNumber(p.real(), p.imag());
}

ComplexNumber& ComplexNumber::operator=(const ComplexNumber &z) {
  this->mImaginaryPart = z.mImaginaryPart;
  this->mRealPart = z.mRealPart;
  return *this;
}

ComplexNumber ComplexNumber::operator-() const {
  double x = mRealPart;
  double y = mImaginaryPart;
  std::complex<double> c(x, y);
  std::complex<double> z = -c;
  return ComplexNumber(z.real(), z.imag());
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber &z) const {
  return ComplexNumber(mRealPart + z.mRealPart,
                       mImaginaryPart + z.mImaginaryPart);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber &z) const {
  return ComplexNumber(mRealPart - z.mRealPart,
                       mImaginaryPart - z.mImaginaryPart);
}

std::ostream& operator<<(std::ostream& output, const ComplexNumber& z) {
  output << z.GetImaginaryPart();
  return output;
}

double ComplexNumber::GetRealPart() const {
  return mRealPart;
}

double ComplexNumber::GetImaginaryPart() const {
  return mImaginaryPart;
}

double RealPart(const ComplexNumber& z) {
  return z.GetRealPart();
}

double ImaginaryPart(const ComplexNumber& z) {
  return z.GetImaginaryPart();
}

ComplexNumber::ComplexNumber(const ComplexNumber& z) : mRealPart(z.GetRealPart()), mImaginaryPart(z.GetImaginaryPart()) {}

ComplexNumber::ComplexNumber(double real) {
  std::complex<double> c(real);
  mRealPart = c.real();
  mImaginaryPart = c.imag();
}

void ComplexNumber::SetConjugate() {
  mImaginaryPart = -mImaginaryPart;
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber &z) const {
  std::complex<double> c(mRealPart, mImaginaryPart);
  std::complex<double> zz(z.mRealPart, z.mImaginaryPart);
  std::complex<double> res = c * zz;
  return ComplexNumber(res.real(), res.imag());
}

ComplexNumber ComplexNumber::CalculateConjugate() const {
  ComplexNumber c(mRealPart, mImaginaryPart);
  c.SetConjugate();
  return c;
}

/*
 std::complex<double> c(mRealPart, mImaginaryPart);
 c = std::conj(c);
 mRealPart = c.real();
 mImaginaryPart = c.imag();
 */



