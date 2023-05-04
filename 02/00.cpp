#include <iostream>
#include <sstream>

int converter(std::string &str) {
  int rez;
  std::stringstream sstr(str);
  sstr >> rez;
  return (rez);
}

void enterCount(int &line, int &column) {
  std::string str;

  std::cout << "Enter count of lines: " << std::endl;
  std::cin >> line;
  std::cout << "Enter count of colunms: " << std::endl;
  std::cin >> column;
  getline(std::cin, str);
}

int **enterData(int &line, int &column) {
  std::cout << "Enter elements: " << std::endl;
std::cout << "&line: " << line << ", &column: " << column << std::endl;
  int **rez = new int *[line];
  for (int i = 0; i < line; i++) {
    rez[i] = new int[column];
    bzero(rez[i], column);
    for (int j = 0; j < column; j++) {
      std::string str;
      getline(std::cin, str);
      rez[i][j] = converter(str);
std::cout << "rez[" << i << "][" << j << "]: " << rez[i][j] << std::endl;
    }
  }
  return (rez);
}

void printArr(int **arr, int line, int column) {
std::cout << "Array: " << std::endl;

  for (int i = 0; i < line; i++) {
    for (int j = 0; j < column; j++)
      std::cout << arr[i][j] << " ";
    std::cout << std::endl;
  }
}

int sumElem(int **arr1, int **arr2, int j, int column2) {
std::cout << "column2 = " << column2 << std::endl;
std::cout << "j = " << j << std::endl;
  if (column2 > 0) {
    column2--;
std::cout << "arr1[j][k] * arr2[k][j] = " << arr1[j][column2] * arr2[column2][j] << std::endl;
std::cout << "arr1[" << j << "][" << column2 << "]: " << arr1[j][column2] << std::endl;
std::cout << "arr2[" << column2 << "][" << j << "]: " << arr2[column2][j] << std::endl;
    return (arr1[j][column2] * arr2[column2][j] + sumElem(arr1, arr2, j, column2));
  }
  else {
    return (0);
  }
}

int **handler(int **arr1, int line1, int column1, int **arr2, int line2, int column2) {
  int **rez = new int *[line1];
  for (int i = 0; i < line1; i++) {
    rez[i] = new int[column2];
    for (int j = 0; j < column2; j++) {
      rez[i][j] = sumElem(arr1, arr2, j, column2);
std::cout << "rez[" << i << "][" << j << "]: " << rez[i][j] << std::endl;
    }
  }
  return (rez);
}

void freeArr(int **arr, int line) {
  for (int i = 0; i < line; i++) {
    if (arr[i])
      delete[] arr[i];
  }
  if (arr)
    delete[] arr;
}

int main() {
  int column1, column2, line1, line2;
  int **arr1, **arr2, **arr3;

  enterCount(line1, column1);
  enterCount(line2, column2);
  if (column1 != line2) {
    std::cerr << "Error of arguments" << std::endl;
    return (1);
  }
  arr1 = enterData(line1, column1);
printArr(arr1, line1, column1);
  arr2 = enterData(line2, column2);
printArr(arr2, line2, column2);
  arr3 = handler(arr1, line1, column1, arr2, line2, column2);
printArr(arr3, line1, column2);
  freeArr(arr1, line1);
  freeArr(arr2, line2);
  freeArr(arr3, line1);
  return (0);
}

// 2
// 3
// 1 2 3
// 1 0 -1

// 3 4 5
// 6 0 -2
// 7 1 8

// rez:
// 36 7 25
// -4 3 -3