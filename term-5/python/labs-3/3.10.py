import sys
import unittest

"""
Stworzyć słownik tłumaczący liczby zapisane w systemie rzymskim (z literami I, V, X, L, C, D, M) na liczby arabskie (podać kilka sposobów tworzenia takiego słownika).
Mile widziany kod tłumaczący całą liczbę [funkcja roman2int()].
"""


def roman_to_int(roman: str) -> int:
    roman_chars = "IVXLCDM"
    arabic_values = [1, 5, 10, 50, 100, 500, 1000]

    roman_dict = dict(zip(roman_chars, arabic_values))

    total = 0
    prev_value = 0

    for numeral in reversed(roman):
        value = roman_dict[numeral]
        if value < prev_value:
            total -= value
        else:
            total += value
        prev_value = value

    return total


class Tests(unittest.TestCase):
    def test_roman_to_int(self) -> None:
        self.assertEqual(roman_to_int("III"), 3)
        self.assertEqual(roman_to_int("IV"), 4)
        self.assertEqual(roman_to_int("IX"), 9)
        self.assertEqual(roman_to_int("LVIII"), 58)
        self.assertEqual(roman_to_int("MCMXCIV"), 1994)


if __name__ == "__main__":
    unittest.main()

    sys.exit(0)
