# Polynomial Class

This is a template class for representing a polynomial of any degree, with the template parameter specifying the type of the coefficients. The class has the following features:

- A default constructor that initializes a zero polynomial
- A copy constructor that takes in a given array of coefficients and a degree, and constructs a polynomial from them
- A copy constructor that takes in another polynomial and creates a copy of it
- A destructor to free up memory when the object is no longer needed
- A method `get_degree()` that returns the degree of the polynomial
- A method `evaluate()` that takes in a point and returns the value of the polynomial at that point using Horner's method
- Overloaded `+`, `-`, and `*` operators to add, subtract, and multiply two polynomials, respectively
- Overloaded `==` and `!=` operators to compare if two polynomials are equal or not
- Overloaded `[]` operator to access the coefficient of a given degree
- A `print()` method that prints the polynomial in a readable format
- A `clear()` method that sets all the coefficients to zero
- A method `is_zero()` that returns `true` if the polynomial is the zero polynomial, and `false` otherwise

Example usage:

```cpp
#include "Poly.hpp"

int main() {
  double coeffs_p[3] = { 1, 2, 3 };
  Poly<double> p(coeffs_p, 2); // constructs a polynomial with degree 2 and coefficients 1, 2, 3

  double coeffs_q[3] = { 1, 2, 3 };
  Poly<double> q(coeffs_q, 2); // constructs another polynomial with degree 2 and coefficients 4, 5, 6

  Poly<double> r = p + q; // r is now a polynomial with degree 2 and coefficients 5, 7, 9
  r.print(); // prints "9x^2 + 7x + 5"

  return 0;
}
```

<br />

# How to run?

```bash
$ make run
```

<br />

# Usage of methods

## `get_degree()` - returns the degree of the polynomial

```cpp
#include <iostream>
#include "Poly.hpp"

int main() {
  double coeffs[3] = { 1, 2, 3 };
  Poly<double> example_poly(coeffs, 2);

  std::cout << example_poly.get_degree() << std::endl; // 2

  return 0;
}
```

<br />

## `evaluate()` - returns the value at the given argument using Horner's method

```cpp
#include <iostream>
#include "Poly.hpp"

int main() {
  double coeffs[3] = { 1, 2, 3 };
  Poly<double> example_poly(coeffs, 2);

  std::cout << example_poly.evaluate(3) << std::endl; // 18

  return 0;
}
```

<br />

## `operator+` - overloads the `+` operator (returns a new polynomial which is a sum of given two)

```cpp
#include "Poly.hpp"

int main() {
  double coeffs_p[3] = { 1, 2, 3 };
  Poly<double> p(coeffs_p, 2);

  double coeffs_q[3] = { 1, 2, 3 };
  Poly<double> q(coeffs_q, 2);

  Poly<double> r = p + q;
  r.print(); // 9x^2 + 7x + 5

  return 0;
}
```

<br />

## `operator-` - overloads the `-` operator (returns a new polynomial which is a difference of given two)

```cpp
#include "Poly.hpp"

int main() {
  double coeffs_p[3] = { 1, 2, 3 };
  Poly<double> p(coeffs_p, 2);

  double coeffs_q[3] = { 3, 2, 1 };
  Poly<double> q(coeffs_q, 2);

  Poly<double> r = p - q;
  r.print(); // -2x^2 + 2

  return 0;
}
```

<br />

## `operator*` - overloads the `*` operator (returns a new polynomial which is a product of given two)

```cpp
#include "Poly.hpp"

int main() {
  double coeffs_p[3] = { 1, 2, 3 };
  Poly<double> p(coeffs_p, 2);

  double coeffs_q[3] = { 3, 2, 1 };
  Poly<double> q(coeffs_q, 2);

  Poly<double> r = p * q;
  r.print(); // 3x^4 + 8x^3 + 14x^2 + 8x + 3

  return 0;
}
```

<br />

## `operator==` - overloads the `==` operator (returns true if the polynomials are equal, true false)

```cpp
#include <iostream>
#include "Poly.hpp"

int main() {
  double coeffs_p[3] = { 1, 2, 3 };
  Poly<double> p(coeffs_p, 2);

  double coeffs_q[3] = { 3, 2, 1 };
  Poly<double> q(coeffs_q, 2);

  std::cout << p == q << std::endl; // false

  return 0;
}
```

<br />

## `operator!=` - overloads the `!=` operator (returns false if the polynomials are not equal, true otherwise)

```cpp
#include <iostream>
#include "Poly.hpp"

int main() {
  double coeffs_p[3] = { 1, 2, 3 };
  Poly<double> p(coeffs_p, 2);

  double coeffs_q[3] = { 3, 2, 1 };
  Poly<double> q(coeffs_q, 2);

  std::cout << p != q << std::endl; // true

  return 0;
}
```

<br />

## `operator[]` - overloads the `[]` operator (returns a coefficient of a given degree)

```cpp
#include <iostream>
#include "Poly.hpp"

int main() {
  double coeffs[3] = { 1, 2, 3 };
  Poly<double> example_poly(coeffs, 2);

  std::cout << example_poly[0] << std::endl; // 3
  std::cout << example_poly[1] << std::endl; // 2
  std::cout << example_poly[2] << std::endl; // 1

  return 0;
}
```

<br />

## `print()` - prints a polynomial to the output stream

```cpp
#include "Poly.hpp"

int main() {
  double coeffs[3] = { 1, 2, 3 };
  Poly<double> example_poly(coeffs, 2);

  example_poly.print(); // x^2 + 2x + 3

  return 0;
}
```

<br />

## `print()` - prints a polynomial to the output stream

```cpp
#include "Poly.hpp"

int main() {
  double coeffs[3] = { 1, 2, 3 };
  Poly<double> example_poly(coeffs, 2);

  example_poly.print(); // x^2 + 2x + 3

  return 0;
}
```

<br />

## `is_zero()` - returns true if a polynomial has every cofficient equals zero, false otherwise

```cpp
#include "Poly.hpp"

int main() {
  double coeffs[3] = { 1, 2, 3 };
  Poly<double> example_poly(coeffs, 2);

  std::cout << example_poly.is_zero() << std::endl; // false

  return 0;
}
```
