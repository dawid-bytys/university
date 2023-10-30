import sys
import unittest
from typing import Self

from points import Point

"""
W pliku rectangles.py zdefiniować klasę Rectangle wraz z potrzebnymi metodami.
Prostokąt jest określony przez podanie dwóch wierzchołków, lewego dolnego i prawego górnego.
Napisać kod testujący moduł rectangles. 
"""


class Rectangle:
    """Class representing a rectangle in 2D space."""

    def __init__(self: Self, x1: float, y1: float, x2: float, y2: float) -> None:
        self.pt1 = Point(x1, y1)
        self.pt2 = Point(x2, y2)

    def __str__(self: Self) -> str:
        return f"[({self.pt1.x}, {self.pt1.y}), ({self.pt2.x}, {self.pt2.y})]"

    def __repr__(self: Self) -> str:
        return f"Rectangle({self.pt1.x}, {self.pt1.y}, {self.pt2.x}, {self.pt2.y})"

    def __eq__(self: Self, other: object) -> bool:
        if not isinstance(other, Rectangle):
            return False

        return self.pt1 == other.pt1 and self.pt2 == other.pt2

    def __ne__(self: Self, other: object) -> bool:
        return not self == other

    def center(self: Self) -> Point:
        return Point((self.pt1.x + self.pt2.x) / 2, (self.pt1.y + self.pt2.y) / 2)

    def area(self: Self) -> float:
        return (self.pt2.x - self.pt1.x) * (self.pt2.y - self.pt1.y)

    def move(self: Self, x: int, y: int) -> None:
        self.pt1.x += x
        self.pt1.y += y
        self.pt2.x += x
        self.pt2.y += y


class Tests(unittest.TestCase):
    def setUp(self) -> None:
        self.r1 = Rectangle(1, 2, 3, 4)
        self.r2 = Rectangle(1, 2, 3, 4)
        self.r3 = Rectangle(1, 2, 3, 5)

    def test_str(self) -> None:
        self.assertEqual(str(self.r1), "[(1, 2), (3, 4)]")

    def test_repr(self) -> None:
        self.assertEqual(repr(self.r1), "Rectangle(1, 2, 3, 4)")

    def test_eq(self) -> None:
        self.assertEqual(self.r1, self.r2)
        self.assertNotEqual(self.r1, self.r3)

    def test_center(self) -> None:
        self.assertEqual(self.r1.center(), Point(2, 3))

    def test_area(self) -> None:
        self.assertEqual(self.r1.area(), 4)

    def test_move(self) -> None:
        self.r1.move(1, 1)
        self.assertEqual(self.r1, Rectangle(2, 3, 4, 5))

    def tearDown(self) -> None:
        del self.r1
        del self.r2
        del self.r3


if __name__ == "__main__":
    unittest.main()

    sys.exit(0)
