#include <iostream>

long long int reverse(long long int num) {
  long long int rev_num = 0;

  while (num) {
    rev_num = rev_num * 10 + num % 10;
    num /= 10;
  }
  return rev_num;
}

int main(){
  int add, num;
  long long int rez;
  std::cin >> add >> num;
  rez = reverse(num * num) + add;
  std::cout << rez << std::endl;
}