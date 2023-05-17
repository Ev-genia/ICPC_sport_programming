#include <iostream>
#include <vector>
#include <strings.h>

int main() {
  int start, finish, count, v1, v2, weight;
  std::cin >> start >> finish >> count;
  start--;

  int **arr = new int*[count];
  for (int i = 0; i < count; i++) {
    arr[i] = new int[count];
    bzero(arr[i], count);
  }
  for (int i = 0; i < count; i++) {
    std::cin >> v1 >> v2 >> weight;
    arr[v1 - 1][v2 - 1] = weight;
  }
  std::vector<int> distance;
  std::vector<bool> vizit;
  int minindex = 0;
  int min;
  int ret = 1;
  int tmp;

  for (size_t i = 0; i < count; i++) {
    distance.push_back(10000);
    vizit.push_back(1);
  }
  distance[start] = 0;
  while (ret || minindex < 10000) {
    minindex = 10000;
    min = 10000;
    for (size_t i = 0; i < count; i++) {
      if (vizit[i] == true && distance[i] < min) {
        min = distance[i];
        minindex = i;
      }
    }
    if (minindex != 10000) {
      for (size_t i = 0; i < count; i++) {
        if (arr[minindex][i] > 0) {
          tmp = min + arr[minindex][i];
          if (tmp < distance[i]) {
            distance[i] = tmp;
          }
        }
      }
      vizit[minindex] = false;
    }
    ret = 0;
  }
  if (distance[finish - 1] == 10000)
    distance[finish - 1] = 0;
  std::cout << distance[finish - 1] << std::endl;
}