#pragma once
#ifndef SETLIST_H
#define SETLIST_H

#include <iostream>
#include <vector>

/*
 * Implementation of set using list.
 */
class setList {
 private:
  std::vector<int> vec;

 public:
  /*
   * Inserts a value into the set.
   *
   * @param x the value to insert
   */
  void insert(int x);

  /*
   * Removes a value from the set.
   *
   * @param x the value to remove
   */
  void withdraw(int x);

  /*
   * Checks if a value is in the set.
   *
   * @param i the value to check
   * @return true if the value is in the set, false otherwise
   */
  bool isInSet(int x);

  /*
   * Gets the size of the set.
   *
   * @return the size of the set
   */
  int getSize();

  /*
   * Clears the set.
   */
  void clearSet();

  /*
   * Prints the set.
   */
  void printSet();

  /*
   * Overloads the + operator to perform the union of two sets.
   *
   * @param object the set to perform the union with
   * @return the union of the two sets
   */
  setList operator+(setList& object);

  /*
   * Overloads the * operator to perform the intersection of two sets.
   *
   * @param object the set to perform the intersection with
   * @return the intersection of the two sets
   */
  setList operator*(setList& object);

  /*
   * Overloads the - operator to perform the difference of two sets.
   *
   * @param object the set to perform the difference with
   * @return the difference of the two sets
   */
  setList operator-(setList& object);

  /*
   * Overloads the == operator to check if two sets are equal.
   *
   * @param object the set to compare with
   * @return true if the sets are equal, false otherwise
   */
  bool operator==(setList& object);

  /*
   * Overloads the <= operator to check if a set is a subset of another set.
   *
   * @param object the set to compare with
   * @return true if the set is a subset of the other set, false otherwise
   */
  bool operator<=(setList& object);

  /*
   * Overloads the >= operator to check if a set is a superset of another set.
   *
   * @param object the set to compare with
   * @return true if the set is a superset of the other set, false otherwise
   */
  bool operator>=(setList& object);
};

#endif  // SETLIST_H