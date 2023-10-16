import sys

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
