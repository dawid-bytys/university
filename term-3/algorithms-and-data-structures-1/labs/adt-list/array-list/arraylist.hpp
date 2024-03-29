/*
Dodałem do klasy ArrayList metodę resize(), ponieważ w przypadku gdy tablica
jest pełna, a chcemy dodać kolejny element, to nie możemy tego zrobić, ponieważ
nie mamy miejsca, lub w przypadku mergowania dwóch tablic, gdy jedna z nich
jest pełna.
*/
#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <cassert>
#include <iostream>

// ArrayList is a simple collection of elements of type T
template <typename T>
class ArrayList {
 private:
  // tab is a pointer to the array
  T* tab;

  // msize is the maximum size of the array
  int msize;

  // last is the first free position in the array
  int last;

 public:
  // default constructor
  ArrayList() = default;
  explicit ArrayList(const int size);

  // copy constructor
  ArrayList(const ArrayList& other);

  // move constructor
  ArrayList(ArrayList&& other);

  // destructor
  ~ArrayList();

  // copy assignment operator
  ArrayList& operator=(const ArrayList& other);

  // move assignment operator
  ArrayList& operator=(ArrayList&& other);

  // returns the element at the given position (array notation)
  T& operator[](const int index);

  // returns the element at the given position (array notation)
  const T& operator[](const int index) const;

  // returns the first element of the list
  const T& front();

  // returns the last element of the list
  const T& back();

  // checks if the list is empty
  bool empty() const;

  // checks if the list is full
  bool full() const;

  // returns the number of elements in the list
  int size() const;

  // returns the maximum number of elements in the list
  int max_size() const;

  // returns the position of the first occurrence of the given element
  int index(const T& item) const;

  // adds an element to the beginning of the list
  void push_front(const T& item);

  // adds an element to the beginning of the list
  void push_front(T&& item);

  // adds an element to the end of the list
  void push_back(const T& item);

  // adds an element to the end of the list
  void push_back(T&& item);

  // removes the first element of the list
  void pop_front();

  // removes the last element of the list
  void pop_back();

  // removes all elements from the list
  void clear();

  // reverses the order of elements in the list
  void reverse();

  // sorts the elements in the list
  void sort();

  // resizes the list to the given size
  void resize(const int new_size);

  // merges two sorted lists
  void merge(ArrayList& other);

  // removes the element at the given position
  void erase(const int index);

  // inserts an element at the given position
  void insert(const int index, const T& item);

  // inserts an element at the given position
  void insert(const int index, T&& item);

  // prints the list to the given stream
  template <typename U>
  friend std::ostream& operator<<(std::ostream& os, const ArrayList<U>& list);
};

template <typename T>
ArrayList<T>::ArrayList(const int size) : msize(size), last(0) {
  assert(size > 0);
  tab = new T[size];
  assert(tab != nullptr);
}

template <typename T>
ArrayList<T>::ArrayList(const ArrayList& other)
    : msize(other.msize), last(other.last) {
  tab = new T[msize];
  assert(tab != nullptr);
  for (int i = 0; i < last; ++i) {
    tab[i] = other.tab[i];
  }
}

template <typename T>
ArrayList<T>::ArrayList(ArrayList&& other)
    : tab(other.tab), msize(other.msize), last(other.last) {
  other.tab = nullptr;
  other.msize = 0;
  other.last = 0;
}

template <typename T>
ArrayList<T>::~ArrayList() {
  delete[] tab;
}

template <typename T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList& other) {
  if (this != &other) {
    delete[] tab;
    msize = other.msize;
    last = other.last;
    tab = new T[msize];
    assert(tab != nullptr);
    for (int i = 0; i < last; ++i) {
      tab[i] = other.tab[i];
    }
  }
  return *this;
}

template <typename T>
ArrayList<T>& ArrayList<T>::operator=(ArrayList&& other) {
  if (this != &other) {
    delete[] tab;
    tab = other.tab;
    msize = other.msize;
    last = other.last;
    other.tab = nullptr;
    other.msize = 0;
    other.last = 0;
  }
  return *this;
}

template <typename T>
bool ArrayList<T>::empty() const {
  return last == 0;
}

template <typename T>
bool ArrayList<T>::full() const {
  return last == msize;
}

template <typename T>
int ArrayList<T>::size() const {
  return last;
}

