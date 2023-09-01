//
//  PokerHelper.hpp
//  Poker
//
//  Created by Zach Allred on 8/30/23.
//

#ifndef PokerHelper_hpp
#define PokerHelper_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>

//create struct
struct CardTypes{
    std::string suit;
    std::string cardName;
    int rank;
};

std::vector<CardTypes> generateDeck();
void ShuffleDeck(std::vector<CardTypes>& deck);

std::vector<CardTypes> GetFiveCards(std::vector<CardTypes> deck);
std::vector<int> SortHand(std::vector<CardTypes> fiveCards);
bool isThereKing(std::vector<CardTypes> fiveCards);
bool isStraight(std::vector<int> rankedFiveCards);
bool isFlush(std::vector<CardTypes> fiveCards) ;
bool isStraightFlush(bool isFlush, bool isStraight);
bool isRoyalFlush(bool isRoyalFlush, std::vector<int> fiveCards);
bool isFullHouse(std::vector<int> fiveCards);
int numStraight(bool checkStraight, int& counter);
int numFlush(bool checkFlush, int& counter);
int numStraightFlush(bool checkFlush, int& counter);
void numRoyalFlush(bool checkRoyalFlush, int& counter);
int numFullHouse(bool checkFullHouse, int& counter);
bool isTriple(std::vector<int> fiveCards);
bool isPair(std::vector<int> fiveCards);
void testFlush(std::vector<CardTypes> flushTest);
void ComputerStats(double runs, double full, double royal, double straight, double straightFlush, double flush);
void testFullHouse(std::vector<int> flushTest);
void testRoyalFlush();


#endif /* PokerHelper_hpp */
