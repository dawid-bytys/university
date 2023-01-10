#ifndef POLY_HPP
#define POLY_HPP

#include <cassert>
#include <cmath>
#include <iostream>

// Polynomial implementation using array
template <class T>
class Poly {
 private:
  T* coeffs;
  unsigned degree;

  // helper function for clearing the polynomial
  void clear();

 public:
  // default constructor
  Poly();

  // copy constructor with a given degree and a given array of coefficients
  Poly(const T* coeffs, const unsigned degree);

  // copy constructor from another polynomial
  Poly(const Poly<T>& poly);

  // destructor
  ~Poly();

  // returns the degree of the polynomial
  unsigned get_degree() const;

  // returns the value of the polynomial at the given point (Horner's method)
  T evaluate(const T& point) const;

  // returns the sum of two polynomials
  Poly<T> operator+(const Poly<T>& poly) const;

  // returns the difference of two polynomials
  Poly<T> operator-(const Poly<T>& poly) const;

  // returns the product of two polynomials
  Poly<T> operator*(const Poly<T>& poly) const;

  // compares if two polynomials are equal
  bool operator==(const Poly<T>& poly) const;

  // compares if two polynomials are not equal
  bool operator!=(const Poly<T>& poly) const;

  // access the coefficient of the given degree
  T& operator[](const unsigned degree) const;

  // prints the polynomial in a readable format
  void print() const;

  // returns if the polynomial is zero
  bool is_zero() const;
};

template <class T>
void Poly<T>::clear() {
  delete[] coeffs;
}

template <class T>
Poly<T>::Poly() {
  coeffs = new T[1];
  assert(coeffs != nullptr);
  coeffs[0] = 0;
  degree = 0;
}

template <class T>
Poly<T>::Poly(const T* coeffs, const unsigned degree) {
  if (degree < 0) {
    throw std::invalid_argument("Degree must be non-negative");
  }
  this->coeffs = new T[degree + 1];
  this->degree = degree;
  assert(this->coeffs != nullptr);
  for (int i = 0; i <= degree; ++i) {
    this->coeffs[i] = coeffs[degree - i];
  }
}

template <class T>
Poly<T>::Poly(const Poly<T>& poly) {
  coeffs = new T[poly.degree + 1];
  degree = poly.degree;
  assert(coeffs != nullptr);
  for (int i = 0; i <= poly.degree; ++i) {
    coeffs[i] = poly.coeffs[i];
  }
}

template <class T>
Poly<T>::~Poly() {
  clear();
}

template <class T>
unsigned Poly<T>::get_degree() const {
  return degree;
}

template <class T>
T Poly<T>::evaluate(const T& point) const {
  T result = 0;
  for (int i = 0; i <= degree; ++i) {
    result += coeffs[i] * std::pow(point, i);
  }
  return result;
}

template <class T>
Poly<T> Poly<T>::operator+(const Poly<T>& poly) const {
  const unsigned max_degree = std::max(degree, poly.degree);
  T* new_coeffs = new T[max_degree + 1];
  assert(new_coeffs != nullptr);
  for (int i = 0; i <= max_degree; ++i) {
    new_coeffs[degree - i] = coeffs[i] + poly.coeffs[i];
  }
  return Poly<T>(new_coeffs, max_degree);
}

template <class T>
Poly<T> Poly<T>::operator-(const Poly<T>& poly) const {
  const unsigned max_degree = std::max(degree, poly.degree);
  T* new_coeffs = new T[max_degree + 1];
  assert(new_coeffs != nullptr);
  for (int i = 0; i <= max_degree; ++i) {
    new_coeffs[degree - i] = coeffs[i] - poly.coeffs[i];
  }
  return Poly<T>(new_coeffs, max_degree);
}

template <class T>
Poly<T> Poly<T>::operator*(const Poly<T>& poly) const {
  const unsigned max_degree = degree + poly.degree;
  T* new_coeffs = new T[max_degree + 1];
  assert(new_coeffs != nullptr);
  for (int i = 0; i <= max_degree; ++i) {
    new_coeffs[i] = 0;
  }
  for (int i = 0; i <= degree; ++i) {
    for (int j = 0; j <= poly.degree; ++j) {
      new_coeffs[max_degree - (i + j)] += coeffs[i] * poly.coeffs[j];
    }
  }
  return Poly<T>(new_coeffs, max_degree);
}

template <class T>
bool Poly<T>::operator==(const Poly<T>& poly) const {
  if (degree != poly.degree) {
    return false;
  }
  return (*this - poly).is_zero();
}

template <class T>
bool Poly<T>::operator!=(const Poly<T>& poly) const {
  return !(*this == poly);
}

template <class T>
T& Poly<T>::operator[](const unsigned degree) const {
  if (degree < 0) {
    throw std::invalid_argument("Degree must be non-negative");
  }
  if (degree > this->degree) {
    throw std::invalid_argument(
        "Degree must be less than or equal to the "
        "degree of the polynomial");
  }
  return coeffs[degree];
}

template <class T>
void Poly<T>::print() const {
  if (is_zero()) {
    std::cout << "0";
    return;
  }
  for (int i = degree; i >= 0; --i) {
    if (coeffs[i] != 0) {
      if (i != degree) {
        std::cout << " + ";
      }
      std::cout << coeffs[i];
      if (i != 0) {
        std::cout << "x";
        if (i != 1) {
          std::cout << "^" << i;
        }
      }
    }
  }
  std::cout << std::endl;
}

template <class T>
bool Poly<T>::is_zero() const {
  for (int i = 0; i <= degree; ++i) {
    if (coeffs[i] != 0) {
      return false;
    }
  }
  return true;
}

#endif