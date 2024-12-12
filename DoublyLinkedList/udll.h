//Header file for the Unsorted Doubly Linked List class
#include <iostream>
#include <unordered_set>
#include <map>
#include <vector>
#include "iterator.h"
#ifndef UDLL_H
#define UDLL_H

template <class T>
class udll{
private:
    //location of the first and last node
    UDLLnode<T>* head;
    UDLLnode<T>* tail;
    //length of the linked list
    int length;

    /*additional MAP to help deal with specific duplicates
    not sure if this is needed but trying to prevent the need to
    create and fillout the map every time a user calls functions
    regarding duplicates.
    */
    std::map <T,int> frequencyMap;

public:
    //constructor
    udll() : head(nullptr), tail(nullptr), length(0){}
    //destructor
    ~udll();
    //copy constructor
    udll(const udll<T> &other);
    //operator =
    udll<T>& operator =(const udll<T> &other);
    //delete function, this will also delete all duplicates including the first one.
    void deleteItem(T item);


    //check if the list is empty
    bool isEmpty()const;
    //return length
    int getLength()const;
    //Search
    bool searchItem(T item);
    //insert front
    void insertFront(T item);
    //push back
    void push_back(T item);
    //destroy function
    void destroy();
    //dummy copy function
    void copy(const udll<T> &other);
    //Get begin Iterator
    iterator<T> begin(){
        return iterator<T>(head);
    }
    //Get Reverse Begin Iterator
    iterator<T> rbegin(){
        return iterator<T>(tail);
    }
    //counting the occurrences of each item
    std::map <T,int> count_Occurrence ()const;

    //print duplicate results
    void printDuplicates()const;

    //remove selected duplicates
    void removeDuplicateSelect(const std::vector<T> &delValue, bool first);

    //remove all duplicates but the first
    void removeDuplicatesSF(T item);

    //I SEE DUPLICATES I DELETE
    void removeDuplicatesAll();

};


#endif