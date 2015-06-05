#include <iostream>
#include <assert.h>

using namespace std;

void swap(double* a, double* b) {
  double tmp = *a;
  *a = *b;
  *b = tmp;
}

void swap(double& a, double& b) {
  double tmp = a;
  a = b;
  b = tmp;
}

int main(int argc, char const *argv[]) {
  double a = 1.0;
  double b = 2.0;
  swap(&a, &b);
  swap(a, b);
  assert(a == 1.0 && b == 2.0 && "expected a = 1.0 and b = 2.0, after swapping two times");
  cout << "a: " << a << endl;
  cout << "b: " << b << endl;
  return 0;
}
