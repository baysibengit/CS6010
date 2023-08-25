//
//  main.cpp
//  Palindromes
//
//  Team: Koffi Danhounsrou & Zach Allred & Ben Baysinger on 8/24/23.
//

#include <iostream>
#include <string>

int main(int argc, const char * argv[]) {
    //initiate string values
    std::string inputString;
    std::string reversed;
    //request string from user
    std::cout << "Please enter a string: ";
    std::cin >> inputString;
    //loop through string characters
    for(int a = inputString.length() - 1; a >= 0; a-= 1){
        //std::cout << InputString[a];
        reversed += inputString[a];
    }
    //check if strings are equal, output yes or no
    if(inputString == reversed) {
        std::cout << reversed << " is a palindrome.\n";
    }
        else{
            std::cout << reversed << " is NOT a palindrome.\n";
        }
    return 0;
}
