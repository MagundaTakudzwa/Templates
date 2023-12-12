#ifndef TUPLE_H
#define TUPLE_H

template <typename T, typename E>
class Tuple {
public:
 
    Tuple(T , E );

    
    ~Tuple();

    
    T getFirst() ;


    E getSecond();

   
    bool operator==( Tuple<T , E> t);

private:
    T firstValue;
    E secondValue;
};

#endif