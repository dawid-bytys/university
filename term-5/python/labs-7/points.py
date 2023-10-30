from typing import TypeVar

Point = TypeVar("Point", bound="str")


class Point:
    """Class representing a point in 2D space."""

    def __init__(self, x: float, y: float) -> None:
        self.x = x
        self.y = y

    def __str__(self) -> str:
        return f"({self.x}, {self.y})"

    def __repr__(self) -> str:
        return f"Point({self.x}, {self.y})"

    def __eq__(self, other: Point) -> bool:
        return self.x == other.x and self.y == other.y

    def __ne__(self, other: Point) -> bool:
        return not self == other

    def __add__(self, other: Point) -> Point:
        return Point(self.x + other.x, self.y + other.y)

    def __sub__(self, other: Point) -> Point:
        return Point(self.x - other.x, self.y - other.y)

    def __mul__(self, other: Point) -> float:
        return self.x * other.x + self.y * other.y

    def cross(self, other: Point) -> float:
        return self.x * other.y - self.y * other.x

    def length(self) -> float:
        return (self.x**2 + self.y**2) ** 0.5

    def __hash__(self) -> int:
        return hash((self.x, self.y))
