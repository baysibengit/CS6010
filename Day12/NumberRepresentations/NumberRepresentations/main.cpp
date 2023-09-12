//
//  main.cpp
//  NumberRepresentations
//
//  Created by Ben Baysinger  on 9/6/23.
//

#include <iostream>
#include <string>
#include <vector>
#include <cstdint>

int main(int argc, const char * argv[]) {
   
//==================== PART 1 ==============================
    int x = 0;
    char y;
    //Print size to varify int and char sizes
    std::cout<< "Integer size: " << sizeof(x) << "\n" << "Char size: " << sizeof(y) << "\n";
    
    int8_t a = 0;
    int16_t b = 0;
    uint8_t c = 0;
    uint16_t d = 0;
    int e[] = { 7, 2, -56, 32, 1, 7, -2, 7 };
    //Printing out size to confirm preset size is correct
    std::cout<< "int8_t size: " << sizeof(a) << "\n" << "int16_t size: " << sizeof(b) << "\n" << "uint8_t size: " << sizeof(c) << "\n" << "uint16_t size: " << sizeof(d) << "\n" << "Array of 8 ints size: " << sizeof(e) << "\n";
    
    //Max and min values for each type
    //All hex mins will be 0 on unsigned
    //Signed cut range value to include negative numbers
    const int eightHexMin = 0x80;
    const int eightHexMax = 0x7F;
    const int sixteenHexMin = 0x8000;
    const int sixteenHexMax = 0X7FFF;
    std::cout << "-" << eightHexMin << "\n";
    std::cout << eightHexMax << "\n";
    std::cout << "-" << sixteenHexMin << "\n";
    std::cout << sixteenHexMax << "\n";
    
    
    
    return 0;
}
