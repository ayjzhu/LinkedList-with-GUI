#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "listempty.h"
#include "complex.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <type_traits>

using namespace std;

/*****************
 **    struct   **
 *****************/

/**************************************************************************
 * IntNode struct
 *  This struct will define the data and next pointer of the IntNode object
 *************************************************************************/
template <typename E>
struct Node{
    E data;
    Node<E>* next;
    Node(E data): data(data), next(0){}
};

/**************************************************************************
 * LinkedList Class
 *   This class will construct and get the data of a linked list
 *************************************************************************/
template <typename E>
class LinkedList
{
public:

    /**********************************************************************
     * Iterator Class
     *   This class will construct an iterator and overload the operators
     *********************************************************************/
    class Iterator{

    public:
        /*****************
         ** CONSTRUCTOR **
         *****************/
        Iterator();
        Iterator(Node<E> *p);

        /***************
         **  Mutator  **
         ***************/
        Iterator operator++();

        /***************
         ** ACCESSORS **
         ***************/
        bool operator==(const Iterator& right)const;
        bool operator!=(const Iterator &right) const;
        E operator*();

    private:
        Node<E>* current;   // IN/OUT - the current node
    };

    // default constructor
    LinkedList();

    // copy constructor
    LinkedList(const LinkedList& source);

    // destructor
    ~LinkedList();

    // assignment copy constructor
    LinkedList& operator=(const LinkedList& source);

    // print all nodes' data in the list
    string display() const;

    string display_portion(int start, int end) const;

    // push an element at the front
    void push_front(const E& value);

    // push an element to the back
    void push_back(const E& value);

    // delete an element at the front
    void pop_front() throw(ListEmpty);

    // return the data in the first element
    const E& front() const throw(ListEmpty);

    // return the data in the last element
    const E& back() const throw(ListEmpty);

    // makes the List Empty by deallocating all of the nodes in the List
    void clear();

    // sort the list using selection sort from ascending order
    void select_sort();

    // insert an elment into the appropriate position by value
    void insert_sorted(const E& value);

    void insert_at_index(const E& value, int index);

    // delete all the duplicates element in the list
    void remove_duplicates();

    void complex_remove_duplicates();
    // return the iterator at the beginning of the list
    Iterator begin(){
        return Iterator(head);
    }

    // return the iterator after the last element
    Iterator end(){
        return NULL;
    }

    // return the length of the list
    int length() const;

    // return the sum of data in the list
    int sum() const;

    // if the list is empty
    bool isEmpty() const;

private:
    Node<E>* head;  // IN/OUT - head node
    Node<E>* tail;  // IN/OUT - tail node

    // counts the number of nodes in a list
    int countNodes(Node<E> *nodePtr) const;
    // swap two node's data
    void swap(Node<E>* &a, Node<E>* &b);
};

/**************************************************************************
 * Iterator();
 *      Constructor; initializes the class attributes current to NULL
 *      Parameters: none
 *      Return: none
 *************************************************************************/
template<typename E>
LinkedList<E>::Iterator::Iterator(){
    current = NULL;
}

/**************************************************************************
 * Iterator(IntNode *p)
 *      Constructor; assign class attributes current to a parameter object
 *      *p: an IntNode type pointer
 *      Return: none
 *************************************************************************/
template<typename E>
LinkedList<E>::Iterator::Iterator(Node<E>* p){
    current = p;
}


/**************************************************************************
 * operator()
 *      Accessor; gets the iterator of the next object
 *      none
 *      Return: the next iterator object
 *************************************************************************/
template<typename E>
typename LinkedList<E>::Iterator LinkedList<E>::Iterator:: operator++(){
    current = current->next;

    return current;
}

/**************************************************************************
 * operator==(const Iterator &right)
 *      Accessor; compare whether the objects are equal
 *      Parameters: right: the right hand iterator object
 *      Return: a boolean
 *************************************************************************/

