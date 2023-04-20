#include <iostream>

int main() {
	std::string line;
	long int n;
  int i = 0;
  int fib1 = 1;
  int fib2 = fib1 + 1;
  long int fib_sum;

	std::cin >> n;
  if (n == 1) {
    std::cout << fib1 << std::endl;
    return (0);
  }
	getline(std::cin, line);
  while (i < n - 2) {
    fib_sum = fib1 + fib2;
    fib1 = fib2;
    fib2 = fib_sum - 1;
    i++;
  }
  std::cout << fib2 << std::endl;
  return (0);
}