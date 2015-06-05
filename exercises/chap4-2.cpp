#include <iostream>
#include <assert.h>

using namespace std;

int main(int argc, char const *argv[]) {
  int i = 5;
  int j = 10;
  int *pi = &i;
  int *pj = &j;
  int *tmp = pi;
  pi = pj;
  pj = tmp;
  cout << *pi << endl;
  cout << *pj << endl;
  return 0;
}
