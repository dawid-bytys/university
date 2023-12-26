import pytest
from randomqueue import RandomQueue


@pytest.fixture
def random_queue():
    return RandomQueue(max_size=5)


def test_insert(random_queue):
    random_queue.insert(1)
    assert random_queue.items == [1]


def test_remove(random_queue):
    random_queue.insert(1)
    removed_item = random_queue.remove()
    assert removed_item == 1
    assert random_queue.is_empty()


def test_is_empty(random_queue):
    assert random_queue.is_empty()
    random_queue.insert(1)
    assert not random_queue.is_empty()


def test_is_full(random_queue):
    assert not random_queue.is_full()
    for i in range(5):
        random_queue.insert(i)
    assert random_queue.is_full()


def test_clear(random_queue):
    random_queue.insert(1)
    random_queue.clear()
    assert random_queue.is_empty()


def test_insert_full_queue(random_queue):
    for i in range(5):
        random_queue.insert(i)
    with pytest.raises(IndexError):
        random_queue.insert(6)


def test_remove_empty_queue(random_queue):
    with pytest.raises(IndexError):
        random_queue.remove()
