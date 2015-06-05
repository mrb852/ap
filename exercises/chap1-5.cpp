#include <iostream>
// Command to compile: g++ chap1-5.cpp chap1-5

int main(int argc, char const *argv[]) {
  char* firstname = (char*)malloc(sizeof(char) * 20);
  char* lastname = (char*)malloc(sizeof(char) * 20);

  std::cout << "first name: ";
  std::cin >> firstname;
  std::cout << "last name: ";
  std::cin >> lastname;
  std::cout << "full name: " << firstname << " " << lastname << std::endl;

  delete firstname;
  delete lastname;

  return 0;
}
