//
//  main.cpp
//  NumberConverter
//
//  Created by Ben Baysinger and Jake Dame on 9/5/23.
//

#include "NumConverter.hpp"
#include "NumberConverterTests.hpp"

int main(int argc, const char * argv[]) {

//=======================================================================================
//                                      PART 1
//=======================================================================================
    
    // run tests for the stringToInt function
    testStringToInt();
    // initialize an empty string for user input
    std::string userString = "";
    // initialize an (empty) integer for user input
    int userBase = 0;
    
    // print prompts and allow user to assign variables
    std::cout << "Enter a number (takes decimal, binary, or hexadecimal; no prefix): ";
    std::cin >> userString;
    std::cout << "Enter the base of that number: ";
    std::cin >> userBase;
    // function that takes user's two inputs as parameters
    stringToInt(userString, userBase);

    
//=======================================================================================
//                                      PART 2
//=======================================================================================

    // initialize empty integers for user input
    int userInt1 = 0;
    int userInt2 = 0;
    int userInt3 = 0;
    
    //Calling all test functions
    testIntToDecimalString();
    testIntToBinaryString();
    testIntToHexadecimalString();
    
    // print prompts and allow user to assign variables
    std::cout << "Enter a decimal integer to convert to a decimal string: ";
    std::cin >> userInt1;
    std::cout<< "Decimal string output: " << IntToDecimalString(userInt1) << "\n";
    
    std::cout << "Enter a decimal integer to convert to a binary value: ";
    std::cin >> userInt2;
    std::cout<< "Binary string output: " << intToBinaryString(userInt2) << "\n";
    
    std::cout << "Enter a decimal integer to convert to a hexadecimal value: ";
    std::cin >> userInt3;
    std::cout<< "Hexadecimal string output: " << "0X" << intToHexadecimalString(userInt3);

    
    // end program
    std::cout << std::endl;
    
    
    
    return 0;
}