template<typename E>
bool LinkedList<E>::Iterator::operator==(const Iterator &right)const
{
    if (current == right.current)
        return true;
    return false;
}

/**************************************************************************
 * operator!=(const Iterator &right)
 *      Accessor; compare whether the objects are non-equal
 *      Parameters: right: the right hand iterator object
 *      Return: a boolean
 *************************************************************************/

template<typename E>
bool LinkedList<E>::Iterator::operator!=(const Iterator &right) const{
    return current != right.current;
}

/**************************************************************************
 * operator*()
 *      Accessor; overload the pointer operator and get the current node data
 *      Parameters: none
 *      Return: *this: the object itself
 *************************************************************************/
template<typename E>
E LinkedList<E>::Iterator::operator*(){
    return current->data;
}

/**************************************************************************
 * LinkedList();
 *      Constructor; initializes the class attributes IntNode pointers to
 *                   NULL
 *      Parameters: none
 *      Return: none
 *************************************************************************/
template<typename E>
LinkedList<E>::LinkedList(){
    head = tail = NULL;
}

/**************************************************************************
 * LinkedList();
 *      Constructor; copy the class attributes from the source object
 *      Parameters: source: the source object to copy from
 *      Return: none
 *************************************************************************/
template<typename E>
LinkedList<E>::LinkedList(const LinkedList& source){

    if (this != &source){  // if they are not same object
        Node<E>* cur = source.head;

        // initialize head and tail first
        head = new Node<E>(cur->data);
        tail = head;
        cur = cur->next;

        while (cur){
            tail->next = new Node<E>(cur->data);
            tail = tail->next;

            cur = cur->next;
        }
    }
}

/**************************************************************************
 * ~LinkedList();
 *      Destructor; destruct the list and deallocate memory
 *      Parameters: none
 *      Return: none
 *************************************************************************/
template<typename E>
LinkedList<E>::~LinkedList(){

    Node<E>* cur = head;

    while (head){
        head = head->next;
        delete cur;
        cur = head;
    }
}

/**************************************************************************
 * operator=(const LinkedList& source)
 *     parameter: source: a LinkedList type object
 *     return: the data attributes of the source object
 *************************************************************************/
template<typename E>
LinkedList<E>& LinkedList<E>::operator=(const LinkedList& source){

    if (this != &source){
        Node<E>* cur = source.head;

        head = new Node<E>(cur->data);
        tail = head;
        cur = cur->next;

        while (cur){
            tail->next = new Node<E>(cur->data);
            tail = tail->next;

            cur = cur->next;
        }
    }
}

/**************************************************************************
 * display();
 *      Accessor; display the linked list in the order from left to right
 *      Parameters: none
 *      Return: none
 *************************************************************************/
template<typename E>
string LinkedList<E>::display() const{

    std::ostringstream outstr;

    Node<E>* current = head;

    while (current != NULL){

        outstr << current->data;

        if (current->next != NULL)
            outstr << " -> ";

        current = current->next;
    }

    return outstr.str();
}

/**************************************************************************
 * display_portion();
 *      Accessor; display the linked list in a portion
 *      Parameters: start: start index
 *                  end: end index
 *      Return: none
 *************************************************************************/
template<typename E>
string LinkedList<E>::display_portion(int start, int end) const{

    std::ostringstream outstr;

    Node<E>* current = head;

    for (int i = 0; i < start; i++)
        current = current->next;

    while (current != NULL && start <= end){

        outstr <<  current->data;

        if (current->next != NULL && start < end)
            outstr << " -> ";

        current = current->next;
        ++start;
    }

    return outstr.str();
}

/**************************************************************************
 * push_front();
 *      Mutator; store the data infront of the previous data
 *      Parameters: data to be stored
 *      Return: none
 *************************************************************************/
template<typename E>
void LinkedList<E>::push_front(const E& value){
    Node<E>* temp = new Node<E>(value);

    temp->next = head;
    head = temp;

    if (!tail)
        tail = head;
}

