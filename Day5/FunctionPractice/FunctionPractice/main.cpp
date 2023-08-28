//
//  main.cpp
//  FunctionPractice
//
//  Created by Ben Baysinger  on 8/25/23.
//

#include <iostream>
#include <string>
#include <cmath>
#include <ctime>


/*Give function type, parameters,and equation. Make sure to return function type*/
float hypotenuse( float triangSideLengthA, float triangSideLengthB){
    float hypotenuse = std::sqrt(pow(triangSideLengthA,2) + pow(triangSideLengthB,2));
    return hypotenuse;
}

//Give function type. Is bool can either be true or false.
bool isCapitalized (std::string wordInputted){
    return std::isupper(wordInputted[0]);
}

/*Give function name. Assign string because that is what we want outputted*/
std::string boolToString (bool value)
{
    if(value){
        return "true";
    }
    else{
        return "false";
    }
}
    
    



int main(int argc, const char * argv[]) {
    
    //Part 1
    //Part A
    //Identify variable for triangle side lengths
    //Prompt user for side lengths
    float triangleSideLengthA;
    float triangleSideLengthB;
    std::cout<< "Please enter triangle's first side length: \n";
    std::cin>> triangleSideLengthA;
    std::cout<< "Please enter triangle's second side length: \n";
    std::cin>> triangleSideLengthB;
    
    /*Call pow function to get side lengths squared and store in float variable.*/
    /*Call square root funciton and plug in squared triangle side lenghts and store in squareRootOfTriangleVariable*/
    float triangleSideLengthASquared = pow(triangleSideLengthA, 2);
    float triangleSideLengthBSquared = pow(triangleSideLengthB, 2);
    float squareRootOfTriangle = triangleSideLengthASquared + triangleSideLengthBSquared;
    squareRootOfTriangle = std::sqrt(squareRootOfTriangle);
    std::cout<< "The length of the hypotenuse is: \n" << squareRootOfTriangle;
    
    //Part B
    /*Identify variablels for speed and angle then prompt user for input*/
    float speed;
    float angle;
    std::cout<< "\n"<<"Please enter your current speed: \n";
    std::cin>> speed;
    std::cout<< "Please enter your the angle you are currently going in: \n";
    std::cin>> angle;
    
    /* Use velocity equations and store in float variable. Call cos and sign functions */
    float velocityOfX = speed * std::cos(angle);;
    float velocityOfY = speed * std::sin(angle);
    std::cout<< "Velocity of x: " << velocityOfX << "\n";
    std::cout<< "Velocity of y: " << velocityOfY << "\n";
    
    //Part C
    std::time_t result = std::time(nullptr);
       std::cout << std::asctime(std::localtime(&result))
                 << result << " seconds since the Epoch\n";
    /*std::asctime and std::localtimes are the functions being called*/
    
    //Part 2
    //Give needed values for function above main
    //store function result in variable
    float triangSideLengthA = 3;
    float triangSideLengthB = 4;
    float res = hypotenuse(triangSideLengthA, triangSideLengthB);
    std::cout<< "Hypotenuse is: " << res;
    //Wouldn't use cin function because users can be unreliable
    
    /*It would be difficult to turn the speed/velocity task into a function because you need to return two answers. It would be easier to do it in two function. I would wrap the code into two functions so that you could return x velocity and return y velocity separately*/
    
    //Print enter word
    //Prompt user to enter word
    //Ran if to print whether it was capitalized or not
    std::string wordInputted;
    std::cout<< "\nEnter word: \n";
    std::cin>> wordInputted;
    if(isCapitalized(wordInputted)) {
        std::cout<< "This word is capitalized\n";
    }
    else {
        std::cout<< "This word is not capitalized\n";
    }
    
    //Prints string true or false
    std::string output;
    output = boolToString(isCapitalized(wordInputted)) ;
    std::cout<< output << "\n";
    
    
    
    
    
    return 0;
}
