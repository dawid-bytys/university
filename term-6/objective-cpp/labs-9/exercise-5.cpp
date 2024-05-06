#include <iostream>

template <typename T>
class Expr {
 public:
  virtual T operator()(T x) const = 0;
  virtual ~Expr() {}
};

template <typename T>
class Variable : public Expr<T> {
 public:
  T operator()(T x) const override { return x; }
};

template <typename T>
class Constant : public Expr<T> {
 private:
  T value_;

 public:
  Constant(T value) : value_(value) {}

  T operator()(T) const override { return value_; }
};

template <typename T>
class AddExpr : public Expr<T> {
 private:
  const Expr<T>& lhs_;
  const Expr<T>& rhs_;

 public:
  AddExpr(const Expr<T>& lhs, const Expr<T>& rhs) : lhs_(lhs), rhs_(rhs) {}

  T operator()(T x) const override { return lhs_(x) + rhs_(x); }
};

template <typename T>
AddExpr<T> operator+(const Expr<T>& lhs, const Expr<T>& rhs) {
  return AddExpr<T>(lhs, rhs);
}

template <typename Func, typename T>
T integrate(const Func& func, T a, T b, T dx) {
  T result = 0.0;
  T x = a;

  while (x < b) {
    T next_x = x + dx;

    if (next_x > b) {
      next_x = b;
    }

    T f1 = func(x);
    T f2 = func(next_x);

    result += (f1 + f2) * (next_x - x) / 2.0;
    x = next_x;
  }

  return result;
}

int main() {
  Variable<float> x;
  Constant<float> c(2.0f);

  auto expr = x + c;
  std::cout << "Integral of (x + 2.0) from 0 to 1 (float): "
            << integrate(expr, 0.0f, 1.0f, 0.001f) << std::endl;

  return 0;
}