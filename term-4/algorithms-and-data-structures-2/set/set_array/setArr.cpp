#include "setArr.h"

#include <iostream>

setArr::setArr() {
  size = 0;
  table = new bool[universeSize];
  for (int i = 0; i < universeSize; ++i) {
    table[i] = false;
  }
}

bool setArr::checkRangeCorrectness(int x) {
  if (x < 0 || x >= universeSize) {
    throw std::out_of_range("The value is out of range");
    return false;
  }
  return true;
}

void setArr::insert(int x) {
  if (!checkRangeCorrectness(x)) {
    return;
  }
  if (!table[x]) {
    table[x] = true;
    ++size;
  }
}

void setArr::withdraw(int x) {
  if (!checkRangeCorrectness(x)) {
    return;
  }
  if (table[x]) {
    table[x] = false;
    --size;
  }
}

bool setArr::isInSet(int i) {
  if (!checkRangeCorrectness(i)) {
    return false;
  }
  return table[i];
}

int setArr::getSize() {
  return size;
}

void setArr::clearSet() {
  for (int i = 0; i < universeSize; ++i) {
    table[i] = false;
  }
  size = 0;
}

void setArr::printSet() {
  std::cout << "{";
  for (int i = 0; i < universeSize; ++i) {
    if (table[i]) {
      std::cout << " " << i;
      if (i != universeSize - 1) {
        std::cout << ",";
      }
    }
  }
  std::cout << " }" << std::endl;
}

setArr setArr::operator+(setArr& object) {
  setArr result;
  for (int i = 0; i < universeSize; ++i) {
    if (table[i] || object.table[i]) {
      result.insert(i);
    }
  }
  return result;
}

setArr setArr::operator*(setArr& object) {
  setArr result;
  for (int i = 0; i < universeSize; ++i) {
    if (table[i] && object.table[i]) {
      result.insert(i);
    }
  }
  return result;
}

setArr setArr::operator-(setArr& object) {
  setArr result;
  for (int i = 0; i < universeSize; ++i) {
    if (table[i] && !object.table[i]) {
      result.insert(i);
    }
  }
  return result;
}

bool setArr::operator==(setArr& object) {
  for (int i = 0; i < universeSize; ++i) {
    if (table[i] != object.table[i]) {
      return false;
    }
  }
  return true;
}

bool setArr::operator<=(setArr& object) {
  for (int i = 0; i < universeSize; ++i) {
    if (table[i] && !object.table[i]) {
      return false;
    }
  }
  return true;
}

bool setArr::operator>=(setArr& object) {
  for (int i = 0; i < universeSize; ++i) {
    if (!table[i] && object.table[i]) {
      return false;
    }
  }
  return true;
}