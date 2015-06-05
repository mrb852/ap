//
//  CalculateExponential.cpp
//  Submission2
//
//  Created by ChristianEnevoldsen on 12/05/15.
//  Copyright (c) 2015 ChristianEnevoldsen. All rights reserved.
//

#include <stdio.h>
#include "CalculateExponential.hpp"
#include <complex>
#include <cmath>

void CalculateExponential(ComplexNumber **A, int nMax, ComplexNumber **res) {
  ComplexNumber c = *(ComplexNumber *)*A;
  std::complex<double> cc(c.GetRealPart(), c.GetImaginaryPart());
  std::complex<double> r = exp(cc);
  **res = ComplexNumber(r.real(), r.imag());
}