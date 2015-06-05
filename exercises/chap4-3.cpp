#include <iostream>
#include <assert.h>

using namespace std;

int main(int argc, char const *argv[]) {
  for (int i = 0; i < 1000000000; ++i) {
    double* v = new double[3];
    double* u = new double[3];
    for (int i = 0; i < 3; ++i) {
      v[i] = i;
      u[i] = i * 2 + 1;
    }
    delete v;
    delete u;
  }

  return 0;
}
