import pytest
from stack import Stack


def test_stack_creation():
    stack = Stack()
    assert stack.is_empty()
    assert not stack.is_full()


def test_push_pop():
    stack = Stack()
    stack.push(1)
    assert not stack.is_empty()
    assert stack.pop() == 1
    assert stack.is_empty()


def test_push_full_stack():
    stack = Stack(max_size=3)
    stack.push(1)
    stack.push(2)
    stack.push(3)
    assert stack.is_full()
    with pytest.raises(IndexError, match="Stack is full"):
        stack.push(4)


def test_pop_empty_stack():
    stack = Stack()
    with pytest.raises(IndexError, match="Stack is empty"):
        stack.pop()


def test_str_representation():
    stack = Stack()
    stack.push(1)
    stack.push(2)
    assert str(stack) == "[1, 2]"


def test_custom_max_size():
    stack = Stack(max_size=2)
    stack.push(1)
    stack.push(2)
    assert stack.is_full()
    with pytest.raises(IndexError, match="Stack is full"):
        stack.push(3)
