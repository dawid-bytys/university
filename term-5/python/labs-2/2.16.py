import sys
import unittest

# W tekście znajdującym się w zmiennej line zamienić ciąg znaków "GvR" na "Guido van Rossum".


def replace_text(text: str, what_to_replace: str, replace_with: str) -> str:
    return text.replace(what_to_replace, replace_with)


class Tests(unittest.TestCase):
    def test_replace_gvr(self) -> None:
        line = "GvR"
        self.assertEqual(
            replace_text(line, "GvR", "Guido van Rossum"), "Guido van Rossum"
        )


if __name__ == "__main__":
    unittest.main()

    sys.exit(0)
