//
//  main.cpp
//  VolumeConvert
//
//  Created by Ben Baysinger and Jake Dame  on 8/22/23.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    
    float volumeOunces ;
      // type and name independent variable - amount in ounces
      std::cout << "Enter volume in ounces: ";
      // print instructions to user
      std::cin >> volumeOunces;
      // assign variable to user's input
      std::cout << "Ounces: " << volumeOunces << "\n";
      // print user's original input - to help user remember while looking down list at conversions
    
    float volumeCups;
      //type and name first of five dependent variables
      volumeCups = volumeOunces / 8;
      // define output by operation named in canvas table
      std::cout << "Cups: " << volumeCups << "\n";
      // print output of conversion
    
    float volumePints ;
      volumePints = volumeOunces / 16;
      std::cout << "Pints: " << volumePints << "\n";
    
    float volumeGallons;
      volumeGallons = volumeOunces / 128;
      std::cout << "Gallons: " << volumeGallons << "\n";
    
    float volumeLiters;
      volumeLiters = volumeOunces * .0296;
      std::cout << "Liters: " << volumeLiters << "\n";
    
    float volumeCubicInches;
      volumeCubicInches = volumeOunces * 1.8;
      std::cout << "Cubic Inches: " << volumeCubicInches << "\n";
    return 0;
}
