#include <iostream>

// Command to compile: g++ chap1-2.cpp chap1-2

int main(int argc, char const *argv[]) {
  int first, second = 0;
  std::cout << "Enter an integer: ";
  std::cin >> first;
  std::cout << "Enter another integer: ";
  std::cin >> second;
  std::cout << first << " + " << second << " = " << first + second << std::endl;
  return 0;
}
