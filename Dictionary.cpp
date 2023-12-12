#ifndef DICTIONARY_CPP
#define DICTIONARY_CPP
#include "Dictionary.h"
#include "Tuple.h"
#include "Tuple.cpp"
#include <cstddef>
#include <string>
using namespace std;
template <typename T, typename E>
Dictionary<T, E>::Dictionary() : keys(NULL), values(NULL), currSize(0) {}

template <typename T, typename E>
Dictionary<T, E>::~Dictionary() {
    if(keys != NULL){
    delete[] keys;}
    if(values != NULL){
    delete[] values;
    }
    keys = NULL;
    values = NULL;
}

template <typename T, typename E>
void Dictionary<T, E>::set(T key, E value) {
    // Check if the key already exists
    for (int i = 0; i < currSize; i++) {
        if(keys != NULL){
        if (keys[i] == key) {
            if(values != NULL){
            values[i] = value;}
            return;  // Return if exists
        }
    }}

    
    T* newKeys = new T[currSize + 1];
    E* newValues = new E[currSize + 1];

    
    for (int i = 0; i < currSize; i++) {
        newKeys[i] = keys[i];
        newValues[i] = values[i];
    }

    
    newKeys[currSize] = key;
    newValues[currSize] = value;

    if(keys != NULL){
    delete[] keys;}
    if(values != NULL){
    delete[] values;
    }
    keys = newKeys;
    values = newValues;
    currSize++;
}


template <typename T, typename E>
E Dictionary<T, E>::at(T key) {
    for (int i = 0; i < currSize; i++) {
        if (keys[i] == key) {
            return values[i];
        }
    }
    return E();
}

template <typename T, typename E>
void Dictionary<T, E>::removeAt(T key) {
    for (int i = 0; i < currSize; i++) {
        if (keys[i] == key) {
            
            for (int j = i; j < currSize - 1; j++) {
                keys[j] = keys[j + 1];
                values[j] = values[j + 1];
            }
            currSize--;

            // Resize the arrays
            T* newKeys = new T[currSize];
            E* newValues = new E[currSize];

            for (int j= 0; j< currSize; j++) {
                 if(newKeys != NULL && keys != NULL){
                newKeys[j] = keys[j];
                 }
                 if(newValues != NULL && values != NULL){
                newValues[j] = values[j];}
            }
            if(keys != NULL){
            delete[] keys;}
            if(values != NULL){
            delete[] values;
            }
            keys = newKeys;
            values = newValues;
            return;
        }
    }
}

template <typename T, typename E>
void Dictionary<T, E>::remove(E value) {
    int newSize = 0;

  
  
    for (int i = 0; i < currSize; i++) {
        if (values[i] != value && values != NULL) {

            newSize++;
        }
    }

    if (newSize == 0) {

        delete[] keys;

        delete[] values;
        keys = NULL;
        values = NULL;
        currSize = 0;
        return;

    }

    T* newKeys = new T[newSize];
    E* newValues = new E[newSize];
    int nindex = 0;

    
    for (int i = 0; i < currSize; i++) {
        if (values[i] != value) {

            newKeys[nindex] = keys[i];
            newValues[nindex] = values[i];

            nindex++;
        }
    }
   if(keys != NULL){
    delete[] keys;}
    if(values != NULL){
    delete[] values;
    }
    currSize = newSize;
    keys = newKeys;
    values = newValues;

}

template <typename T, typename E>
bool Dictionary<T, E>::exists(T key) {
    for (int i = 0; i < currSize; i++) {
    if(keys != NULL){
        if (keys[i] == key) {
            return true;
           }
    }}

    return false;
}

template <typename T, typename E>
Tuple<int, T*> Dictionary<T, E>::keysWithValue(E value) {
    int count = 0;

    for (int i = 0; i < currSize; i++) {
        if(values != NULL){
        if (values[i] == value) {
            count++;
        }
        }
    }

    T* keyss = new T[count];
    int index = 0;

    for (int i = 0; i < currSize; i++) {
        if(values != NULL){
        if (values[i] == value) {

            keyss[index] = keys[i];
            index++;
        }
        }
    }

    Tuple<int, T*> result(count, keyss);
    return result;
}


template <typename T, typename E>
void Dictionary<T, E>::swap(T firstKey, T secondKey) {
    E tempValue;
    int firstIndex = -1;
    int ind = -1;

    
    for (int i = 0; i < currSize; i++) {

        if(keys != NULL){
        if (keys[i] == firstKey) {

            firstIndex = i;
        }
        if (keys[i] == secondKey) {

            ind = i;
        }
        }
    }

    
    if (firstIndex != -1 && ind != -1) {
       
        tempValue = values[firstIndex];

        values[firstIndex] = values[ind];

        values[ind] = tempValue;
    }
}

template <typename T, typename E>
void Dictionary<T, E>::clear() {
  currSize = 0;
  if(keys != NULL){
    delete[] keys;
  }
  if(values != NULL){
    delete[] values;
  }
    keys = NULL;
    values = NULL;
  
}

template <typename T, typename E>
T* Dictionary<T, E>::getKeys() {
    return keys;
}

template <typename T, typename E>
int Dictionary<T, E>::size() {
    return currSize;
}


#endif