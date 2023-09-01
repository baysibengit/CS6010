//
//  main.cpp
//  BookAnalyzer
//
//  Created by Ben Baysinger  on 8/31/23.
//

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <fstream>

int main(int argc, const char * argv[]) {
    //Read in book file and assign variable name
    std::ifstream bookOne("testfile.txt");
    //Assign varialbe
    std::string singleWord;
    std::vector<std::string> allWords;
    while (bookOne >> singleWord){
        allWords.push_back(singleWord);
    }
   
    

    
    
    
    
    
    return 0;
}
