#include <iostream>
#include <stdlib.h>

long long int factorial(long int input, long int finish) {
  if (input == finish+1)
    return (1);
  else
    return (input * factorial(input + 1, finish));
}

int main() {
	std::string	line;
	long int		n, finish;

	std::cin >> n >> finish;

  if (n > finish || n < 0) {
    std::cout << -1 << std::endl;
    return (0);
  }
  std::cout << factorial(n, finish) << std::endl;
  return (0);
}