import sys
import unittest

"""
Napisać funkcję odwracanie(L, left, right) odwracającą kolejność elementów na liście od numeru left do right włącznie.
Lista jest modyfikowana w miejscu (in place).
Rozważyć wersję iteracyjną i rekurencyjną.
"""


def reverse_iterative(L: list, left: int, right: int) -> None:
    if left < 0 or right >= len(L):
        raise ValueError("Left and right values must be greater than zero.")

    while left < right:
        L[left], L[right] = L[right], L[left]
        left += 1
        right -= 1


def reverse_recursive(L: list, left: int, right: int) -> None:
    if left < 0 or right >= len(L):
        raise ValueError("Left and right values must be greater than zero.")

    if left < right:
        L[left], L[right] = L[right], L[left]
        reverse_recursive(L, left + 1, right - 1)


class Tests(unittest.TestCase):
    def test_reverse_iterative(self) -> None:
        L = [1, 2, 3, 4, 5]
        reverse_iterative(L, 0, 4)
        self.assertEqual(L, [5, 4, 3, 2, 1])

    def test_reverse_iterative_one_element(self) -> None:
        L = [1]
        reverse_iterative(L, 0, 0)
        self.assertEqual(L, [1])

    def test_reverse_iterative_negative(self) -> None:
        with self.assertRaises(ValueError):
            L = [1, 2, 3, 4, 5]
            reverse_iterative(L, 0, 5)

    def test_reverse_recursive(self) -> None:
        L = [1, 2, 3, 4, 5]
        reverse_recursive(L, 0, 4)
        self.assertEqual(L, [5, 4, 3, 2, 1])

    def test_reverse_recursive_one_element(self) -> None:
        L = [1]
        reverse_recursive(L, 0, 0)
        self.assertEqual(L, [1])

    def test_reverse_recursive_negative(self) -> None:
        with self.assertRaises(ValueError):
            L = [1, 2, 3, 4, 5]
            reverse_recursive(L, 0, 5)


if __name__ == "__main__":
    unittest.main()

    sys.exit(0)
