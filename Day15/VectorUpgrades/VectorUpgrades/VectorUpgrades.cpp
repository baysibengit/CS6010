//
//  VectorUpgrades.cpp
//  VectorUpgrades
//
//  Created by Ben Baysinger  on 9/13/23.
//

#include "VectorUpgrades.hpp"

//Constructor function that takes in capacity.
MyVector::MyVector(size_t capacity)
{
    //check if capacity request is less than 0.
    if(capacity > 0){
        size_=0;
        capacity_ = capacity;
        data = new int[capacity_];
    }
}

//Constructor Function that takes in a vector of ints
MyVector::MyVector(const std::vector<int>& inputData)
{
    size_ = 0;
    capacity_ = 10;
    if (inputData.size() > 0) {
        for( const int& num: inputData) {
            push_back(num);
        }
    }
}

//Destructor vector function
 MyVector::~MyVector(){
    delete[] data;
    data = nullptr;
    size_ = 0;
    capacity_ = 0;
     //Acts as a test to make sure it works by printing out while build
    std::cout<< "Hello from Destructor";
}

//Copy Constructor Function that takes in size capacity thats double the size and data
MyVector::MyVector(const MyVector& rhs)
: size_(rhs.size()), capacity_(2* rhs.size()), data(nullptr){
    data = new int[capacity_];
    for (size_t i = 0; i < size_; i++){
        data[i] = rhs.data[i];
    }
}


//Operator = function
MyVector& MyVector::operator=(const MyVector& rhs)
{
    if (this != &rhs) {
        delete[] data;
        size_ = rhs.size();
        capacity_ = 2 * size_;
        return *this;
    }
    if(capacity_ > 0) {
        data = new int [capacity_];
        for (size_t i = 0; i < rhs.size(); i++) {
            data[i] = rhs.data[i];
            }
    }
    
    return *this;
}

//Operator [] function
const int& MyVector::operator[] (size_t index) const
{
    assert(index < size_ && "Out of bounds in operator[]!");
    return data[index];
}

//Size method
size_t MyVector::size() const
{
    return size_;
}

//Capacity method
size_t MyVector::capacity() const
{
    return capacity_;
}

//Grow Vector function
void MyVector::growVector()
{
    int* temp = new int[capacity_ * 2];
    for (int i = 0; i < size_; i++){
        temp[i] = data[i];
    }
    delete[] data;
    data = temp;
    temp = nullptr;
    capacity_*= 2;

}

//Make push back function
void MyVector::push_back(int value){
    if (size_ + 1 >= capacity_){
        growVector();
    }
    data[size_] = value;
    size_++;
}

//Pop back function
void MyVector::pop_back() {
//data[size -1] = inf;
    if (size_ > 0){
        size_--;
    }
}

//Set function
void MyVector::set(int value, size_t pos){
    if ( pos < capacity_){
        data[pos] = value;
    }
}

//Get function
int MyVector::get (size_t pos){
    assert(pos < size_ && "Invalid Position!");
    assert(data != nullptr && "Invalid Pointer");
    return data[pos];
}

//Get size method
 size_t MyVector::getSize(){
     return size_;
}

//Get capacity method
 size_t MyVector::getCapacity(){
     return capacity_;
}


//Draw up tests to test each function
void testSet(){
    MyVector v7(5);
    v7.push_back(5);
    v7.push_back(3);
    v7.push_back(6);
    v7.push_back(2);
    v7.push_back(1);
    //Call set to check and test against
    v7.set(4, 2);
    assert(v7[2] == 4 && "Set Function test failed");
}

void testGet(){
    MyVector v7(5);
    v7.push_back(5);
    v7.push_back(3);
    v7.push_back(6);
    v7.push_back(2);
    v7.push_back(1);
    assert(v7.get(0) == 5 && "Get function test failed");
}

void testPushBack(){
    MyVector v7(5);
    v7.push_back(5);
    v7.push_back(3);
    v7.push_back(6);
    v7.push_back(2);
    v7.push_back(1);
//Since push_back calls growVector we can just check capacity and size
    assert(v7.getCapacity() == 10 && "Push_back test failed capacity check");
    assert(v7.getSize() == 5 && "Push_back test failed size check");
}

void testPopBack(){
    //Empty vector
    MyVector v9(0);
    MyVector v7(5);
    v7.push_back(5);
    v7.push_back(3);
    v7.push_back(6);
    v7.push_back(2);
    v7.push_back(1);
    //Call popBack function
    v7.pop_back();
    //Check for size after popback call
    assert(v7.getSize() == 4 && "PopBack test failed size check");
    //Test empty vector
    v9.pop_back();
    assert(v9.getSize() == 0 && "PopBack test function failed for empty vector");
}

void testGetSize(){
    MyVector v7(5);
    v7.push_back(5);
    v7.push_back(3);
    v7.push_back(6);
    v7.push_back(2);
    v7.push_back(1);
    assert(v7.getSize() == 5 && "GetSize test failed");
}

void testGetCapacity(){
    MyVector v7(5);
    assert(v7.getCapacity() == 5 && "GetCapacity test failed");
}

void testGrow(){
    MyVector v7(5);
    v7.push_back(5);
    v7.push_back(3);
    v7.push_back(6);
    v7.push_back(2);
    v7.push_back(1);
    
    MyVector v8(5);
    v8.push_back(3);
    v8.push_back(4);
    v8.push_back(2);
   
    //Can test for capacity being doubled because pushback calls grow
    assert(v7.getCapacity() == 10 && "Grow function test failed for capacity check");
    //Test early to make sure it doesn't get called at wrong time
    assert(v8.getCapacity() == 5 && "Grow funciton test failed for early call");
}

void testCopyConstructor(){
    MyVector v1(5);
    v1.push_back(5);
    v1.push_back(3);
    v1.push_back(6);
    v1.push_back(2);
    v1.push_back(1);
    MyVector v2(5);
    v1 = v2;
    
    assert(v1.size() == v2.size() && "Copy Constructor test failed for data check");
    
    
}



