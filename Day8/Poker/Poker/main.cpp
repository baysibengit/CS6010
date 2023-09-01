//
//  main.cpp
//  Poker
//
//  Created by Zach Allred, Ben Baysinger, and Jake Dame on 8/30/23.
//

#include <iostream>
#include "PokerHelper.hpp"

int main(int argc, const char * argv[]) {
    //generate vector and load with deck from generateDeck function.
    srand(time(0));
    int flushCounter=0;
    int straightCounter=0;
    int royalFlushCounter = 0;
    int fullHouseCounter=0;
    int straightFlushCounter=0;
    int runCounter=0;
    for(int a=0; a < 100000; a++){
        /*
        int isFlushc1A {3};
        int isFlushc2A {3};
        int isFlushc3A {3};
        int isFlushc4A {5};
        int isFlushc5A {5};
        
        std::vector<int> isFullHouse2;
        
        isFullHouse2 = {isFlushc1A, isFlushc2A, isFlushc3A, isFlushc4A, isFlushc5A};
        
        testFullHouse(isPair(isFullHouse2),isTriple(isFullHouse2));
        */
        std::vector<CardTypes> deck = generateDeck();
        ShuffleDeck(deck);
        numStraight(isStraight(SortHand(GetFiveCards(deck))),straightCounter);
        numFlush(isFlush((GetFiveCards(deck))),flushCounter);
        
        numFullHouse(isFullHouse(isPair(SortHand(GetFiveCards(deck))), isTriple(SortHand(GetFiveCards(deck)))),fullHouseCounter);
        
        numRoyalFlush(isRoyalFlush((isFlush(GetFiveCards(deck))), SortHand(GetFiveCards(deck))), royalFlushCounter);
        numStraightFlush(isStraightFlush(isStraight(SortHand(GetFiveCards(deck))),isFlush(deck)), straightFlushCounter);
        runCounter++;
    }
    std::cout <<"Total Number of Flushes: "<< flushCounter << "\n";
    std::cout <<"Total Number of Straights: "<< straightCounter << "\n";
    std::cout <<"Total Number of Royal Flushes: "<< royalFlushCounter << "\n";
    std::cout <<"Total Number of Full Houses: "<< fullHouseCounter << "\n";
    std::cout <<"Total Number of Straight Flushes: "<< straightFlushCounter << "\n";
    std::cout << "Total runs: " << runCounter << "\n";
    
    ComputerStats(runCounter, fullHouseCounter, royalFlushCounter,straightCounter, straightFlushCounter, flushCounter);
    //push out cards in deck to console.

    return 0;
}
