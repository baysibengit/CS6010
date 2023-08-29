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
/* IsTerminator takes in character value of ?,.,or !. Helper funcitons*/
bool IsTerminator(char terminatorType)
{
    return terminatorType == '?'|| terminatorType == '!'|| terminatorType == '.';
}


/*IsPunctuation takes in character value of ?,.,',', or !. Helper functions*/
bool IsPunctuation(char punctuationType)
{
    return punctuationType == '?'|| punctuationType == '!'|| punctuationType == '.'|| punctuationType == ',';
}


/* IsVowel checks how many characters are vowels in the strings user entered. Helper functions*/
bool IsVowel(char vowelType)
{
    return vowelType == 'a'|| vowelType == 'e'|| vowelType == 'i'|| vowelType == 'o'|| vowelType == 'u'|| vowelType == 'y'||vowelType == 'A'|| vowelType == 'E'|| vowelType == 'I'|| vowelType == 'O'|| vowelType == 'U'|| vowelType == 'Y';
}


/* IsConsonant checks how mnay consanant characters are in the stings user entered*/
bool IsConsonant(char consonantType)
{
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


/* NumWords checks how many words are in string/stings user entered*/
int NumWords(std::string wordsInString)
{
    int count = 0;
    for (int i = 0; i < wordsInString.size(); i++){
        if(wordsInString[i] == ' '){
            count++;
        }
    }
    return count;
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
    double avg = (NumVowels(wordLength) + NumConsonants(wordLength))/ (NumWords(wordLength) * 1.0);
    return avg;
}


/* Calling NumVowels and dividing it by the amount of words in user inputted string*/
double AverageVowelsPerWord (std::string aveVowPerWord)
{
    double avg = NumVowels(aveVowPerWord) * 1.0/NumWords(aveVowPerWord);
    return avg;
}


int main(int argc, const char * argv[]){
        //Prompt user to enter string of sentences
        /* Use get line to prompt user to enter string of sentences*/
        /*Use while loop to allow user to enter multiple strings until they break loop and end by typing "done"*/
    //Initialize stringInput
    std::string stringInput = " ";

    while (stringInput != "done")
    {
        std::cout<< "\nEnter a string containing one or more sentences:\n";
        std::getline (std::cin,stringInput);
        if(stringInput != "done"){
            std::cout<< "\nAnalysis:";
            /* store variables in desired type outcome and plug in functions*/
            int wordCount = NumWords(stringInput);
            std::cout<< "\nNumber of words: " << wordCount + 1;// +1 to account for space
            int sentenceCount = NumSentences(stringInput);
            std::cout<< "\nNumber of sentences: "<< sentenceCount;
            
            int vowelCount = NumVowels(stringInput);
            std::cout<<"\nNumber of vowels: " << vowelCount;
            
            int consonantCount = NumConsonants(stringInput);
            std::cout<< "\nNumber of consonants: " << consonantCount;
            
            double avgWordLength = AverageWordLength(stringInput);
            std::cout<< "\nReading level (average word length): " << avgWordLength;
            
            double avgVowelPerWord = AverageVowelsPerWord(stringInput);
            std::cout<< "\nAverage vowels per word: " << avgVowelPerWord;
        }
        else
        {
            std::cout<< "Goodbye";
        }
        
    }
    
    
    return 0;
}
