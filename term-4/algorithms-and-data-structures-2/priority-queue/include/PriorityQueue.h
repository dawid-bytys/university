#ifndef PRIOQUEUE_H
#define PRIOQUEUE_H
#pragma once

#include <vector>

/**
 * A priority queue implementation using binary heap
 */
class PriorityQueue {
 private:
  std::vector<int> heap;
  void heapify(int i);

 public:
  /**
   * Constructs a new Priority Queue object
   */
  PriorityQueue(){};

  /**
   * Checks if the queue is empty
   *
   * @return true if the queue is empty and false otherwise
   */
  const bool empty() const;

  /**
   * Returns the size of the queue
   *
   * @return the size of the queue
   */
  const int size() const;

  /**
   * Adds a new element to the end of the queue
   *
   * @param value the value to be added
   */
  void enqueue(int value);

  /**
   * Removes the element with the highest priority from the queue
   */
  void dequeue();

  /**
   * Returns the element with the highest priority
   *
   * @return the element with the highest priority or -1 if the queue is empty
   */
  const int top() const;

  /**
   * Removes all elements from the queue
   */
  void clear();

  /**
   * Prints the queue to the console
   */
  void display() const;
};

#endif  // PRIOQUEUE_H