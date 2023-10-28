import math
import sys
import unittest

"""
Stworzyć plik fracs.py i zapisać w nim funkcje do działań na ułamkach.
Ułamek będzie reprezentowany przez listę dwóch liczb całkowitych [licznik, mianownik].
Napisać kod testujący moduł fracs. Nie należy korzystać z klasy Fraction z modułu fractions.
Można wykorzystać funkcję fractions.gcd() implementującą algorytm Euklidesa. 
"""


def signum(x: int) -> int:
    """
    Function which returns sign of number

    :param x: number
    :return: sign of number
    """

    if x < 0:
        return -1
    elif x > 0:
        return 1

    return 0


def simplify_frac(frac: list[int, int]) -> list[int, int]:
    """
    Function which simplifies fraction

    :param frac: fraction
    :return: simplified fraction
    """

    gcd = math.gcd(frac[0], frac[1])
    sign = signum(frac[0] * frac[1])

    return [sign * abs(frac[0]) // gcd, abs(frac[1]) // gcd]


def add_fracs(
    first_frac: list[int, int], second_frac: list[int, int]
) -> list[int, int]:
    """
    Function which adds two fractions

    :param first_frac: first fraction
    :param second_frac: second fraction
    :return: sum of two fractions
    """

    nominator = first_frac[0] * second_frac[1] + second_frac[0] * first_frac[1]
    denominator = first_frac[1] * second_frac[1]

    return simplify_frac([nominator, denominator])


def sub_fracs(
    first_frac: list[int, int], second_frac: list[int, int]
) -> list[int, int]:
    """
    Function which subtracts two fractions

    :param first_frac: first fraction
    :param second_frac: second fraction
    :return: difference of two fractions
    """

    nominator = first_frac[0] * second_frac[1] - second_frac[0] * first_frac[1]
    denominator = first_frac[1] * second_frac[1]

    return simplify_frac([nominator, denominator])


def mul_fracs(
    first_frac: list[int, int], second_frac: list[int, int]
) -> list[int, int]:
    """
    Function which multiplies two fractions

    :param first_frac: first fraction
    :param second_frac: second fraction
    :return: product of two fractions
    """

    nominator = first_frac[0] * second_frac[0]
    denominator = first_frac[1] * second_frac[1]

    return simplify_frac([nominator, denominator])


def div_fracs(
    first_frac: list[int, int], second_frac: list[int, int]
) -> list[int, int]:
    """
    Function which divides two fractions

    :param first_frac: first fraction
    :param second_frac: second fraction
    :return: quotient of two fractions
    """

    nominator = first_frac[0] * second_frac[1]
    denominator = first_frac[1] * second_frac[0]

    return simplify_frac([nominator, denominator])


def is_positive(frac: list[int, int]) -> bool:
    """
    Function which checks if fraction is positive

    :param frac: fraction
    :return: True if fraction is positive, False otherwise
    """

    return frac[0] * frac[1] > 0


def is_zero(frac: list[int, int]) -> bool:
    """
    Function which checks if fraction is equal to zero

    :param frac: fraction
    :return: True if fraction is equal to zero, False otherwise
    """

    return frac[0] == 0


def cmp_fracs(first_frac: list[int, int], second_frac: list[int, int]) -> int:
    """
    Function which compares two fractions

    :param first_frac: first fraction
    :param second_frac: second fraction
    :return: 0 if fractions are equal, 1 if first fraction is greater than second, -1 otherwise
    """

    first_frac = simplify_frac(first_frac)
    second_frac = simplify_frac(second_frac)

    if first_frac[0] == second_frac[0] and first_frac[1] == second_frac[1]:
        return 0

    if frac_to_float(first_frac) > frac_to_float(second_frac):
        return 1

    return -1


def frac_to_float(frac: list[int, int]) -> float:
    """
    Function which converts fraction to float

    :param frac: fraction
    :return: float representation of fraction
    """

    return frac[0] / frac[1]


class Tests(unittest.TestCase):
    def setUp(self) -> None:
        self.zero = [0, 1]
        self.one = [1, 1]
        self.minus_one = [-1, 1]

    def test_add_fracs(self) -> None:
        self.assertEqual(add_fracs([1, 2], [1, 3]), [5, 6])
        self.assertEqual(add_fracs([1, 2], [1, 2]), self.one)
        self.assertEqual(add_fracs([-1, 2], [1, 2]), self.zero)
        self.assertEqual(add_fracs([1, 2], [-1, 2]), self.zero)
        self.assertEqual(add_fracs([1, -2], [1, 2]), self.zero)
        self.assertEqual(add_fracs([3, 4], [10, 20]), [5, 4])

    def test_sub_fracs(self) -> None:
        self.assertEqual(sub_fracs([1, 2], [1, 3]), [1, 6])
        self.assertEqual(sub_fracs([1, 2], [1, 2]), self.zero)
        self.assertEqual(sub_fracs([-1, 2], [1, 2]), self.minus_one)
        self.assertEqual(sub_fracs([1, 2], [-1, 2]), self.one)
        self.assertEqual(sub_fracs([1, -2], [1, 2]), self.minus_one)

    def test_mul_fracs(self) -> None:
        self.assertEqual(mul_fracs([1, 2], [1, 3]), [1, 6])
        self.assertEqual(mul_fracs([1, 2], [1, 2]), [1, 4])
        self.assertEqual(mul_fracs([-1, 2], [1, 2]), [-1, 4])
        self.assertEqual(mul_fracs([1, 2], [-1, 2]), [-1, 4])
        self.assertEqual(mul_fracs([1, -2], [1, 2]), [-1, 4])

    def test_div_fracs(self) -> None:
        self.assertEqual(div_fracs([1, 2], [1, 3]), [3, 2])
        self.assertEqual(div_fracs([1, 2], [1, 2]), self.one)
        self.assertEqual(div_fracs([-1, 2], [1, 2]), self.minus_one)
        self.assertEqual(div_fracs([1, 2], [-1, 2]), self.minus_one)
        self.assertEqual(div_fracs([1, -2], [1, 2]), self.minus_one)

    def test_is_positive(self) -> None:
        self.assertTrue(is_positive([1, 2]))
        self.assertFalse(is_positive([-1, 2]))
        self.assertFalse(is_positive([1, -2]))

    def test_is_zero(self) -> None:
        self.assertTrue(is_zero([0, 2]))
        self.assertFalse(is_zero([1, 2]))
        self.assertFalse(is_zero([-1, 2]))

    def test_cmp_fracs(self) -> None:
        self.assertEqual(cmp_fracs([1, 2], [1, 3]), 1)
        self.assertEqual(cmp_fracs([1, 2], [1, 2]), 0)
        self.assertEqual(cmp_fracs([-1, 2], [1, 2]), -1)
        self.assertEqual(cmp_fracs([1, 2], [-1, 2]), 1)
        self.assertEqual(cmp_fracs([1, -2], [1, 2]), -1)

    def test_frac_to_float(self) -> None:
        self.assertEqual(frac_to_float([1, 2]), 0.5)
        self.assertEqual(frac_to_float([1, 3]), 1 / 3)
        self.assertEqual(frac_to_float([1, 4]), 0.25)
        self.assertEqual(frac_to_float([1, 5]), 0.2)
        self.assertEqual(frac_to_float([1, 6]), 1 / 6)

    def tearDown(self) -> None:
        del self.zero
        del self.one
        del self.minus_one


if __name__ == "__main__":
    unittest.main()

    sys.exit(0)
