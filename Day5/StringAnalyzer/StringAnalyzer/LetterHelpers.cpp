//
//  LetterHelpers.cpp
//  StringAnalyzer
//
//  Created by Ben Baysinger  on 8/29/23.
//

#include "LetterHelpers.hpp"
#include <iostream>
//Include signatures and definitions
/* IsTerminator takes in character value of ?,.,or !. Helper funcitons*/
bool IsTerminator(char terminatorType){
    return terminatorType == '?'|| terminatorType == '!'|| terminatorType == '.';
}

/*IsPunctuation takes in character value of ?,.,',', or !. Helper functions*/
bool IsPunctuation( char punctuationType){
    return punctuationType == '?'|| punctuationType == '!'|| punctuationType == '.'|| punctuationType == ','|| punctuationType == '\'';
}

/* IsVowel checks how many characters are vowels in the strings user entered. Helper functions*/
bool IsVowel( char vowelType){
    return vowelType == 'a'|| vowelType == 'e'|| vowelType == 'i'|| vowelType == 'o'|| vowelType == 'u'|| vowelType == 'y'||vowelType == 'A'|| vowelType == 'E'|| vowelType == 'I'|| vowelType == 'O'|| vowelType == 'U'|| vowelType == 'Y';
}

/* IsConsonant checks how mnay consanant characters are in the stings user entered*/
bool IsConsonant( char consonantType){
    if(IsPunctuation(consonantType)){
        return false;
    }
    else if(IsVowel(consonantType)){
        return false;
    }
    else if(consonantType == ' '){
        return false;
    }
    else{
        return true;
    }
}
