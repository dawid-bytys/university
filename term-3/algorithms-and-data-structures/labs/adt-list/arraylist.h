#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <iostream>

// ArrayList is a simple implementation of a dynamic memory container
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
  explicit ArrayList(int size);

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

  // checks if the list is empty
  bool empty() const;

  // checks if the list is full
  bool full() const;

  // returns the number of elements in the list
  int size() const;

  // returns the maximum number of elements in the list
  int max_size() const;

  // adds an element to the beginning of the list
  void push_front(const T& item);

  // adds an element to the beginning of the list
  void push_front(T&& item);

  // adds an element to the end of the list
  void push_back(const T& item);

  // adds an element to the end of the list
  void push_back(T&& item);

  // returns the first element of the list
  T& front();

  // returns the last element of the list
  T& back();

  // removes the first element of the list
  void pop_front();

  // removes the last element of the list
  void pop_back();

  // removes all elements from the list
  void clear();

  // returns the element at the given position
  void display();

  // reverses the order of elements in the list
  void reverse();

  // sorts the elements in the list
  void sort();

  // merges two sorted lists
  void merge(ArrayList& other);

  // returns the element at the given position (array notation)
  T& operator[](int pos);

  // returns the element at the given position (array notation)
  const T& operator[](int pos) const;

  // removes the element at the given position
  void erase(int pos);

  // returns the position of the first occurrence of the given element
  int index(const T& item);

  // inserts an element at the given position
  void insert(int pos, const T& item);

  // inserts an element at the given position
  void insert(int pos, T&& item);

  // prints the list to the given stream
  friend std::ostream& operator<<(std::ostream& os, const ArrayList& L);
};

#endif
