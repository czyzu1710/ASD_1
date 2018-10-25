#ifndef ARRAY_LIST_H_
#define ARRAY_LIST_H_
#include <iostream>
using namespace std;
using position_t=int;
template <typename T>
class ArrayList
{
public:
  ArrayList<T>();
  ArrayList<T>(int max_num);
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
  int actual_size;
  int tail;
  T* tab;
};

template <typename T>
ArrayList<T>::ArrayList():tail{0}, actual_size{0}
{
  tab=new T[1000000];
}

template<typename T>
ArrayList<T>::ArrayList(int max_num):tail{0},actual_size{0}
{
  tab=new T[max_num];
}

template <typename T>
void ArrayList<T>:: push_back(T element)
{
  tab[tail]=element;
  tail++;
  actual_size++;
}

template<typename T>
void ArrayList<T>::push_front(T element)
{
  int tmp=tail;
  tail++;
  do{
    tab[tmp]=tab[tmp-1];
    tmp--;
  }while(tmp>0);
  tab[tmp]=element;
  actual_size++;
}

template<typename T>
T ArrayList<T>::pop_back()
{
  tail--;
  actual_size--;
  return tab[tail];

}

template<typename T>
T ArrayList<T>::pop_front()
{
  T first_element=tab[0];
  int tmp=0;
  do{
    tab[tmp]=tab[tmp+1];
    tmp++;
  }while(tmp<tail);
  tail--;
  actual_size--;
  return first_element;
}

template<typename T>
position_t ArrayList<T>::find(T element)
{
  position_t pos=-1;
  for(int i=0;i<tail;i++)
  {
    if(tab[i]==element){pos=i;}
  }
  if(pos==-1){cout<<"Nie ma takiego elementu na liście"<<endl;}
  return pos;
}

template<typename T>
position_t ArrayList<T>::erase(position_t pos)
{
  position_t result=pos+1;
  do {
    tab[pos]==tab[pos+1];
    pos++;
  } while(pos<tail);
  tail--;
  return result;
}

template<typename T>
position_t ArrayList<T>::insert(position_t pos, T element)
{
  position_t result=pos-1;
  pos=tail;
  do {
    tab[pos]=tab[pos-1];
    pos--;
  } while(pos>result);
  tab[pos]=element;
  return result;
  tail++;
  actual_size++;

}


#endif
