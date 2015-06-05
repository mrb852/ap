#include <iostream>
#include <assert.h>

using namespace std;

int main(int argc, char const *argv[]) {
  int i = 5;
  int* p_j = &i;
  *p_j *= 5;
  int* p_k = new int;
  *p_k = i;
  assert(p_k != p_j && "p_k and p_j must have different addresses");
  cout << *p_k << endl;
  delete p_k;
  return 0;
}
