#include <iostream>
#include <algorithm>

typedef struct s_elem {
  int wightItem;
  int costItem;
} t_elem;

int findMaxCost(int itemCount, int wight, t_elem *items) {
  int **dynamic = new int*[itemCount + 1];
  int maxCost = -1;
  for (int i = 0; i < itemCount + 1; i++) {
    dynamic[i] = new int[wight + 1];
    for (int j = 0; j < wight + 1; j++) {
      if (i == 0 || j == 0)
        dynamic[i][j] = 0;
      else {
        if (j >= items[i - 1].wightItem) {
          dynamic[i][j] = std::max(dynamic[i - 1][j], dynamic[i - 1][j - items[i - 1].wightItem] + items[i - 1].costItem);
        } else {
          dynamic[i][j] = dynamic[i - 1][j];
        }
      }
      if (dynamic[i][j] > maxCost)
        maxCost = dynamic[i][j];
    }
  }
  return (maxCost);
}

int main() {
  int itemCount, wight;
  t_elem *items = new t_elem[itemCount];

  std::cin >> itemCount >> wight;
  for (int i = 0; i < itemCount; i++) {
    std::cin >> items[i].wightItem;
  }
  for (int i = 0; i < itemCount; i++) {
    std::cin >> items[i].costItem;
  }
  int maxCost = findMaxCost(itemCount, wight, items);
  std::cout << maxCost << std::endl;
}