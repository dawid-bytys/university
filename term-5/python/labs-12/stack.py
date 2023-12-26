# Poprawić implementację tablicową stosu tak, aby korzystała z wyjątków w przypadku pojawienia się błędu.
# Metoda pop() ma zgłaszać błąd w przypadku pustego stosu.
# Metoda push() ma zgłaszać błąd w przypadku przepełnienia stosu.
# Napisać kod testujący stos.


class Stack:
    def __init__(self, max_size=None):
        self.items = []
        self.max_size = max_size

    def __str__(self):
        return str(self.items)

    def is_empty(self):
        return not self.items

    def is_full(self):
        return self.max_size is not None and len(self.items) == self.max_size

    def push(self, item):
        if self.max_size is not None and len(self.items) >= self.max_size:
            raise IndexError("Stack is full")

        self.items.append(item)

    def pop(self):
        if self.is_empty():
            raise IndexError("Stack is empty")

        return self.items.pop()
