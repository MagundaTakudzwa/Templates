
#ifndef TUPLE_CPP
#define TUPLE_CPP
#include <cstddef>
#include "Tuple.h"
#include <string>
#include <iostream>
using namespace std;


template <typename T, typename E>
Tuple<T, E>::Tuple(T first, E second) : firstValue(first), secondValue(second) {
}

template <typename T, typename E>
Tuple<T, E>::~Tuple() {
   
}

template <typename T, typename E>
T Tuple<T, E>::getFirst() {
    return firstValue;
}

template <typename T, typename E>
E Tuple<T, E>::getSecond() {
    return secondValue;
}


template <typename T, typename E>
bool Tuple<T, E>::operator==(Tuple<T, E> t) {
    return (firstValue == t.firstValue) && (secondValue == t.secondValue);
}

#endif