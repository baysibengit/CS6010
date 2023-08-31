/*
  Author: Daniel Kopta and ??
  July 2017
  
  CS 6010 Fall 2019
  Vector util library definitions
  Complete the functions defined in this file.
  Some basic tests for your library are provided in VectorTest.cpp.
  Compile the tests together with your library using the following command:
  clang++ -std=c++11 VectorTest.cpp VectorUtil.cpp
  Most of the provided tests will fail until you have provided correct 
  implementations for the VectorUtil library functions.
  You will need to provide more thorough tests.
*/

#include "VectorUtil.h"

/*
 * Determines whether or not a vector contains a certain item.
 *
 * Parameters:
 *   input -- The vector to search
 *   lookFor -- The item to look for
 *
 * Returns:
 *   Whether or not the item is contained in the vector
 */
bool Contains( vector<int> input, int lookFor )
{
/*Run for loop to look through values of input and check if any of them are equal to/contain variable lookFor*/
    for (int a = 0; a < input.size(); a++){
        if( input [a]== lookFor){
            return true;
        }
    }
    return false;
}

/*
 * Determines the minimum value in a vector.
 *
 * Assumes the vector is non-empty.
 *
 * Parameters:
 *   input -- A vector of integers
 *
 * Returns:
 *   The smallest item in the vector
 */
int FindMin( vector<int> input )
{
//Initialize smallest with larger integer value
    int smallest = INT_MAX;
/*Run through vector and repeatedly check if number is smaller than number/s in vector. If it is it will replace smallest variable with the smaller number*/
    for(int i = 0 ; i< input.size();i++){
        if(input[i]< smallest){
            smallest = input[i];
        }
    }
    return smallest;
}
/*
 * Determines the maximum value in a vector.
 *
 * Assumes the vector is non-empty
 *
 * Parameters:
 *   input -- A vector of integers
 *
 * Returns:
 *   The largest item in the vector
 */
int FindMax( vector<int> input )
{
//Initialize largest with smaller integer
    int largest = INT_MIN;
/*Run through vector and repeatedly check if number is larger than number in vector. If it is it will replace largest variable with the larger number*/
    for(int i =0 ; i< input.size();i++){
        if(input[i]> largest){
            largest = input[i];
        }
    }
    return largest;
}

/*
 * Determines the average of all values in a vector
 *
 * Assumes the vector is non-empty
 *
 * Parameters:
 *   input -- A vector of integers
 *
 * Returns:
 *   The (integer) average of all values in the vector
 */
int Average( vector<int> input )
{
//Initialize sum
    int sum = 0;
//Add all values of input and store in sum
    for (int a = 0; a < input.size(); a++){
        sum += input[a];
    }
//Divide by size of input to get average
    return sum/input.size();
}


/*
 * Determines whether or not the items in a vector are in non-descending order
 *
 * Non-descending order is similar to ascending order, except that it allows for 
 * duplicate items to appear next to each other.
 * i.e., no item appearing at a lower index than another item is greater than that
 * other item.
 * 
 * Examples:
 *  {1, 2, 2, 15, 70} is sorted
 *  {2, 3, 0} is not sorted
 *
 * Parameters:
 *   input -- A vector of integers
 *
 * Returns:
 *   True if the vector is sorted in non-descending order, false otherwise
 *   An empty vector is considered sorted, since there are no items out of order
 *   A single-item vector is considered sorted, since there are no items out of order
 */
bool IsSorted( std::vector<int> input )
{
    //Make a copy
        std::vector<int> sortedInput = input;
        //Sort vector
            std::sort(sortedInput.begin(), sortedInput.end());
        //Check if it matches up and return true
            if (sortedInput == input){
                return true;
            }
            else {
                return false;
            }
}


