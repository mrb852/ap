#include <iostream>
// Command to compile: g++ chap1-4.cpp chap1-4

void printMat(double a[2][2], const char* name) {
  std::cout << "mat " << name << ": \n[";
  std::cout << a[0][0] << ", ";
  std::cout << a[0][1] << "]\n[";
  std::cout << a[1][0] << ", ";
  std::cout << a[1][1] << "]\n";
}

void matrixAdd(double a[2][2], double b[2][2], double c[2][2]) {
  c[0][0] = a[0][0] + b[0][0];
  c[0][1] = a[0][1] + b[0][1];
  c[1][0] = a[1][0] + b[1][0];
  c[1][1] = a[1][1] + b[1][1];
}

void matrixMul(double a[2][2], double b[2][2], double c[2][2]) {
  c[0][0] = a[0][0] * b[0][0] + a[0][1] * b[1][0];
  c[0][1] = a[0][0] * b[0][1] + a[0][1] * b[1][1];
  c[1][0] = a[1][0] * b[0][0] + a[1][1] * b[1][0];
  c[1][1] = a[1][0] * b[0][1] + a[1][1] * b[1][1];
}

int main(int argc, char const *argv[]) {
  double A[2][2];
  double B[2][2];
  double C[2][2];
  double D[2][2];
  A[0][0] = 3.0; A[0][1] = 2.0; A[1][0] = 4.0; A[1][1] = 10.0;
  B[0][0] = 5.0; B[0][1] = 20.0; B[1][0] = 14.0; B[1][1] = 6.0;
  printMat(A, "A");
  printMat(B, "B");
  matrixAdd(A, B, C);
  matrixMul(A, B, D);
  printMat(C, "C");
  printMat(D, "D");
  return 0;
}
