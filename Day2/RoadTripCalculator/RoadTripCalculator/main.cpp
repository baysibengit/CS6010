//
//  main.cpp
//  RoadTripCalculator
//
//  Created by Ben Baysinger  on 8/22/23.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    
    //Integer because prompt wants whole miles
    // milePerGallonEfficiency is float because number can have a decimal
    //costOfGasInDollarsPerGallon is float because gas is charged in dollars and cents
    //Prompt user to enter variables below
    int distanceInMiles;
    float milesPerGallonEfficiency;
    float costOfGasInDollarsPerGallon;
        std::cout<< "Pleae enter the total distance of your trip in miles\n";
        std::cin>> distanceInMiles;
        std::cout<< "Please enter your vehicles mile per gallon efficienty\n";
        std::cin>> milesPerGallonEfficiency;
        std::cout<< "Please enter the cost of gas in dollars per gallon\n";
        std::cin>> costOfGasInDollarsPerGallon;
    
    //numberOfGallonsUsed is float because we are using division
    float numberOfGallonsUsed = distanceInMiles / milesPerGallonEfficiency;
        std::cout<< "The number of gallons used\n";
        std::cout<< numberOfGallonsUsed <<'\n';
    
    //finalCostOfRoadTrip is float because we will most likely recieve answer with decimal
    float finalCostOfRoadTrip = numberOfGallonsUsed * costOfGasInDollarsPerGallon;
        std::cout<< "The final cost of your trip\n";
        std::cout<< finalCostOfRoadTrip <<'\n';
        std::cout<< "You will need at least 16 dollars to fund your road trip\n";
    
    
    

    
    
   
    
    
    
    

    
    
    
    return 0;
}
