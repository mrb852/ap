#include "5_9.h"

double det3x3(double **A) {
  return ((A[0][0] * A[1][1] * A[2][2]) +
          (A[0][1] * A[1][2] * A[2][0]) +
          (A[0][2] * A[1][0] * A[2][1])) -
         ((A[2][0] * A[1][1] * A[0][2]) +
          (A[2][1] * A[1][2] * A[0][0]) +
          (A[2][2] * A[1][0] * A[0][1]));
}

void swap_matrix_col(double** res, double** A, double* b, int col) {

  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      res[i][j] = A[i][j];
      if (j == col) {
        res[i][j] = b[i];
      }
    }
  }
}

void solve3by3(double **A, double *b, double *u) {
  double d = det3x3(A);
  double *Dx[3];
  for (int i = 0; i < 3; ++i)  Dx[i] = new double[3];
  swap_matrix_col(Dx, A, b, 0);
  double *Dy[3];
  for (int i = 0; i < 3; ++i)  Dy[i] = new double[3];
  swap_matrix_col(Dy, A, b, 1);
  double *Dz[3];
  for (int i = 0; i < 3; ++i)  Dz[i] = new double[3];
  swap_matrix_col(Dz, A, b, 2);

  double dx = det3x3(Dx);
  double dy = det3x3(Dy);
  double dz = det3x3(Dz);

  u[0] = dx / d;
  u[1] = dy / d;
  u[2] = dz / d;

  for (int i = 0; i < 3; ++i) {
    delete[] Dx[i];
    delete[] Dz[i];
    delete[] Dy[i];
  }

}
