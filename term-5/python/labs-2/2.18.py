import sys
import unittest

# Znaleźć liczbę cyfr zero w dużej liczbie całkowitej. Wskazówka: zamienić liczbę na napis.


def count_zeros_in_text(text: str) -> int:
    return str(text).count("0")


class Tests(unittest.TestCase):
    def test_valid_text(self) -> None:
        self.assertEqual(count_zeros_in_text("10000000"), 7)

    def test_empty_text(self) -> None:
        self.assertEqual(count_zeros_in_text(""), 0)


if __name__ == "__main__":
    unittest.main()

    sys.exit(0)
