import sys

"""
Napisać program pobierający w pętli od użytkownika liczbę rzeczywistą x (typ float) i wypisujący x oraz trzecią potęgę x.
Zatrzymanie programu następuje po wpisaniu z klawiatury stop.
Jeżeli użytkownik wpisze napis zamiast liczby, to program ma wypisać komunikat o błędzie i kontynuować pracę.
"""


if __name__ == "__main__":
    while True:
        user_input = input("Enter a real number (or 'stop' to end): ")

        if user_input.lower() == "stop":
            break

        try:
            x = float(user_input)
            x_cubed = x**3
            print(f"{x}^3 = {x_cubed}")
        except ValueError:
            print("Error: The entered value is not a real number. Try again.")

    sys.exit(0)
