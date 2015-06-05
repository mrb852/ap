#include <iostream>
#include <assert.h>

using namespace std;

void print_val(int* ptr) {
  cout << *ptr << endl;
}

int main(int argc, char const *argv[]) {
  int i = 100;
  print_val(&i);
  return 0;
}
