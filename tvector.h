#ifndef TVECTOR_H
#define TVECTOR_H

#include <iostream>
#include <stdlib.h>
using namespace std;

template<typename T>
class TVector
{
private:
    unsigned sz;                    // IN/OUT - the size of the vector
    unsigned cap;                   // IN/OUT - the capacity of the vector
    T* data;                        // IN/OUT - the dynamic array
    void expand();
    void expand( unsigned amount );
public:
    /*****************
     ** CONSTRUCTOR **
     *****************/
    TVector();                    // default constructor
    TVector( unsigned size );     // constructor with one parameter
    TVector( unsigned size,       // constructor with two parameters
               T value );

    /*****************
     ** DESTRUCTOR  **
     *****************/
    ~TVector();

    /***************
     ** ACCESSORS **
     ***************/
    unsigned size( ) const;
    unsigned capacity( ) const;
    bool empty( ) const;
    const T & at( unsigned index ) const;
    T & at( unsigned index );
    const T & front( ) const;
    T & front( );
    const T & back( ) const;
    T & back( );
    T & operator[](int index);
    const T & operator[](int index) const;

    /***************
     **  Mutator  **
     ***************/
    void insert( unsigned index, T value );
    void erase( unsigned index );
    void assign( unsigned n, T value );
    void push_back( T value );
    void pop_back( );
    void clear( );
    void resize( unsigned size );
    void resize( unsigned size, T value );
    void reserve( unsigned n );
};

/**************************************************************************
 * TVector Class
 *   This class is a similar version of the STL vector class that is
 *   capable of storing abstract datatype.
 *************************************************************************/

/*****************
 ** CONSTRUCTOR **
 *****************/

/**************************************************************************
 * IntVector();
 *      Constructor; initializes class attributes to zeros.
 *      Parameters: none
 *      Return: none
 *************************************************************************/
template <typename T>
TVector<T>::TVector()
{
    sz = 0;
    cap = 0;
    data = nullptr;
}

/**************************************************************************
 * IntVector( unsigned size );
 *      Constructor; initializes all values in array to 0.
 *      Parameters:
 *          size: size of the vector
 *      Return: none
 *************************************************************************/
template <typename T>
TVector<T>::TVector( unsigned size )   // IN - size of vector
{
    sz = size;
    cap = size;
    data = new T[sz]{0};
}


/**************************************************************************
 * IntVector( unsigned size,
                   int value );
 *      Constructor; initializes all elements of the array to the value of
 *      the 2nd parameter.
 *      Parameters:
 *          size: size of the vector
 *          value: the value to be stored
 *      Return: none
 *************************************************************************/
template <typename T>
TVector<T>::TVector( unsigned size,    // IN - size of vector
                         T value )       // IN - value passed in
{
    sz = size;
    cap = size;
    data = new T[sz]{value};

    // assign value to array
    for (unsigned int i = 0; i < sz; i++)
        data[i] = value;
}

/**************************************************************************
 * ~IntVector();
 *      destructor; deallocate all remaining dynamically allocated memory
 *          andreset the data members
 *      Parameters: none
 *      Return: none
 *************************************************************************/
template <typename T>
TVector<T>::~TVector()
{
    delete[] data;
    sz = 0;
    cap = 0;
}


/**************************************************************************
 * unsigned size( ) const;
 *
 *  Accessor; This method returns the current size of the IntVector object,
 *      which is the value stored in the sz data field.
 * ________________________________________________________________________
 *  Parameters: none
 *_________________________________________________________________________
 *  Returns: none
 *************************************************************************/
template <typename T>
unsigned TVector<T>::size( ) const
{
    return sz;
}

template <typename T>
unsigned TVector<T>::capacity( ) const
{
    return cap;
}

template <typename T>
bool TVector<T>::empty( ) const
{
    if(sz == 0)
        return true;

    return false;
}

template<typename T>
const T & TVector<T>:: at( unsigned index ) const  // IN - index number
{
    if(index >= sz)
        exit(1);

    return data[index];
}

template<typename T>
T &TVector<T>:: at( unsigned index )   // IN - index number
{
    if(index >= sz)
        exit(1);

    return data[index];
}

