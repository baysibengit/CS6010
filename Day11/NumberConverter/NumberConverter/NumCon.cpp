//
//  NumberCon.cpp
//  NumberConverter
//
//  Created by u0858882 on 9/5/23.
//

#include "NumberConverter.hpp"

#include <iostream>
#include <cctype>
#include <cerrno>
#include <cfenv>
#include <cmath>
#include <cstring>
#include <string>
#include <clocale>

/* function that takes a string (of numerical characters) as the first parameter, and an integer (for three distinct "if" paths: 10, 2, or 16), and converts the string-base pair to its equivalent decimal value*/

void stringToInt(std::string string, int base) {
    
    /* initialize a variable that will be equal to the size of the string minus one; this will be the exponent that is applied to the base; * 1.0 for conversion */
    
    int place = string.length() - 1 * 1.0;
    
// =====================================
// decimal (string) => decimal (integer)
// =====================================
    
    if(base == 10) {
        // use a string method to convert numerical characters to digits
        int decimalInt = std::stoi(string);
        // print the result
        std::cout << "Decimal value: " << decimalInt;
    }
    
// ====================================
// binary (string) => decimal (integer)
// ====================================
    
    if(base == 2) {
        // initialize a variable binaryInt to store the final product
        int binaryInt = 0;
        // initialize a variable to store each individual numerical character as an int
        int binaryDigit = 0;
        
        // path for POSITIVE numbers
        if(string[0] != '-') {
            // for-each loop that converts each character into an int using
            for(char c : string) {
                // this formula
                binaryDigit = c - '0';
                // then the actual math (e.g. 2^3 * 1) is done
                int powerProduct = std::pow(2, place) * binaryDigit;
                // powerProduct sums and stores the results
                binaryInt += powerProduct;
                // place (exponent) is decremented by 1
                place--;
            }
        }

        // path for NEGATIVE numbers
        if(string[0] == '-') {
            place = string.length() - 2 * 1.0;
            
            /* similar logic as above path but place (exponent) must be the size of the string - 2 and the for-loop must start on the character AFTER the '-' sign */
            
            for(int i = 1; i <= string.length(); i++) {
                char c = string[i];
                binaryDigit = c - '0';
                int powerProduct = std::pow(2, place) * binaryDigit;
                binaryInt += powerProduct;
                place--;
            }
        }
        
        // print the result
        std::cout << "Decimal value: " << binaryInt;
    }
    
// =========================================
// hexadecimal (string) => decimal (integer)
// =========================================
    
    // similar logic to binary to decimal block
    if(base == 16) {
        int hexInt = 0;
        int hexDigit = 0;

        for(char c : string) {
            // character is made to lowercase from the start
            char cLower = std::tolower(c);
            
            // two different formulas for finding the integer value of a single character whether it is a numerical character
            
            if(cLower >= '0' && cLower <= '9') {
                hexDigit = cLower - '0';
            }
            
            // or an alphabetical character
            
            if(cLower >= 'a' && cLower <= 'f') {
                hexDigit = cLower - 'a' + 10;
            }
        
            int powerProduct = std::pow(16, place) * hexDigit;
            hexInt += powerProduct;
            place--;
        }
        
        /* for some reason hex numbers did not seem to need the length manipulation, etc., that binary did. So here, the number is simply multiplied by -1 */
        
        if(string[0] == '-') {
            hexInt = hexInt * -1;
        }
        
        // print the result
        std::cout << "Decimal value: " << hexInt;
    }
}

//Create a function that takes in int and returns string dec
void intToDec(int refNum){
    std::string stringConverter = std::to_string(refNum);
    std::cout<< stringConverter;
}

//Create functiont to convert  int to  binary string
void intToBin (int refNum2){
//Initializing string
    std::string binConverter;
//Setting array at 32 to account for standard 4 byte integer
    int binaryNum[32];
    int i = 0;
/*Running while loop and storing remainder in array and diving number by 2 to repeat process until 0 which ends while loop. i++ acts as an index counter to keep track of where to store binary number*/
    while( refNum2 > 0){
        binaryNum[i] = refNum2 % 2;
        refNum2 = refNum2/2;
        i++;
    }
/*Running for loop to switch order of binary output*/
    for( int j = i - 1; j >= 0; j--){
//Converting binary integer to string and printing
        std::string binConverter = std::to_string(binaryNum[j]);
        std::cout<< binConverter;
    }
}

