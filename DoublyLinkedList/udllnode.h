//Basic Node class for the unsorted doubly linked list
#include <iostream>
#ifndef UDLLNODE_H
#define UDLLNODE_H


template <class T>
struct UDLLnode{
// Actual information, pointer to previous node and pointer to next node
    T data;
    UDLLnode<T> * prev;
    UDLLnode<T>* next;

//default constructor for the node
    UDLLnode() : prev(nullptr), next(nullptr){}

//constructor
    UDLLnode(UDLLnode<T> * previous, UDLLnode<T> *nextnode, T newdata) : prev(previous), next(nextnode), data(newdata){}

//desctructor
    ~UDLLnode(){}

};

#endif