import re
import sys
import unittest

# Zbudować napis stworzony z pierwszych znaków wyrazów z wiersza line. Zbudować napis stworzony z ostatnich znaków wyrazów z wiersza line.


def text_from_first(text: str) -> str:
    words = re.split(r"\s+", text)
    return "".join([word[0] for word in words])


def text_from_last(text: str) -> str:
    words = re.split(r"\s+", text)
    return "".join([word[-1] for word in words])


class Tests(unittest.TestCase):
    text = "Ala ma kota"

    def test_from_first(self) -> None:
        self.assertEqual(text_from_first(self.text), "Amk")

    def test_from_last(self) -> None:
        self.assertEqual(text_from_last(self.text), "aaa")


if __name__ == "__main__":
    unittest.main()

    sys.exit(0)
