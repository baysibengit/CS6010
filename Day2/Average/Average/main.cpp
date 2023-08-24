//
//  main.cpp
//  Average
//
//  Created by Ben Baysinger and Jake Dame on 8/22/23.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    
    /*Prompt user to enter 5 assingment scores but first assign each assignment score a variable. Integer assignment because they are all whole numbers. Average is a float because you can have a decimal*/
    int assignmentScore1;
    int assignmentScore2;
    int assignmentScore3;
    int assignmentScore4;
    int assignmentScore5;
        std::cout<< " Please enter your assignment scores one by one:\n";
        std::cin>> assignmentScore1 ;
        std::cout<< '\n';
        std::cin>> assignmentScore2;
        std::cout<< '\n';
        std::cin>> assignmentScore3;
        std::cout<< '\n';
        std::cin>> assignmentScore4;
        std::cout<< '\n';
        std::cin>> assignmentScore5;
        std::cout<< '\n';
    
    /*Parenthesis around the assignment score to honor order of operations. Divide by 5.0 to make sure we get a float answer*/
    float averageOfAssignmentScores;
    averageOfAssignmentScores = (assignmentScore1 + assignmentScore2 + assignmentScore3 + assignmentScore4 + assignmentScore5)/5.0 ; 
        std::cout<<"Average:\n";
        std::cout<< averageOfAssignmentScores;
    
    
    
    return 0;
}
