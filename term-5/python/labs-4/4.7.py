import sys
import unittest
from typing import Self, Sequence

"""
Mamy daną sekwencję, w której niektóre z elementów mogą okazać się podsekwencjami, a takie zagnieżdżenia mogą się nakładać do nieograniczonej głębokości.
Napisać funkcję flatten(sequence), która zwróci spłaszczoną listę wszystkich elementów sekwencji.
Wskazówka: rozważyć wersję rekurencyjną, a sprawdzanie czy element jest sekwencją, wykonać przez isinstance(item, (list, tuple)).

seq = [1,(2,3),[],[4,(5,6,7)],8,[9]]
print(flatten(seq))   # [1,2,3,4,5,6,7,8,9]
"""


def flatten(sequence: Sequence[int | Sequence]) -> list[int]:
    result = []

    for item in sequence:
        if isinstance(item, Sequence):
            result.extend(flatten(item))
        else:
            result.append(item)

    return result


class Tests(unittest.TestCase):
    def test_flatten(self: Self) -> None:
        self.assertEqual(
            flatten([1, (2, 3), [], [4, (5, 6, 7)], 8, [9]]),
            [1, 2, 3, 4, 5, 6, 7, 8, 9],
        )


if __name__ == "__main__":
    unittest.main()

    sys.exit(0)
