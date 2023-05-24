#include <iostream>
#include <string.h>

void printArr(double **matrix, int count){
  for (int i = 0; i < count; i++) {
    for (int j = 0; j < count; j++) {
      std::cout << matrix[i][j] << " ";
    }
  std::cout << std::endl;
}
}

void makeMinor(double **matrix, double **minor, int i, int j, int count) {
  int ki, kj, di, dj;
  di = 0;
  for (ki = 0; ki < count - 1; ki++) {
    if (ki == i)
      di = 1;
    dj = 0;
    for (kj = 0; kj < count - 1; kj++) {
      if (kj == j)
        dj = 1;
      minor[ki][kj] = matrix[ki + di][kj + dj];
    }
  }
}

double findDet(double **matrix, int count) {
  int i, j, znak, n;
  double det;
  double **minor;

  minor = new double*[count];
  for (int i = 0; i < count; i++) {
    minor[i] = new double[count];
  }

  // det = 0;
  if (count == 1) {
    std::cout << matrix[0][0] << std::endl;
    det = matrix[0][0];
    return (det);
  }
  if (count == 2) {
    det = matrix[0][0] * matrix[1][1] - (matrix[1][0] * matrix[0][1]);
// std::cout << "count in det: " << count << std::endl;
// printArr(matrix, count);
// std::cout << "det: " << det << std::endl;
    return (det);
  }
  j = 0;
  znak = 1;
  n = count - 1;
  det = 0;
  if (count > 2) {
    for (i = 0; i < count; i++) {
// std::cout << "minor " << i << ": "<< std::endl;
// std::cout << "count: " << count << std::endl;
      makeMinor(matrix, minor, i, 0, count);
// printArr(minor, count);
      det = det + znak * matrix[i][0] * findDet(minor, n);
      znak = -znak;
    }
  }
  return (det);
}

int main() {
  int count;
  int det;

  std::cin >> count;
  double **matrix = new double *[count];
  for (int i = 0; i < count; i++) {
    matrix[i] = new double[count];
    bzero(matrix[i], count);
    for (int j = 0; j < count; j++) {
      std::cin >> matrix[i][j];
    }
  }
  det = findDet(matrix, count);
  std::cout << det << std::endl;
  return (0);
}