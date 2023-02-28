#pragma once
#ifndef SETARR_H
#define SETARR_H

/*
 * Implementation of set using array
 */
class setArr {
 private:
  int size;
  const int universeSize = 100;
  bool* table;

  /*
   * Checks if the value is in the range of the universe.
   *
   * @param x the value to check
   * @return true if the value is in the range, false otherwise
   * @throw std::out_of_range if the value is out of range
   */
  bool checkRangeCorrectness(int x);

 public:
  /*
   * Creates a new setArr object.
   */
  setArr();

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
  bool isInSet(int i);

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
  setArr operator+(setArr& object);

  /*
   * Overloads the * operator to perform the intersection of two sets.
   *
   * @param object the set to perform the intersection with
   * @return the intersection of the two sets
   */
  setArr operator*(setArr& object);

  /*
   * Overloads the - operator to perform the difference of two sets.
   *
   * @param object the set to perform the difference with
   * @return the difference of the two sets
   */
  setArr operator-(setArr& object);

  /*
   * Overloads the == operator to check if two sets are equal.
   *
   * @param object the set to compare with
   * @return true if the sets are equal, false otherwise
   */
  bool operator==(setArr& object);

  /*
   * Overloads the <= operator to check if a set is a subset of another set.
   *
   * @param object the set to compare with
   * @return true if the set is a subset of the other set, false otherwise
   */
  bool operator<=(setArr& object);

  /*
   * Overloads the >= operator to check if a set is a superset of another set.
   *
   * @param object the set to compare with
   * @return true if the set is a superset of the other set, false otherwise
   */
  bool operator>=(setArr& object);
};

#endif  // SETARR_H