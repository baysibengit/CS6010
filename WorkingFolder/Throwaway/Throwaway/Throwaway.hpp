//
//  Throwaway.hpp
//  Throwaway
//
//  Created by Ben Baysinger  on 9/14/23.
//

#ifndef DiyVector_hpp
#define DiyVector_hpp
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
    MyVector makeVector(size_t initialCapacity);
    void push_back(int value);
    void pop_back();
    void set (int value, size_t pos);
    int get (size_t pos);
    void freeVector();
    unsigned long getSize();
    unsigned long getCapacity();
    void testFunctions ();
};

#endif /* DiyVector_hpp */
