#include <iostream>

int fib(int n) {
  if (n <= 1) 
    return 0;
  else if (n == 2)
    return 1;
  return (fib(n - 1) + fib(n - 2));
}

int handler(int *nbrs, int count) {
  int counter = 0;

  for (int i = 0; i < count; i++) {
    if (nbrs[i] >= 0) {
      for (int f = i; f <= count; f++) {
        int fibon = fib(f);
        if (nbrs[i] == fibon) {
          counter++;
          break;
        }
      }
    }
  }
  return counter;
}

int main() {
  int count;
  std::cin >> count;
  int *nbrs = new int[count];
  for (int i = 0; i < count; i++)
    std::cin >> nbrs[i];
  std::cout << (handler(nbrs, count)) << std::endl;
}