#include <iostream>
#include <math.h>

using namespace std;

double mean(double* x, size_t len) {
  double res = 0.0;
  for (int i = 0; i < len; ++i) {
    res += x[i];
  }
  return res / len;
}

double std_deviation(double* x, size_t len) {
  double sum = 0.0;
  double m = mean(x, len);
  for (int j = 0; j < len; ++j) {
    double d = (x[j] - m);
    sum += d * d;
  }
  sum /= (len - 1);
  return sqrt(sum);
}

int main(int argc, char const *argv[]) {
  double *x = new double[5];
  x[0] = 1;
  x[1] = 12;
  x[2] = 5;
  x[3] = 10;
  x[4] = 20;
  cout << std_deviation(x, 5) << endl;
  delete[] x;
  return 0;
}
