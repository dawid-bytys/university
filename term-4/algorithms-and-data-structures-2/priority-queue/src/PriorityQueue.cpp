#include "../include/PriorityQueue.h"

#include <iostream>

void PriorityQueue::heapify(int i) {
  int left = 2 * i + 1;
  int right = 2 * i + 2;
  int largest = i;
  if (left < heap.size() && heap[left] > heap[largest]) {
    largest = left;
  }
  if (right < heap.size() && heap[right] > heap[largest]) {
    largest = right;
  }
  if (largest != i) {
    std::swap(heap[i], heap[largest]);
    heapify(largest);
  }
}

const bool PriorityQueue::empty() const {
  return heap.empty();
}

const int PriorityQueue::size() const {
  return heap.size();
}

void PriorityQueue::enqueue(int value) {
  heap.push_back(value);
  int i = heap.size() - 1;
  while (i > 0 && heap[i] > heap[(i - 1) / 2]) {
    std::swap(heap[i], heap[(i - 1) / 2]);
    i = (i - 1) / 2;
  }
}

void PriorityQueue::dequeue() {
  if (heap.empty()) {
    return;
  }
  heap[0] = heap.back();
  heap.pop_back();
  heapify(0);
}

const int PriorityQueue::top() const {
  if (heap.empty()) {
    return -1;
  }
  return heap[0];
}

void PriorityQueue::clear() {
  heap.clear();
}

void PriorityQueue::display() const {
  PriorityQueue copy = *this;
  while (!copy.empty()) {
    std::cout << copy.top() << " ";
    copy.dequeue();
  }
  std::cout << std::endl;
}