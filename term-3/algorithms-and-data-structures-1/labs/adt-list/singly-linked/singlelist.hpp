#ifndef SINGLELIST_HPP
#define SINGLELIST_HPP

#include <cassert>
#include <iostream>

// template for a single list node
template <typename T>
struct SingleNode {
  // current node value
  T value;

  // pointer to the next node
  SingleNode<T>* next;

  // default constructor
  SingleNode();

  // parameterized constructor
  explicit SingleNode(const T& item, SingleNode* ptr = nullptr);

  // destructor
  ~SingleNode();
};

// template for a single list
template <typename T>
class SingleList {
 public:
  // points to the first node in the list
  SingleNode<T>* head;

  // points to the last node in the list
  SingleNode<T>* tail;

  // default constructor
  SingleList();

  // copy constructor
  SingleList(const SingleList& other);

  // move constructor
  SingleList(SingleList&& other);

  // destructor
  ~SingleList();

  // copy assignment operator
  SingleList& operator=(const SingleList& other);

  // move assignment operator
  SingleList& operator=(SingleList&& other);

  // returns true if the list is empty, false otherwise
  bool empty() const;

  // returns the number of elements in the list
  int size() const;

  // adds a new element to the beginning of the list
  void push_front(const T& item);

  // adds a new element to the beginning of the list
  void push_front(T&& item);

  // adds a new element to the end of the list
  void push_back(const T& item);

  // adds a new element to the end of the list
  void push_back(T&& item);

  // returns the first element of the list, does not remove it
  T& front() const;

  // returns the last element of the list, does not remove it
  T& back() const;

  // removes the first element of the list
  void pop_front();

  // removes the last element of the list
  void pop_back();

  // removes all elements from the list
  void clear();

  // displays the list
  void display();

  // reverses the list
  void reverse();
};

/* SingleNode definitions */
// default constructor, initializes the next pointer to nullptr
template <typename T>
SingleNode<T>::SingleNode() : value(T()), next(nullptr){};

// parameterized constructor, initializes the value and next pointer
template <typename T>
SingleNode<T>::SingleNode(const T& item, SingleNode* ptr)
    : value(item), next(ptr){};

// destructor
template <typename T>
SingleNode<T>::~SingleNode(){};

/* SingleList definitions */
// default constructor, initializes the head and tail pointers to nullptr
template <typename T>
SingleList<T>::SingleList() : head(nullptr), tail(nullptr){};

// copy constructor, copies the nodes from the other list
template <typename T>
SingleList<T>::SingleList(const SingleList& other) {
  head = nullptr;
  tail = nullptr;
  SingleNode<T>* temp = other.head;
  while (temp != nullptr) {
    push_back(temp->value);
    temp = temp->next;
  }
}

// move constructor, moves the nodes from the other list
template <typename T>
SingleList<T>::SingleList(SingleList&& other) {
  head = other.head;
  tail = other.tail;
  other.head = nullptr;
  other.tail = nullptr;
}

// destructor, deletes the nodes
template <typename T>
SingleList<T>::~SingleList() {
  clear();
}

// copy assignment operator, copies the nodes from the other list
template <typename T>
SingleList<T>& SingleList<T>::operator=(const SingleList& other) {
  if (this != &other) {
    clear();
    SingleNode<T>* temp = other.head;
    while (temp != nullptr) {
      push_back(temp->value);
      temp = temp->next;
    }
  }
  return *this;
}

// move assignment operator, moves the nodes from the other list
template <typename T>
SingleList<T>& SingleList<T>::operator=(SingleList&& other) {
  if (this != &other) {
    clear();
    head = other.head;
    tail = other.tail;
    other.head = nullptr;
    other.tail = nullptr;
  }
  return *this;
}

// returns true if the list is empty, false otherwise
template <typename T>
bool SingleList<T>::empty() const {
  return head == nullptr;
}

// returns the number of elements in the list
template <typename T>
int SingleList<T>::size() const {
  int size = 0;
  SingleNode<T>* temp = head;
  while (temp != nullptr) {
    ++size;
    temp = temp->next;
  }
  return size;
}

// adds a new element to the beginning of the list
template <typename T>
void SingleList<T>::push_front(const T& item) {
  if (empty()) {
    head = new SingleNode<T>(item);
    tail = head;
  } else {
    head = new SingleNode<T>(item, head);
  }
}

// adds a new element to the beginning of the list (move version)
template <typename T>
void SingleList<T>::push_front(T&& item) {
  if (empty()) {
    head = new SingleNode<T>(std::move(item));
    tail = head;
  } else {
    head = new SingleNode<T>(std::move(item), head);
  }
}

// adds a new element to the end of the list
template <typename T>
void SingleList<T>::push_back(const T& item) {
  if (empty()) {
    head = new SingleNode<T>(item);
    tail = head;
  } else {
    tail->next = new SingleNode<T>(item);
    tail = tail->next;
  }
}

// adds a new element to the end of the list (move version)
template <typename T>
void SingleList<T>::push_back(T&& item) {
  if (empty()) {
    head = new SingleNode<T>(std::move(item));
    tail = head;
  } else {
    tail->next = new SingleNode<T>(std::move(item));
    tail = tail->next;
  }
}

// returns the first element of the list, does not remove it
template <typename T>
T& SingleList<T>::front() const {
  assert(!empty());
  return head->value;
}

// returns the last element of the list, does not remove it
template <typename T>
T& SingleList<T>::back() const {
  assert(!empty());
  return tail->value;
}

// removes the first element of the list
template <typename T>
void SingleList<T>::pop_front() {
  assert(!empty());
  SingleNode<T>* temp = head;
  head = head->next;
  delete temp;
  if (head == nullptr) {
    tail = nullptr;
  }
}

// removes the last element of the list
template <typename T>
void SingleList<T>::pop_back() {
  assert(!empty());
  if (head == tail) {
    delete head;
    head = nullptr;
    tail = nullptr;
  } else {
    SingleNode<T>* temp = head;
    while (temp->next != tail) {
      temp = temp->next;
    }
    delete tail;
    tail = temp;
    tail->next = nullptr;
  }
}

// removes all elements from the list
template <typename T>
void SingleList<T>::clear() {
  while (!empty()) {
    pop_front();
  }
}

// displays the elements of the list
template <typename T>
void SingleList<T>::display() {
  SingleNode<T>* temp = head;
  while (temp != nullptr) {
    std::cout << temp->value << " ";
    temp = temp->next;
  }
  std::cout << std::endl;
}

// reverses the elements of the list
template <typename T>
void SingleList<T>::reverse() {
  if (head != nullptr) {
    SingleNode<T>* prev = nullptr;
    SingleNode<T>* curr = head;
    SingleNode<T>* next = head->next;
    while (next != nullptr) {
      curr->next = prev;
      prev = curr;
      curr = next;
      next = next->next;
    }
    curr->next = prev;
    tail = head;
    head = curr;
  }
}

#endif
