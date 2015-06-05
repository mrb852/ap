#include <iostream>
// Command to compile: g++ chap1-5.cpp chap1-5

int main(int argc, char const *argv[]) {
  int data[5] = {34, 58, 57, 32, 43};
  double result;
  for (int i = 0; i < 5; ++i) {
    result += data[i];
  }
  result /= 5.0;
  std::cout << result << std::endl;
  return 0;
}
