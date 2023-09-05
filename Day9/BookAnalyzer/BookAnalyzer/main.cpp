
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
#include <algorithm>


/*Using unsigned long becuase there can't be negatives and there can be tons of strings in a book*/
//totalWords will equal the size of the vector containing the book
unsigned long wordCount(std::vector<std::string> vector){
    int totalWords = vector.size() * 1.0;
    return totalWords;
}

/*Initiate variable to zero. Loop through vector containng book and continually add chars to counter being stored in totalChars*/
int numCount(std::vector<std::string> vector){
    int totalChars = 0;
    for(std::string VarString : vector){
        totalChars += VarString.length();
    }
    return totalChars;
}

//Creating function to find title
std::string titleFinder (std::vector<std::string> vector){
    std::string title = " ";
    for(std::string titleLocator : vector){
        if (titleLocator.find("Title: ")) {
            title = titleLocator.find("Title: ");
        }
    }
    return title;
}

//Creating Find author function
//Creating function to find shortest word in book
std::string shortestWordFinder (std::vector<std::string> vector){
//Initializing with "the" because every book has the
    std::string shortestWord = "the";
//Looping through vector to find string
    for(std::string wordChecker : vector){
/*checking length of "the" versus every word in vector and replacing it if word is shorter*/
        if (wordChecker.length() < shortestWord.length()){
            shortestWord = wordChecker;
        }
    }
    return shortestWord;
}

//Creating function to find longest word in book
std::string longestWordFinder (std::vector<std::string> vector){
//Initializing with "the" because every book has the
    std::string longestWord = "the";
//Looping through vector to find string
    for(std::string wordComp : vector){
/*checking length of "the" versus every word in vector and replacing it if word is longer*/
        if (wordComp.length() > longestWord.length()){
            longestWord = wordComp;
        }
    }
    return longestWord;
}

int keyWordFinder (std::vector<std::string> vector, std::string keyWord){
//Initialize variable
    int keyWordCounter = 0;
//Loop through vector to find key word using for loop
    for ( int i = 0; i < vector.size(); i++){
        if (keyWord == vector[i]){
            keyWordCounter++;
        }
    }
    return keyWordCounter;
}





int main(int argc, const char * argv[]) {
//Read in book file and assign variable name
    std::ifstream bookOne("/Users/benbaysinger/myGithubRepo/day9/BookAnalyzer/BookAnalyzer/testfile.txt");
//Assign variable
    std::string singleWord;
    std::vector<std::string> allWords;
    
/*Runnign while loop to read in words from file and store in vector allwords. */
    while (bookOne >> singleWord){
        allWords.push_back(singleWord);
    }
//Calling functions and displaying information
    std::cout<< "\n" << "Number of words: " << wordCount(allWords) << "\n" << "\n" << "Number of characters: " << numCount(allWords) << "\n" << "\n" << "The shortest word is \"" << shortestWordFinder(allWords) << "\" , and the longest word is \"" << longestWordFinder(allWords) << "\"." <<  "\n";
    
    
    std::cout<< "\n" << " Title: " << titleFinder(allWords);
    
    
    
    return 0;
}
