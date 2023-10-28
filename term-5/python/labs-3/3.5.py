import sys

"""
Napisać program rysujący "miarkę" o zadanej długości.
Należy prawidłowo obsłużyć liczby składające się z kilku cyfr (ostatnia cyfra liczby ma znajdować się pod znakiem kreski pionowej).
Należy zbudować pełny string, a potem go wypisać.
"""


def draw_ruler(length: int) -> tuple[str, str]:
    ruler = "|"
    numbers = "0"

    for i in range(1, length + 1):
        ruler += "....|"
        i_len = len(str(i))
        numbers += " " * (5 - i_len) + str(i)

    print(ruler)
    print(numbers)


if __name__ == "__main__":
    length = int(input("Enter the length of the ruler: "))
    draw_ruler(length)

    sys.exit(0)
