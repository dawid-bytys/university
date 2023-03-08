#ifndef MY_PRIORITY_QUEUE_HPP
#define MY_PRIORITY_QUEUE_HPP

#include <forward_list>
#include <iostream>

// Priority queue implemented as a linked list
template <typename T>
class MyPriorityQueue {
 private:
  std::forward_list<T> lst;
  size_t capacity;

 public:
  // default constructor
  MyPriorityQueue(const size_t size = 10);

  // destructor
  ~MyPriorityQueue();

  // copy constructor
  MyPriorityQueue(const MyPriorityQueue& other);

  // move constructor
  MyPriorityQueue(MyPriorityQueue&& other);

  // copy assignment operator
  MyPriorityQueue& operator=(const MyPriorityQueue& other);

  // move assignment operator
  MyPriorityQueue& operator=(MyPriorityQueue&& other);

  // checks if the queue is empty
  bool empty() const;

  // returns the number of elements in the queue
  size_t size() const;

  // adds an element to the queue / O(n)
  void enqueue(const T& item);

  // adds an element to the queue / O(n)
  void enqueue(T&& item);

  // returns the element with the highest priority / O(1)
  T& top();

  // removes the element with the highest priority / O(1)
  void dequeue();

  // removes all elements from the queue
  void clear();

  // prints the elements of the queue
  void display();
};

template <typename T>
MyPriorityQueue<T>::MyPriorityQueue(const size_t size) {
  capacity = size;
}

template <typename T>
MyPriorityQueue<T>::~MyPriorityQueue() {
  clear();
}

template <typename T>
MyPriorityQueue<T>::MyPriorityQueue(const MyPriorityQueue& other) {
  lst = other.lst;
  capacity = other.capacity;
}

template <typename T>
MyPriorityQueue<T>::MyPriorityQueue(MyPriorityQueue&& other) {
  lst = std::move(other.lst);
  capacity = other.capacity;
}

template <typename T>
MyPriorityQueue<T>& MyPriorityQueue<T>::operator=(const MyPriorityQueue& other) {
  if (this != &other) {
    lst = other.lst;
    capacity = other.capacity;
  }
  return *this;
}

template <typename T>
MyPriorityQueue<T>& MyPriorityQueue<T>::operator=(MyPriorityQueue&& other) {
  if (this != &other) {
    lst = std::move(other.lst);
    capacity = other.capacity;
  }
  return *this;
}

template <typename T>
bool MyPriorityQueue<T>::empty() const {
  return lst.empty();
}

template <typename T>
size_t MyPriorityQueue<T>::size() const {
  return std::distance(lst.begin(), lst.end());
}

template <typename T>
void MyPriorityQueue<T>::enqueue(const T& item) {
  if (size() == capacity) {
    throw std::out_of_range("Queue is full");
  }

  if (lst.empty() || lst.front() < item) {
    lst.push_front(item);
    return;
  }

  auto it = lst.begin();
  while (it != lst.end() && item < *it) {
    ++it;
  }
  lst.insert_after(it, item);
}

template <typename T>
void MyPriorityQueue<T>::enqueue(T&& item) {
  if (size() == capacity) {
    throw std::out_of_range("Queue is full");
  }

  if (lst.empty() || lst.front() < item) {
    lst.push_front(std::move(item));
    return;
  }

  auto it = lst.begin();
  while (it != lst.end() && item < *it) {
    ++it;
  }
  lst.insert_after(it, std::move(item));
}

template <typename T>
T& MyPriorityQueue<T>::top() {
  if (empty()) {
    throw std::out_of_range("Queue is empty");
  }
  return lst.front();
}

template <typename T>
void MyPriorityQueue<T>::dequeue() {
  if (empty()) {
    throw std::out_of_range("Queue is empty");
  }
  lst.pop_front();
}

template <typename T>
void MyPriorityQueue<T>::clear() {
  lst.clear();
}

template <typename T>
void MyPriorityQueue<T>::display() {
  for (auto it = lst.begin(); it != lst.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}

#endif