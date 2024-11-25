#include <iostream>

using namespace std;

bool narcissistic( int value ){
  int real_value = value;
  int digit = 0;
  int sum = 0;
  while (value != 0) {
    value /= 10;
    digit += 1;
  }
  value = real_value;
  while (value != 0) {
    int dig = real_value % 10;
    int square;
    while (dig > 0) {
      square = 1;
      square *= dig;
      dig--;
      cout << square << endl;
    }
    sum += square;
    value /= 10;
  }
  return sum == real_value;
}

int main()
{
    cout << narcissistic(7) << endl;
    return 0;
}
