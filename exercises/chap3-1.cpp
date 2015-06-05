#include <iostream>
#include <fstream>

void write_file(const char* file, double a[4]) {
  std::ofstream data;
  data.open(file, std::ios::app);
  data.setf(std::ios::scientific);
  data.setf(std::ios::showpos);
  data.precision(10);
  for (int i = 0; i < 3; ++i) {
    data << a[i] << " ";
  }
  data << a[3] << "\n";
  data.close();
}

int main(int argc, char const *argv[]) {
  double x[4] = {0, 1, 1, 0};
  double y[4] = {0, 0, 1, 1};
  write_file("x_and_y.dat", x);
  write_file("x_and_y.dat", y);
  return 0;
}
