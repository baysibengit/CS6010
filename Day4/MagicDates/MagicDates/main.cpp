//
// main.cpp
//  MagicDates
//
//  Created by Zach Allred && Ben Baysinger && Koffi Danhounsrou on 8/24/23.
//

#include <iostream>
#include <string>

int main(int argc, const char * argv[]) {
    //initiate variables
    std::string dateInput;
    std::string monthVar;
    std::string dayVar;
    std::string yearVar;
    std::string monthOutput;
    std::string yearCompVar;
    //request input from user
    std::cout << "Please enter date in mm/dd/yyyy format.\n";
    std::cin >> dateInput;
    //find slash positions to use in substr
    int firstSlash = dateInput.find("/");
   
    
    int lastSlash = dateInput.rfind("/");
    
    //find where each value is based on the slash positions using substr. Then convert to integers.
    monthVar = dateInput.substr(0,firstSlash);
    int numMonthVar = std::stoi(monthVar);
    
    
    dayVar = dateInput.substr(firstSlash+1,lastSlash-1);
    int numDayVar = std::stoi(dayVar);
   
    
    yearVar = dateInput.substr(lastSlash+3,lastSlash+3);
    int yearNumVar = std::stoi(yearVar);
    
    yearCompVar = dateInput.substr(lastSlash+1,lastSlash+3);
    int yearCompNumVar = std::stoi(yearCompVar);
    
    //Check for invalid values before proceeding.
    
    if(numMonthVar < 1 || numMonthVar > 12 || numDayVar < 1 || numDayVar > 31 || yearNumVar < 0 || yearNumVar > 99 || yearCompNumVar < 1000 || yearCompNumVar > 9999){
        std::cout << "Invalid Entry.\n";
    }
 //multiply day and month integers to see if it equals year
    else{
        if(numDayVar*numMonthVar == yearNumVar){
            std::cout << dateInput << " is a magic number.\n";
        }
        else{
            std::cout << dateInput << " is NOT a magic number.\n";
    }
        
    }
    
    return 0;
}
