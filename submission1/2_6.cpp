#include "2_6.h"
#include <math.h>
#include <cmath>

double f(double x) {
  return (exp(x) + (x * x * x)) - 5;
}

double fmark(double x) {
  return 3 * (x * x) + exp(x);
}

double newton_Raphson(double initialGuess, double epsilon) {
  double x0 = initialGuess;
  double x1 = epsilon + 1;
  int maxIter = 1000;

  while(maxIter-- > 0) {
    x1 = x0 - f(x0) / fmark(x0);
    if (fabs(x1 - x0) < epsilon) break;
    x0 = x1;
  }

  return x0;
}
