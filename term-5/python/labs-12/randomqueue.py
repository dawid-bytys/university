import random

# Stworzyć ADT w postaci kolejki losowej, z której elementy będą pobierane w losowej kolejności.
# Zadbać o to, aby każda operacja była wykonywana w stałym czasie, niezależnie od liczby elementów w kolejce.


class RandomQueue:
    def __init__(self, max_size=None):
        self.items = []
        self.max_size = max_size

    def insert(self, item):
        if self.max_size is not None and len(self.items) >= self.max_size:
            raise IndexError("Queue is full")

        self.items.append(item)

    def remove(self):
        if self.is_empty():
            raise IndexError("Queue is empty")

        return self.items.pop(random.randint(0, len(self.items) - 1))

    def is_empty(self):
        return len(self.items) == 0

    def is_full(self):
        return self.max_size is not None and len(self.items) == self.max_size

    def clear(self):
        self.items = []
