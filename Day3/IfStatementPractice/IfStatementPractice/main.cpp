//
//  main.cpp
//  IfStatementPractice
//
//  Created by Ben Baysinger  on 8/23/23.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    int age ;
    std::cout<< "How old are you? \n";
    std::cin>> age;
    if ( age > 17 ) {
        std::cout<< " You are able to vote \n"; //Have to be 18 to vote
    }
    
    else {
        std::cout<< " You are unable to run for vote \n";
    }
    if (age > 29 ) {
        std::cout<< " You are able to run for senate \n"; // Have to be 30 to run for senate
    }
    else {
        std::cout<< " You are unable to run for senate \n";
    }
    if ( age >= 80 ) {
        std::cout<< " You are part of the greatest generation \n"; /* Have to be at least 80 or older to be considered part of the greatest generation*/
    }
    else if (age < 80 && age >= 60) {
        std::cout<< " You are a part of the baby boomer generation \n"; /* To be a baby boomer you have to be at least 60 but younger than 80*/
    }
    else if (age < 60 && age >= 40 ) {
        std::cout<< " You are a in generation x \n "; /* To be in generation x you have to be younger than 60 but at least 40 or older*/
    }
    else if (age < 40 && age >= 20) {
        std::cout<< " You are a millennial \n"; /* to be a millennial you have to be younger than 40 but at least 20 or older*/
    }
    else {
        std::cout<< " You are and IKid \n"; // If younger than 20 you are an IKid
    }
    char weekday, holiday, children; // character variables
    bool isWeekday;
    bool isHoliday;
    bool hasChildren; // all bools can be true or false
    
    
    std::cout<< " Is it a weekday (Y/N)? \n";
    std::cin>> weekday ;
    std::cout<< " Is it a holiday (Y/N)?\n";
    std::cin>> holiday ;
    std::cout<< " Do you have children? (Y/N) \n"; /*Giving yes or no answer choices to questions about character variables*/
    std::cin>> children ;
    if (weekday == 'Y') {
        isWeekday = true;
    } //Assigning Y to represent true
    else {
        isWeekday = false;
    } // anything else represents false
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
    
    if( hasChildren ) {
        std::cout<< " You are unable to sleep in \n"; /* If user has children automatically they cannot sleep in*/
    }
    else if( !isWeekday  && !hasChildren ) {
        std::cout<< " You are able to sleep in \n "; /* If it is not a weekday and the user does not have children then they can sleep in*/
    }
    else if ( isWeekday ) {
        std::cout<< " You are unable to sleep in \n"; /* If it is a weekday user cannot sleep in */
        }
    else if ( isHoliday && !hasChildren) {
        std::cout<< " You are able to sleep in \n "; /* IF it is a holiday and the user does not have children then they can sleep in*/
    }
    
    
            
        
    
    
    
    return 0;
}
