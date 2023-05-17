#include <iostream>
#include <string.h>

int countEdges(int **arr, int count) {
  int edges = 0;
  for (int i = 0; i < count; i++) {
    for (int j = i; j < count; j++) {
      if (arr[i][j])
        edges++;
    }
  }
  return (edges);
}

void dfs(int vertex, int **arr, int *vizited, int count) {
  if (vizited[vertex] == 1)
    return ;
  else {
    vizited[vertex] = 1;
    for (int i = 0; i < count; i++) {
      if (arr[vertex][i])
        dfs(i, arr, vizited, count);
    }
  }
}

int main() {
  int count;

  std::cin >> count;
  int **arr = new int *[count];
  for (int i = 0; i < count; i++) {
    arr[i] = new int[count];
    for (int j = 0; j < count; j++)
      std::cin >> arr[i][j];
  }
  int edges = countEdges(arr, count);
  if (edges != count - 1) {
    std::cout << "NO" << std::endl;
    return (0);
  }
  int *vizited = new int[count];
  memset(vizited, 0, count);
  dfs(0, arr, vizited, count);
  for (int i = 0; i < count; i++) {
    if (vizited[i] != 1) {
      std::cout << "NO" << std::endl;
      return (0);
    }
  }
  std::cout << "YES" << std::endl;
  return (0);
}
