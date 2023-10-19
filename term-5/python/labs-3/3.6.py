import sys
import unittest

"""
Napisać program rysujący prostokąt zbudowany z małych kratek. Należy zbudować pełny string, a potem go wypisać. Przykładowy prostokąt składający się 2x4 pól ma postać:

+---+---+---+---+
|   |   |   |   |
+---+---+---+---+
|   |   |   |   | 
+---+---+---+---+

"""


def create_grid(cols: int, rows: int) -> None:
    if cols < 1 or rows < 1:
        raise ValueError("Cols and rows values must be greater than zero.")

    result = "+---" * cols + "+\n"

    for _ in range(rows):
        result += "|   " * cols + "|\n"
        result += "+---" * cols + "+\n"

    return result.strip()


class Tests(unittest.TestCase):
    def test_create_grid(self):
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
        self.assertEqual(create_grid(4, 2), result)


if __name__ == "__main__":
    unittest.main()

    sys.exit(0)
