import random
import sys
import unittest
from typing import Iterator, Literal

"""
Stworzyć następujące iteratory nieskończone:
(a) zwracający 0, 1, 0, 1, 0, 1, ...,
(b) zwracający przypadkowo jedną wartość z ("N", "E", "S", "W") [błądzenie przypadkowe na sieci kwadratowej 2D],
(c) zwracający 0, 1, 2, 3, 4, 5, 6, 0, 1, 2, 3, 4, 5, 6, ... [numery dni tygodnia]. 
"""


def iterator_a() -> Iterator[Literal[0, 1]]:
    while True:
        yield 0
        yield 1


def iterator_b() -> Iterator[Literal["N", "E", "S", "W"]]:
    while True:
        yield random.choice(["N", "E", "S", "W"])


def iterator_c() -> Iterator[Literal[0, 1, 2, 3, 4, 5, 6]]:
    while True:
        for i in range(7):
            yield i


class Tests(unittest.TestCase):
    def test_a(self):
        it = iterator_a()
        self.assertEqual(next(it), 0)
        self.assertEqual(next(it), 1)
        self.assertEqual(next(it), 0)
        self.assertEqual(next(it), 1)

    def test_b(self):
        it = iterator_b()
        self.assertIn(next(it), ["N", "E", "S", "W"])
        self.assertIn(next(it), ["N", "E", "S", "W"])
        self.assertIn(next(it), ["N", "E", "S", "W"])

    def test_c(self):
        it = iterator_c()
        self.assertEqual(next(it), 0)
        self.assertEqual(next(it), 1)
        self.assertEqual(next(it), 2)
        self.assertEqual(next(it), 3)
        self.assertEqual(next(it), 4)
        self.assertEqual(next(it), 5)
        self.assertEqual(next(it), 6)
        self.assertEqual(next(it), 0)
        self.assertEqual(next(it), 1)
        self.assertEqual(next(it), 2)
        self.assertEqual(next(it), 3)
        self.assertEqual(next(it), 4)
        self.assertEqual(next(it), 5)
        self.assertEqual(next(it), 6)


if __name__ == "__main__":
    unittest.main()

    sys.exit(0)
