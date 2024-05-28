#include <iostream>

template <typename T>
class Expr {
 public:
  virtual T operator()(T x, T y) const = 0;
  virtual ~Expr() {}
};

template <typename T>
class First : public Expr<T> {
 public:
  T operator()(T x, T y) const override {
    return x;
  }
};

template <typename T>
class Second : public Expr<T> {
 public:
  T operator()(T x, T y) const override {
    return y;
  }
};

template <typename T>
class AddExpr : public Expr<T> {
 public:
  AddExpr(const Expr<T>& lhs, const Expr<T>& rhs) : lhs_(lhs), rhs_(rhs) {}

  T operator()(T x, T y) const override {
    return lhs_(x, y) + rhs_(x, y);
  }

 private:
  const Expr<T>& lhs_;
  const Expr<T>& rhs_;
};

template <typename T>
AddExpr<T> operator+(const Expr<T>& lhs, const Expr<T>& rhs) {
  return AddExpr<T>(lhs, rhs);
}

template <typename Func, typename T>
T integrate(const Func& func, T ax, T bx, T ay, T by, T dx, T dy) {
  T result = 0;

  for (T x = ax; x < bx; x += dx) {
    for (T y = ay; y < by; y += dy) {
      result += func(x + dx / 2, y + dy / 2) * dx * dy;
    }
  }

  return result;
}

int main() {
  First<double> x;
  Second<double> y;

  auto expr = x + y;
  std::cout << "Integral of (x + y) from (0,0) to (1,1): "
            << integrate(expr, 0.0, 1.0, 0.0, 1.0, 0.01, 0.01) << std::endl;

  return 0;
}
