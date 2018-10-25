// Copyright 2018 <Michał Czyż>
#ifndef INCLUDE_CURSORLIST_HPP_
#define INCLUDE_CURSORLIST_HPP_
#include <iostream>
using namespace std;
using position_t = int;
template<typename T>
class CursorList{
  CursorList<T>();
  CursorList<T>(int max_num);
  void push_front(T element);
  void push_back(T element);
  T pop_front();
  T pop_back();
  position_t find(T element);
  position_t erase(position_t pos);
  position_t insert(position_t pos, T element);
  int size();
  bool empty() {
    if (actual_size == 0) return true;
    else
    return false;
  }
  class Node;
 private:
  Node *tab;
  int head;
  int free;
  int actual_size;
};

template <typename T>
class CursorList <T> ::Node{
 public:
  T value;
  T next;
};

template<typename T>
CursorList<T>::CursorList():head{0}, free{0}, actual_size{0} {
tab = new Node[1000000];
}


#endif  // INCLUDE_CURSORLIST_HPP_
