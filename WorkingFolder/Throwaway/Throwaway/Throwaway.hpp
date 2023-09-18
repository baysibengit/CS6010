//
//  Throwaway.hpp
//  Throwaway
//
//  Created by Ben Baysinger  on 9/14/23.
//

#ifndef Throwaway_hpp
#define Throwaway_hpp
#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <stdio.h>
#include <mutex>
#include <fstream>
class MyVector{
    
private:
    int* data;
    size_t size_, capacity_;
    void growVector();
   
   
public:
    MyVector(const std::vector<int>& inputData);
    MyVector makeVector(size_t initialCapacity);
    void push_back(int value);
    void pop_back();
    void set (int value, size_t pos);
    int get (size_t pos)const;
    unsigned long getSize();
    unsigned long getCapacity();
    void testFunctions ();
    ~MyVector();
    MyVector& operator=(const MyVector& rhs);
    const int& operator[] (size_t index) const;
    size_t size() const;
    size_t capacity() const;
    MyVector(const MyVector& rhs);
    
  
};

#endif /* Throwaway_hpp */
