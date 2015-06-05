#include <iostream>
// Command to compile: g++ chap1-3.cpp chap1-3

/**
 * Computes the scalar (dot) product of two 3-dim vectors
 * @param  a 3 dim vector
 * @param  b 3 dim vector
 * @return the scalar (dot) product of the two 3 dim vectors a and b
 */
double scalarProduct(double *a, double *b) {
  double retVal = 0.0;

  // Store the sum of the product of each coordinates into retVal
  for (int i = 0; i < 3; i++) {
    retVal += a[i] * b[i]; // ie: a[x] * b[x] + a[y] * b[y] ...
  }

  return retVal;
}

int main(int argc, char const *argv[]) {
  // Creates two vec3 arrays
  double vec1[3] = {1.0, 2.0, 3.0};
  double vec2[3] = {2.0, 1.5, 4.0};

  // compute the scalar product
  double scalar = scalarProduct(vec1, vec2);

  // print the result
  std::cout << scalar << std::endl;
  return 0;
}
