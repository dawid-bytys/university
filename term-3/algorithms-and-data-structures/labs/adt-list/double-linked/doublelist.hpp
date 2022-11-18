#ifndef DOUBLELIST_HPP
#define DOUBLELIST_HPP

#include <iostream>

// template of a node of a double linked list
template <typename T>
struct DoubleNode {
  // value of the node
  T value;

  // pointer to the next node
  DoubleNode* next;

  // pointer to the previous node
  DoubleNode* prev;

  // default constructor
  DoubleNode();

  // parametreized constructor
  explicit DoubleNode(const T& item, DoubleNode* next_ptr = nullptr,
                      DoubleNode* prev_ptr = nullptr);

  // destructor
  ~DoubleNode();
};

// template of a double linked list
template <typename T>
class DoubleList {
 public:
  // pointer to the first node
  DoubleNode<T>* head;

  // pointer to the last node
  DoubleNode<T>* tail;

  // size of the list
  int size;

  // default constructor
  DoubleList();

  // destructor
  ~DoubleList();

  // copy constructor
  explicit DoubleList(const DoubleList& other);

  // move constructor
  explicit DoubleList(DoubleList&& other);

  // copy assignment operator
  DoubleList& operator=(const DoubleList& other);

  // move assignment operator
  DoubleList& operator=(DoubleList&& other);

  // checks if the list is empty
  bool empty() const;

  // returns the size of the list
  int get_size() const;

  // adds an element at the beginning of the list
  void push_front(const T& item);

  // adds an element at the beginning of the list (move version)
  void push_front(T&& item);

  // adds an element at the end of the list
  void push_back(const T& item);

  // adds an element at the end of the list (move version)
  void push_back(T&& item);

  // returns the first element of the list
  T& front() const;

  // returns the last element of the list
  T& back() const;

  // removes the first element of the list
  void pop_front();

  // removes the last element of the list
  void pop_back();

  // removes all the elements of the list
  void clear();

  // displays the list
  void display();

  // displays the list in reverse order
  void display_reversed();

  // returns an element at a given position
  T& operator[](int pos);

  // returns an element at a given position (const version)
  const T& operator[](int pos) const;

  // removes an element at a given position
  void erase(int pos);

  // returns the position of an element
  int index(const T& item) const;

  // inserts an element at a given position
  void insert(int pos, const T& item);

  // inserts an element at a given position (move version)
  void insert(int pos, T&& item);
};

/* DoubleNode definitions */
// default constructor
template <typename T>
DoubleNode<T>::DoubleNode() : next(nullptr), prev(nullptr) {}

// parametreized constructor
template <typename T>
DoubleNode<T>::DoubleNode(const T& item, DoubleNode* next_ptr,
                          DoubleNode* prev_ptr)
    : value(item), next(next_ptr), prev(prev_ptr) {}

// destructor
template <typename T>
DoubleNode<T>::~DoubleNode() {
  next = nullptr;
  prev = nullptr;
}

/* DoubleList definitions */
// default constructor
template <typename T>
DoubleList<T>::DoubleList() : head(nullptr), tail(nullptr), size(0) {}

// destructor
template <typename T>
DoubleList<T>::~DoubleList() {
  clear();
}

// copy constructor
template <typename T>
DoubleList<T>::DoubleList(const DoubleList& other) {
  head = nullptr;
  tail = nullptr;
  size = 0;

  DoubleNode<T>* current = other.head;
  while (current != nullptr) {
    push_back(current->value);
    current = current->next;
  }
}

// move constructor
template <typename T>
DoubleList<T>::DoubleList(DoubleList&& other) {
  head = other.head;
  tail = other.tail;
  size = other.size;

  other.head = nullptr;
  other.tail = nullptr;
  other.size = 0;
}

// copy assignment operator
template <typename T>
DoubleList<T>& DoubleList<T>::operator=(const DoubleList& other) {
  if (this != &other) {
    clear();

    DoubleNode<T>* current = other.head;
    while (current != nullptr) {
      push_back(current->value);
      current = current->next;
    }
  }

  return *this;
}

// move assignment operator
template <typename T>
DoubleList<T>& DoubleList<T>::operator=(DoubleList&& other) {
  if (this != &other) {
    clear();

    head = other.head;
    tail = other.tail;
    size = other.size;

    other.head = nullptr;
    other.tail = nullptr;
    other.size = 0;
  }

  return *this;
}

// checks if the list is empty
template <typename T>
bool DoubleList<T>::empty() const {
  return size == 0;
}

// returns the size of the list
template <typename T>
int DoubleList<T>::get_size() const {
  return size;
}

// adds an element at the beginning of the list
template <typename T>
void DoubleList<T>::push_front(const T& item) {
  DoubleNode<T>* new_node = new DoubleNode<T>(item, head);

  if (head != nullptr) {
    head->prev = new_node;
  }

  head = new_node;

  if (tail == nullptr) {
    tail = new_node;
  }

  ++size;
}

// adds an element at the beginning of the list (move version)
template <typename T>
void DoubleList<T>::push_front(T&& item) {
  DoubleNode<T>* new_node = new DoubleNode<T>(std::move(item), head);

  if (head != nullptr) {
    head->prev = new_node;
  }

  head = new_node;

  if (tail == nullptr) {
    tail = new_node;
  }

  ++size;
}

