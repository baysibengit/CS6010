//
//  main.cpp
//  Average
//
//  Created by Ben Baysinger and Jake Dame on 8/22/23.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    int assignmentScore1;
    std::cout<< " Please enter your assignment scores one by one:\n";
    std::cin>> assignmentScore1 ;//making each test score a variable
    std::cout<< '\n'; // to create a space between assignment score
    int assignmentScore2 ;
    std::cin>> assignmentScore2 ;
    std::cout<< '\n';
    int assignmentScore3;
    std::cin>> assignmentScore3 ;
    std::cout<< '\n';
    int assignmentScore4 ;
    std::cin>> assignmentScore4 ;
    std::cout<< '\n';
    int assignmentScore5 ;
    std::cin>> assignmentScore5 ;
    std::cout<< '\n';
    float averageOfAssignmentScores ; /*making this a float because averages can have decimals*/
    averageOfAssignmentScores = (assignmentScore1 + assignmentScore2 + assignmentScore3 + assignmentScore4 + assignmentScore5)/5.0 ; /* Parenthesis around the the assigment scores to honor PEMDAS rule, Divided by a float to obtain a float answer*/
    std::cout<<"Average:\n" ;
    std::cout<< averageOfAssignmentScores ;
    
    
    
    return 0;
}
