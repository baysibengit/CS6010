//
//  main.cpp
//  StringAnalyzer
//
//  Created by Ben Baysinger  on 8/27/23.
//

#include <iostream>
#include <string>
#include <string_view>

//List needed functions

bool IsTerminator(char terminatorType)
{
    return terminatorType == '?'|| terminatorType == '!'|| terminatorType == '.';
}
bool IsPunctuation(char c);
bool IsVowel(char c);
bool IsConsonant(char c);
int NumWords(std::string s);
int NumSentences (std::string s);
int NumVowels (std::string s);
int NumConsonants(std::string s);
double AverageWordLength (std::string s);
double AverageVowelsPerWord (std::string s);


int main(int argc, const char * argv[]) {
   
    char terminatorType = IsTerminator('?'||'!'||'.');
        if(terminatorType == '?'){
    }
        else if(terminatorType == '!' ){
    }
        else if(terminatorType == '.'){
    }
        
    
    return 0;
}
