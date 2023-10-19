import sys
import unittest

# Dla dwóch sekwencji liczb lub znaków znaleźć: (a) listę elementów występujących jednocześnie w obu sekwencjach (bez powtórzeń), (b) listę wszystkich elementów z obu sekwencji (bez powtórzeń).


def strings_intersection(a: str, b: str) -> list[str]:
    if not a or not b:
        return []

    return list(set(a) & set(b))


def strings_union(a: str, b: str) -> list[str]:
    if not a or not b:
        return []

    return list(set(a) | set(b))


class Tests(unittest.TestCase):
    def test_strings_intersection(self):
        self.assertCountEqual(strings_intersection("abc", "abc"), ["a", "b", "c"])
        self.assertCountEqual(strings_intersection("abc", "abcd"), ["a", "b", "c"])

    def test_strings_union(self):
        self.assertCountEqual(strings_union("abc", "abcd"), ["a", "b", "c", "d"])
        self.assertCountEqual(strings_union("abc", "abc"), ["a", "b", "c"])


if __name__ == "__main__":
    unittest.main()

    sys.exit(0)
