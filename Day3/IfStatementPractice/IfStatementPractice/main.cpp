//
//  main.cpp
//  IfStatementPractice
//
//  Created by Ben Baysinger  on 8/23/23.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    int age ;
    
    /*Prompting user for age. If older than 17 can vote else unable to vote. Same process used for running for senate only difference is you need to be older than 29 instead of 17*/
        std::cout<< "How old are you? \n";
        std::cin>> age;
            if ( age > 17 ) {
                    std::cout<< " You are able to vote \n";
    }
    
            else {
                    std::cout<< " You are unable to vote \n";
    }
    
    
            if (age > 29 ) {
                    std::cout<< " You are able to run for senate \n"; // Have to be 30 to run for senate
    }
            else {
                    std::cout<< " You are unable to run for senate \n";
    }
    
    /*Setting parameters sequentially from oldest generation to youngest. IKid only has else becuase all other parameter fufill a generation assignment as well as it ends our if conditions*/
            if ( age >= 80 ) {
                    std::cout<< " You are part of the greatest generation \n";
    }
            else if (age < 80 && age >= 60) {
                std::cout<< " You are a part of the baby boomer generation \n";
            }
            else if (age < 60 && age >= 40 ) {
                    std::cout<< " You are a in generation x \n ";
    }
            else if (age < 40 && age >= 20) {
                    std::cout<< " You are a millennial \n";
    }
            else {
                    std::cout<< " You are and IKid \n";
    }
    
    //Character variables are assigned to weekday, holiday, and children
    /*bools are assigned to the condition of the characters becuase they can either be true or false*/
    char weekday, holiday, children;
    bool isWeekday;
    bool isHoliday;
    bool hasChildren;
    
    /*Giving yes or no answer choices to questions about character variables*/
    //Assigning Y to true and anything else represents false
    std::cout<< " Is it a weekday (Y/N)? \n";
    std::cin>> weekday ;
    std::cout<< " Is it a holiday (Y/N)?\n";
    std::cin>> holiday ;
    std::cout<< " Do you have children? (Y/N) \n";
    std::cin>> children ;
        if (weekday == 'Y') {
        isWeekday = true;
    }
        else {
        isWeekday = false;
    }
    
        if (holiday == 'Y') {
        isHoliday = true;
    }
        else {
        isHoliday = false;
    }
    
        if (children == 'Y') {
        hasChildren = true;
    }
        else {
        hasChildren = false;
    }
    
    //If user has children they cannot sleep in
    //If it is a weekday user cannot sleep in
    //If it is a holiday and the user does not have children they can sleep in
    //If it is not a weekday and the user does not have children they can sleep in
    
        if( hasChildren ) {
        std::cout<< " You are unable to sleep in \n";
    }
        else if( !isWeekday  && !hasChildren ) {
        std::cout<< " You are able to sleep in \n ";
    }
        else if ( isWeekday ) {
        std::cout<< " You are unable to sleep in \n";
        }
        else if ( isHoliday && !hasChildren) {
        std::cout<< " You are able to sleep in \n "; 
    }
    
    
            
        
    
    
    
    return 0;
}
