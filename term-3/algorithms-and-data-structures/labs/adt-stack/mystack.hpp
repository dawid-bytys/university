#include <cstddef>
#include <forward_list>
#include <iostream>

// Stack implementation using a forward_list
template <typename T>
class MyStack {
 private:
  // container for stack elements
  std::forward_list<T> container;

  // maximum number of elements
  size_t m_size;

 public:
  // default constructor
  explicit MyStack(size_t size = 10);

  // destructor
  ~MyStack();

  // copy constructor
  MyStack(const MyStack& other);

  // move constructor
  MyStack(MyStack&& other);

  // copy assignment operator
  MyStack& operator=(const MyStack& other);

  // move assignment operator
  MyStack& operator=(MyStack&& other);

  // check if stack is empty
  bool empty() const;

  // check if stack is full
  bool full() const;

  // return number of elements in stack
  size_t size() const;

  // return number of elements stack can hold
  size_t max_size() const;

  // push element onto stack
  void push(const T& item);

  // push element onto stack (move version)
  void push(T&& item);

  // return top element of stack
  T& top();

  // return first element of stack
  void pop();

  // clear stack
  void clear();

  // print stack elements
  void display();
};

template <typename T>
MyStack<T>::MyStack(size_t size) {
  m_size = size;
}

template <typename T>
MyStack<T>::~MyStack() {
  clear();
}

template <typename T>
MyStack<T>::MyStack(const MyStack& other) {
  m_size = other.m_size;
  container = other.container;
}

template <typename T>
MyStack<T>::MyStack(MyStack&& other) {
  m_size = other.m_size;
  container = std::move(other.container);
}

template <typename T>
MyStack<T>& MyStack<T>::operator=(const MyStack& other) {
  if (this != &other) {
    m_size = other.m_size;
    container = other.container;
  }
  return *this;
}

template <typename T>
MyStack<T>& MyStack<T>::operator=(MyStack&& other) {
  if (this != &other) {
    m_size = other.m_size;
    container = std::move(other.container);
  }
  return *this;
}

template <typename T>
bool MyStack<T>::empty() const {
  return container.empty();
}

template <typename T>
bool MyStack<T>::full() const {
  return m_size == std::distance(container.begin(), container.end());
}

template <typename T>
size_t MyStack<T>::size() const {
  return std::distance(container.begin(), container.end());
}

template <typename T>
size_t MyStack<T>::max_size() const {
  return m_size;
}

template <typename T>
void MyStack<T>::push(const T& item) {
  if (full()) {
    throw std::out_of_range("Stack is full");
  }
  container.push_front(item);
}

template <typename T>
void MyStack<T>::push(T&& item) {
  if (full()) {
    throw std::out_of_range("Stack is full");
  }
  container.push_front(std::move(item));
}

template <typename T>
T& MyStack<T>::top() {
  if (empty()) {
    throw std::out_of_range("Stack is empty");
  }
  return container.front();
}

template <typename T>
void MyStack<T>::pop() {
  if (empty()) {
    throw std::out_of_range("Stack is empty");
  }
  container.pop_front();
}

template <typename T>
void MyStack<T>::clear() {
  container.clear();
}

template <typename T>
void MyStack<T>::display() {
  for (auto& item : container) {
    std::cout << item << " ";
  }
  std::cout << std::endl;
}