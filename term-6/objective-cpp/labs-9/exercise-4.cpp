#include <iostream>

class Variable {
 public:
  double operator()(double x) const {
    return x;
  }
};

class Constant {
 private:
  double value_;

 public:
  Constant(double value) : value_(value) {}

  double operator()(double) const {
    return value_;
  }
};

template <typename LHS, typename RHS>
class AddExpr {
 private:
  LHS lhs_;
  RHS rhs_;

 public:
  AddExpr(const LHS& lhs, const RHS& rhs) : lhs_(lhs), rhs_(rhs) {}

  double operator()(double x) const {
    return lhs_(x) + rhs_(x);
  }
};

template <typename LHS, typename RHS>
AddExpr<LHS, RHS> operator+(const LHS& l, const RHS& r) {
  return {l, r};
}

template <typename LHS>
AddExpr<LHS, Constant> operator+(const LHS& lhs, double rhs) {
  return {lhs, Constant(rhs)};
}

template <typename RHS>
AddExpr<Constant, RHS> operator+(double lhs, const RHS& rhs) {
  return {Constant(lhs), rhs};
}

template <typename RHS>
class DivExpr {
 private:
  double lhs_;
  RHS rhs_;

 public:
  DivExpr(double lhs, const RHS& rhs) : lhs_(lhs), rhs_(rhs) {}

  double operator()(double x) const {
    return lhs_ / rhs_(x);
  }
};

template <typename RHS>
DivExpr<RHS> operator/(double lhs, const RHS& rhs) {
  return {lhs, rhs};
}

template <typename Expr>
class SinExpr {
 private:
  Expr expr_;

 public:
  SinExpr(const Expr& expr) : expr_(expr) {}

  double operator()(double x) const {
    return std::sin(expr_(x));
  }
};

template <typename Expr>
SinExpr<Expr> sin(const Expr& expr) {
  return {expr};
}

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
  Variable x;

  std::cout << "Integral of 1/sin(x + 1) from 0 to 1: "
            << integrate(1. / sin(x + 1.), 0, 1, 0.001) << std::endl;

  return 0;
}
