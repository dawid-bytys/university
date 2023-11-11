import sys
import unittest
from typing import Self

"""
Rozwiązania zadań 3.5 i 3.6 z poprzedniego zestawu zapisać w postaci funkcji, które zwracają pełny string przez return.
Funkcje nie powinny pytać użytkownika o dane, tylko korzystać z argumentów.
"""


def make_ruler(length: int) -> str:
    ruler = "|"
    numbers = "0"

    for i in range(1, length + 1):
        ruler += "....|"
        i_len = len(str(i))
        numbers += " " * (5 - i_len) + str(i)

    ruler += "\n" + numbers

    return ruler


def make_grid(cols: int, rows: int) -> str:
    if cols < 1 or rows < 1:
        raise ValueError("Cols and rows values must be greater than zero.")

    result = "+---" * cols + "+\n"

    for _ in range(rows):
        result += "|   " * cols + "|\n"
        result += "+---" * cols + "+\n"

    return result.strip()


class Tests(unittest.TestCase):
    def test_make_grid(self: Self) -> None:
        result = (
            "+---+---+---+---+"
            + "\n"
            + "|   |   |   |   |"
            + "\n"
            + "+---+---+---+---+"
            + "\n"
            + "|   |   |   |   |"
            + "\n"
            + "+---+---+---+---+"
        )
        self.assertEqual(make_grid(4, 2), result)

    def test_make_ruler_one_digit(self: Self) -> None:
        result = "|....|....|....|" + "\n" + "0    1    2    3"
        self.assertEqual(make_ruler(3), result)

    def test_make_ruler_two_digits(self: Self) -> None:
        result = (
            "|....|....|....|....|....|....|....|....|....|....|"
            + "\n"
            + "0    1    2    3    4    5    6    7    8    9   10"
        )
        self.assertEqual(make_ruler(10), result)


if __name__ == "__main__":
    unittest.main()

    sys.exit(0)
