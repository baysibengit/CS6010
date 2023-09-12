//
//  main.cpp
//  Throwaway
//
//  Created by Ben Baysinger  on 9/7/23.
//

#include <iostream>
#include <string>
#include <vector>
//Initializing vector
struct MyVector {
double* data;

int size;

int capacity;
};

//Creating function to sum elments of array
int arrayModSum (MyVector& someVar)
{
    int result = 0;
    for (int i = 0; i < someVar.size; i++){
        result += someVar.data[i] + 1;
    }
    return  result;
}

//
void growMyVector(MyVector& someVar){
    if (someVar.size == someVar.capacity){
        someVar.capacity = someVar.capacity * 2;
        double* tempArray = new  double [someVar.capacity];
        
        for (int i = 0; i < someVar.size; i++){
            tempArray[i] = someVar.data[i];
        }
        //Delete someVar.data to free up space
  //      delete [] someVar.data;
        // Set someVar.data = the pointer to the temp array
        someVar.data = tempArray;
        //Set the pointer to the temp array to nullptr
        tempArray = nullptr;
        
    }
}

std::string intToDecimalString(int input){
    std::string result;
    while(input > 0){
        int remainder = input % 10;
        input = input / 10;
        char value = remainder + '0';
        result = value + result;
    }
    return result;
}

int main(int argc, const char * argv[]) {
   
//=================PART ONE===========================

    //Ininitalize a vector
    MyVector vec1;
    int VecCap;
    std::cout<< "Enter the vector capacity: ";
    std::cin>>VecCap;
    
    /*update vec1.size to the new size, and vec1.capacity to be equal to the size.*/
    vec1.size = 0;
    vec1.capacity = VecCap;
    
    //Create an array and allocate to heap
    /*Store array in vec1.data so that vec1.data is now pointing to the first element of the array*/
    vec1.data  = new double [VecCap];

    for (int i=0; i<vec1.capacity;i++)
    {
        vec1.data[i]=1.0;
        vec1.size++;
    }
    
    // print out the vector that we created and initialized
    std::cout<<"size of the vector: "<<vec1.size<<"\n";
    
    for (int i=0; i<vec1.capacity;i++)
    {
        std::cout<<vec1.data[i]<<"\n";
    }
    
// call a function to print the sum of the elements of the vector
    std::cout<<"Sum of elements plus one: " << arrayModSum(vec1) << "\n";

//Clean up allocated array
    delete [] vec1.data;
    
    
// ====================PART TWO=======================
    growMyVector(vec1);
    int input = 5;
    std::cout<< intToDecimalString(input);
    return 0;
}
