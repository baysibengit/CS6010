//
//  main.cpp
//  NumberConverter
//
//  Created by Ben Baysinger  on 9/5/23.
//

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include <bitset>
#include "NumCon.hpp"




int main(int argc, const char * argv[]) {
// initialize an empty string for user input
    std::string userString = "";
// initialize an (empty) integer for user input
    int userBase = 0;
        
// print prompts and allow user to assign variables
    std::cout << "Enter a number: ";
    std::cin >> userString;
    std::cout << "Enter a base: ";
    std::cin >> userBase;
        
// function that takes user's two inputs as parameters
    stringToInt(userString, userBase);
        
    
//Prompt user to enter integer and call functions 
    int userInput;
    std::cout<< "Enter a integer to convert to string: \n";
    std::cin>> userInput;
    std::cout<< "Decimal output as string: \n";
    intToDec(userInput);
    std::cout<< "\nBinary output as string: \n";
    intToBin(userInput);
    std::cout << "\n";
    return 0;
}
