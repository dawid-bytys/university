// Wprowadziłem trochę zmian w stosunku do oryginalnego kodu.
// a) dodałem const'y
// b) dodałem konstruktor inicjalizujący.

#ifndef MYDEQUE_HPP
#define MYDEQUE_HPP

#include <cassert>
#include <iostream>

// implementation of a deque
template <typename T>
class MyDeque {
 private:
  // the node type
  T* tab;

  // index of the first element
  int first;

  // index of the last element
  int last;

  // maximum number of elements
  int msize;

 public:
  // default constructor
  MyDeque();

  // destructor
  ~MyDeque();

  // parameterized constructor
  explicit MyDeque(const int size);

  // initializer list constructor
  MyDeque(std::initializer_list<T> list);

  // copy constructor
  MyDeque(const MyDeque& other);

  // move constructor
  MyDeque(MyDeque&& other);

  // copy assignment operator
  MyDeque& operator=(const MyDeque& other);

  // move assignment operator
  MyDeque& operator=(MyDeque&& other);

  // checks if the deque is empty
  bool empty() const;

  // checks if the deque is full
  bool full() const;

  // returns the size of the deque
  size_t size() const;

  // returns the capacity of the deque
  size_t max_size() const;

  // adds an element to the front of the deque
  void push_front(const T& item);

  // adds an element to the back of the deque (move version)
  void push_front(T&& item);

  // adds an element to the back of the deque
  void push_back(const T& item);

  // adds an element to the back of the deque (move version)
  void push_back(T&& item);

  // returns the element at the front of the deque
  T& front() const;

  // returns the element at the back of the deque
  T& back() const;

  // removes the element at the front of the deque
  void pop_front();

  // removes the element at the back of the deque
  void pop_back();

  // clears the deque
  void clear();

  // prints the deque
  void display();

  // access operator
  T& operator[](const int index) const;

  // removes the element at the specified position
  void erase(const int index);

  // returns the index of the specified element
  int index(const T& item) const;

  // inserts an element at the specified position
  void insert(const int index, const T& item);

  // inserts an element at the specified position (move version)
  void insert(const int index, T&& item);
};

// default constructor
template <typename T>
MyDeque<T>::MyDeque() {
  msize = 10;
  first = -1;
  last = 0;
  tab = new T[msize];
  assert(tab != nullptr);
}

// destructor
template <typename T>
MyDeque<T>::~MyDeque() {
  delete[] tab;
}

// parameterized constructor
template <typename T>
MyDeque<T>::MyDeque(const int size) {
  if (size < 0) {
    throw std::invalid_argument("Size must be positive");
  }

  msize = size;
  first = -1;
  last = 0;
  tab = new T[msize];
  assert(tab != nullptr);
}

// initializer list constructor
template <typename T>
MyDeque<T>::MyDeque(std::initializer_list<T> list) {
  msize = list.size();
  first = -1;
  last = 0;
  tab = new T[msize];
  assert(tab != nullptr);

  for (auto& item : list) {
    push_back(item);
  }
}

// copy constructor
template <typename T>
MyDeque<T>::MyDeque(const MyDeque& other) {
  msize = other.msize;
  first = other.first;
  last = other.last;
  tab = new T[msize];
  assert(tab != nullptr);
  std::copy(other.tab, other.tab + msize, tab);
}

// move constructor
template <typename T>
MyDeque<T>::MyDeque(MyDeque&& other) {
  msize = other.msize;
  first = other.first;
  last = other.last;
  tab = other.tab;
  other.tab = nullptr;
  other.first = -1;
  other.last = 0;
}

// copy assignment operator
template <typename T>
MyDeque<T>& MyDeque<T>::operator=(const MyDeque& other) {
  if (this != &other) {
    delete[] tab;
    msize = other.msize;
    first = other.first;
    last = other.last;
    tab = new T[msize];
    assert(tab != nullptr);
    std::copy(other.tab, other.tab + msize, tab);
  }
  return *this;
}

// move assignment operator
template <typename T>
MyDeque<T>& MyDeque<T>::operator=(MyDeque&& other) {
  if (this != &other) {
    delete[] tab;
    msize = other.msize;
    first = other.first;
    last = other.last;
    tab = other.tab;
    other.tab = nullptr;
    other.first = -1;
    other.last = 0;
  }
  return *this;
}

// checks if the deque is empty
template <typename T>
bool MyDeque<T>::empty() const {
  return first == -1;
}

// checks if the deque is full
template <typename T>
bool MyDeque<T>::full() const {
  return (first == 0 && last == msize - 1) || (first == last + 1);
}

// returns the size of the deque
template <typename T>
size_t MyDeque<T>::size() const {
  if (first == -1) {
    return 0;
  }

  if (last >= first) {
    return last - first + 1;
  }

  return msize - (first - last - 1);
}

// returns the capacity of the deque
template <typename T>
size_t MyDeque<T>::max_size() const {
  return msize;
}

// adds an element to the front of the deque
template <typename T>
void MyDeque<T>::push_front(const T& item) {
  if (full()) {
    throw std::out_of_range("Deque is full");
  }

  if (first == -1) {
    first = 0;
    last = 0;
  } else if (first == 0) {
    first = msize - 1;
  } else {
    --first;
  }

  tab[first] = item;
}

// adds an element to the front of the deque (move version)
template <typename T>
void MyDeque<T>::push_front(T&& item) {
  if (full()) {
    throw std::out_of_range("Deque is full");
  }

  if (first == -1) {
    first = 0;
    last = 0;
  } else if (first == 0) {
    first = msize - 1;
  } else {
    --first;
  }

  tab[first] = std::move(item);
}

