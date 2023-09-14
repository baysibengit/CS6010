//
//  main.cpp
//  NumberRepresentations
//
//  Created by Ben Baysinger  on 9/6/23.
//

#include "NumberRepresentations.hpp"

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
    //Signed cuts range value to include negative numbers
    
    uint8_t eightMin = 0X0;
    uint8_t eightMax = 0XFF;
    uint16_t sixteenMin = 0X0;
    uint16_t sixteenMax = 0XFFFF;
    uint64_t sixtyFourMin = 0X0;
    uint64_t sixtyFourMax = 0XFFFFFFFFFFFFFFFF;
    std::cout << +eightMin << "\n";
    std::cout << +eightMax << "\n";
    std::cout << +sixteenMin << "\n";
    std::cout << +sixteenMax << "\n";
    std::cout << +sixtyFourMin << "\n";
    std::cout << +sixtyFourMax << "\n";
    const int eightHexMin = 0X80;
    const int eightHexMax = 0X7F;
    const int sixteenHexMin = 0X8000;
    const int sixteenHexMax = 0X7FFF;
    std::cout << "-" << +eightHexMin << "\n";
    std::cout << +eightHexMax << "\n";
    std::cout << "-" << +sixteenHexMin << "\n";
    std::cout << +sixteenHexMax << "\n";
    
    int8_t signedHexEightMinOne = 0xFF80-1;
    int8_t signedHexEightMaxOne=0x7F+1;
    std::cout << +signedHexEightMinOne << '\n';
    std::cout << +signedHexEightMaxOne << '\n';
    /*-1 on the min or + 1 on the max reverses them to the max and min because of the circular nature. Sanitizer didn't change the output when turned on. */
    
    
//======================= PART TWO ========================
    double decReturn = .1 + .2;
    std::cout << decReturn << '\n';
    //assert(decReturn==.3 && "Error");
     //Ran above, and it failed.
    std::cout << std::setprecision(18);
    std::cout << decReturn << std::endl;
    
    float decReturn2 = .1 + .2;
    std::cout << decReturn2 << '\n';
    
    /*using a float changed the number of visible decimals. Change was due to the precision change from double to float. */
    double decimal1=.1 +.2;
    double decimal2=.3;
    double tolerance=.1;
    
    std::cout << approxEquals(decimal1, decimal2, tolerance) << std::endl;
    
//======================PART THREE ========================
    std::string filePath="/Users/benbaysinger/myGithubRepo/Day12/NumberRepresentations/NumberRepresentations/UTF-8-demo.txt";
    std::ifstream  myStream( filePath );
    char f;
    int totalCharCounter = 0;
    int ASCIICounter = 0;
    int UnicodeCharacters = 0;
    
    while( myStream >> f ){
    
        totalCharCounter++;
        if(+f >= 0 && +f <= 127){
            ASCIICounter++;
        }
        UnicodeCharacters=totalCharCounter - ASCIICounter;
        std::cout << f << '\n';
    }
    std::cout << "Total : " << totalCharCounter << '\n' << "Total ASCII: " << ASCIICounter << '\n' << "Total Unicode: " << UnicodeCharacters << '\n';
    return 0;
}
