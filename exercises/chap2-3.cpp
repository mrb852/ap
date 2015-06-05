#include <iostream>
// Command to compile: g++ chap2-3.cpp chap2-3

int main(int argc, char const *argv[]) {
  int res, input = 0;

  while(input != -1) {
    std::cin >> input;
    // If input is -1 then exit. Otherwise check if
    // input is an invalid int and if so reset to zero(-res). Else
    // add the input to the sum
    res += input != -1 ? input > 0 ? input : -res : 0;
    if (res > 100) break;
  }

  std::cout << res << std::endl;

  return 0;
}
