//
//  PokerTests.cpp
//  Poker
//
//  Created by Ben Baysinger  on 8/31/23.
//

#include "PokerTests.hpp"
#include <iostream>
#include <cassert>
#include "PokerHelper.hpp"

/* ErrorExit function needed to exit program and prompt user if test is failed*/
void ErrorExit( std::string message )
{
  std::cerr << "Failed test: " << message << std::endl;
  exit(1); // Causes the entire program to exit.
}

//Test vectors 
std::vector<int> straightOne { 1, 2, 3, 4, 5};
std::vector<int> straightTwo {6, 7, 8, 9, 10};
std::vector<int> notStraight {7, 4, 3, 3, 2};
std::vector<int> sameNumDiffSuit {4, 4, 4, 4, 3};
std::vector<int> onePairHand {2, 2, 3, 5, 6};
std::vector<int> multiplePairHand{2, 2, 3, 3, 4};
std::vector<int> tripleHand{2, 2, 2, 3, 4};
std::vector<int> fullHouseHand{2, 2, 2, 3, 3};
std::vector<CardTypes> flushHand = {
       {"Hearts", "Ace", 14},
       {"Hearts", "King", 13},
       {"Hearts", "Queen", 12},
       {"Hearts", "Jack", 11},
       {"Hearts", "Ten", 10}
   };
std::vector<CardTypes> notFlushHand = {
    {"Hearts", "Queen", 12},
    {"Spades", "King", 13},
    {"Clubs", "Queen", 12},
    {"Diamonds", "Jack", 11},
    {"Hearts", "Ten", 10}
};
std::vector<CardTypes> straightFlushHand = {
    {"Hearts", "Ace", 14},
    {"Hearts", "King", 13},
    {"Hearts", "Queen", 12},
    {"Hearts", "Jack", 11},
    {"Hearts", "Ten", 10}
};
std::vector<CardTypes> notStraightFlushHand = {
    {"Hearts", "Queen", 12},
    {"Spades", "King", 13},
    {"Clubs", "Queen", 12},
    {"Diamonds", "Jack", 11},
    {"Hearts", "Ten", 10}
};

/*Test against two cases of striaghts and two cases of not straights while throwing repeats in*/
void testIsStraight(){
    if (isStraight(straightOne) != true){
        ErrorExit("Test failed - isStraight");
    }
    if (isStraight(straightTwo) != true){
        ErrorExit("Test failed - isStraight");
    }
    if (isStraight(notStraight) != false){
        ErrorExit("Test failed - notStraight");
    }
    if (isStraight(sameNumDiffSuit) != false){
        ErrorExit("Test failed - sameNumDiffSuit");
    }
}

//Testing flush hands and not flush hands 
void testIsFlush(){
    assert(isFlush(flushHand)&& "isFlush function failed");
    assert(!isFlush(notFlushHand) && "isFlush function failed");
}

/*Testing isStraightFlush function with a hand that would return true and one that would return false*/
void testIsStraightIsFlush(){
    
    assert(isStraightFlush(isFlush(straightFlushHand), isStraight(SortHand(straightFlushHand)))&& "IsStraightIsFlush function failed");
    assert(!isStraightFlush(isFlush(notStraightFlushHand), isStraight(SortHand(notStraightFlushHand)))&& "IsStraightIsFlush function failed");
}

//Testing isPair function
void testIsPair(){
    assert(isPair(onePairHand) && "isPair function failed");
    assert(isPair(multiplePairHand) && "isPair function failed ");
    assert(!isPair(straightOne) && "isPair function failed");
}

//Testing isTriple function
void testIsTriple(){
    assert(isTriple(tripleHand) && "isTriple function failed");
    assert(!isTriple(onePairHand) && "isTriple function failed");
}

//Testing full house function
/*void testIsFullHouse(){
    assert(isFullHouse(fullHouseHand)) && "isFullHouse function failed ");
    assert(!isFullHouse(tripleHand)) && "isFullHouse function failed ");
    assert(!isFullHouse(onePairHand) && "isFullHouse function failed ");
    assert(!isFullHouse(straightOne) && "isFullHouse function failed ");
}*/





