#include <iostream>
#include <assert.h>

using namespace std;

double** create_matrix(size_t r, size_t c) {
  double **C = new double*[r];
  for (int i = 0; i < r; ++i) {
    C[i] = new double[c];
    for(int j = 0; j < c; ++j) {
      C[i][j] = 0;
    }
  }
  return C;
}

void free_mat(double** M, size_t r) {
  for (int i = 0; i < r; ++i) {
    delete[] M[i];
  }
  delete[] M;
}

template <size_t r, size_t c, size_t r1, size_t c1>
double** multiply(double (&M)[r][c], double(&M1)[r1][c1]) {
  assert(c == r1 && "The number of cols in the first matrix should be equal to the number of rows in the second matrix");
  double** C = create_matrix(r, c1);

  for (int i = 0; i < r1; ++i) {
    for (int j = 0; j < r; ++j) {
      for (int k = 0; k < c; ++k) {
        C[j][i] += M[j][k] * M1[k][i];
      }
    }
  }

  return C;
}

template <size_t r, size_t c>
double** multiply(double (&M)[r][c], double scale) {
  double **C = create_matrix(r, c);
  for (int i = 0; i < r; ++i) {
    for(int j = 0; j < c; j++) {
      C[i][j] = M[i][j] * scale;
    }
  }
  return C;
}

template <size_t r, size_t c>
double** multiply(double scale, double (&M)[r][c]) {
  return multiply(M, scale);
}

void print_mat(double **M, int r, int c) {
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      cout << M[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

template<size_t r, size_t c>
void print_mat(double (&M)[r][c]) {
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      cout << M[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

int main(int argc, char const *argv[]) {
  double A[3][4] = {
    {1, 2, 4, 7},
    {2, 3, 2, 0},
    {5, 3, 1, 9}
  };

  // Print A
  cout << "Matrix A: " << endl;
  print_mat(A);

  double B[4][3] = {
    {1, 2, 5},
    {2, 3, 1},
    {3, 4, 2},
    {6, 7, 8}
  };

  // Print B
  cout << "Matrix B: " << endl;
  print_mat(B);

  // A*B
  double** mat = multiply(A, B);
  cout << "A*B: " << endl;
  print_mat(mat, 3, 3);

  // A*3
  double** scaled_A = multiply(A, 3.0);
  cout << "A*3: " << endl;
  print_mat(scaled_A, 3, 4);

  // 5*B
  double** scaled_B = multiply(3.0, B);
  cout << "5*B: " << endl;
  print_mat(scaled_B, 4, 3);


  cout << "Cleaning up" << endl;
  free_mat(mat, 3);
  free_mat(scaled_A, 3);
  free_mat(scaled_B, 4);

  return 0;
}
