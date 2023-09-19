//
//  TemplateVector.hpp DiyVector Created by Ben Baysinger and Jake Jake Dame on 9/18/23.

#pragma once
#include <stdio.h>
#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <numeric>

// test functions - see imp file
void testMethods();
void testLabSTLVector ();

//================================DECLARATIONS=========================================


/* template class Vektor: a container that includes several basic methods and overloaded operators; it is a simplified version of std::vector */

template<typename T>
class Vektor
{
    
    // declare private member variables and function
private:
    
    // pointer to a memory address on the heap
    T* m_data;
    
    // variable that stores container's current size (number of elements in container)
    size_t m_size;
    
    /* variable that stores container's current capacity (number of spaces in container, including empty spaces) */
    
    size_t m_capacity;
    
    
    // Private member function
    void growVektor();
    
    
public:
    
    // Constructors
    Vektor();
    Vektor(size_t inputCapacity);
    Vektor(T* inputData, size_t size);
    Vektor(const std::vector<T>& inputData);
    
    // Copy constructor
    Vektor(const Vektor<T>& rhs);
    
    // Destructor
    ~Vektor();
    
    // Public member functions
    void push_back(T input);
    void pop_back();
    T get(size_t index) const;
    void set(T input, size_t index);
    size_t size() const;
    size_t capacity() const;
    void print() const;
    
    // Overloaded operators
    Vektor<T>& operator=(const Vektor<T>& rhs);
    
    T& operator[](size_t index);
    const T& operator[](size_t index) const;
    
    Vektor<T> operator+(const Vektor<T>& rhs) const;
    Vektor<T>& operator+=(const Vektor<T>& rhs);
    
    bool operator<(const Vektor<T>& rhs) const;
    bool operator>(const Vektor<T>& rhs);
    bool operator<=(const Vektor<T>& rhs);
    bool operator>=(const Vektor<T>& rhs);
    bool operator==(const Vektor<T>& rhs);
    bool operator!=(const Vektor<T>& rhs);
    
    
        T* begin()
        {
            return m_data;
    
        }
        T* end()
        {
            return m_data + m_size;
    
        }
    
        const T* begin() const
        {
            return m_data;
    
        }
        const T* end() const
        {
            return m_data + m_size;
    
        }
    
    
};

//==========================DEFINITIONS FOR TEMPLATE CLASS============================


//================================Constructors=========================================


/*
 CONSTRUCTOR: called automatically when a Vektor object is instantiated in main; creates empty Vektor
*/
template<typename T>
Vektor<T>::Vektor()
{
    // initialize size of empty Vektor (0)
    m_size = 0;
    
    // initialize reasonable non-zero arbitrary capacity
    m_capacity = 10;
    
    // allocate memory for (10) ints on the heap and assign first to m_data pointer
    m_data = new T[m_capacity];
    
    // ( printout for testing: see TESTS )
    std::cout << "Contructor has allocated memory.\n";
    
}


/*
 CONSTRUCTOR WITH CUSTOM CAPACITY: constructor that allows a user in main to set their own initial capacity
 */
template<typename T>
Vektor<T>::Vektor(size_t inputCapacity)
{
    // prevent user from creating an impossible Vektor of capacity 0
    assert(inputCapacity != 0 && "Size cannot be 0");
    
    // initialize size of Vektor
    m_size = 0;
    
    // assign capacity of Vektor to user-inputted integer
    m_capacity = inputCapacity;
    
    /* allocate memory on heap for as many ints as the user inputted and assign to m_data pointer */
    
    m_data = new T[m_capacity];
    
    // ( printout for testing: see TESTS )
    std::cout << "Contructor that takes input has allocated memory.\n";
    
}


/*
 CONSTRUCTOR THAT TAKES AN ARRAY: construct a Vektor using data from an array
 */
template<typename T>
Vektor<T>::Vektor(T* inputData, size_t size)
{
    // initialize size of empty Vektor (0)
    m_size = 0;
    
    // initiailize reasonable non-zero arbitrary capacity
    m_capacity = 10;
    
    // allocate memory for (10) ints on the heap and assign first to m_data pointer
    m_data = new T[m_capacity];
    
    // prevent a pointer with no data attached from trying to become a Vektor
    if(inputData != nullptr) {
        
        // pushback all the contents from the array into a Vektor
        for(size_t i = 0; i < size; i++) {
            push_back(inputData[i]);
        }
        
    }
}


/*
 CONSTRUCTOR THAT TAKES A VECTOR: construct a Vektor using data from an std::vector
 */
template<typename T>
Vektor<T>::Vektor(const std::vector<T>& inputData)
{
    // initialize size of empty Vektor (0)
    m_size = 0;
    
    // initiailize reasonable non-zero arbitrary capacity
    m_capacity = 10;
    
    // allocate memory for (10) ints on the heap and assign first to m_data pointer
    m_data = new T[m_capacity];
    
    // prevent construction if std::vector is empty
    if(inputData.size() > 0) {
        
        // pushback all the contents from the std::vector into a Vektor
        for(const T& datum : inputData) {
            push_back(datum);
        }
        
    }
}


