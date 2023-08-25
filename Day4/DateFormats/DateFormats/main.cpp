//
//  main.cpp
//  DateFormats
//
/*  Created by Team: Ben Baysinger, Koffi Danhounsrou Zach Allred on 8/24/23.*/
//

#include <iostream>
#include <string>
//identify variables
int main(int argc, const char * argv[]) {
    std::string dateInput;
    std::string monthVar;
    std::string dayVar;
    std::string yearVar;
    std::string monthOutput;
    std::cout << "Please enter date in mm/dd/yyyy format.\n";
    std::cin >> dateInput;
//find slashes and put it in integer variable
    int firstSlash = dateInput.find("/");
   
    
    int lastSlash = dateInput.rfind("/");
    
/*Starting at first input and ending at slash for monthVar then storing/converting to integer*/
    monthVar = dateInput.substr(0,firstSlash);
    int numMonthVar = std::stoi(monthVar);
    
/*Designating position for day input. converting day variable to integer*/
    dayVar = dateInput.substr(firstSlash+1,lastSlash-1);
    int numDayVar = std::stoi(dayVar);
   
//Same process for year variables
    yearVar = dateInput.substr(lastSlash+1,lastSlash+3);
    int yearNumVar = std::stoi(yearVar);
//Setting parameteres
    if(numMonthVar < 1 || numMonthVar > 12 || numDayVar < 1 || numDayVar > 31 || yearNumVar < 1000 || yearNumVar > 9999){
        std::cout << "Invalid Entry.\n";
    }
//Converting numerical month value to written form
    else{
        
        
        if(numMonthVar == 1){
            monthOutput = "January";
        }
        
        if(numMonthVar == 2){
            monthOutput = "February";
        }
        
        if(numMonthVar == 3){
            monthOutput = "March";
        }
        
        if(numMonthVar == 4){
            monthOutput = "April";
        }
        
        if(numMonthVar == 5){
            monthOutput = "May";
        }
        
        if(numMonthVar == 6){
            monthOutput = "June";
        }
        
        if(numMonthVar == 7){
            monthOutput = "July";
        }
        
        if(numMonthVar == 8){
            monthOutput = "August";
        }
        if(numMonthVar == 9){
            monthOutput = "September";
        }
        if(numMonthVar == 10){
            monthOutput = "October";
        }
        if(numMonthVar == 11){
            monthOutput = "November";
        }
        if(numMonthVar == 12){
            monthOutput = "December";
        }
        
//Printing English date format
        std::cout << monthOutput << " " << numDayVar << ", " << yearNumVar << "\n";
        
    }
    
    return 0;
}
