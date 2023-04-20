#include <iostream>

unsigned long long akk(int n, int m) {
  if (n == 0)
    return (m + 1);
  else {
    if (m == 0)
      return(akk(n - 1, 1));
    else
      return(akk(n - 1, akk(n, m - 1)));
  }
}

int main() {
	std::string	line;
	long int		n, m;

	std::cin >> n >> m;
	getline(std::cin, line);
  std::cout << akk(n, m) << std::endl;
  return (0);
}