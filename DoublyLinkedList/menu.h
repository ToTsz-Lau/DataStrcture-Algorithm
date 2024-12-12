#include <iostream>
#include "udll.h"
#ifndef MENU_H
#define MENU_H

template <class T>
class menu{
private:
//the list that the user will be working with for majority of the time
    udll<T> main_list;

public:
//printing the main menu
    void print_menu()const;
//create random list
    void random_list();
//printing backward
    void print_backward()const;
//printing forward
    void print_forward()const;
//print out the duplicates
    void print_duplicate()const;
//delete duplicates that the user want to delete
    void delete_duplicates();
//duplicate branches
    void check_duplicate();
//void copy constructor and operator = overload demonstration
    void deleteItem();
//insert item front
    void insert_front();
//insert item back;
    void push_back();
    //input validation
    void input(char type);

//MAIN FUNCTION!!!!!!
    void run();




};

template<class T>
void menu<T>::input(char type) {
switch:

}

template<class T>
void menu<T>::push_back() {
    std::cout << "Enter the item you want to append to the back: " <<std::endl;
}

template<class T>
void menu<T>::insert_front() {

}

template<class T>
void menu<T>::deleteItem() {

}

template<class T>
void menu<T>::delete_duplicates() {

}

template<class T>
void menu<T>::print_duplicate() const {

}

template<class T>
void menu<T>::print_forward() const {

}

template<class T>
void menu<T>::print_backward() const {

}

template<class T>
void menu<T>::random_list() {

}

template<class T>
void menu<T>::print_menu() const {

}

template<class T>
void menu<T>::check_duplicate() {

}


#endif