//
//  main.cpp
//  Poker
//
//  Created by Zach Allred && Ben Baysinger && Jake Dame on 8/30/23.
//

#include <iostream>
#include "PokerHelper.hpp"
#include "PokerTests.hpp"
int main(int argc, const char * argv[]) {
    
    //Test function calls
    testIsStraight();
      testIsFlush();
      testIsStraightIsFlush();
      testIsFullHouse();
      testRoyalFlush();
    
    //resets counter each time for random.
    srand(time(0));
    //initialize counters for functions.
    int flushCounter=0;
    int straightCounter=0;
    int royalFlushCounter = 0;
    int fullHouseCounter=0;
    int straightFlushCounter=0;
    int runCounter=0;
    
    //start loop for generating hand statistics. Run 100000 times.
    for(int a=0; a < 1000000; a++){
        //create vector for deck using generatedeck function.
        std::vector<CardTypes> deck = generateDeck();
        //shuffle deck using shuffle deck function.
        ShuffleDeck(deck);
        //get number of straight using numstraight function and accompanying functions.
        numStraight(isStraight(SortHand(GetFiveCards(deck))),straightCounter);
        //get number of flush using numflush function and accompanying functions.
        numFlush(isFlush((GetFiveCards(deck))),flushCounter);
        //get number of fullhouse using num function and accompanying functions.
        
        numFullHouse(isFullHouse(SortHand(GetFiveCards(deck))),fullHouseCounter);
        //get number of royal flush using num function and accompanying functions.
        
        numRoyalFlush(isRoyalFlush((isFlush(GetFiveCards(deck))), SortHand(GetFiveCards(deck))), royalFlushCounter);
        //get number of Straight flush using num function and accompanying functions.
        numStraightFlush(isStraightFlush(isStraight(SortHand(GetFiveCards(deck))),isFlush(deck)), straightFlushCounter);
        runCounter++;
    }
    /*
    std::cout <<"Total Number of Flushes: "<< flushCounter << "\n";
    std::cout <<"Total Number of Straights: "<< straightCounter << "\n";
    std::cout <<"Total Number of Royal Flushes: "<< royalFlushCounter << "\n";
    std::cout <<"Total Number of Full Houses: "<< fullHouseCounter << "\n";
    std::cout <<"Total Number of Straight Flushes: "<< straightFlushCounter << "\n";
     */
    //function to compute stats
    ComputerStats(runCounter, fullHouseCounter, royalFlushCounter,straightCounter, straightFlushCounter, flushCounter);
    //push out cards in deck to console.


    
    return 0;
}

