import sys
import unittest
from typing import Sequence

# Mamy daną listę sekwencji (listy lub krotki) różnej długości zawierających liczby. Znaleźć listę zawierającą sumy liczb z tych sekwencji. Przykładowa sekwencja [[],[4],(1,2),[3,4],(5,6,7)], spodziewany wynik [0,4,3,7,18].


def sum_sequences(seqs: Sequence[Sequence[int]]) -> int:
    return [sum(seq) for seq in seqs]


class Tests(unittest.TestCase):
    def test_sum_sequences(self):
        self.assertEqual(
            sum_sequences([[], [4], (1, 2), [3, 4], (5, 6, 7)]), [0, 4, 3, 7, 18]
        )
        self.assertEqual(sum_sequences([(1, 2, 3), (4, 5)]), [6, 9])

    def test_empty_sequence(self):
        self.assertEqual(sum_sequences([]), [])


if __name__ == "__main__":
    unittest.main()

    sys.exit(0)