/**************************************************************************
 * push_back();
 *      Mutator; store the data at the back of the previous data
 *      Parameters: value: data to be stored
 *      Return: none
 *************************************************************************/
template<typename E>
void LinkedList<E>::push_back(const E& value){

    if (head == NULL){
        head = new Node<E>(value);
        tail = head;
    }
    else{
        tail->next = new Node<E>(value);
        tail = tail->next;
    }

}

/**************************************************************************
 * pop_front();
 *      Accessor; pop the data at the front of the list
 *      Parameters: none
 *      Return: none
 *************************************************************************/
template<typename E>
void LinkedList<E>::pop_front()throw(ListEmpty){
    if (head){
        Node<E>* temp = head;
        head = head->next;
        delete temp;
    }
    else
        throw ListEmpty();
}

/**************************************************************************
 * front();
 *      Accessor; return the data at the front of the list
 *      Parameters: none
 *      Return: the first element in the list
 *************************************************************************/
template<typename E>
const E& LinkedList<E>::front() const throw(ListEmpty){
    if (head)
        return head->data;
    else
        throw ListEmpty();
}

/**************************************************************************
 * back();
 *      Accessor; return the data at the end of the list
 *      Parameters: none
 *      Return: the last element in the list
 *************************************************************************/
template<typename E>
const E& LinkedList<E>::back() const throw(ListEmpty){
    if (tail)
        return tail->data;
    else
        throw ListEmpty();
}


/**************************************************************************
 * clear();
 *      Mutator; clear all the data from the list
 *      Parameters: none
 *      Return: none
 *************************************************************************/
template<typename E>
void LinkedList<E>::clear(){
    Node<E>* temp = head;

    while (head){
        temp = head->next;
        delete head;
        head = temp;
    }
}

/**************************************************************************
 * select_sort()
 *      Mutator; sort the list in ascending order using selection
 *                  algorithm
 *      Parameters: none
 *      Return: none
 *************************************************************************/
template<typename E>
void LinkedList<E>::select_sort(){

    Node<E>* current = head;

    while (head != NULL){
        Node<E>* min = head;
        Node<E>* temp = head->next;

        while (temp != NULL){
            if (min->data > temp->data){
                min = temp;
            }
            temp = temp->next;
        }

        swap(head, min);
        head = head->next;
    }

    head = current;
}

/**************************************************************************
 * swap(Node<E>* &a, Node<E>* &b)
 *      Mutator; swap the position of the two values
 *      Parameters:
 *          a: the data node to be swapped
 *          b: the data node to be swapped
 *      Return: none
 *************************************************************************/
template<typename E>
void LinkedList<E>::swap(Node<E>* &a, Node<E>* &b){
    E temp = a->data;
    a->data = b->data;
    b->data = temp;
}

/**************************************************************************
 * insert_sorted()
 *      Mutator; insert the data into an appropriate position of
 *               the list
 *      Parameters: value: the data to be inserted
 *      Return: none
 *************************************************************************/
template<typename E>
void LinkedList<E>::insert_sorted(const E& value){
    Node<E>* cur;
    Node<E>* temp = new Node<E>(value);

    if (head == NULL || head->data >= value){
        temp->next = head;
        head = temp;
    }
    else{
        cur = head;

        while (cur->next != NULL && cur->next->data < value)
            cur = cur->next;

        // if inserting at tail
        if(cur == tail){
            push_back(value);
        }

        temp->next = cur->next;
        cur->next = temp;
    }
}

/**************************************************************************
 * insert_at_index()
 *      Mutator; insert the data into a given  position of the list
 *      Parameters: value: the data to be inserted
 *                  index: the index position to be inserted
 *      Return: none
 *************************************************************************/
