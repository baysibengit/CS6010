//
//  NumberConverter.hpp
//  NumberConverter
//
//  Created by Ben Baysinger and Jake Dame on 9/5/23.
//

#pragma once
#include <stdio.h>

#include <iostream>
#include <cctype>
#include <cerrno>
#include <cfenv>
#include <cmath>
#include <cstring>
#include <string>
#include <clocale>
#include <cassert>

int stringToInt(std::string string, int base);

std::string IntToDecimalString(int integer);
std::string intToBinaryString(int integer);
std::string intToHexadecimalString(int integer);
void ErrorExit( std::string message );
