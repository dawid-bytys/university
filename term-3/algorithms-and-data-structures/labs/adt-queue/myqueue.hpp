#ifndef MYQUEUE_HPP
#define MYQUEUE_HPP

#include <list>

// Queue implmenentaion using std::list
template <typename T>
class MyQueue {
 private:
  std::list<T> lst;
  size_t capacity;

 public:
  // default constructor
  MyQueue(const size_t size = 10);

  // destructor
  ~MyQueue();

  // copy constructor
  MyQueue(const MyQueue& other);

  // move constructor
  MyQueue(MyQueue&& other);

  // copy assignment operator
  MyQueue& operator=(const MyQueue& other);

  // move assignment operator
  MyQueue& operator=(MyQueue&& other);

  // checks if queue is empty
  bool empty() const;

  // checks if queue is full
  bool full() const;

  // returns size of queue
  size_t size() const;

  // returns max size of queue
  size_t max_size() const;

  // adds item to queue
  void enqueue(const T& item);

  // adds item to queue (move version)
  void enqueue(T&& item);

  // returns item at front of queue
  T& front();

  // returns item at back of queue
  T& back();

  // removes item from front of queue
  void dequeue();

  // removes all items from queue
  void clear();

  // displays all items in queue
  void display();
};

template <typename T>
MyQueue<T>::MyQueue(const size_t size) {
  capacity = size;
}

template <typename T>
MyQueue<T>::~MyQueue() {
  clear();
}

template <typename T>
MyQueue<T>::MyQueue(const MyQueue& other) {
  lst = other.lst;
  capacity = other.capacity;
}

template <typename T>
MyQueue<T>::MyQueue(MyQueue&& other) {
  lst = std::move(other.lst);
  capacity = other.capacity;
}

template <typename T>
MyQueue<T>& MyQueue<T>::operator=(const MyQueue& other) {
  if (this != &other) {
    lst = other.lst;
    capacity = other.capacity;
  }
  return *this;
}

template <typename T>
MyQueue<T>& MyQueue<T>::operator=(MyQueue&& other) {
  if (this != &other) {
    lst = std::move(other.lst);
    capacity = other.capacity;
  }
  return *this;
}

template <typename T>
bool MyQueue<T>::empty() const {
  return lst.empty();
}

template <typename T>
bool MyQueue<T>::full() const {
  return lst.size() == capacity;
}

template <typename T>
size_t MyQueue<T>::size() const {
  return lst.size();
}

template <typename T>
size_t MyQueue<T>::max_size() const {
  return capacity;
}

template <typename T>
void MyQueue<T>::enqueue(const T& item) {
  if (full()) {
    throw std::out_of_range("Queue is full");
  }
  lst.push_back(item);
}

template <typename T>
void MyQueue<T>::enqueue(T&& item) {
  if (full()) {
    throw std::out_of_range("Queue is full");
  }
  lst.push_back(std::move(item));
}

template <typename T>
T& MyQueue<T>::front() {
  if (empty()) {
    throw std::out_of_range("Queue is empty");
  }
  return lst.front();
}

template <typename T>
T& MyQueue<T>::back() {
  if (empty()) {
    throw std::out_of_range("Queue is empty");
  }
  return lst.back();
}

template <typename T>
void MyQueue<T>::dequeue() {
  if (empty()) {
    throw std::out_of_range("Queue is empty");
  }
  lst.pop_front();
}

template <typename T>
void MyQueue<T>::clear() {
  lst.clear();
}

template <typename T>
void MyQueue<T>::display() {
  for (auto& item : lst) {
    std::cout << item << " ";
  }
  std::cout << std::endl;
}

#endif