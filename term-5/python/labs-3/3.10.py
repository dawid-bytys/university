import sys
import unittest
import re

"""
Stworzyć słownik tłumaczący liczby zapisane w systemie rzymskim (z literami I, V, X, L, C, D, M) na liczby arabskie (podać kilka sposobów tworzenia takiego słownika).
Mile widziany kod tłumaczący całą liczbę [funkcja roman2int()].
"""


def roman_to_int_dict(roman: str) -> int:
    is_roman_valid = re.match(
        r"^(M{0,3})(CM|CD|D?C{0,3})(XC|XL|L?X{0,3})(IX|IV|V?I{0,3})$", roman
    )

    if not is_roman_valid:
        raise ValueError("Invalid Roman numeral")

    roman_dict = {"I": 1, "V": 5, "X": 10, "L": 50, "C": 100, "D": 500, "M": 1000}

    if roman in roman_dict:
        return roman_dict[roman]

    raise ValueError("Invalid Roman numeral")


def roman_to_int_if(roman: str) -> int:
    is_roman_valid = re.match(
        r"^(M{0,3})(CM|CD|D?C{0,3})(XC|XL|L?X{0,3})(IX|IV|V?I{0,3})$", roman
    )

    if not is_roman_valid:
        raise ValueError("Invalid Roman numeral")

    if roman == "I":
        return 1
    elif roman == "V":
        return 5
    elif roman == "X":
        return 10
    elif roman == "L":
        return 50
    elif roman == "C":
        return 100
    elif roman == "D":
        return 500
    elif roman == "M":
        return 1000

    raise ValueError("Invalid Roman numeral")


def roman_to_int_list(roman: str) -> int:
    is_roman_valid = re.match(
        r"^(M{0,3})(CM|CD|D?C{0,3})(XC|XL|L?X{0,3})(IX|IV|V?I{0,3})$", roman
    )

    if not is_roman_valid:
        raise ValueError("Invalid Roman numeral")

    roman_numerals = ("I", "V", "X", "L", "C", "D", "M")
    values = (1, 5, 10, 50, 100, 500, 1000)

    if roman in roman_numerals:
        return values[roman_numerals.index(roman)]


def roman_to_int(roman: str) -> int:
    is_roman_valid = re.match(
        r"^(M{0,3})(CM|CD|D?C{0,3})(XC|XL|L?X{0,3})(IX|IV|V?I{0,3})$", roman
    )

    if not is_roman_valid:
        raise ValueError("Invalid Roman numeral")

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
        with self.assertRaises(ValueError):
            roman_to_int("IIII")
        with self.assertRaises(ValueError):
            roman_to_int("VV")

    def test_roman_to_int_dict(self) -> None:
        self.assertEqual(roman_to_int_dict("I"), 1)
        self.assertEqual(roman_to_int_dict("V"), 5)
        self.assertEqual(roman_to_int_dict("X"), 10)
        with self.assertRaises(ValueError):
            roman_to_int_dict("IIII")
        with self.assertRaises(ValueError):
            roman_to_int_dict("VV")

    def test_roman_to_int_if(self) -> None:
        self.assertEqual(roman_to_int_if("I"), 1)
        self.assertEqual(roman_to_int_if("V"), 5)
        self.assertEqual(roman_to_int_if("X"), 10)
        with self.assertRaises(ValueError):
            roman_to_int_if("IIII")
        with self.assertRaises(ValueError):
            roman_to_int_if("VV")

    def test_roman_to_int_list(self) -> None:
        self.assertEqual(roman_to_int_list("I"), 1)
        self.assertEqual(roman_to_int_list("V"), 5)
        self.assertEqual(roman_to_int_list("X"), 10)
        with self.assertRaises(ValueError):
            roman_to_int_list("IIII")
        with self.assertRaises(ValueError):
            roman_to_int_list("VV")


if __name__ == "__main__":
    unittest.main()

    sys.exit(0)
