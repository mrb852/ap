#include <iostream>
#include <assert.h>

using namespace std;

void print_val(int* ptr) {
  cout << *ptr << endl;
}

void change_val(int* ptr, int val) {
  *ptr = val;
}

int main(int argc, char const *argv[]) {
  int i = 100;
  change_val(&i, 1337);
  print_val(&i);
  return 0;
}
