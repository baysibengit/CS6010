//
//  main.cpp
//  GiveChange
//
//  Created by Ben Baysinger  on 8/22/23.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    
    // assigning corresponding values to types of change one can recieve
    // Integers assigned because we are already dealing with cents and cannot have a decimal
    int quarters = 25;
    int dimes = 10;
    int nickels = 5;
    int pennies = 1;
    int itemPriceInCents ;
    int amountPaidInCents ;
    // Prompting user to enter item price and amount paid
        std::cout<< "Enter the item price in cents\n";
        std::cin>> itemPriceInCents ;
        std::cout<< "Enter amount paid in cents\n";
        std::cin>> amountPaidInCents ;
    int remainingChange = amountPaidInCents - itemPriceInCents;
        std::cout<< remainingChange << " cents in change" << '\n';
    int leastCoinsReturned = remainingChange;
    
    /*Start by dividing leastCoinsReturned/remainingChange by coin type to get leftover amount of coin type and assign it integer variable
     leastCoinsReturned is equal to the remaining change minus the number of coin type in the change multiplied by coin type value. Process will run for quarters, dimes, nickels, and pennies*/
    int numberOfQuartersInChange  = leastCoinsReturned / quarters;
        leastCoinsReturned -= numberOfQuartersInChange * quarters;
    int numberOfDimesInChange = leastCoinsReturned / dimes;
        leastCoinsReturned -= numberOfDimesInChange *dimes;
    int numberOfNickelsInChange  = leastCoinsReturned / nickels;
        leastCoinsReturned -= numberOfNickelsInChange * nickels;
    int numberOfPenniesInChange = leastCoinsReturned / pennies;
        leastCoinsReturned -= numberOfPenniesInChange * pennies;
    
    /*Prints categorized change received in least possible coins*/
        std::cout<< "Quarters:" << numberOfQuartersInChange << '\n' << "Dimes:" << numberOfDimesInChange << '\n' << "Nickels:" << numberOfNickelsInChange << '\n' << "Pennies:" << numberOfPenniesInChange<< '\n';
    
    
    
    
    
    
    
    
    return 0;
}