template <typename T>
int ArrayList<T>::max_size() const {
  return msize;
}

template <typename T>
void ArrayList<T>::push_front(const T& item) {
  assert(!full());
  for (int i = last; i > 0; --i) {
    tab[i] = tab[i - 1];
  }
  tab[0] = item;
  ++last;
}

template <typename T>
void ArrayList<T>::push_front(T&& item) {
  assert(!full());
  for (int i = last; i > 0; --i) {
    tab[i] = tab[i - 1];
  }
  tab[0] = std::move(item);
  ++last;
}

template <typename T>
void ArrayList<T>::push_back(const T& item) {
  assert(!full());
  tab[last] = item;
  ++last;
}

template <typename T>
void ArrayList<T>::push_back(T&& item) {
  assert(!full());
  tab[last] = std::move(item);
  ++last;
}

template <typename T>
const T& ArrayList<T>::front() {
  assert(!empty());
  return tab[0];
}

template <typename T>
const T& ArrayList<T>::back() {
  assert(!empty());
  return tab[last - 1];
}

template <typename T>
void ArrayList<T>::pop_front() {
  assert(!empty());
  for (int i = 0; i < last - 1; ++i) {
    tab[i] = tab[i + 1];
  }
  --last;
}

template <typename T>
void ArrayList<T>::pop_back() {
  assert(!empty());
  --last;
}

template <typename T>
void ArrayList<T>::clear() {
  last = 0;
}

template <typename T>
void ArrayList<T>::reverse() {
  for (int i = 0; i < last / 2; ++i) {
    std::swap(tab[i], tab[last - i - 1]);
  }
}

template <typename T>
void ArrayList<T>::sort() {
  for (int i = 0; i < last - 1; ++i) {
    for (int j = i + 1; j < last; ++j) {
      if (tab[i] > tab[j]) {
        std::swap(tab[i], tab[j]);
      }
    }
  }
}

template <typename T>
void ArrayList<T>::resize(const int new_size) {
  assert(new_size > 0);
  T* new_tab = new T[new_size];
  assert(new_tab != nullptr);
  const int new_last = last < new_size ? last : new_size;
  for (int i = 0; i < new_last; ++i) {
    new_tab[i] = tab[i];
  }
  delete[] tab;
  tab = new_tab;
  msize = new_size;
  last = new_last;
}

template <typename T>
void ArrayList<T>::merge(ArrayList<T>& other) {
  assert(last + other.last <= msize);
  for (int i = 0; i < other.last; ++i) {
    tab[last + i] = other.tab[i];
  }
  last += other.last;
  other.last = 0;
}

template <typename T>
T& ArrayList<T>::operator[](const int index) {
  assert(index >= 0 && index < last);
  return tab[index];
}

template <typename T>
const T& ArrayList<T>::operator[](const int index) const {
  assert(index >= 0 && index < last);
  return tab[index];
}

template <typename T>
void ArrayList<T>::erase(const int index) {
  assert(!empty());
  assert(index >= 0 && index < last);
  for (int i = index; i < last - 1; ++i) {
    tab[i] = tab[i + 1];
  }
  --last;
}

template <typename T>
int ArrayList<T>::index(const T& item) const {
  for (int i = 0; i < last; ++i) {
    if (tab[i] == item) {
      return i;
    }
  }
  return -1;
}

template <typename T>
void ArrayList<T>::insert(const int index, const T& item) {
  assert(index >= 0 && index <= last);
  if (index == 0) {
    return push_front(item);
  }
  if (index == last) {
    return push_back(item);
  }
  assert(!full());
  for (int i = last; i > index; --i) {
    tab[i] = tab[i - 1];
  }
  tab[index] = item;
  ++last;
}

template <typename T>
void ArrayList<T>::insert(const int index, T&& item) {
  assert(index >= 0 && index <= last);
  if (index == 0) {
    return push_front(std::move(item));
  }
  if (index == last) {
    return push_back(std::move(item));
  }
  assert(!full());
  for (int i = last; i > index; --i) {
    tab[i] = tab[i - 1];
  }
  tab[index] = std::move(item);
  ++last;
}

template <typename U>
std::ostream& operator<<(std::ostream& os, const ArrayList<U>& list) {
  for (int i = 0; i < list.size(); ++i) {
    os << list[i] << " ";
  }
  return os;
}

#endif
