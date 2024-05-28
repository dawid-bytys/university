#include <iostream>

class sina {
 private:
  double a_;

 public:
  sina(double a) : a_(a) {}

  double operator()(double x) const {
    return std::sin(a_ * x);
  }
};

template <typename Func>
double integrate(const Func& func, double a, double b, double dx) {
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
  std::cout << integrate(sina(0), 0, 3.1415926, 0.01) << std::endl;
  std::cout << integrate(sina(1), 0, 3.1415926, 0.01) << std::endl;
  std::cout << integrate(sina(2), 0, 3.1415926, 0.01) << std::endl;

  return 0;
}
