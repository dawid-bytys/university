#include "setList.h"

#include <iostream>

void setList::insert(int x) {
  if (!isInSet(x)) {
    vec.push_back(x);
  }
}

void setList::withdraw(int x) {
  for (int i = 0; i < vec.size(); ++i) {
    if (vec[i] == x) {
      vec.erase(vec.begin() + i);
      return;
    }
  }
}

bool setList::isInSet(int x) {
  for (int i = 0; i < vec.size(); ++i) {
    if (vec[i] == x) {
      return true;
    }
  }
  return false;
}

int setList::getSize() {
  return vec.size();
}

void setList::clearSet() {
  vec.clear();
}

void setList::printSet() {
  std::cout << "{";
  for (int i = 0; i < vec.size(); ++i) {
    std::cout << " " << vec[i];
    if (i != vec.size() - 1) {
      std::cout << ",";
    }
  }
  std::cout << " }" << std::endl;
}

setList setList::operator+(setList &object) {
  setList result;
  for (int i = 0; i < vec.size(); ++i) {
    result.insert(vec[i]);
  }
  for (int i = 0; i < object.vec.size(); ++i) {
    if (!isInSet(object.vec[i])) {
      result.insert(object.vec[i]);
    }
  }
  return result;
}

setList setList::operator*(setList &object) {
  setList result;
  for (int i = 0; i < vec.size(); ++i) {
    if (object.isInSet(vec[i])) {
      result.insert(vec[i]);
    }
  }
  return result;
}

setList setList::operator-(setList &object) {
  setList result;
  for (int i = 0; i < vec.size(); ++i) {
    if (!object.isInSet(vec[i])) {
      result.insert(vec[i]);
    }
  }
  return result;
}

bool setList::operator==(setList &object) {
  if (vec.size() != object.vec.size()) {
    return false;
  }
  for (int i = 0; i < vec.size(); ++i) {
    if (!object.isInSet(vec[i])) {
      return false;
    }
  }
  return true;
}

bool setList::operator<=(setList &object) {
  if (vec.size() > object.vec.size()) {
    return false;
  }
  for (int i = 0; i < vec.size(); ++i) {
    if (!object.isInSet(vec[i])) {
      return false;
    }
  }
  return true;
}

bool setList::operator>=(setList &object) {
  if (vec.size() < object.vec.size()) {
    return false;
  }
  for (int i = 0; i < object.vec.size(); ++i) {
    if (!isInSet(object.vec[i])) {
      return false;
    }
  }
  return true;
}
