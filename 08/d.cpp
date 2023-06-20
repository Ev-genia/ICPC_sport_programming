#include <iostream>
#include <vector>

void fillDynamicArr(int *dynamic, int *prevColumn, int *coins, int countColumn, int step) {
  dynamic[0] = 0;
  dynamic[1] = coins[1];
  prevColumn[0] = -1;
  prevColumn[1] = 0;
  int maxNum = -1;
  int j;
  for (int i = 2; i < countColumn; i++) {
    if (i - step > 0)
      j = i - step;
    else
      j = 1;
    int max = -1;
    for (; j < i; j++) {
      if (dynamic[j] > max) {
        maxNum = j;
        max = dynamic[j];
      }
    }
    dynamic[i] = dynamic[maxNum] + coins[i];
    prevColumn[i] = maxNum;
  }
}

void makeAnsver(int *prevColumn, int countColumn) {
  std::vector<int> rez;
  rez.push_back(0);
  for (int i = 1; i < countColumn; i++) {
    if (prevColumn[i] != rez.back())
      rez.push_back(prevColumn[i]);
  }
  rez.push_back(countColumn - 1);
  std::cout << rez.size() - 1 << std::endl;
  for (std::vector<int>::iterator it = rez.begin(); it != rez.end(); it++) {
    std::cout << *it + 1 << " ";
  }
    std::cout << std::endl;
}

int main() {
  int countColumn, step;
  std::cin >> countColumn >> step;
  int *coins = new int[countColumn];
  int *dynamic = new int[countColumn];
  int *prevColumn = new int[countColumn];

  coins[0] = coins[countColumn - 1] = 0;
  for (int i = 1; i < countColumn - 1; i++)
    std::cin >> coins[i];
  fillDynamicArr(dynamic, prevColumn, coins, countColumn, step);
  std::cout << dynamic[countColumn - 1] << std::endl;
  makeAnsver(prevColumn, countColumn);
  return (0);
}