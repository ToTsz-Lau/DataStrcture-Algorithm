#include <iostream>
#include "iterator.h"

//implementation file


//overloading the comparision operators
template <class T>
bool iterator<T> :: operator == (const iterator<T> &other)const{
    return current == other.current;
}


template <class T>
bool iterator<T> :: operator !=(const iterator<T>&other)const{
    return current != other.current;
}

//overloading the dereference operator
template <class T>
T& iterator<T> :: operator*(){
    return current -> data;
}

//overloading the operators for increment and decrement

// pre-increment
template <class T>
iterator<T>& iterator<T>::operator++(){
    current = current -> next;
    return *this;
}

// post-increment
/* the copy of the original object is returned
while the actual object had already moved to next */
template <class T>
iterator<T> iterator<T>:: operator++(T){
    iterator<T> temp = *this;
    ++(*this);

    return temp;
}

// pre-decrement
template <class T>
iterator<T>& iterator<T>::operator--(){
    current = current -> prev;
    return *this;
}
//post-decrement
/* the copy of the original object is returned
while the actual object had already moved to previous */
template <class T>
iterator<T> iterator<T>::operator--(T){
    iterator<T> temp = *this;
    --(*this);
    return temp;
}
