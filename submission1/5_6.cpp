#include "5_6.h"

void Multiply(double **res, double **A, double **B, int ARows, int ACols,
              int BRows, int BCols) {
  for (int i = 0; i < BRows; ++i) {
    for (int j = 0; j < ARows; ++j) {
      for (int k = 0; k < ACols; ++k) {
        res[j][i] += A[j][k] * B[k][i];
      }
    }
  }
}

void Multiply(double *res, double *A, double **B, int ACols, int BRows,
              int BCols) {

  for (int i = 0; i < BRows; ++i) {
    res[i] = 0;
  }

  for (int i = 0; i < BRows; ++i) {
    for (int j = 0; j < ACols; ++j) {
      res[i] += A[j] * B[i][j];
    }
  }
}

void Multiply(double *res, double **A, double *B, int ARows, int ACols,
              int BRows) {
  for (int i = 0; i < ACols; ++i) {
    res[i] = 0;
  }

  for (int i = 0; i < ACols; ++i) {
    for (int j = 0; j < BRows; ++j) {
      res[i] += B[j] * A[j][i];
    }
  }
}

void Multiply(double **res, double scalar, double **B, int BRows, int BCols) {
  Multiply(res, B, scalar, BRows, BCols);
}

void Multiply(double **res, double **B, double scalar, int BRows, int BCols) {
  for (int i = 0; i < BRows; ++i) {
    for (int j = 0; j < BCols; ++j) {
      res[i][j] = B[i][j] * scalar;
    }
  }
}

