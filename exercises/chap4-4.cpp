#include <iostream>
#include <assert.h>

using namespace std;

double** create_matrix() {
  double** m = new double*[2];
  for (int i = 0; i < 2; ++i) {
    m[i] = new double[2];
  }

  return m;
}

double** mat_add(double** A, double** B) {
  double** C = create_matrix();
  for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 2; ++j)
      C[i][j] = A[i][j] + B[i][j];

  return C;
}

void print_mat(double** M, size_t n) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << M[i][j] << " ";
    }
    cout << endl;
  }
}

void free_mat(double** M) {
  for (int i = 0; i < 2; ++i) {
    delete M[i];
  }
  delete[] M;
}

int main(int argc, char const *argv[]) {
  for (int i = 0; i < 100000000; ++i) {
    double** A = create_matrix();
    double** B = create_matrix();
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < 2; ++j) {
        A[i][j] = i + j;
        B[i][j] = (i + j) * 2;
      }
    }
    double** C = mat_add(A, B);
    // print_mat(C, 2);
    free_mat(A);
    free_mat(B);
    free_mat(C);
  }

  return 0;
}
