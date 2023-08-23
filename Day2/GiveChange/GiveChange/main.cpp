//
//  main.cpp
//  GiveChange
//
//  Created by Ben Baysinger  on 8/22/23.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    int quarters = 25; // assigning corresponding values to types of change one can recieve
    int dimes = 10;
    int nickels = 5;
    int pennies = 1;
    int itemPriceInCents ;//integer because you can't have a fraction of a cent
    int amountPaidInCents ;
    std::cout<< "Enter the item price in cents\n";
    std::cin>> itemPriceInCents ;
    std::cout<< "Enter amount paid in cents\n";
    std::cin>> amountPaidInCents ;
    int remainingChange = amountPaidInCents - itemPriceInCents ;
    std::cout<< remainingChange << " cents in change" << '\n' ;
    int breakdownOfChange = remainingChange ;
    int numberOfQuartersInChange  = breakdownOfChange / quarters ;/* Gives us amount leftover in quarters in change*/
    breakdownOfChange -= numberOfQuartersInChange * quarters ;/* breakdown of change is equal to breakdown of change minus the number of quarters in the change multiplied by 25*/
    int numberOfDimesInChange = breakdownOfChange / dimes ;
    breakdownOfChange -= numberOfDimesInChange *dimes ; /* breakdown of change is equal to breakdown of change minus the number of quarters in the change multiplied by 10*/
    int numberOfNickelsInChange  = breakdownOfChange / nickels ;
    breakdownOfChange -= numberOfNickelsInChange * nickels ; /* breakdown of change is equal to breakdown of change minus the number of nickels in the change multiplied by 5*/
    int numberOfPenniesInChange = breakdownOfChange / pennies ;
    breakdownOfChange -= numberOfPenniesInChange * pennies ; /* breakdown of change is equal to breakdown of change minus the nubmer of pennies in the change multiplied by 2*/
    std::cout<< "Quarters:" << numberOfQuartersInChange << '\n' << "Dimes:" << numberOfDimesInChange << '\n' << "Nickels:" << numberOfNickelsInChange << '\n' << "Pennies:" << numberOfPenniesInChange<< '\n' ;
    
    
    
    
    
    
    
    
    return 0;
}
