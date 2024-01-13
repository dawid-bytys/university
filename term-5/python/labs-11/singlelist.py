class Node:
    def __init__(self, data=None, next=None):
        self.data = data
        self.next = next

    def __str__(self):
        return str(self.data)

    def __eq__(self, other):
        return self.data == other.data

    def __ne__(self, other):
        return not self == other


class SingleList:
    def __init__(self):
        self.head = None
        self.tail = None
        self.length = 0

    def is_empty(self):
        return self.head is None

    def count(self):
        return self.length

    def insert_head(self, node):
        if self.head:
            node.next = self.head
            self.head = node
        else:
            self.head = self.tail = node

        self.length += 1

    def insert_tail(self, node):
        if self.tail:
            self.tail.next = node
            self.tail = node
        else:
            self.head = self.tail = node

        self.length += 1

    def remove_head(self):
        if self.is_empty():
            raise ValueError("List is empty")

        node = self.head

        if self.head == self.tail:
            self.head = self.tail = None
        else:
            self.head = self.head.next

        self.length -= 1
        node.next = None
        return node

    def remove_tail(self):
        if self.is_empty():
            raise ValueError("List is empty")

        node = self.tail

        if self.head == self.tail:
            self.head = self.tail = None
        else:
            current = self.head
            while current.next != self.tail:
                current = current.next

            self.tail = current
            self.tail.next = None

        self.length -= 1
        return node

    def join(self, other):
        if self.head:
            self.tail.next = other.head
            self.tail = other.tail
        else:
            self.head = other.head
            self.tail = other.tail

        self.length += other.length
        other.clear()

    def clear(self):
        self.head = self.tail = None
        self.length = 0
