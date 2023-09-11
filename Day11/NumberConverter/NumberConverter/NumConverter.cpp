//
//  NumberConverter.cpp
//  NumberConverter
//
//  Created by Ben Baysinger and Jake Dame on 9/5/23.
//

#include "NumConverter.hpp"

/* function that takes a string (of numerical characters) as the first parameter, and an integer (for three distinct "if" paths: 10, 2, or 16), and converts the string-base pair to its equivalent decimal value*/
int stringToInt(std::string string, int base) {
    
    /* initialize a variable that will be equal to the size of the string minus one; this will be the exponent that is applied to the base; * 1.0 for conversion */
    
    size_t place = string.length() - 1;
    
// =====================================
// decimal (string) => decimal (integer)
// =====================================
    
    if(base == 10) {
        // use a string method to convert numerical characters to digits
        int decimalInt = std::stoi(string);
        // print the result (commented out)
            // std::cout << "Decimal value: " << decimalInt;
        return decimalInt;
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
        else {
            place = string.length() - 2;
            
            /* similar logic as above path but place (exponent) must be the size of the string - 2 and the for-loop must start on the character AFTER the '-' sign */
            
            for(int i = 1; i < string.length(); i++) {
                char c = string[i];
                binaryDigit = c - '0';
                int powerProduct = std::pow(2, place) * binaryDigit;
                binaryInt += powerProduct;
                place--;
            }
            binaryInt = binaryInt * -1;
        }
        
        // print the result (commented out)
            // std::cout << "Decimal value: " << binaryInt;
        return binaryInt;
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
            
            // two different formulas for finding the integer value of a single character:
            
            // whether it is a numerical character
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
        
        // print the result (commented out)
            // std::cout << "Decimal value: " << hexInt;
        return hexInt;
    }
    std::cout << std::endl;
    
    // arbitrary number that returns if user inputs an invalid number/base (assume they won't)
    return 1;
}






// function that converts int to decimal string
std::string IntToDecimalString(int integer){
    std::string decimalString = std::to_string(integer);
    return decimalString;
}

// function that converts int to binary string
std::string intToBinaryString(int integer){
// initialize variables
    std::string binaryString = "";
    int i = 0;
    // set array at 32 to account for standard 4-byte integer
    int binaryNum[32];
    
//Guard against negatives
    bool isNegativeBinary = integer < 0;
    if (isNegativeBinary){
        integer = -integer;
    }
//Guard against zero
    if (integer == 0){
        return "0";
    }

/* while-loop which stores remainder in array and divides number by 2; repeat process until 0 which ends the while-loop. i++ acts as an index counter to keep track of where to store binary number */
    while(integer > 0){
        binaryNum[i] = integer % 2;
        integer = integer / 2;
        i++;
    }
    
/* for-loop to reverse order of first binary output; initialize variable to display concatenated output while padding to account for negative numbers*/
    std::string binaryStringOutput = "";
    for(int j = i - 1 ; j >= 0; j--){
// converting binary integer to string and printing
        binaryString = std::to_string(binaryNum[j]);
//concatenate outpute and add negative if applicable
        binaryStringOutput += binaryString;
    }
//tack on negative symbol if negative
    if (isNegativeBinary){
        binaryStringOutput = "-" + binaryStringOutput;
    }
    return binaryStringOutput;
}

std::string intToHexadecimalString(int integer) {
/*Initialize variables. hexString to store output is desired string format. hexNum array at 32 to account for standard 4 byte integer. Char to store hexDigit*/
    char hexDigit;
    std::string hexString = "";
    int i = 0;
    int hexNum[32];
/*Guard to account for 0 becuase its a straight conversion and can avoid unneccessary loop*/
    if ( integer == 0){
        return "0";
    }
//Guard against negative input integers
    bool isNegative = integer < 0;
    if (isNegative){
        integer = -integer;
    }
    
    
    
/* while-loop which stores remainder in hexNum array by using modulo. Divides number by base(16)a and repeat process until integer is 0 which ends the while-loop. i++ acts as an index counter to keep track of where to store hexadecimal number */
    while(integer > 0){
        hexNum[i] = integer % 16;
        integer = integer / 16;
        i++;
    }
/*For loop to iterate in reverse order of array. If digit is from 0 - 9 add 48 to get the ASCII corresponding character. If it is greater than ten (A-F) add 55 to get ASCII corresponding character */
    for(int j = i - 1; j >= 0; j--){
        if(hexNum[j] < 10) {
            hexDigit = hexNum[j] + 48;
        }
        else {
            hexDigit = hexNum[j] + 55;
        }
//Concatenate chars to form hexadecimal string
        hexString += hexDigit;
        
        if (isNegative){
//Add sign for negative numbers
            hexString = "-" + hexString;
        }
    }
    return hexString;
}

//Function to exit program early if there is a failed test.
void ErrorExit( std::string message )
{
  std::cerr << "Failed test: " << message << std::endl;
  exit(1); // Causes the entire program to exit.
}
