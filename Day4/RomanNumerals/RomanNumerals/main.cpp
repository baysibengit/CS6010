//
//  main.cpp
//  RomanNumerals
//
//  Created by Ben Baysinger  on 8/24/23.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    
    
    //Assign integer variable to user input
    //Prompt user to enter a decimal number
    /*run a continuous loop so that it ommits any number value less than 1 but allows user to keep attempting it they fail to enter a positive number*/
   /*Add if statement to let user know response is invalid*/
    int decimalNumber;
    
    do {
        std::cout<< "Enter a positive decimal number: \n";
        std::cin>> decimalNumber;
        
    } while(decimalNumber < 1);
    
//    if (decimalNumber < 1){
//        std::cout<< "Invalid Input\n";
//        return 1;
//    }
    //Printing description for Roman Numerals
    std::cout<< "Roman Numeral Version: \n";
    /*Run while looks to check in decimalNumber is over 1000 if so prints M then subtracts  1000 from decimal number. Repeats process until decimalNumber is no longer over 1000 then hits next while loop and so on and so forth*/
    while(decimalNumber >= 1000) {
        std::cout<< "M";
        decimalNumber -= 1000;
    }
    while(decimalNumber >= 900) {
        std::cout<< "CM";
        decimalNumber -= 900;
    }
    while(decimalNumber >= 500) {
        std::cout<< "D";
        decimalNumber -= 500;
    }
    while(decimalNumber >= 400) {
        std::cout<< "CD";
        decimalNumber -= 400;
    }
    while(decimalNumber >= 100) {
        std::cout<< "C";
        decimalNumber -= 100;
    }
    while(decimalNumber >= 90) {
        std::cout<< "XC";
        decimalNumber -= 90;
    }
    while(decimalNumber >= 50) {
        std::cout<< "L";
        decimalNumber -= 50;
    }
    while(decimalNumber >= 40) {
        std::cout<< "XL";
        decimalNumber -= 40;
    }
    while(decimalNumber >= 10) {
        std::cout<< "X";
        decimalNumber -= 10;
    }
    while(decimalNumber >= 9) {
        std::cout<< "IX";
        decimalNumber -= 9;
    }
    while(decimalNumber >= 5) {
        std::cout<< "V";
        decimalNumber -= 5;
    }
    while(decimalNumber >= 4) {
        std::cout<< "IV";
        decimalNumber -= 4;
    }
    while(decimalNumber >= 1) {
        std::cout<< "I";
        decimalNumber -=  1;
    }
    return 0;
}
 
