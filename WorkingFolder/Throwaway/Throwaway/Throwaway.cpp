//
//  Throwaway.cpp
//  Throwaway
//
//  Created by Ben Baysinger  on 9/14/23.
//

#include "Throwaway.hpp"


//Destructor vector function
 MyVector::~MyVector(){
    delete[] data;
    data = nullptr;
    size_ = 0;
    capacity_ = 0;
    std::cout<< "Hello from Destructor";
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
            data[i] = rhs[i];
            }
    }
    
    return *this;
}

//Constructor Function
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



//Copy Constructor Function that takes in size capacity thats double the size and data
MyVector::MyVector(const MyVector& rhs)
: size_(rhs.size()), capacity_(2* rhs.size()), data(nullptr){
    data = new int[capacity_];
    for (size_t i = 0; i < size_; i++){
        data[i] = rhs.data[i];
    }
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
int MyVector::get (size_t pos)const{
    assert(pos < size_ && "Invalid Position!");
    assert(data != nullptr && "Invalid Pointer");
    return data[pos];
}

//Make Vector function
MyVector MyVector::makeVector(size_t initialCapacity )
    {
       capacity_ = initialCapacity;
       size_ = 0;
        data = new int[capacity_];
        return *this;
    }

//Get size method
 unsigned long MyVector::getSize(){
     return size_;
}

//Get capacity method
unsigned long MyVector::getCapacity(){
     return capacity_;
}

//Draw up tests to test each function
void MyVector::testFunctions (){
    //Initializing test vector to test freeVector function
    //By initializing even of itself is testing makeVector
  MyVector v7 = makeVector(5);
    v7.push_back(5);
    v7.push_back(3);
    v7.push_back(6);
    v7.push_back(2);
    v7.push_back(1);
    //Calling freeVector function on test function
    v7.~MyVector();
    //Checking size and capacity post function call
    assert(v7.size_ == 0 && "FreeVector test failed for size check");
    assert(v7.capacity_ == 0 && "FreeVector test failed for capacity check");

    //Initializing test vector to test growVector and push_back function
    MyVector v8 = makeVector(5);
      v8.push_back(5);
      v8.push_back(3);
      v8.push_back(6);
      v8.push_back(2);
      v8.push_back(1);
       

    
    //Since push_back calls growVector we can just check capacity
   // assert(v8.capacity_ == 0 && "growVector/push_back test failed");
    //Checking elements to test push_back and get
    assert(v8.get(0) == 5 && "Push_back/get test failed");
    assert(v8.get(4) == 1 && "Push_back/get test failed");
    
    //Initializing vector to test pop_back function
    MyVector v6 = makeVector(5);
      v6.push_back(5);
      v6.push_back(3);
      v6.push_back(6);
      v6.push_back(2);
      v6.push_back(1);
    
    //Call pop_back
    v6.pop_back();
    //testing pop_back
    assert(v6.size_ == 4 && "Pop_back test failed");
   
    //Testing get and set functions
    v6.set(4, 2);
   // assert(v6.get(2) == 4 && "Set/get test failed");
    
    //Testing getSize and getCapacity methods
    assert(v6.getSize() == 4 && "getSize method test failed");
    assert(v6.getCapacity() == 10 && "getCapacity method test failed");
    
    //Test Various functions against empty vectors
    MyVector v9 = makeVector(0);
    assert(v9.getSize() == 0 && "getSize method test failed for empty vector");
    assert(v9.getCapacity() == 0 && "getCapacity method test failed for empty vector");
    
}
