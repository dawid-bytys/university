import random
import sys
import tkinter as tk


class DiceSimulator:
    def __init__(self):
        self.window = tk.Tk()
        self.window.title("Rzut kostką")
        self.window.geometry("500x500")

        self.result_label = tk.Label(self.window, text="-", font=("Arial", 50))
        self.result_label.pack(pady=50)

        self.throw_button = tk.Button(
            self.window, text="Rzuć kostką", command=self.throw_dice
        )
        self.throw_button.pack()

    def throw_dice(self):
        result = random.randint(1, 6)
        self.display_result(result)

    def display_result(self, result):
        self.result_label.config(text=f"Wynik: {result}")

    def main_loop(self):
        self.window.mainloop()


if __name__ == "__main__":
    dice_simulator = DiceSimulator()
    dice_simulator.main_loop()

    sys.exit(0)