// adds an element to the back of the deque
template <typename T>
void MyDeque<T>::push_back(const T& item) {
  if (full()) {
    throw std::out_of_range("Deque is full");
  }

  if (first == -1) {
    first = 0;
    last = 0;
  } else if (last == msize - 1) {
    last = 0;
  } else {
    ++last;
  }

  tab[last] = item;
}

// adds an element to the back of the deque (move version)
template <typename T>
void MyDeque<T>::push_back(T&& item) {
  if (full()) {
    throw std::out_of_range("Deque is full");
  }

  if (first == -1) {
    first = 0;
    last = 0;
  } else if (last == msize - 1) {
    last = 0;
  } else {
    ++last;
  }

  tab[last] = std::move(item);
}

// removes the first element of the deque
template <typename T>
void MyDeque<T>::pop_front() {
  if (empty()) {
    throw std::out_of_range("Deque is empty");
  }

  if (first == last) {
    first = -1;
    last = 0;
  } else if (first == msize - 1) {
    first = 0;
  } else {
    ++first;
  }
}

// removes the last element of the deque
template <typename T>
void MyDeque<T>::pop_back() {
  if (empty()) {
    throw std::out_of_range("Deque is empty");
  }

  if (first == last) {
    first = -1;
    last = 0;
  } else if (last == 0) {
    last = msize - 1;
  } else {
    --last;
  }
}

// returns the first element of the deque
template <typename T>
T& MyDeque<T>::front() const {
  if (empty()) {
    throw std::out_of_range("Deque is empty");
  }

  return tab[first];
}

// returns the last element of the deque
template <typename T>
T& MyDeque<T>::back() const {
  if (empty()) {
    throw std::out_of_range("Deque is empty");
  }

  return tab[last];
}

// clears the deque
template <typename T>
void MyDeque<T>::clear() {
  first = -1;
  last = 0;
}

// prints the deque
template <typename T>
void MyDeque<T>::display() {
  if (empty()) {
    std::cout << "Deque is empty" << std::endl;
    return;
  }

  if (last >= first) {
    for (int i = first; i <= last; ++i) {
      std::cout << tab[i] << " ";
    }
  } else {
    for (int i = first; i < msize; ++i) {
      std::cout << tab[i] << " ";
    }
    for (int i = 0; i <= last; ++i) {
      std::cout << tab[i] << " ";
    }
  }

  std::cout << std::endl;
}

// access operator
template <typename T>
T& MyDeque<T>::operator[](const int index) const {
  if (index < 0 || index >= size()) {
    throw std::out_of_range("Index out of range");
  }

  if (first + index > msize - 1) {
    return tab[first + index - msize];
  }

  return tab[first + index];
}

// removes the element at the given index
template <typename T>
void MyDeque<T>::erase(const int index) {
  if (index < 0 || index >= size()) {
    throw std::out_of_range("Index out of range");
  }

  if (index == 0) {
    pop_front();
    return;
  }

  if (index == size() - 1) {
    pop_back();
    return;
  }

  if (first + index > msize - 1) {
    for (int i = first + index - msize; i < last; ++i) {
      tab[i] = tab[i + 1];
    }
    --last;
    return;
  }

  for (int i = first + index; i < last; ++i) {
    tab[i] = tab[i + 1];
  }
  --last;
}

// returns the index of the given element
template <typename T>
int MyDeque<T>::index(const T& item) const {
  if (empty()) {
    return -1;
  }

  if (last >= first) {
    for (int i = first; i <= last; ++i) {
      if (tab[i] == item) {
        return i - first;
      }
    }
  } else {
    for (int i = first; i < msize; ++i) {
      if (tab[i] == item) {
        return i - first;
      }
    }
    for (int i = 0; i <= last; ++i) {
      if (tab[i] == item) {
        return i + msize - first;
      }
    }
  }

  return -1;
}

// inserts an element at the given index
template <typename T>
void MyDeque<T>::insert(const int index, const T& item) {
  if (index < 0 || index > size()) {
    throw std::out_of_range("Index out of range");
  }

  if (full()) {
    throw std::out_of_range("Deque is full");
  }

  if (index == 0) {
    push_front(item);
    return;
  }

  if (index == size()) {
    push_back(item);
    return;
  }

  if (last == msize - 1) {
    last = 0;
  } else {
    ++last;
  }

  if (first + index > msize - 1) {
    for (int i = last; i > first + index - msize; --i) {
      tab[i] = tab[i - 1];
    }
    tab[first + index - msize] = item;
    return;
  }

  for (int i = last; i > first + index; --i) {
    tab[i] = tab[i - 1];
  }
  tab[first + index] = item;
}

// inserts an element at the given index (move version)
template <typename T>
void MyDeque<T>::insert(const int index, T&& item) {
  if (index < 0 || index > size()) {
    throw std::out_of_range("Index out of range");
  }

  if (full()) {
    throw std::out_of_range("Deque is full");
  }

  if (index == 0) {
    push_front(std::move(item));
    return;
  }

  if (index == size()) {
    push_back(std::move(item));
    return;
  }

  if (last == msize - 1) {
    last = 0;
  } else {
    ++last;
  }

  if (first + index > msize - 1) {
    for (int i = last; i > first + index - msize; --i) {
      tab[i] = tab[i - 1];
    }
    tab[first + index - msize] = std::move(item);
    return;
  }

  for (int i = last; i > first + index; --i) {
    tab[i] = tab[i - 1];
  }
  tab[first + index] = std::move(item);
}

#endif