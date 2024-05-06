#include <functional>
#include <iostream>

class Variable {
 public:
  double operator()(double x) const { return x; }
};

class Constant {
 private:
  double value_;

 public:
  Constant(double value) : value_(value) {}

  double operator()(double) const { return value_; }
};

template <typename Func>
double integrate(Func func, double a, double b, double dx) {
  double result = 0.0;
  double x = a;

  while (x < b) {
    double next_x = x + dx;

    if (next_x > b) {
      next_x = b;
    }

    double f1 = func(x);
    double f2 = func(next_x);

    result += (f1 + f2) * (next_x - x) / 2.0;
    x = next_x;
  }

  return result;
}

int main() {
  Variable x;
  std::cout << "Integral of x from 0 to 1: " << integrate(x, 0, 1, 0.001)
            << std::endl;

  Constant one(1.0);
  std::cout << "Integral of 1 from 0 to 1: " << integrate(one, 0, 1, 0.001)
            << std::endl;

  return 0;
}
