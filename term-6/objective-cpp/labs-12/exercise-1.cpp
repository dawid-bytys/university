#include <concepts>
#include <iostream>

template <std::integral T>
T gcd(T a, T b) {
  while (b != 0) {
    T temp = b;
    b = a % b;
    a = temp;
  }
  
  return a;
}

int main() {
  int a = 56;
  int b = 98;

  std::cout << "GCD of " << a << " and " << b << " is " << gcd(a, b)
            << std::endl;

  long x = 1234567890L;
  long y = 9876543210L;

  std::cout << "GCD of " << x << " and " << y << " is " << gcd(x, y)
            << std::endl;

  unsigned int ua = 48;
  unsigned int ub = 18;

  std::cout << "GCD of " << ua << " and " << ub << " is " << gcd(ua, ub)
            << std::endl;

  return 0;
}
