#include <iostream>
#include <assert.h>
#include <fstream>

using namespace std;

void write_file(const char* file, double x, double y) {
  std::ofstream data;
  data.open(file, std::ios::app);
  data.precision(7);

  data << x << "," << y << endl;

  data.close();
}

void implicit_Euler(int n) {
  double h = 1.0 / (double)n;
  double y = 1.0;
  double x = 0.0;
  int i = 0;

  while(i++ < n) {
    write_file("xy.dat", x, y);
    x = i * h;
    y = y / (1 + h);
  }
}
