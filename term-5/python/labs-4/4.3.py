import sys
import unittest

"""
Napisać iteracyjną wersję funkcji factorial(n) obliczającej silnię.
"""


def factorial(n: int) -> int:
    if n < 0:
        raise ValueError("Value must be greater than zero.")

    result = 1

    for i in range(1, n + 1):
        result *= i

    return result


class Tests(unittest.TestCase):
    def test_factorial(self) -> None:
        self.assertEqual(factorial(0), 1)
        self.assertEqual(factorial(1), 1)
        self.assertEqual(factorial(2), 2)
        self.assertEqual(factorial(3), 6)
        self.assertEqual(factorial(5), 120)
        self.assertEqual(factorial(10), 3628800)

    def test_factorial_negative(self) -> None:
        with self.assertRaises(ValueError):
            factorial(-1)


if __name__ == "__main__":
    unittest.main()

    sys.exit(0)
