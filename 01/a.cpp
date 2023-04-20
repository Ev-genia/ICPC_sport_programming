#include <iostream>
#include <stdlib.h>

long long int factorial(long int input) {
  if (input == 1)
    return (1);
  else
    return (input * factorial(input - 1));
}

int main() {
	std::string	line;
	long int		n;

	std::cin >> n;
	getline(std::cin, line);

  if (n == 0) {
    std::cout << 1 << std::endl;
    return (0);
  }
  std::cout << factorial(n) << std::endl;
  return (0);
}