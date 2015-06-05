#include <iostream>
#include <assert.h>

using namespace std;

void printMat2x2(double** a, const char* name) {
  std::cout << "mat " << name << ": \n[";
  std::cout << a[0][0] << ", ";
  std::cout << a[0][1] << "]\n[";
  std::cout << a[1][0] << ", ";
  std::cout << a[1][1] << "]\n";
}

double detMat2x2(double** a) {
  return a[0][0] * a[1][1] - a[0][1] * a[1][0];
}
double** create_matrix(size_t n) {
  double** d = new double*[n];
  for (int i = 0; i < n; ++i) {
    d[i] = new double[n];
  }
  return d;
}

double** mat_scale(double** m, size_t n, double scale) {
  double **res = create_matrix(n);
  for (int i = 0; i < n; ++i) {
    for(int j = 0; j < n; ++j) {
      res[i][j] = m[i][j] * scale;
    }
  }
  return res;
}

double** inverse(double** a) {
  double det = detMat2x2(a);
  assert(det != 0 && "Determinant is null. Matrix not invertable");
  double** inv = create_matrix(2);
  inv[0][0] = a[1][1]; inv[0][1] = -a[0][1];
  inv[1][0] = -a[1][0]; inv[1][1] = a[0][0];
  return mat_scale(inv, 2, 1/det);
}

int main(int argc, char const *argv[]) {
  double** A = create_matrix(2);
  A[0][0] = 4; A[0][1] = 10; A[1][0] = 1; A[1][1] = 1;
  cout << "det A = " << detMat2x2(A) << endl;
  double** inv = inverse(A);
  printMat2x2(inv, "inv A");
  delete[] A;
  delete[] inv;
  return 0;
}
