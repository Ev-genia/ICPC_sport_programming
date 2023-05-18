#include <iostream>
#include <algorithm>
#include <string.h>

typedef struct s_shop {
  int price;
  int countMateria;
  int salePrice;
  int maxMateria;
} t_shop;

int findMinCost(int shopsCount, int needMateria, t_shop *shops) {
  int **dynamic = new int*[shopsCount + 1];
  int cost;

  for (int i = 0; i < shopsCount + 1; i++) {
    dynamic[i] = new int[needMateria + 1];
    memset(dynamic[i], 0, needMateria + 1);
    for (int j = 0; j < needMateria + 1; j++) {
      if (i == 0 || j == 0)
        dynamic[i][j] = 10000;
      else {
        if (j <= shops[i - 1].maxMateria) {
          if (j < shops[i - 1].countMateria)
            cost = j * shops[i - 1].price;
          else
            cost = j * shops[i - 1].salePrice;
        } else {
          cost = dynamic[i][shops[i - 1].maxMateria] + dynamic[i - 1][j - shops[i - 1].maxMateria];
        }
        dynamic[i][j] = std::min(dynamic[i - 1][j], cost);
      }
    }
  }
  return (dynamic[shopsCount][needMateria]);
}

int main() {
  int shopsCount, needMateria;
  std::cin >> shopsCount >> needMateria;

  t_shop *shops = new t_shop[shopsCount];
  for (int i = 0; i < shopsCount; i++) {
    std::cin >> shops[i].price >> shops[i].countMateria >> shops[i].salePrice >> shops[i].maxMateria;
  }
  int minCost = findMinCost(shopsCount, needMateria, shops);
  if (minCost >= 10000)
    minCost = -1;
  std::cout << minCost << std::endl;
}