//
//  main.cpp
//  StringAnalyzer
//
//  Created by Ben Baysinger  on 8/27/23.
//

#include <iostream>
#include <string>
#include <string_view>
#include <stdio.h>
#include "LetterHelpers.hpp"
#include "wordHelpers.hpp"

int main(int argc, const char * argv[]){
        //Prompt user to enter string of sentences
        /* Use get line to prompt user to enter string of sentences*/
        /*Use while loop to allow user to enter multiple strings until they break loop and end by typing "done"*/
    //Initialize stringInput
    std::string stringInput = "";

    while (stringInput != "done")
    {
        std::cout<< "\nEnter a string containing one or more sentences:\n";
        std::getline (std::cin,stringInput);
        if(stringInput != "done"){
            std::cout<< "\nAnalysis:";
            /* store variables in desired type outcome and plug in functions*/
            int wordCount = NumWords(stringInput);
            std::cout<< "\nNumber of words: " << wordCount;
            int sentenceCount = NumSentences(stringInput);
            std::cout<< "\nNumber of sentences: "<< sentenceCount;
            
            int vowelCount = NumVowels(stringInput);
            std::cout<<"\nNumber of vowels: " << vowelCount;
            
            int consonantCount = NumConsonants(stringInput);
            std::cout<< "\nNumber of consonants: " << consonantCount;
            
            double avgWordLength = AverageWordLength(stringInput);
            std::cout<< "\nReading level (average word length): " << avgWordLength;
            
            double avgVowelPerWord = AverageVowelsPerWord(stringInput);
            std::cout<< "\nAverage vowels per word: " << avgVowelPerWord << "\n";
        }
        else
        {
            std::cout<< "Goodbye\n";
        }
        
    }
    
    
    return 0;
}
