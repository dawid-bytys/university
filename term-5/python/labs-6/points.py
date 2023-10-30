import sys
import unittest
from typing import Self

"""
W pliku points.py zdefiniować klasę Point wraz z potrzebnymi metodami.
Punkty są traktowane jak wektory zaczepione w początku układu współrzędnych, o końcu w położeniu (x, y).
Napisać kod testujący moduł points.
"""


class Point:
    """Class representing a point in 2D space."""

    def __init__(self: Self, x: float, y: float) -> None:
        self.x = x
        self.y = y

    def __str__(self: Self) -> str:
        return f"({self.x}, {self.y})"

    def __repr__(self: Self) -> str:
        return f"Point({self.x}, {self.y})"

    def __eq__(self: Self, other: object) -> bool:
        if not isinstance(other, Point):
            return False

        return self.x == other.x and self.y == other.y

    def __ne__(self: Self, other: object) -> bool:
        return not self == other

    def __add__(self: Self, other: Self) -> Self:
        return Point(self.x + other.x, self.y + other.y)  # type: ignore

    def __sub__(self: Self, other: Self) -> Self:
        return Point(self.x - other.x, self.y - other.y)  # type: ignore

    def __mul__(self: Self, other: Self) -> float:
        return self.x * other.x + self.y * other.y

    def __hash__(self: Self) -> int:
        return hash((self.x, self.y))

    def cross(self: Self, other: Self) -> float:
        return self.x * other.y - self.y * other.x

    def length(self: Self) -> float:
        return (self.x**2 + self.y**2) ** 0.5


class Tests(unittest.TestCase):
    def setUp(self: Self) -> None:
        self.p1 = Point(1, 2)
        self.p2 = Point(3, 4)
        self.p3 = Point(1, 2)

    def test_str(self: Self) -> None:
        self.assertEqual(str(self.p1), "(1, 2)")

    def test_repr(self: Self) -> None:
        self.assertEqual(repr(self.p1), "Point(1, 2)")

    def test_eq(self: Self) -> None:
        self.assertTrue(self.p1 == self.p3)

    def test_ne(self: Self) -> None:
        self.assertTrue(self.p1 != self.p2)

    def test_add(self: Self) -> None:
        self.assertEqual(self.p1 + self.p2, Point(4, 6))

    def test_sub(self: Self) -> None:
        self.assertEqual(self.p1 - self.p2, Point(-2, -2))

    def test_mul(self: Self) -> None:
        self.assertEqual(self.p1 * self.p2, 11)

    def test_cross(self: Self) -> None:
        self.assertEqual(self.p1.cross(self.p2), -2)

    def test_length(self: Self) -> None:
        self.assertEqual(self.p1.length(), 5**0.5)

    def test_hash(self: Self) -> None:
        self.assertEqual(hash(self.p1), hash(self.p3))

    def tearDown(self: Self) -> None:
        del self.p1
        del self.p2
        del self.p3


if __name__ == "__main__":
    unittest.main()

    sys.exit(0)
