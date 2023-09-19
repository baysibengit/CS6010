//
//  VectorUpgrades.cpp
//  VectorUpgrades
//
//  Created by Ben Baysinger and Jake Dame  on 9/13/23.
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
        //Delete Data
        delete[] data;
        //Copy size and double capacity
        size_ = rhs.size();
        capacity_ = 2 * size_;
        //Allocate memory
        data = new int [capacity_];
        //Copy over data
        for (size_t i = 0; i < rhs.size(); i++) {
            data[i] = rhs.data[i];
            }
    }
    return *this;
}

//Operator [] function
const int& MyVector::operator[] (size_t index) const
{
    //First check that index is less than size
    assert(index < size_ && "Out of bounds in operator[]!");
    //Returns what data lies within index
    return data[index];
}

/*
 OPERATOR <: function that lexicographically compares another vector and this; function's logic is used to define the next three comparison functions
 */
bool MyVector::operator<(const MyVector& rhs) const
{
    // condition where this is larger than rhs returns false
    if(size_ > rhs.size()) {
        return false;
    }
    
    /* for-loop that compares elements in tandem; continues to loop as long as this's element is not greater than rhs's element */
    
    for(size_t i = 0; i < size_; i++) {
        if(data[i] > rhs[i]) {
            return false;
        }
    }
/* if neither of the false conditions have been triggered, this is smaller than rhs*/
    return true;
}
    
// see above; logic altered to return true if this is greater than rhs
bool MyVector::operator>(const MyVector& rhs)const
    {
        return rhs < *this;
    }
    
// see above; logic altered to return true if this is not greater than rhs
bool MyVector::operator<=(const MyVector& rhs)const
    {
        return !(*this > rhs);
    }


// see above; logic altered to return true if this is not lesser than rhs
bool MyVector::operator>=(const MyVector& rhs)const
    {
        return !(*this < rhs);
    }

/*
 OPERATOR ==: function that compares this and another vector to determine equality; this function's logic is used to determine the following function as well
 */
bool MyVector::operator==(const MyVector& rhs)const
{
    // if the two objects being compared are not the same size, return false
    if(size_ != rhs.size()) {
        return false;
    }
    
    // compare elements of the two vectors in tandem; any inequality triggers false
    for(size_t i = 0; i < size_; i++) {
        if(data[i] != rhs[i]) {
            return false;
        }
    }
    
    // return true if neither false conditions have been triggered
    return true;
}

// see above; logic altered to return true if this does not equal rhs
bool MyVector::operator!=(const MyVector& rhs)const
{
    return !(*this == rhs);
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
    MyVector copy(v2);
    assert(copy.size() == v2.size() && "Copy Constructor test failed for size check");
    for (size_t i = 0; i < v2.size(); i++){
       assert(v2[i] == copy[i] && "Copy constructor test failed for data check");
    }
}

void testOperatorEquals(){
    MyVector v7(5);
    v7.push_back(5);
    v7.push_back(3);
    v7.push_back(6);
    v7.push_back(2);
    v7.push_back(1);
    MyVector v8(0);
    v7 = v8;
    for( size_t i = 0; i < v7.size(); i++){
        assert(v7[i] == v8[i] && "Operator = test failed for data check");
    }
    assert(v7.size() == v8.size() && "Operator = test failed for size check");
    assert(v7.capacity() == v8.capacity() && "Operator = test failed for capacity check");
}

void testOperatorIndex(){
    MyVector v7(5);
    v7.push_back(5);
    v7.push_back(3);
    v7.push_back(6);
    v7.push_back(2);
    v7.push_back(1);
    
    assert(v7[4] == 1 && "Operator index test failed");
}

void testOperatorLessThan(){
    MyVector v7(5);
    v7.push_back(5);
    v7.push_back(3);
    v7.push_back(6);
    v7.push_back(2);
    v7.push_back(1);
    //Initialize another vector with less size and capacity
    MyVector v6(1);
    assert(v6.size() < v7.size() && "Operator less than function failed size check");
    assert(v6.capacity() < v7.capacity() && "Opreator less than function failed capcity check");
}

void testOperatorGreaterThan(){
    MyVector v7(5);
    v7.push_back(5);
    v7.push_back(3);
    v7.push_back(6);
    v7.push_back(2);
    v7.push_back(1);
    //Initialize another vector with less size and capacity
    MyVector v6(1);
    assert(v7.size() > v6.size() && "Operator greater than function failed size check");
    assert(v7.capacity() > v6.capacity() && "Operator greater than function failed capcity check");
}

void testOperatorLessThanEqualToo(){
    MyVector v7(5);
    v7.push_back(5);
    v7.push_back(3);
    v7.push_back(6);
    v7.push_back(2);
    v7.push_back(1);
    
    MyVector v6(5);
    v6.push_back(5);
    v6.push_back(3);
    v6.push_back(6);
    v6.push_back(2);
    v6.push_back(1);
    
    assert(v7.size() >= v6.size() && "Operator less than or equal too failed size check");
    assert(v7.capacity() >= v6.capacity() && "Operator less than or equal too failed capacity check");
}

void testOperatorGreaterThanEqualToo(){
    MyVector v7(5);
    v7.push_back(5);
    v7.push_back(3);
    v7.push_back(6);
    v7.push_back(2);
    v7.push_back(1);
    
    MyVector v6(5);
    v6.push_back(5);
    v6.push_back(3);
    v6.push_back(6);
    v6.push_back(2);
    v6.push_back(1);
    
    assert(v6.size() <= v7.size() && "Operator greater than or equal too failed size check");
    assert(v6.capacity() <= v7.capacity() && "Operator greater than or equal too failed capacity check");
}

void testOperatorDoubleEquals(){
    MyVector v7(5);
    v7.push_back(5);
    v7.push_back(3);
    v7.push_back(6);
    v7.push_back(2);
    v7.push_back(1);
    
    MyVector v6(5);
    v6.push_back(5);
    v6.push_back(3);
    v6.push_back(6);
    v6.push_back(2);
    v6.push_back(1);
    
   assert(v6 == v7 && "Operator == test failed");
   assert(v6.size() == v7.size() && "Operator == test failed size check");
   assert(v6.capacity() == v7.capacity() && "Operator == test failed capacity check");
}

void testOperatorDoesNotEqual(){
    MyVector v7(5);
    v7.push_back(5);
    v7.push_back(3);
    v7.push_back(6);
    v7.push_back(2);
    v7.push_back(1);
    
    MyVector v6(5);
    v6.push_back(8);
    v6.push_back(0);
    v6.push_back(5);
    v6.push_back(2);
    v6.push_back(1);
    v6.push_back(9);
    v6.push_back(1);
    v6.push_back(2);
    v6.push_back(1);
    v6.push_back(4);
    
   assert(v6 != v7 && "Operator != test failed");
   assert(v6.size() != v7.size() && "Operator != test failed size check");
   assert(v6.capacity() != v7.capacity() && "Operator != test failed capacity check");
}







