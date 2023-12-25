import pytest
from singlelist import (
    Node,
    SingleList,
)


# Test cases for Node class
def test_node_creation():
    node = Node(1)
    assert node.data == 1
    assert node.next is None


def test_node_equality():
    node1 = Node(1)
    node2 = Node(1)
    node3 = Node(2)

    assert node1 == node2
    assert node1 != node3


# Test cases for SingleList class
def test_empty_list():
    slist = SingleList()
    assert slist.is_empty()
    assert slist.count() == 0


def test_insert_head():
    slist = SingleList()
    node1 = Node(1)
    node2 = Node(2)

    slist.insert_head(node1)
    assert not slist.is_empty()
    assert slist.head == node1
    assert slist.tail == node1
    assert slist.count() == 1

    slist.insert_head(node2)
    assert slist.head == node2
    assert slist.tail == node1
    assert slist.head.next == node1
    assert slist.count() == 2


def test_insert_tail():
    slist = SingleList()
    node1 = Node(1)
    node2 = Node(2)

    slist.insert_tail(node1)
    assert not slist.is_empty()
    assert slist.head == node1
    assert slist.tail == node1
    assert slist.count() == 1

    slist.insert_tail(node2)
    assert slist.head == node1
    assert slist.tail == node2
    assert slist.head.next == node2
    assert slist.count() == 2


def test_remove_head():
    slist = SingleList()
    node1 = Node(1)
    node2 = Node(2)

    slist.insert_head(node1)
    slist.insert_head(node2)

    removed_node = slist.remove_head()
    assert removed_node == node2
    assert slist.head == node1
    assert slist.tail == node1
    assert slist.count() == 1


def test_remove_tail():
    slist = SingleList()
    node1 = Node(1)
    node2 = Node(2)

    slist.insert_head(node1)
    slist.insert_head(node2)

    removed_node = slist.remove_tail()
    assert removed_node == node1
    assert slist.head == node2
    assert slist.tail == node2
    assert slist.count() == 1


def test_join_lists():
    slist1 = SingleList()
    slist2 = SingleList()

    node1 = Node(1)
    node2 = Node(2)

    slist1.insert_head(node1)
    slist2.insert_head(node2)

    slist1.join(slist2)

    assert slist1.head == node1
    assert slist1.tail == node2
    assert slist1.count() == 2


def test_clear_list():
    slist = SingleList()
    node1 = Node(1)
    node2 = Node(2)

    slist.insert_head(node1)
    slist.insert_head(node2)

    slist.clear()

    assert slist.is_empty()
    assert slist.count() == 0
    assert slist.head is None
    assert slist.tail is None
