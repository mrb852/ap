#include <iostream>
// Command to compile: g++ chap2-4.cpp chap2-4

void mat3x3Sub(double a[3][3], double b[3][3], double res[3][3]) {
  for (int i = 0; i < 3; ++i) {
    for(int j = 0; j < 3; ++j) {
      res[i][j] = a[i][j] - b[i][j];
    }
  }
}

void printMat2x2(double a[2][2], const char* name) {
  std::cout << "mat " << name << ": \n[";
  std::cout << a[0][0] << ", ";
  std::cout << a[0][1] << "]\n[";
  std::cout << a[1][0] << ", ";
  std::cout << a[1][1] << "]\n";
}

void printMat3x3(double a[3][3], const char* name) {
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      std::cout << a[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

void printVec(double a[3], const char* name) {
  std::cout << "vec3 " << name << ": [";
  std::cout << a[0] << ", " << a[1] << ", " << a[2] << "]\n";
}

void vecSubtract(double a[3], double b[3], double c[3]) {
  for (int i = 0; i < 3; ++i)
    c[i] = a[i] - b[i];
}

void mulMat3x3Vec3(double m[3][3], double v[3], double res[3]) {
  for (int i = 0; i < 3; ++i) {
    for(int j = 0; j < 3; ++j) {
      res[i] += m[i][j] * v[j];
    }
  }
}

void mat3x3Scale(double m[3][3], double scale, double res[3][3]) {
  for (int i = 0; i < 3; ++i) {
    for(int j = 0; j < 3; ++j) {
      res[i][j] = m[i][j] * scale;
    }
  }
}

void mat3x3Mul(double m[3][3], double v[3][3], double res[3][3]) {
  for (int i = 0; i < 3; ++i) {
    for (int c = 0; c < 3; ++c) {
      for (int j = 0; j < 3; ++j) {
        res[c][i] += m[c][j] * v[j][i];
      }
    }
  }
}

int main(int argc, char const *argv[]) {
  double u[3] = {1.0, 2.0, 3.0};
  double v[3] = {6.0, 5.0, 4.0};
  double A[3][3] = {
    {1.0, 5.0, 0.0},
    {7.0, 1.0, 2.0},
    {0.0, 0.0, 1.0}
  };
  double B[3][3] = {
    {-2.0, 0.0, 1.0},
    {1.0, 0.0, 0.0},
    {4.0, 1.0, 0.0}
  };
  double w[3];
  for (int i = 0; i < 3; ++i) {
    w[i] = u[i] - 3.0 * v[i];
  }

  double x[3];
  vecSubtract(u, v, x);


  double y[3];
  mulMat3x3Vec3(A, u, y);


  double tmp[3];
  double z[3];
  mulMat3x3Vec3(A, u, tmp);
  vecSubtract(tmp, v, z);

  double tmp_M[3][3];
  mat3x3Scale(A, 4, tmp_M);
  double tmp_M1[3][3];
  mat3x3Scale(B, 3, tmp_M1);
  double C[3][3];
  mat3x3Sub(tmp_M, tmp_M1, C);
  double D[3][3];
  mat3x3Mul(A, B, D);
  printMat3x3(D, "D");
  return 0;
}
