//implementation file for Unsorted Doubly Linked List Class
#include "udll.h"

//destroy function for basically destroying the whole list
template <class T>
void udll<T>::destroy(){
    //create a reference node to traverse the list
    UDLLnode<T> *current;

    //delete nodes as long as head is not a nullptr
    while(head != nullptr){
        current = head;
        head = head -> next;
        delete current;
    }

    /* previous while loop made head a nullptr, but we need
    to manually set tail to nullptr and make lenght = 0 */
    tail = nullptr;
    length = 0;
    for (auto it : frequencyMap){
        delete it ->second;
    }

}


//desctructor
template<class T>
udll<T>::~udll(){
    //calls the destroy function that actually does the job
    destroy();
}

//dummy copy function
template<class T>
void udll<T>::copy(const udll<T> &other){
    //set length equals to length of the other list
    length = other.length;
    //temporary node pointer to help traverse the other list
    UDLLnode<T> *temp = other.head;
    //only goes into the while loop if temp/other.head is not nullptr
    while(temp){
        push_back(temp->data);
        temp = temp ->next;
    }
}



//copy constructor, assuming the head and tail to be nullptr
template<class T>
udll<T>::udll(const udll<T> &other):head(nullptr), tail(nullptr){
    //calls the copy function that does the actual work
    copy(other);
}


//overloading assignment operator
template <class T>
udll<T>& udll<T>::operator =(const udll<T> &other){
    //prevent self assignment
    if(this != &other){
        //clear out the current data
        destroy();
        //copy the data from the other list to this list
        copy(other);
    }
    //returning the new object by reference
    return *this;
}


//delete specified items, all of them
template <class T>
void udll<T>::deleteItem(T item){
    //first check if the list is empty
    if(isEmpty()){
        std::cout << "Error: The List is already Empty.\n";
    }else{
        //create a temporary node pointer to help traverse the list
        UDLLnode<T> *temp = head;
        //comparison indicator
        int check = length;
        //as long as temp is not a nullptr
        while(temp){
            if (item == temp->data){
                //found the item
                if (temp->prev){
                    //if item is not at head
                    temp->prev->next = temp->next;
                }else{
                    //if item is at head
                    head = head->next;
                }

                if(temp->next){
                    //item is not at tail
                    temp -> next -> prev = temp -> prev;
                }else{
                    //item is at tail
                    tail = temp ->prev;
                }

                delete temp;
                length--;
            }

            temp = temp->next;
        }

        if (check==length)
            std::cout << "Item is not in the list.\n";
    }

}
//check if the list is empty
template<class T>
bool udll<T>:: isEmpty()const{
    return head == nullptr;
}



//return length
template <class T>
int udll<T>:: getLength()const{
    return length;
}

//Search
template <class T>
bool udll<T>::searchItem(T item){
    for(iterator<T> it = begin(); it != nullptr; it++){
        if(*it == item) return true;
    }
    return false;
}


//insert front
template <class T>
void udll<T>::insertFront(T item){
    UDLLnode<T> *temp = new UDLLnode<T>(nullptr, nullptr, item);
    if (isEmpty()){
        //when the list is empty
        head = tail = temp;
    }else{
        //when the list is not empty
        temp -> next = head;
        head -> prev = temp;
        head = temp;
    }
    length++;
}

//push back
template <class T>
void udll<T>::push_back(T item){
    UDLLnode<T> *temp = new UDLLnode<T>(nullptr, nullptr, item);
    if(isEmpty()){
        //if the list is empty, this will be the first and last node
        head = tail = temp;
    }else{
        temp->prev = tail;
        tail -> next = temp;
        tail = temp;
    }
    length++;
}

//counting the occurrences of each item
template <class T>
std::map <T,int> udll<T>::count_Occurrence ()const{
    UDLLnode<T> * temp = head;
    while(temp){
        frequencyMap[temp->data]++;
        temp = temp -> next;
    }
    return frequencyMap;
}

//Trying to only print out the items that have duplicates and how many duplicates
template <class T>
void udll<T>::printDuplicates()const{
    std::cout << "DUPLICATE ITEM\tCOUNTS\n";
    for(const auto& it: frequencyMap){
        if(it.second > 1){
            std::cout << it.first << "\t" << it.second << std::endl;
        }
    }
}

//remove selected duplicates, the vector contains duplicated items that the user want to delete.
template <class T>
void udll<T>::removeDuplicateSelect(const std::vector<T> &delValue, bool first){

    UDLLnode<T> *temp = head;

    if(first){
        //if the user decide to delete all of the but the first one
        while(temp){
            for(const T it:delValue){
                //iterate through the vector
                removeDuplicatesSF(it);
            }
        }
    }else{
        //if the user decide to delete all of them
        for(const T it: delValue){
            deleteItem(it);
        }
    }

}

//remove all duplicates but the first encounter
template <class T>
void udll<T>::removeDuplicatesSF(T item){
    std::unordered_set <T> first_encounter;
    UDLLnode<T> *temp = new UDLLnode<T>;
    temp = head;

    while(temp){
        if(frequencyMap[temp->data] >1){
            //is the current node a duplicate according to the map?
            //Does the current node has data that is listed in the vector
            if(first_encounter.find(item)){
                //if this is not the first time encountering the item, delete the item
                //sadly will need to go through the same deletion process again, could be optimized?
                if (item == temp->data){
                    //found the item
                    if (temp->prev){
                        //if item is not at head
                        temp->prev->next = temp->next;
                    }else{
                        //if item is at head
                        head = head->next;
                    }

                    if(temp->next){
                        //item is not at tail
                        temp -> next -> prev = temp -> prev;
                    }else{
                        //item is at tail
                        tail = temp ->prev;
                    }

                    delete temp;
                    length--;
                }
            }else{
                //if this is the first time encountering the item, insert into the set
                first_encounter.insert(temp->data);
                temp = temp->next;
            }
        }else{

            std::cout << "Error: Item: " << temp->data << " does not exist in the list or does not have any duplicates." << std::endl;

        }
    }
}


template <class T>
void udll<T> :: removeDuplicatesAll(){
    //NO MORE DUPLICATES
    std::unordered_set<T> first_encounter;
    UDLLnode<T> * temp = head;

    while(temp){
        //check map to see if it has duplicate
        if(frequencyMap[temp->data]>1){
            if(first_encounter.find(temp->data)){
                deleteItem(temp->data);
            }else{
                first_encounter.insert(temp->data);
            }
            temp = temp->next;
        }else{
            std::cout << "Error: Item: " << temp->data << " does not exist in the list or does not have any duplicates." << std::endl;
        }
    }
}
