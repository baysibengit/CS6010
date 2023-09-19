//
//  VectorUpgrades.hpp
//  VectorUpgrades
//
//  Created by Ben Baysinger  on 9/13/23.
//

#ifndef VectorUpgrades_hpp
#define VectorUpgrades_hpp
#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <stdio.h>
class MyVector{
    
private:
    int* data;
    size_t size_, capacity_;
    void growVector();
public:
    void push_back(int value);
    void pop_back();
    void set (int value, size_t pos);
    int get (size_t pos);
    size_t getSize();
    size_t getCapacity();
    void testFunctions ();
    //Constructor
    MyVector(size_t capacity);
    MyVector(const std::vector<int>& inputData);
    //Destructor
    ~MyVector();
    //Copy Constructor
    MyVector(const MyVector& rhs);
    //Size and Capacity retrievers
    size_t size() const;
    size_t capacity() const;
    //Operator signatures
    MyVector& operator=(const MyVector& rhs);
    const int& operator[] (size_t index) const;
    bool operator<(const MyVector& rhs) const;
    bool operator>(const MyVector& rhs)const;
    bool operator<=(const MyVector& rhs)const;
    bool operator>=(const MyVector& rhs)const;
    bool operator==(const MyVector& rhs)const;
    bool operator!=(const MyVector& rhs)const;
};



//Test Functions
void testPushBack();
void testPopBack();
void testSet();
void testGet();
void testGrow();
void testGetSize();
void testGetCapacity();
void testCopyConstructor();
void testOperatorEquals();
void testOperatorIndex();
void testOperatorLessThan();
void testOperatorGreaterThan();
void testOperatorLessThanEqualToo();
void testOperatorGreaterThanEqualToo();
void testOperatorDoubleEquals();
void testOperatorDoesNotEqual();


#endif /* VectorUpgrades_hpp */
