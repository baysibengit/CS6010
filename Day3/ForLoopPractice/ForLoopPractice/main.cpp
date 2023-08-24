//
//  main.cpp
//  ForLoopPractice
//
//  Created by Ben Baysinger  on 8/23/23.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    
    //For loop starts at 1 and counts up 1 until 10
        int i;
        for ( i = 1;  i <= 10 ; i++) {
        std::cout<< i <<"\n";
    }
    
    //While loop does same action as for loop
        i = 1;
        while ( i <= 10) {
        std::cout<< i <<"\n";
        i++;
    }
    //Prompting the user to enter two numbers. Setting them first
        int firstNumberEntered;
        int secondNumberEntered;
        std::cout<< "Please enter two numbers \n";
        std::cin>> firstNumberEntered;
        std::cin>> secondNumberEntered;
    
    /*Using a for loop to print every number in between two numbers user entered because we "know" how many numbers should be printed in between two numbers user entered*/
        for ( int i = firstNumberEntered; i <= secondNumberEntered; i++) {
        std::cout<< i << "\n";
    }
    
    //Use if statement to so that numbers can be entered in any order
        if (secondNumberEntered < firstNumberEntered)
        {
            for ( i = secondNumberEntered; i <= firstNumberEntered; i++){
                std::cout<< i << "\n";
            }
        }
    //Printing odd numbers betwween 1 and 20. I prefer this way because it is faster and less code
        for ( int i = 1; i <= 20; i++) {
                std::cout<< i << "\n";
                i++;
            }
    /*Pintinng odd numbers between 1 and 20 using an if statement. Using modulo to ommit any multiple of two*/
        for ( int i = 1; i <= 20; i++) {
            if (i%2 != 0) {
                std::cout<< i <<"\n";
            }
    }
    /*Running a while loop so that the user can keep inputting information and placing a break when number inputted is negative. Calculating sum of all positve numbers user entered*/
        int j=0;
        int sum = 0;
        while (true) {
        std::cout<< "Please enter a number\n";
        std::cin>> j;
            if (j < 0) {
                break;
            }
            sum = sum + j;
        }
        std::cout<< sum << " Is the sum of all postive numbers entered" << "\n";
        std::cout<< "\n";
    
    
    /* Identified 'a' as value in loop. Plugged 1, 2, 3, 4, and 5 for values of 'a' and cut off at 5 multiples. Added space so that multiples are in uniform rows*/
        for (int a = 1; a <= 5; a++) {
            std::cout<< a <<"X*: " << a * 1 << " " << a * 2 << " " << a * 3 << " " << a * 4 << " " << a * 5 << " " << "\n";
    }
        
    return 0;
}