template<typename T>
void TVector<T>::insert( unsigned index,   // IN - the index position
                           T value )       // IN - the value to be inserted
{
    // exit if the index value greater than size
    if(index > sz)
        exit(1);

    // double the capacity when it runs out
    if(sz == cap){
        expand();
    }

    // shift all the element starts at the given index position by 1
    for (unsigned int i = sz + 1; i > index; i--)
        data[i] = data[i - 1];

    data[index] = value;
    sz++;   // increase size by 1
}

template<typename T>
void TVector<T>::erase( unsigned index )     // IN - the index location
{
    // if out of index
    if (index >= sz)
        exit(1);

    // move all elements after index position to right
    for (unsigned int i = index; i < sz; i++)
        data[i] = data[i + 1];

    sz--; // size decrement
}

template<typename T>
const T & TVector<T>::front( ) const
{
    return data[0];
}

template<typename T>
T & TVector<T>::front( )
{
    return data[0];
}

template<typename T>
const T & TVector<T>::back( ) const
{
    return data[sz -1];
}

template<typename T>
T & TVector<T>::back( )
{
    return data[sz -1];
}

template<typename T>
T& TVector<T>::operator[](int index){
    // exit if the index is out of bound
    if(index >= size()){
        exit(1);
    }
    return data[index];
}

template<typename T>
const T& TVector<T>::operator[](int index) const{
    // exit if the index is out of bound
    if(index >= size()){
        exit(1);
    }
    return data[index];
}


template<typename T>
void TVector<T>::assign( unsigned n,     // IN - the size of vector
                           T value )     // IN - the value to be stored
{
    sz = 0;
    resize(n,value);
}

template<typename T>
void TVector<T>::push_back( T value )  // IN - the value to be stored
{
    if (cap == 0)  // if the capacity of vector is 0, then expand to 1
        expand(++cap);
    else if (sz == cap)  // if no more capacity
        expand();

    data[sz++] = value;  // add the element to the back
}

template<typename T>
void TVector<T>::pop_back( )
{
    if (sz == 0)  // if no elements in vector
        exit(1);

    sz--; // size decrement
}

template<typename T>
void TVector<T>::clear( )
{
    delete [] data;  // delete contents
    sz = 0;  // make size to 0
}

template<typename T>
void TVector<T>::resize( unsigned size ) // IN - the size of vector
{
    // initialize the other newly resized values
    resize(size, {});
}

template<typename T>
void TVector<T>::resize( unsigned size,      // IN - size of the vector
                           T value )         // IN - the value to be stored
{
    //    if (size < sz)  // if new size is smaller than size, just reduce the size
    //        sz = size;
    //    else if (size > sz){  // if new size if bigger than size
    //        if (size >= cap){  // if no more capacity
    //            if (cap * 2 > size - cap)
    //                // if double the capacity is bigger than the difference between
    //                // new size and capacity
    //                expand();
    //            else
    //                expand(size - cap);
    //        }

    //        // put values into empty locations
    //        for (unsigned int i = sz; i < cap; i++)
    //            data[i] = value;

    //        sz = size;  // update the size
    //    }

    // expand the capacity if the size is larger than the current size
    if(size > sz){
        // expand if size is >= than capacity
        if(size > cap*2)
            expand(size);
        else
            expand();   // double the capacity

        // append the new values till it fills up to the size
        for(unsigned int i=sz; i<size; i++){
            data[i] = value;
        }
    }

    // update the size
    sz = size;
}

template<typename T>
void TVector<T>::reserve( unsigned n )       // IN - the value of capacity
{
    if (n > cap){  // if need to expand capacity
        // if double the capacity is larger than n
        if (n < cap * 2)
            expand();
        else        // update the capacity to n
            expand(n);
    }
}

template<typename T>
void TVector<T>::expand()
{
    cap = cap * 2;     // double the capacity
    T* temp = new T[cap];

    // copy all elements
    for(unsigned int i =0; i<sz; i++){
        temp[i] = data[i];
    }

    // reallocate memory for the dynamically allocated array
    delete[] data;
    data = temp;
    temp = nullptr;
}

template<typename T>
void TVector<T>::expand( unsigned amount )   // IN - the amount of capacity
{
    // Do work if new size if bigger than capacity
    if (amount > cap)
        cap = amount;
    T* temp = new T[cap];

    // copy all elements
    for(unsigned int i=0; i<sz; i++){
        temp[i] = data[i];
    }

    // reallocate memory for the dynamically allocated array
    delete[] data;
    data = temp;
    temp = nullptr; // assign temp pointer to Null

}


#endif // TVECTOR_H
