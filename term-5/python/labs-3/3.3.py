import sys

"""
Wypisać w pętli liczby od 0 do 30 z wyjątkiem liczb podzielnych przez 3.
"""


if __name__ == "__main__":
    for x in range(0, 31):
        if x % 3 != 0:
            print(x)

    sys.exit(0)
