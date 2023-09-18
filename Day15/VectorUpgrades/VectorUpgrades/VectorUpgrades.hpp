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
    
};



//Test Functions
void testPushBack();
void testPopBack();
void testSet();
void testGet();
void testGrow();
void testGetSize();
void testGetCapacity();

////Constructor function that takes in capacity.
//MyVector::MyVector(size_t capacity)
//{
//    //check if capacity request is less than 0.
//    if(capacity > 0){
//        size_=0;
//        capacity_ = capacity;
//        data = new int[capacity_];
//    }
//}
//
////Constructor Function that takes in a vector of ints
//MyVector::MyVector(const std::vector<int>& inputData)
//{
//    size_ = 0;
//    capacity_ = 10;
//    if (inputData.size() > 0) {
//        for( const int& num: inputData) {
//            push_back(num);
//        }
//    }
//}
//
////Destructor vector function
// MyVector::~MyVector(){
//    delete[] data;
//    data = nullptr;
//    size_ = 0;
//    capacity_ = 0;
//    std::cout<< "Hello from Destructor";
//}
//
////Copy Constructor Function that takes in size capacity thats double the size and data
//MyVector::MyVector(const MyVector& rhs)
//: size_(rhs.size()), capacity_(2* rhs.size()), data(nullptr){
//    data = new int[capacity_];
//    for (size_t i = 0; i < size_; i++){
//        data[i] = rhs.data[i];
//    }
//}
//
//
////Operator = function
//MyVector& MyVector::operator=(const MyVector& rhs)
//{
//    if (this != &rhs) {
//        delete[] data;
//        size_ = rhs.size();
//        capacity_ = 2 * size_;
//        return *this;
//    }
//    if(capacity_ > 0) {
//        data = new int [capacity_];
//        for (size_t i = 0; i < rhs.size(); i++) {
//            data[i] = rhs.data[i];
//            }
//    }
//    
//    return *this;
//}
//
////Operator [] function
//const int& MyVector::operator[] (size_t index) const
//{
//    assert(index < size_ && "Out of bounds in operator[]!");
//    return data[index];
//}
//
////Size method
//size_t MyVector::size() const
//{
//    return size_;
//}
//
////Capacity method
//size_t MyVector::capacity() const
//{
//    return capacity_;
//}
//
////Grow Vector function
//void MyVector::growVector()
//{
//    int* temp = new int[capacity_ * 2];
//    for (int i = 0; i < size_; i++){
//        temp[i] = data[i];
//    }
//    delete[] data;
//    data = temp;
//    temp = nullptr;
//    capacity_*= 2;
//
//}
//
////Make push back function
//void MyVector::push_back(int value){
//    if (size_ + 1 >= capacity_){
//        growVector();
//    }
//    data[size_] = value;
//    size_++;
//}
//
////Pop back function
//void MyVector::pop_back() {
////data[size -1] = inf;
//    if (size_ > 0){
//        size_--;
//    }
//}
//
////Set function
//void MyVector::set(int value, size_t pos){
//    if ( pos < capacity_){
//        data[pos] = value;
//    }
//}
//
////Get function
//int MyVector::get (size_t pos){
//    assert(pos < size_ && "Invalid Position!");
//    assert(data != nullptr && "Invalid Pointer");
//    return data[pos];
//}
//
////Get size method
// size_t MyVector::getSize(){
//     return size_;
//}
//
////Get capacity method
// size_t MyVector::getCapacity(){
//     return capacity_;
//}

#endif /* VectorUpgrades_hpp */
