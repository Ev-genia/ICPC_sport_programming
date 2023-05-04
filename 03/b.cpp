#include <iostream>
#include <vector>

void makeAnswer(int *nbrs, int *last, int indexMax) {
  std::vector<int> rez;

  rez.push_back(nbrs[indexMax]);
  while (last[indexMax] != -1) {
    rez.push_back(nbrs[last[indexMax]]);
    indexMax = last[indexMax];
  }
  for (int i = rez.size() - 1; i >= 0; i--) {
    std::cout << rez[i] << " ";
  }
  std::cout << std::endl;
  std::cout << rez.size() << std::endl;
}

void handler(int *dynamic, int *nbrs, int *last, int count) {
  int max, indexMax;

  dynamic[0] = 1;
  last[0] = -1;
  for (int i = 1; i < count; i++) {
    max = 0;
    last[i] = -1;
    for (int k = i - 1; k >= 0; k--) {
      if (dynamic[k] > max && nbrs[k] < nbrs[i]) {
        max = dynamic[k];
        last[i] = k;
      }
    }
    dynamic[i] = max + 1;
  }
  max = 0;
  for (int i = 0; i < count; i++) {
    if (dynamic[i] > max) {
      max = dynamic[i];
      indexMax = i;
    }
  }
  makeAnswer(nbrs, last, indexMax);
}

int main() {
  int count;
  std::cin >> count;
  int *nbrs = new int[count];
  int *dynamic = new int[count];
  int *last = new int[count];
  for (int i = 0; i < count; i++)
    std::cin >> nbrs[i];
  handler(dynamic, nbrs, last, count);
}