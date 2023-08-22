//
//  main.cpp
//  RoadTripCalculator
//
//  Created by Ben Baysinger  on 8/22/23.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    int distanceInMiles; //prompt wants in whole miles
    std::cout<< "Pleae enter the total distance of your trip in miles\n" ;
     std::cin>> distanceInMiles;
    float milesPerGallonEfficiency; // float because number can have a decimal
    std::cout<< "Please enter your vehicles mile per gallon efficienty\n" ;
    std::cin>> milesPerGallonEfficiency;
    float costOfGasInDollarsPerGallon; /*float because gas usually is charged in dollars and cents*/
    std::cout<< "Please enter the cost of gas in dollars per gallon\n";
    std::cin>> costOfGasInDollarsPerGallon;
    float numberOfGallonsUsed = distanceInMiles / milesPerGallonEfficiency;
    std::cout<< "The number of gallons used\n" ;
    std::cout<< numberOfGallonsUsed <<'\n';
    float finalCostofRoadTrip = numberOfGallonsUsed * costOfGasInDollarsPerGallon;
    std::cout<< "The final cost of your trip\n" ;
    std::cout<< finalCostofRoadTrip <<'\n';
    std::cout<< "You will need at least 16 dollars to fund your road trip\n";
    
    
    

    
    
   
    
    
    
    

    
    
    
    return 0;
}
