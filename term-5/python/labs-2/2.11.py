import sys
import unittest

# Podać sposób wyświetlania napisu word tak, aby jego znaki były rozdzielone znakiem podkreślenia.


def add_delimiter(text: str, delimiter: str) -> str:
    return delimiter.join(text)


class Tests(unittest.TestCase):
    def test_word_with_underscores(self) -> None:
        word = "example"
        self.assertEqual(add_delimiter(word, "_"), "e_x_a_m_p_l_e")

    def test_empty_word(self) -> None:
        word = ""
        self.assertEqual(add_delimiter(word, "_"), "")

    def test_single_character_word(self) -> None:
        word = "A"
        self.assertEqual(add_delimiter(word, "_"), "A")


if __name__ == "__main__":
    unittest.main()

    sys.exit(0)
