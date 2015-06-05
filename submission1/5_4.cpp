#include "5_4.h"
#include <math.h>
#include <assert.h>

double calc_mean(double a[], int len) {
  double res = 0.0;
  for (int i = 0; i < len; ++i) {
    res += a[i];
  }

  return res / len;
}

double calc_std(double a[], int len) {
  // assert(len > 1 && "len must be strictly higher than 1: len > 1");
  if (len <= 1) {
    return 0.0;
  }

  double sum = 0.0;
  double m = calc_mean(a, len);
  for (int j = 0; j < len; ++j) {
    double d = (a[j] - m);
    sum += d * d;
  }
  sum /= (len - 1);

  return sqrt(sum);
}
