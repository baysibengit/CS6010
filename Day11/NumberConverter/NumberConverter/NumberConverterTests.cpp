//
//  NumberConverterTests.cpp
//  NumberConverter
//
//  Created by Ben Baysinger and Jake Dame on 9/7/23.
//

#include "NumberConverterTests.hpp"
#include "NumConverter.hpp"

//Testing negative, 0, and positive ints
int testPositiveInt = 9;
int testNegativeInt = -5;
int testZeroInt = 0;
int largeNumber = 777;


void testStringToInt() {
    assert((stringToInt("99", 10)) == 99);
    assert((stringToInt("-99", 10)) == -99);
    assert((stringToInt("0", 10)) == 0);
    assert((stringToInt("1111", 2)) == 15);
    assert((stringToInt("-1111", 2)) == -15);
    assert((stringToInt("0", 2)) == 0);
    assert((stringToInt("0xFF", 16)) == 255);
    assert((stringToInt("-0xFF", 16)) == -255);
    assert((stringToInt("0", 16)) == 0);
}

void testIntToDecimalString(){
    std::string value = IntToDecimalString(testPositiveInt);
    if (stoi(value) == testPositiveInt){
    }
    else{
        ErrorExit("IntToDecimalString test failed");
    }
    std::string valueTwo = IntToDecimalString(testNegativeInt);
    if (stoi(valueTwo) == testNegativeInt){
    }
    else{
        ErrorExit("IntToDecimalString test failed");
    }
    std::string valueThree = IntToDecimalString(testZeroInt);
    if (stoi(valueThree) == testZeroInt){
    }
    else{
        ErrorExit("IntToDecimalString test failed");
    }
    std::string valueFour = IntToDecimalString(largeNumber);
    if (stoi(valueFour) == largeNumber){
    }
    else{
        ErrorExit("IntToDecimalString test failed");
    }
}

void testIntToBinaryString(){
    std::string value = (intToBinaryString(testPositiveInt));
    if (value == "1001") {
    }
    else{
        ErrorExit("IntToBinaryString test failed");
    }
    std::string valueTwo = (intToBinaryString(testNegativeInt));
    if (valueTwo == "-101") {
    }
    else{
        ErrorExit("IntToBinaryString test failed");
    }
    std::string valueThree = (intToBinaryString(testZeroInt));
    if (valueThree == "0") {
    }
    else{
        ErrorExit("IntToBinaryString test failed");
    }
    std::string valueFour = (intToBinaryString(largeNumber));
    if (valueFour == "1100001001") {
    }
    else{
        ErrorExit("IntToBinaryString test failed");
    }
}

void testIntToHexadecimalString(){
    std::string value = (intToHexadecimalString(testPositiveInt));
    if ( value == "9"){
    }
    else{
        ErrorExit("IntToHexadecimalString test failed");
    }
    std::string valueTwo = (intToHexadecimalString(testNegativeInt));
    if ( valueTwo == "-5"){
    }
    else{
        ErrorExit("IntToHexadecimalString test failed");
    }
    std::string valueThree = (intToHexadecimalString(testZeroInt));
    if ( valueThree == "0"){
    }
    else{
        ErrorExit("IntToHexadecimalString test failed");
    }
    std::string valueFour = (intToHexadecimalString(largeNumber));
    if ( valueFour == "309"){
    }
    else{
        ErrorExit("IntToHexadecimalString test failed");
    }
}
