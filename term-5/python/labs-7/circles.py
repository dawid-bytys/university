import math
import sys
import unittest
from typing import TypeVar

from points import Point

Circle = TypeVar("Circle", bound="str")


class Circle:
    """Class representing a circle in 2D space."""

    def __init__(self, x: float, y: float, radius: float) -> None:
        if radius < 0:
            raise ValueError("Radius must be non-negative.")

        self.pt = Point(x, y)
        self.radius = radius

    def __repr__(self) -> str:
        return f"Circle({self.pt.x}, {self.pt.y}, {self.radius})"

    def __eq__(self, other: Circle) -> bool:
        return self.pt == other.pt and self.radius == other.radius

    def __ne__(self, other: Circle) -> bool:
        return not self == other

    def area(self) -> float:
        return self.radius**2 * math.pi

    def move(self, x: float, y: float) -> None:
        self.pt = Point(x, y)

    def cover(self, other: Circle) -> "Circle":
        d = self.pt - other.pt
        dist = d.length()

        if dist + other.radius <= self.radius:
            return self
        if dist + self.radius <= other.radius:
            return other

        r = (dist + self.radius + other.radius) / 2
        x = self.pt.x + d.x * (r - self.radius) / dist
        y = self.pt.y + d.y * (r - self.radius) / dist

        return Circle(x, y, r)


class Tests(unittest.TestCase):
    def test_repr(self) -> None:
        self.assertEqual(repr(Circle(1, 2, 3)), "Circle(1, 2, 3)")

    def test_eq(self) -> None:
        self.assertEqual(Circle(1, 2, 3), Circle(1, 2, 3))
        self.assertNotEqual(Circle(1, 2, 3), Circle(1, 2, 4))
        self.assertNotEqual(Circle(1, 2, 3), Circle(1, 3, 3))
        self.assertNotEqual(Circle(1, 2, 3), Circle(2, 2, 3))

    def test_area(self) -> None:
        self.assertEqual(Circle(0, 0, 1).area(), math.pi)
        self.assertEqual(Circle(0, 0, 2).area(), 4 * math.pi)
        self.assertEqual(Circle(0, 0, 3).area(), 9 * math.pi)

    def test_move(self) -> None:
        c = Circle(1, 2, 3)
        c.move(4, 5)
        self.assertEqual(c, Circle(4, 5, 3))

    def test_cover(self) -> None:
        self.assertEqual(Circle(0, 0, 1).cover(Circle(0, 0, 2)), Circle(0, 0, 2))
        self.assertEqual(Circle(0, 0, 2).cover(Circle(0, 0, 1)), Circle(0, 0, 2))
        self.assertEqual(Circle(0, 0, 1).cover(Circle(3, 0, 1)), Circle(1.5, 0, 2.5))
        self.assertEqual(Circle(0, 0, 1).cover(Circle(3, 0, 2)), Circle(1.5, 0, 3.5))
        self.assertEqual(Circle(0, 0, 1).cover(Circle(3, 0, 3)), Circle(1.5, 0, 4.5))
        self.assertEqual(Circle(0, 0, 1).cover(Circle(3, 0, 4)), Circle(1.5, 0, 4.5))
        self.assertEqual(Circle(0, 0, 1).cover(Circle(3, 0, 5)), Circle(1.5, 0, 5.5))


if __name__ == "__main__":
    unittest.main()

    sys.exit(0)
