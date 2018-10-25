#ifndef CURSOR_LIST_H_
#define CURSOR_LIST_H_
#include <iostream>
using namespace std;
using position_t=int;
template<typename T>
class CursorList
{
  CursorList<T>();
  CursorList<T>(int max_num);
  void push_front( T element);
  void push_back(T element);
  T pop_front();
  T pop_back();
  position_t find(T element);
  position_t erase(position_t pos);
  position_t insert(position_t pos,T element);
  int size();
  bool empty(){
    if(actual_size==0)return true;
    else return false;
  }
  class Node;
private:
  Node *tab;
  int head;
  int free;
  int actual_size;

};
template <typename T>
class CursorList <T> ::Node
{
public:
  T value;
  T next;
};
#endif