/*
 COPY CONSTRUCTOR: makes a deep copy of this Vektor
 */
template<typename T>
Vektor<T>::Vektor(const Vektor<T>& rhs)
{
    /* prevent self-copies by only allowing things that do NOT have the same address to enter the copying logic */
    
    if(this != &rhs) {
        
        // deallocate this's memory
        delete[] m_data;
        
        // re-assign m_size to rhs's size
        m_size = rhs.size();
        
        // ensure m_capacity is double the new value of m_size
        m_capacity = 2 * m_size;
        
        // ensure capacity is not 0
        if(m_capacity > 0) {
            
            // allocate memory for m_data
            m_data = new T[m_capacity];
            
            // assign element values in tandem
            for(size_t i = 0; i < rhs.size(); i++) {
                m_data[i] = rhs[i];
            }
        }
    }
}


/*
 DESTRUCTOR: deallocates memory used by a Vektor object; sets its pointer to null
 */
template<typename T>
Vektor<T>::~Vektor()
{
    // set size to 0
    m_size = 0;
    
    // set capacity to 0
    m_capacity = 0;
    
    // deallocate memory of array starting at m_data
    delete[] m_data;
    
    // remove dangling pointer
    m_data = nullptr;
    
    // ( printout for testing: see TESTS )
    std::cout << "Destructor has deallocated memory.\n";

}

//================================MEMBER FUNCTIONS=====================================


/*
 PUSH BACK: function that takes in a user's inputted integer and makes it the last element of a Vektor
 */
template<typename T>
void Vektor<T>::push_back(T input)
{
    /* first, check to make sure that there will be space for a pushback by triggering growVektor if the current size of the Vektor, plus the anticipated pushback, equals the Vektor's capacity (in which case it should be grown before the pushback can occur) */
    
    if(m_size + 1 == m_capacity) {
        growVektor();
    }
    
    // assign the last element of the array to the value of the user's input
    m_data[m_size] = input;
    
    // increment the Vektor's m_size in order to maintain an accurate reflection of the current state of the object
    m_size++;
    
    // test
    assert((m_data[m_size - 1] == input) && "Input does not match last element.");
        
}


/*
 POP BACK: function the removes the last element from a Vektor
 */
template<typename T>
void Vektor<T>::pop_back()
{
    // guard against popping back an empty Vektor
    assert(m_size != 0);
        
    // decrement the size to maintain an accurate value of m_size
    m_size--;
}


/*
GETTER: function that returns the value of the element at a user inputted index
 */
template<typename T>
T Vektor<T>::get(size_t index) const
{
    // prevent a dangling pointer from being used
    assert(m_data != nullptr && "Pointer is null.");
    
    // guard against user inputting an invalid index number
    if(index >= m_size) {
        std::cerr << "Invalid get() input: index must be 0-" << m_size - 1 << "\n";
        exit(1);
    }
    
    // return the value at m_data[inputted index number]
    return m_data[index];
    
}


/*
 SETTER: function that takes a user's inputted integer value, and an index, and replaces the element at that index with the user's inputted value
 */
template<typename T>
void Vektor<T>::set(T input, size_t index)
{
    // guard against a user setting a value at an index that doesn't exist
    if(index >= m_size) {
        std::cerr << "Invalid set() input: index must be 0-" << m_size - 1 << "\n";
        exit(1);
    }
    
    // assign the user's input to the element at m_data[index]
    m_data[index] = input;
    
}


/*
 GET SIZE: a function that returns the current size of a Vektor
 */
template<typename T>
size_t Vektor<T>::size() const
{
    return m_size;
}


/*
 GET CAPACITY: a function that returns the current capacity of a Vektor
 */
template<typename T>
size_t Vektor<T>::capacity() const
{
    return m_capacity;
}


/*
 GROW: a function that manages the ratio between size and capacity of a Vektor
 */
template<typename T>
void Vektor<T>::growVektor()
{

    /* create a temporary array, with twice the capacity (of the current m_capacity value) */
    T* temp = new T[m_capacity * 2];
    
    /* copy contents from current Vektor to the temp array so that the current (too-small) Vektor can be deleted (memory freed) */
    for(size_t i = 0; i < m_size; i++) {
        // for-loop copies over data straight across
        temp[i] = m_data[i];
    }
    
    // the memory starting at the old Vektor is deallocated
    delete[] m_data;
    
    // m_data (original pointer) is re-pointed to where the temp's array is
    m_data = temp;
    // remove dangling pointer
    temp = nullptr;
    
    // double m_capacity to maintain accuracy of its value
    m_capacity *= 2;

}

/*
 PRINT: function that prints the contents of a Vektor
 */
template<typename T>
void Vektor<T>::print() const
{
    // newline at beginning and end of function for console readability
    std::cout << "\n";
    
    // for-loop moves through each element of a Vektor and prints it in a pattern
    for(size_t i = 0; i < m_size; i++) {
        std::cout << "Element " << i << ": " << m_data[i] << "\n";
    }
    std::cout << "\n";
    
}

