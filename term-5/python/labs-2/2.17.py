import re
import sys
import unittest

# Posortować wyrazy z napisu line raz alfabetycznie, a raz pod względem długości. Wskazówka: funkcja wbudowana sorted().


def sort_words_alphabetically(text: str) -> str:
    words = re.split(r"\s+", text)
    return " ".join(sorted(words, key=lambda x: x.lower()))


def sort_words_by_length(text: str) -> str:
    words = re.split(r"\s+", text)
    return " ".join(sorted(words, key=len, reverse=True))


class Tests(unittest.TestCase):
    line = "To jest przykładowy tekst"

    def test_sort_alphabetically(self) -> None:
        self.assertEqual(
            sort_words_alphabetically(self.line), "jest przykładowy tekst To"
        )

    def test_sort_by_length(self) -> None:
        self.assertEqual(sort_words_by_length(self.line), "przykładowy tekst jest To")


if __name__ == "__main__":
    unittest.main()

    sys.exit(0)
