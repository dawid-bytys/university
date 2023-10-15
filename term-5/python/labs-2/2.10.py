import re
import sys
import unittest

# Mamy dany napis wielowierszowy line. Podać sposób obliczenia liczby wyrazów w napisie. Przez wyraz rozumiemy ciąg "czarnych" znaków, oddzielony od innych wyrazów białymi znakami (spacja, tabulacja, newline).


def count_words(text: str) -> int:
    return len(re.split(r"\s+", text))


class Tests(unittest.TestCase):
    def test_spaces(self) -> None:
        word = "To jest przykładowy tekst ze spacjami."
        self.assertEqual(count_words(word), 6)

    def test_tabs(self) -> None:
        word = "To  jest    tekst   z   tabami."
        self.assertEqual(count_words(word), 5)

    def test_newlines(self) -> None:
        word = """To
        jest
        tekst
        z
        newline."""
        self.assertEqual(count_words(word), 5)

    def test_all(self) -> None:
        word = """To jest   tekst ze
        wszystkimi  delimiterami."""
        self.assertEqual(count_words(word), 6)


if __name__ == "__main__":
    unittest.main()

    sys.exit(0)
