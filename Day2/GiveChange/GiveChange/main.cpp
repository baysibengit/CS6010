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
    int quarters;
    int dimes;
    int nickels;
    int pennies;
    int itemPriceInCents;
    int amountPaidInCents;
    // Prompting user to enter item price and amount paid
        std::cout<< "Enter the item price in cents\n";
        std::cin>> itemPriceInCents ;
        std::cout<< "Enter amount paid in cents\n";
        std::cin>> amountPaidInCents ;
    int change = amountPaidInCents - itemPriceInCents;
        std::cout<< change << " cents in change" << '\n';
    
    quarters = change/25;
    change = change%25;
    dimes = change/10;
    change = change%10;
    nickels = change/5;
    change = change%5;
    pennies = change/1;
    change = change%1;
    
    
        std::cout<< "Quarters:" << quarters << '\n' << "Dimes:" << dimes << '\n' << "Nickels:" << nickels << '\n' << "Pennies:" << pennies<< '\n';
    
    
    
    
    
    
    
    
    return 0;
}
