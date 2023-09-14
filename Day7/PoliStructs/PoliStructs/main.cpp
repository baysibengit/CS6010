//
//  main.cpp
//  PoliStructs
//
//  Created by Ben Baysinger  on 8/29/23.
//

#include <iostream>
#include <string>
#include <vector>
#include "PoliticianTypeHelper.hpp"
#include <stdio.h>

int main(int argc, const char * argv[]) {
    //Call test functions
    testJavacans();
    testIsCpluser();
    testIsJavacan();
    testFederalCplusers();
    
    
    
    
// Dummy politician names
    Politician politician1 {
      "John Stockton", "Javacan", "State politician"
    };
    Politician politician2 {
      "Deron Williams", "Cpluser", "Federal politician"
    };
    Politician politician3 {
      "Donovan Mitchel", "Javacan", "State politician"
    };
    Politician politician4 {
      "Carlos Boozer", "Cpluser", "Federal politician"
    };
    Politician politician5 {
      "Joe Ingles", "Javacan", "State politician"
    };
    Politician politician6 {
      "Jordan Clarkson", "Cpluser", "Federal politician"
    };
    
    // List all politicians and store
    std::vector<Politician> politicians{
        politician1, politician2, politician3, politician4, politician5, politician6
    };
    // For clarity of what is printed
    std::cout<< "The following politicians are Javacans: \n";
    // Call Javacans functions for politicians
    std::vector<Politician> J = Javacans(politicians);
    // For clarity of what is printed
    std::cout<< "\nThe following politicians are federal politicians in the Cpluser party: \n";
    // Call federalCpluser function for politicians
    std::vector<Politician> fc =
    federalCplusers(politicians);
    
    return 0;
}