// adds an element at the end of the list
template <typename T>
void DoubleList<T>::push_back(const T& item) {
  DoubleNode<T>* new_node = new DoubleNode<T>(item, nullptr, tail);

  if (tail != nullptr) {
    tail->next = new_node;
  }

  tail = new_node;

  if (head == nullptr) {
    head = new_node;
  }

  ++size;
}

// adds an element at the end of the list (move version)
template <typename T>
void DoubleList<T>::push_back(T&& item) {
  DoubleNode<T>* new_node = new DoubleNode<T>(std::move(item), nullptr, tail);

  if (tail != nullptr) {
    tail->next = new_node;
  }

  tail = new_node;

  if (head == nullptr) {
    head = new_node;
  }

  ++size;
}

// returns the first element of the list
template <typename T>
T& DoubleList<T>::front() const {
  return head->value;
}

// returns the last element of the list
template <typename T>
T& DoubleList<T>::back() const {
  return tail->value;
}

// removes the first element of the list
template <typename T>
void DoubleList<T>::pop_front() {
  if (head != nullptr) {
    DoubleNode<T>* temp = head;
    head = head->next;

    if (head != nullptr) {
      head->prev = nullptr;
    }

    delete temp;
    if (head == nullptr) {
      tail = nullptr;
    }
    --size;
  }
}

// removes the last element of the list
template <typename T>
void DoubleList<T>::pop_back() {
  if (tail != nullptr) {
    DoubleNode<T>* temp = tail;
    tail = tail->prev;

    if (tail != nullptr) {
      tail->next = nullptr;
    }

    delete temp;
    if (tail == nullptr) {
      head = nullptr;
    }
    --size;
  }
}

// removes all elements from the list
template <typename T>
void DoubleList<T>::clear() {
  while (head != nullptr) {
    pop_front();
  }
}

// displays the list
template <typename T>
void DoubleList<T>::display() {
  DoubleNode<T>* current = head;
  while (current != nullptr) {
    std::cout << current->value << " ";
    current = current->next;
  }
  std::cout << std::endl;
}

// displays the list in reverse order
template <typename T>
void DoubleList<T>::display_reversed() {
  DoubleNode<T>* current = tail;
  while (current != nullptr) {
    std::cout << current->value << " ";
    current = current->prev;
  }
  std::cout << std::endl;
}

// returns an element at a given position (index operator)
template <typename T>
T& DoubleList<T>::operator[](int index) {
  if (index < 0 || index >= size) {
    throw std::out_of_range("Index out of range");
  }

  DoubleNode<T>* current = head;
  for (int i = 0; i < index; ++i) {
    current = current->next;
  }

  return current->value;
}

// returns a const element at a given position (index operator)
template <typename T>
const T& DoubleList<T>::operator[](int index) const {
  if (index < 0 || index >= size) {
    throw std::out_of_range("Index out of range");
  }

  DoubleNode<T>* current = head;
  for (int i = 0; i < index; ++i) {
    current = current->next;
  }

  return current->value;
}

// erases an element at a given position
template <typename T>
void DoubleList<T>::erase(int index) {
  if (index < 0 || index >= size) {
    throw std::out_of_range("Index out of range");
  }

  if (index == 0) {
    pop_front();
  } else if (index == size - 1) {
    pop_back();
  } else {
    DoubleNode<T>* current = head;
    for (int i = 0; i < index; ++i) {
      current = current->next;
    }

    current->prev->next = current->next;
    current->next->prev = current->prev;

    delete current;
    --size;
  }
}

// returns an index of an element
template <typename T>
int DoubleList<T>::index(const T& item) const {
  DoubleNode<T>* current = head;
  int index = 0;
  while (current != nullptr) {
    if (current->value == item) {
      return index;
    }
    current = current->next;
    ++index;
  }

  return -1;
}

// inserts an element at a given position
template <typename T>
void DoubleList<T>::insert(int index, const T& item) {
  if (index < 0 || index > size) {
    throw std::out_of_range("Index out of range");
  }

  if (index == 0) {
    push_front(item);
  } else if (index == size) {
    push_back(item);
  } else {
    DoubleNode<T>* current = head;
    for (int i = 0; i < index; ++i) {
      current = current->next;
    }

    DoubleNode<T>* new_node = new DoubleNode<T>(item, current, current->prev);
    current->prev->next = new_node;
    current->prev = new_node;

    ++size;
  }
}

// inserts an element at a given position (move version)
template <typename T>
void DoubleList<T>::insert(int index, T&& item) {
  if (index < 0 || index > size) {
    throw std::out_of_range("Index out of range");
  }

  if (index == 0) {
    push_front(std::move(item));
  } else if (index == size) {
    push_back(std::move(item));
  } else {
    DoubleNode<T>* current = head;
    for (int i = 0; i < index; ++i) {
      current = current->next;
    }

    DoubleNode<T>* new_node =
        new DoubleNode<T>(std::move(item), current, current->prev);
    current->prev->next = new_node;
    current->prev = new_node;

    ++size;
  }
}

#endif
