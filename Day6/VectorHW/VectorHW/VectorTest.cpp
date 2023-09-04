/*
  Author: Daniel Kopta and ??
  July 2017
  
  CS 6010 Fall 2019
  Vector util library tests
  Compile this file together with your VectorUtil library with the following command:
  clang++ -std=c++11 VectorTest.cpp VectorUtil.cpp
  Most of the provided tests will fail until you have provided correct 
  implementations for the VectorUtil library functions.
  You will need to provide more thorough tests.
*/

#include <iostream>
#include <string>
//Include for testing using assert
#include <cassert>

// Include the VectorUtil library
#include "VectorUtil.h"

/*
 * Helper function for failing a test.
 * Prints a message and exits the program.
 */
void ErrorExit( std::string message )
{
  std::cerr << "Failed test: " << message << std::endl;
  exit(1); // Causes the entire program to exit.
}

std::vector<int> negatives ={-1, -2, -3, -4};
std::vector<int> singleDigit ={1};
std::vector<int> maximum = {INT_MAX, 4, 5, 6};
std::vector<int> minimum = {INT_MIN, 4, 5, 3};
std::vector<int> repeats = {7, 7, 7};
vector<int> empty;

//Test function for find max
void TestFindMax(){

    
    if (FindMax(negatives) != -1){
        ErrorExit("Find Max Failed negatives test");
    }
    if (FindMax(singleDigit) != 1){
        ErrorExit("Find Max Failed single digit test");
    }
    if (FindMax(maximum) != INT_MAX){
        ErrorExit("Find Max Failed maximum test");
    }
    if (FindMax(minimum) != 5){
        ErrorExit("Find Max Failed minimum test");
    }
    if (FindMax(repeats) != 7){
        ErrorExit("Find Max Failed repeats test");
    }
    if (FindMax(empty)){
       ErrorExit("Find Max Failed due to empty vector");
    }
}
//Test Function for find min
void TestFindMin(){
    if (FindMin(negatives) != -4){
        ErrorExit("Find Min Failed negatives test");
    }
    if (FindMin(singleDigit) != 1){
        ErrorExit("Find Min Failed single digit test");
    }
    if (FindMin(maximum) != 4){
        ErrorExit("Find Min Failed maximum test");
    }
    if (FindMin(minimum) != INT_MIN){
        ErrorExit("Find Min Failed minimum test");
    }
    if (FindMin(repeats) != 7){
        ErrorExit("Find Min Failed repeats test");
    }
    if (FindMin(empty)){
        ErrorExit("Find Max Failed due to empty vector");
    }
}

//Test function for contains
void TestContains(){
    if (Contains(negatives, 0)){
        ErrorExit("Contains Failed negatives test");
    }
    if (!Contains(singleDigit, 1)){
        ErrorExit("Contains Failed single digit test");
    }
    if (Contains(maximum, 0)){
        ErrorExit("Contains Failed maximum test");
    }
    if (!Contains(minimum, INT_MIN)){
        ErrorExit("Contains Failed minimum test");
    }
    if (Contains(repeats, 0)){
        ErrorExit("Contains Failed repeats test");
    }
    if (Contains(empty, 0)){
        ErrorExit("Contains Failed due to empty vector");
    }
    
}

//Test Function for average
void TestAverage(){
    if (Average(negatives) == -2){
        ErrorExit("Average Failed negatives test");
    }
    if (Average(singleDigit) != 1){
        ErrorExit("Average Failed single digit test");
    }
    if (Average(maximum) == 4){
        ErrorExit("Average Failed maximum test");
    }
    if (Average(minimum) == 3){
        ErrorExit("Average Failed minimum test");
    }
    if (Average(repeats) != 7){
        ErrorExit("Average Failed repeats test");
    }
    if (Average(empty)){
        ErrorExit("Average cannot be done for empty vector");
    }
}

//Test Function for isSorted
void TestIsSorted(){
    if (IsSorted(negatives)){
        ErrorExit("IsSorted Failed negatives test");
    }
    if (!IsSorted(singleDigit)){
        ErrorExit("IsSorted Failed single digit test");
    }
    if (IsSorted(maximum)){
        ErrorExit("IsSorted Failed maximum test");
    }
    if (IsSorted(minimum)){
        ErrorExit("IsSorted Failed minimum test");
    }
    if (!IsSorted(repeats)){
        ErrorExit("IsSorted Failed repeats test");
    }
    if (IsSorted(empty)){
        ErrorExit("IsSorted Failed repeats test");
    }
}



int main()
{
  
  // Set up some input vectors for testing purposes.

  // We can use list initialization syntax:
  vector<int> v1 = {3, 1, 0, -1, 5};

  // Or we can repeatedly push_back items
  vector<int> v2;
  v2.push_back(1);
  v2.push_back(2);
  v2.push_back(3);

  // When testing, be sure to check boundary conditions, such as an empty vector
  vector<int> empty;
  
  
  /* 
   * Contains tests 
   */

  // v1 doesn't contain 4, so this should return false
  if( Contains(v1, 4) ) {
    ErrorExit( "Contains() - test 1" );
  }

  // v1 does contain -1, so this should return true
  if(!Contains(v1, -1)) {
    ErrorExit("Contains() - test 2");
  }

  /* 
   * The vector 'empty' doesn't contain anything, so this should return false
   * The specific value we're looking for here (99) is not important in this test. 
   * This test is designed to find any general errors caused by the array being empty. 
   * That type of error is unlikely to depend on the value we are looking for.
  */
  if( Contains(empty, 99) ) {
    ErrorExit("Contains() - empty");
  }
    
//Calling all test functions
    TestAverage();
    TestContains();
    TestFindMax();
    TestFindMin();
    TestAverage();
    TestIsSorted();
    
  // Since any failed test exits the program, if we made it this far, we passed all tests.
  std::cout << "All tests passed!\n";

}
