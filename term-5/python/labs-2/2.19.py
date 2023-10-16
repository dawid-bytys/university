import sys
import unittest

# Na liście L mamy liczby jedno-, dwu- i trzycyfrowe dodatnie. Chcemy zbudować napis z trzycyfrowych bloków, gdzie liczby jedno- i dwucyfrowe będą miały blok dopełniony zerami, np. 007, 024. Wskazówka: str.zfill().


def create_blocks(some_list: list[int]) -> str:
    return " ".join([str(number).zfill(3) for number in some_list])


class Tests(unittest.TestCase):
    def test_valid_list(self) -> None:
        self.assertEqual(create_blocks([12, 123, 1]), "012 123 001")

    def test_empty_list(self) -> None:
        self.assertEqual(create_blocks([]), "")


if __name__ == "__main__":
    unittest.main()

    sys.exit(0)
