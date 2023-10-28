import re
import sys
import unittest

# Znaleźć łączną długość wyrazów w napisie line. Wskazówka: można skorzystać z funkcji sum().


def count_total_words_length(text: str) -> int:
    words = re.split(r"\s+", text)
    return sum([len(word) for word in words])


class Tests(unittest.TestCase):
    def test_string(self) -> None:
        self.assertEqual(count_total_words_length("Ala ma kota"), 9)

    def test_empty_string(self) -> None:
        self.assertEqual(count_total_words_length(""), 0)

    def test_one_word(self) -> None:
        self.assertEqual(count_total_words_length("kot"), 3)


if __name__ == "__main__":
    unittest.main()

    sys.exit(0)
