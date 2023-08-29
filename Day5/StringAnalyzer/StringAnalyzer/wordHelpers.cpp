//
//  wordHelpers.cpp
//  StringAnalyzer
//
//  Created by Ben Baysinger  on 8/29/23.
//

#include "wordHelpers.hpp"
#include "LetterHelpers.hpp"
#include <iostream>
/* NumWords checks how many words are in string/stings user entered*/
int NumWords(std::string wordsInString)
{
    int count = 0;
    for (int i = 0; i < wordsInString.size(); i++){
        if(wordsInString[i] == ' '){
            count++;
        }
    }
    return count + 1; /* Add one to account for word after last space*/
}

/* NumSentences checks number of sentences from user inputted string/strings*/
int NumSentences(std::string sentencesInString)
{
    int count = 0;
    for (int i = 0; i < sentencesInString.size(); i++) {
        if (sentencesInString[i] == '.' || sentencesInString[i] == '?' || sentencesInString[i] == '!') {
            count++;
        }
    }
    return count;
}

/* NumVowels gives number of vowels in user inputed string. Call IsVowel function*/
int NumVowels (std::string vowelsInString)
{
    int vowelCount = 0;
    for (int i = 0; i < vowelsInString.size(); i ++){
        if (IsVowel(vowelsInString[i])){
            vowelCount++;
        }
    }
    return vowelCount;
}

/* NumConsonants gives number of vowels in user inputted string. Call IsConsonant function*/
int NumConsonants(std::string consonantsInString)
{
    int consonantCount = 0;
    for (int i = 0; i < consonantsInString.size(); i ++){
        if (IsConsonant(consonantsInString[i])){
            consonantCount++;
        }
    }
    return consonantCount;
}

/* Calling NumWords, NumVowel, and NumConsonants functions to find the average word length*/
double AverageWordLength (std::string wordLength)
{
//    std::cout << NumVowels(wordLength) << " " << NumConsonants(wordLength) << " " << NumWords(wordLength);
    double avg = (NumVowels(wordLength) + NumConsonants(wordLength))/ (NumWords(wordLength) * 1.0);
    return avg;
}

/* Calling NumVowels and dividing it by the amount of words in user inputted string*/
double AverageVowelsPerWord (std::string aveVowPerWord)
{
    double avg = NumVowels(aveVowPerWord) * 1.0 /NumWords(aveVowPerWord);
    return avg;
}
