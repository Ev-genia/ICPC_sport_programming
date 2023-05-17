#include <iostream>
#include <string.h>

void dfs(int vertex, int **arr, int *vizited, int count) {
  if (vizited[vertex] == 1)
    return ;
  else {
    vizited[vertex] = 1;
    for (int i = 0; i < count; i++) {
      if ((arr[vertex][i] || arr[i][vertex]) && vizited[i] == 0) {
        dfs(i, arr, vizited, count);
      }
    }
  }
}

int main() {
  int vertCount, edgesCount;
  std::cin >> vertCount >> edgesCount;

  int **arr = new int *[vertCount];
  for (int i = 0; i < vertCount; i++) {
    arr[i] = new int[vertCount];
    bzero(arr[i], vertCount);
  }
  int from, to;
  for (int i = 0; i < edgesCount; i++) {
    std::cin >> from >> to;
    arr[from - 1][to - 1] = 1;
  }
  int *vizited = new int[vertCount];
  memset(vizited, 0, vertCount);
  int compCount = 0;
  for (int i = 0; i < vertCount; i++) {
    if (vizited[i] == 0) {
      dfs(i, arr, vizited, vertCount);
      compCount++;
    }
  }
  std::cout << compCount << std::endl;
  return (0);
}