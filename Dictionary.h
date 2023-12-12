#ifndef DICTIONARY_H
#define DICTIONARY_H

#include "Tuple.h"
#include "Tuple.cpp"
#include <string>
template <typename T, typename E>
class Dictionary {
  
public:
    Dictionary();
    ~Dictionary();

    void set(T , E );
    E at(T);
    void removeAt(T);
    void remove(E);
    bool exists(T);
    Tuple<int, T*> keysWithValue(E);
    void swap(T , T );
    void clear();
    T* getKeys();
    int size();
  private:
    T* keys;
    E* values;
    int currSize;

};
#include "Dictionary.cpp"

#endif