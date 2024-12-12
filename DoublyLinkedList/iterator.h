// Custom Iterator Class for the Unsorted Doubly Linked.
#include <iostream>
#include "udllnode.h"


#ifndef ITERATOR_H
#define ITERATOR_H

template <class T>
class iterator{
private:
    //current node that the iterator is pointing to
    UDLLnode<T>* current;

public:
    //constructors
    iterator() : current (nullptr){}
    iterator(UDLLnode <T>* node) : current(node) {}
    //destructor
    ~iterator(){}

    //overloading the comparision operators
    bool operator == (const iterator<T>&other)const;
    bool operator !=(const iterator<T>&other)const;

    //overloading the dereference operator
    T& operator*();

    //overloading the operators for increment and decrement
    // pre-increment
    iterator &operator++();
    // post-increment
    iterator operator++(T);
    // pre-decrement
    iterator &operator--();
    //post-decrement
    iterator operator--(T);
};


#endif