//================================Operators============================================

/*
 OPERATOR =: function that assigns the value of one Vektor to this
 */
template<typename T>
Vektor<T>& Vektor<T>::operator=(const Vektor<T>& rhs)
{
    // if statement prevents this from being assigned to itself and leaking memory
    if(this != &rhs) {
        
        // deallocate this's memory
        delete[] m_data;
        
        // re-assign m_size to the size of rhs
        m_size = rhs.size();
        
        // re-assign m_capacity to be double the new value of m_size
        m_capacity = 2 * m_size;
        
        // ensure capacity is not zero
        if(m_capacity > 0) {
            
            // allocate new memory for this
            m_data = new T[m_capacity];
            
            // assign element values in tandem
            for(size_t i = 0; i < rhs.size(); i++) {
                m_data[i] = rhs[i];
                
            }
        }
    }
    
    // return this, which is now an exact copy of rhs
    return *this;
}

/*
OPERATOR []: overload array subscript operators for SETTING values of elements
 */
template<typename T>
T& Vektor<T>::operator[](size_t index)
{
    /* size_t prevents negative index values; assert prevents out-of-bounds values larger than size - 1 */
    
    assert(index < m_size && "Invalid index in operator[]");
    
    //
    return m_data[index];
}

/*
OPERATOR []: overload array subscript operators for GETTING values of elements
 */
template<typename T>
const T& Vektor<T>::operator[](size_t index) const
{
    /* size_t prevents negative index values; assert prevents out-of-bounds values larger than size - 1; const function prevents value of element from being changed */
    
    assert(index < m_size && "Invalid index in operator[]");
    
    // return the value of the element using m_data's array subscript operators
    return m_data[index];
}


/*
 OPERATOR +: function that adds / concatenates elements of this and another Vektor into a new Vektor
 */
template<typename T>
Vektor<T> Vektor<T>::operator+(const Vektor<T>& rhs) const
{
    // assert that the two Vektors are the same size
    assert((m_size == rhs.size()) && "Size mismatch in operator+");
    
    // declare Vektor to store the results of the sum operations
    Vektor result;
    
    // for-loop that adds elements together and pushes them back into result Vektor
    for(size_t i = 0; i < m_size; i++) {
        result.push_back(m_data[i] + rhs[i]);
    }
    
    // return result Vektor
    return result;
}

/*
 OPERATOR +=: function that adds a Vektor to this (without storing in separate result Vektor)
 */
template<typename T>
Vektor<T>& Vektor<T>::operator+=(const Vektor<T>& rhs)
{
    // shortcut if comparing an empty Vektor to this
    if(rhs.size() == 0) {
        return *this;
    }
    
    // for-loop that pushes back each element of rhs onto the end of this
    for(size_t i = 0; i < rhs.size(); i++) {
        push_back(rhs[i]);
    }
    
    // return the concatenated this
    return *this;
    
}


/*
 OPERATOR <: function that lexicographically compares another Vektor and this; function's logic is used to define the next three comparison functions
 */
template<typename T>
bool Vektor<T>::operator<(const Vektor<T>& rhs) const
{
    // condition where this is larger than rhs returns false
    if(m_size > rhs.size()) {
        return false;
    }
    
    /* for-loop that compares elements in tandem; continues to loop as long as this's element is not greater than rhs's element */
    
    for(size_t i = 0; i < m_size; i++) {
        if(m_data[i] > rhs[i]) {
            return false;
        }
    }
    
    // if neither of the false conditions have been triggered, this is smaller than rhs
    return true;
}


// see above; logic altered to return true if this is greater than rhs
template<typename T>
bool Vektor<T>::operator>(const Vektor<T>& rhs)
{
    return rhs < *this;
}


// see above; logic altered to return true if this is not greater than rhs
template<typename T>
bool Vektor<T>::operator<=(const Vektor<T>& rhs)
{
    return !(*this > rhs);
}


// see above; logic altered to return true if this is not lesser than rhs
template<typename T>
bool Vektor<T>::operator>=(const Vektor<T>& rhs)
{
    return !(*this < rhs);
}


/*
 OPERATOR ==: function that compares this and another Vektor to determine equality; this function's logic is used to determine the following function as well
 */
template<typename T>
bool Vektor<T>::operator==(const Vektor<T>& rhs)
{
    // if the two objects being compared are not the same size, return false
    if(m_size != rhs.size()) {
        return false;
    }
    
    // compare elements of the two Vektors in tandem; any inequality triggers false
    for(size_t i = 0; i < m_size; i++) {
        if(m_data[i] != rhs[i]) {
            return false;
        }
    }
    
    // return true if neither false conditions have been triggered
    return true;
}


// see above; logic altered to return true if this does not equal rhs
template<typename T>
bool Vektor<T>::operator!=(const Vektor<T>& rhs)
{
    return !(*this == rhs);
}

//Print vector function for Lab STL Vector
template<typename T>
void printVector (const Vektor<T>& vec)
{
    for (auto c : vec){
        std::cout<< c << "\n";
    }
}

