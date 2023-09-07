//
//  NumberCon.hpp
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

void stringToInt(std::string string, int base);
void intToBin (int refNum2);
void intToDec(int refNum);
