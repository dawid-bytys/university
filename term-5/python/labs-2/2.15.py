import sys
import unittest

# Na liście L znajdują się liczby całkowite dodatnie. Stworzyć napis będący ciągiem cyfr kolejnych liczb z listy L.


def create_text_from_list(list: list) -> str:
    return "".join([str(element) for element in list])


class Tests(unittest.TestCase):
    def test_complete_list(self) -> None:
        example_list = [1, 12, 13, 32]
        self.assertEqual(create_text_from_list(example_list), "1121332")

    def test_empty_list(self) -> None:
        empty_list = []
        self.assertEqual(create_text_from_list(empty_list), "")


if __name__ == "__main__":
    unittest.main()

    sys.exit(0)
