import sys
import unittest
from typing import Self, Sequence

"""
Napisać funkcję sum_seq(sequence) obliczającą sumę liczb zawartych w sekwencji, która może zawierać zagnieżdżone podsekwencje.
Wskazówka: rozważyć wersję rekurencyjną, a sprawdzanie, czy element jest sekwencją, wykonać przez isinstance(item, (list, tuple)).
"""


def sum_seq(sequence: Sequence[int | Sequence]) -> int:
    result = 0

    for item in sequence:
        if isinstance(item, Sequence):
            result += sum_seq(item)
        else:
            result += item

    return result


class Tests(unittest.TestCase):
    def test_sum_seq(self: Self) -> None:
        self.assertEqual(sum_seq([1, 2, 3, 4, 5]), 15)
        self.assertEqual(sum_seq((1, 2, 3, 4, 5)), 15)
        self.assertEqual(sum_seq([1, (2, 3), [], [4, (5, 6, 7)], 8, [9]]), 45)


if __name__ == "__main__":
    unittest.main()

    sys.exit(0)
