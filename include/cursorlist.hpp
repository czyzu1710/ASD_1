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
  int head_node;
  int free_node;
  int actual_size;
  int last_free_node;
  int last_head_node;
};

template <typename T>
class CursorList <T> ::Node{
 public:
  T value;
  T next;
};

template<typename T>
CursorList<T>::CursorList():head_node{NULL}, free_node{0}, actual_size{0} {
tab = new Node[1000000];
}

template<typename T>
CursorList<T>::CursorList(int max_num):head_node{NULL}, free_node{0},
actual_size{0}, last_free_node{0} {
tab = new T[max_num];
for(int i=max_num-2; i >= 0; i--) {
  tab[i].next = i+1;
  tab[i].value = NULL;
}
tab[max_num-1].value = NULL;
tab[max_num-1].next = 0;
}

template<typename T>
void CursorList<T>::push_back(T element) {
tab[last_head_node].next = free_node;
tab[free_node].value = element;
tab[free_node].next = NULL;
free_node = tab[free_node].next;
}

template <typename T>
void CursorList<T>::push_front(T element) {
tab[free_node].value = element;
}

#endif  // INCLUDE_CURSORLIST_HPP_
