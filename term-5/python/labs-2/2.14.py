import re
import sys
import unittest
from functools import reduce

# Znaleźć: (a) najdłuższy wyraz, (b) długość najdłuższego wyrazu w napisie line.


def find_longest_word(text: str) -> str:
    words = re.split(r"\s+", text)
    return reduce(lambda x, y: x if len(x) > len(y) else y, words)


def longest_word_length(text: str) -> int:
    words = re.split(r"\s+", text)
    return len(reduce(lambda x, y: x if len(x) > len(y) else y, words))


class Tests(unittest.TestCase):
    text = "Jest to przykładowy tekst do testu"

    def test_find_longest_word(self) -> None:
        self.assertEqual(find_longest_word(self.text), "przykładowy")

    def test_longest_word_length(self) -> None:
        self.assertEqual(longest_word_length(self.text), 11)


if __name__ == "__main__":
    unittest.main()

    sys.exit(0)
