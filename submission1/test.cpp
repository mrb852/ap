#include <iostream>
#include <assert.h>
#include <math.h>
#include "2_6.h"
#include "3_3.h"
#include "5_3.h"
#include "5_4.h"
#include "5_6.h"
#include "5_9.h"

using namespace std;

void it(bool test, const char* message) {
  if (!test) {
    cout << message << endl;
  }
  assert(test);
}

void test2_6() {
  it(fabs(newton_Raphson(0, 0.0001) - 1.19368) < 0.0001, "|val - expected| < epsilon");
}

void test3_3() {
  // implicit_Euler(10000);
}

void test5_4() {
  double a[4] = {1, 2, 3, 4};
  it(calc_std(a, 4) == 1.2909944487358056, "std der for 1,2,3,4 should equal 1.2909944487358056");
  double b[1] = {1};
  it(calc_std(b, 1) == 0.0, "std der for 1 should equal 0");
}

/*
void Multiply(double *res, double *A, double **B, int ACols, int BRows,
              int BCols) {
 */
void test5_6() {
  double res[3]   =   {0, 0, 0};
  double A[4]     =   {2, 3, 5, 7};

  double *B[3];
  for (int i = 0; i < 4; ++i) {
    B[i] = new double[3];
  }
  B[0][0] = 5; B[0][1] = 9; B[0][2] = 3;
  B[1][0] = 7; B[1][1] = 8; B[1][2] = 1;
  B[2][0] = 1; B[2][1] = 5; B[2][2] = 3;
  B[3][0] = 9; B[3][1] = 3; B[3][2] = 2;

  Multiply(res, B, A, 4, 3, 4);
  for (int i = 0; i < 3; ++i) {
    cout << res[i] << ", ";
  }
  cout << endl;
}

void test5_9() {
  double *A[3];
  for (int i = 0; i < 3; ++i) {
    A[i] = new double[3];
  }
  A[0][0] = 5; A[0][1] = 9; A[0][2] = 3;
  A[1][0] = 7; A[1][1] = 8; A[1][2] = 1;
  A[2][0] = 1; A[2][1] = 5; A[2][2] = 3;

  double b[3] = {5, 3, 2};
  double u[3] = {0,0,0};
  solve3by3(A, b, u);
  for (int i = 0; i < 3; ++i) {
    cout << u[i]  << endl;
  }
}

int main(int argc, char const *argv[]) {
  test2_6();
  test3_3();
  test5_4();
  test5_6();
  test5_9();

  return 0;
}