template<typename E>
void LinkedList<E>::insert_at_index(const E& value, int index){

    if(index > this->length() || index < 0){
        cout << "Index out of bound" << endl;
        exit(1);
    }

    Node<E>* walker;
    Node<E>* cur;
    Node<E>* temp = new Node<E>(value);

    walker = head;
    cur = walker;
    // iterate through the list till the coresponding index
    for(int i = 0; i<index; i++){
        cur = walker;
        walker = walker->next;
    }

    // edge case: if inserting at index 0
    if(walker == head){
        push_front(value);
    }
    // edge case: if inserting at last index
    else if(cur == tail){
        push_back(value);
    }
    else{
        temp->next = cur->next;
        cur->next = temp;
    }
}


/**************************************************************************
 * remove_duplicates()
 *      Mutator; remove all the duplicates data in the list
 *      Parameters: none
 *      Return: none
 *************************************************************************/
template<typename E>
void LinkedList<E>::remove_duplicates(){
    Node<E>* temp;
    Node<E>* current;

    for (Node<E>* i = head; i != NULL; i = i -> next)
    {
        current = i;

        // if theres more entry in the list
        while( current -> next )
        {
            // if the next data is equal to the current data
            if( current -> next -> data == i -> data )
            {
                // edge case - deleting the last entry
                if(current -> next == tail){
                    tail = current; // set the tail to the previous node
                }
                // store the next entry of the deleting item
                temp = current -> next -> next;
                delete current -> next;
                current -> next = temp;   // connect the list

            } else {
                current = current -> next;
            }
        }
    }
}

/**************************************************************************
 * complex_remove_duplicates()
 *      Mutator; remove all the duplicates Complex data in the list
 *      Parameters: none
 *      Return: none
 *************************************************************************/
template<typename Complex>
void LinkedList<Complex>::complex_remove_duplicates(){
    Node<Complex>* temp;
    Node<Complex>* current;
    double epsilon = 0.001;

    //      if((std::abs(real - rhs.real) < epsilon )
    //              && (std::abs(imaginary - rhs.imaginary) < epsilon) )

    for (Node<Complex>* i = head; i != NULL; i = i -> next)
    {
        current = i;

        // if theres more entry in the list
        while( current -> next )
        {
            // if the next data is equal to the current data
            if((std::abs(current -> next -> data.real - i -> data.real) < epsilon)
                    && (std::abs(current -> next -> data.imaginary
                                 - i->data.imaginary) < epsilon))
            {
                // edge case - deleting the last entry
                if(current -> next == tail){
                    tail = current; // set the tail to the previous node
                }
                // store the next entry of the deleting item
                temp = current -> next -> next;
                delete current -> next;
                current -> next = temp;   // connect the list

            } else {
                current = current -> next;
            }
        }
    }
}

/**************************************************************************
 * countNodes()
 *      Accessor; counts all the nodes in the list
 *      Parameters: nodePtr: a pointer to a node
 *      Return: none
 *************************************************************************/
template<typename E>
int LinkedList<E>::countNodes(Node<E> *nodePtr) const
{
    if (nodePtr != NULL)
        return 1 + this->countNodes(nodePtr->next);
    return 0;
}

/**************************************************************************
 * length()
 *      Accessor; get the total number of nodes in the list
 *      Parameters: none
 *      Return: the number of nodes
 *************************************************************************/
template<typename E>
int LinkedList<E>::length() const
{
    return countNodes(head);
}

/**************************************************************************
 * sum()
 *      Accessor; get the total value of nodes in the list
 *      Parameters: none
 *      Return: the sum of all the values
 *************************************************************************/
template<typename E>
int LinkedList<E>::sum() const{

    int total = 0;

    static Node<E>* cur = head;

    if (cur == NULL)
        return 0;
    else{
        total += cur->data;
        cur = cur->next;
        return total + sum();
    }
}

/**************************************************************************
 * isEmpty()
 *      Accessor; check if the list is empty
 *      Parameters: none
 *      Return: a boolean
 *************************************************************************/
template<typename E>
bool LinkedList<E>::isEmpty() const{
    return head;
}

#endif // LINKEDLIST_H
