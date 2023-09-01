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

//Testing find max function
  if (FindMax(v1) != 5){
    ErrorExit("Find Max() - test 3");
  }
  if (FindMax(empty) == 1 ){
      ErrorExit("Find Max() - test 3");
  }
    
    
//Testing find min function
    if (FindMin(v1) != -1){
        ErrorExit("Find Min() - test 4");
    }
    if (FindMin(v1) == 1){
        ErrorExit("Find Min() - test 5");
    }

//Testing average functions
    if (Average(v1) != 1){
        ErrorExit("Average () - test 6");
    }
    if (Average(v1) == 3){
        ErrorExit("Average () - test 7");
    }
    
    
//Testing IsSorted
    assert(!IsSorted(v1) && "Shouldn't have been sorted!");
    
    if (IsSorted(v1)){
        ErrorExit("IsSorted () - test 8");
    }
    TestFindMax();
    
    
  // Since any failed test exits the program, if we made it this far, we passed all tests.
  std::cout << "All tests passed!\n";

}
