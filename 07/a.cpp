#include <iostream>
#include <vector>
#include <string.h>
#include <string>
#include <sstream>
#include <algorithm>

int mirror(int nbr) {
  int rez = 0;

  while (nbr) {
    rez = rez * 10 + nbr % 10;
    nbr /= 10;
  }
  return (rez);
}

int sort(int nbr) {
  int rez;
  std::stringstream ss;

  ss << nbr;
  std::string s = ss.str();
  sort(s.begin(), s.end());
  rez = std::stoi(s);
  return (rez);
}

int main() {
  int firstElem, endNbr;
  std::cin >> firstElem >> endNbr;
  std::vector<int> data;

  endNbr--;
  data.push_back(firstElem);
  for (int i = 0; i < endNbr; i++) {
    int elem1 = data.back();
    int elem2 = mirror(elem1);
    int rez = elem1 + elem2;
    rez = sort(rez);
    data.push_back(rez);
  }
  std::cout << data.back() << std::endl;
  return (0);
}
