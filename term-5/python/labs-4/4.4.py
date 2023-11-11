import sys
import unittest
from typing import Self

"""
Napisać iteracyjną wersję funkcji fibonacci(n) obliczającej n-ty wyraz ciągu Fibonacciego.
"""


def fibbonacci(n: int) -> int:
    if n < 0:
        raise ValueError("Value must be greater than zero.")

    if n == 0 or n == 1:
        return n

    prev = 0
    curr = 1

    for _ in range(2, n + 1):
        prev, curr = curr, prev + curr

    return curr


class Tests(unittest.TestCase):
    def test_fibbonacci(self: Self) -> None:
        self.assertEqual(fibbonacci(0), 0)
        self.assertEqual(fibbonacci(1), 1)
        self.assertEqual(fibbonacci(2), 1)
        self.assertEqual(fibbonacci(3), 2)
        self.assertEqual(fibbonacci(5), 5)
        self.assertEqual(fibbonacci(10), 55)

    def test_fibbonacci_negative(self: Self) -> None:
        with self.assertRaises(ValueError):
            fibbonacci(-1)


if __name__ == "__main__":
    unittest.main()

    sys.exit(0)
