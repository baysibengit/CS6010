//
//  PokerHelpers.cpp
//  Cards
//
//  Created by Ben Baysinger && Jake Dame && Zach Allred on 8/30/23.
//

#include "PokerHelper.hpp"
//generate deck using arrays and vectors.

std::vector<CardTypes> generateDeck(){
    //assign vector
    std::vector<CardTypes> deck;
    //create arrays to load into cards.
    std::string suit[]={"Hearts", "Diamonds", "Spades", "Clubs"};
    std::string cardName[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
    //loop through all cards in each suit.
    for(int a=0; a < 4; a++){
        for(int b=0; b < 13; b++){
            //create vector variables from arrays.
            CardTypes card;
            card.suit = suit[a];
            card.cardName=cardName[b];
            card.rank=b+1;
            deck.push_back(card);
            }
        }
    return deck;
}
//shuffle deck, but use reference so deck is unchanged.
void ShuffleDeck(std::vector<CardTypes>& deck){
    //loop through deck, assign random value.
    for(int a = 0; a <= 51; a++){
        int randomCardVal = std::rand() % 52;
        //create temp to pass value temporarily.
        CardTypes tempCard = deck[a];
        deck[a]= deck[randomCardVal];
        deck[randomCardVal] = tempCard;
    }
}

//get five cards from deck for hand comparison.
std::vector<CardTypes> GetFiveCards(std::vector<CardTypes> deck){
    std::vector<CardTypes> fiveCards;
    //pull first 5 cards from deck.
    for(int f=0; f < 5;f++){
        CardTypes tempCard = deck[f];
        //push cards into fiveCards vector.
        fiveCards.push_back(tempCard);
    }
    return fiveCards;
}

//helper function for king checks.

bool isThereKing(std::vector<CardTypes> fiveCards){
    //load suit into a string variable.
    std::string suit = fiveCards[0].cardName;
    //
    for(int i = 1; i < 5; i++) {
        //check for cardname king, return true if found.
        if(fiveCards[i].cardName == "King") {
            return true;
        }
    }
    return false;
}
//function to obtain a sorted hand of 5 cards with their ranks.

std::vector<int> SortHand(std::vector<CardTypes> fiveCards){
    //create vector to push ranks into
    std::vector<int> rankSort;
    for(CardTypes card:fiveCards){
        int rank = card.rank;
        //change ace to 14 when there is a ace for royal flush.
        if(rank==1 && isThereKing(fiveCards)){
            rank=14;
            
           }
        //push into vector.
        rankSort.push_back(rank);
    }
    //sort vector.
    std::sort(rankSort.begin(), rankSort.end());
    return rankSort;
    }
//function to check if hand is a straight.
bool isStraight(std::vector<int> rankedFiveCards){
    for(int a=1; a < 5; a++){
        //loop through cards checking if rank of card i is less than next card by 1.
        if((rankedFiveCards[a-1]+1)!=rankedFiveCards[a]){
            return false;
        }
    }
    return true;
}
//function to check if hand is flush.
bool isFlush(std::vector<CardTypes> fiveCards) {
    std::string suit = fiveCards[0].suit;
    //loop through suits from vector to see if they all match.
    for(int i = 1; i < 5; i++) {
        if(fiveCards[0].suit != fiveCards[i].suit) {
            return false;
        }
    }
    return true;
}
//function to check if straight flush.
bool isStraightFlush(bool isFlush, bool isStraight){
    //check helper functions to determine if both are true.
    if(isFlush && isStraight){
        return true;
    }
    return false;
}
//function to determine if hand is royal flush.
bool isRoyalFlush(bool isFlush, std::vector<int> fiveCards){
    //if first card is 10, last card is ace from isKing helper function, and isflush is true, its a royal flush.
    if (fiveCards[0]==10 && isFlush && fiveCards[4]==14){
        return true;
    }
    return false;
}
//fullhouse checker function.
bool isFullHouse(std::vector<int> fiveCards){
    int PairCounter=0;
    //loop through all cards checking each card against every other card.
    for(int a=0; a < 5; a++){
        for(int b=a+1; b < 5; b++){
            if(fiveCards[a]==fiveCards[b]){
                //increase counter for pairs.
                PairCounter++;
            }
        }
        //if 4 pairs, return true.
        if(PairCounter == 4){
            return true;
        }
    }
    return false;
}
//generate number of straights by checking if is straight function is true, and increment counter by 1 using reference so it updates in main.
int numStraight(bool checkStraight, int& straightCounter){
    if(checkStraight){
        straightCounter++;
    }
    return straightCounter;
}
//generate number of flushs by checking if is flush function is true, and increment counter by 1 using reference so it updates in main.

int numFlush(bool checkFlush, int& flushCounter){
    if(checkFlush){
        flushCounter++;
    }
    return flushCounter;
}

//generate number of straightflushs by checking if is straightflush function is true, and increment counter by 1 using reference so it updates in main.

int numStraightFlush(bool checkFlush, int& straightFlushCounter){
    if(checkFlush){
        straightFlushCounter++;
    }
    return straightFlushCounter;
}

//generate number of royal flushes by checking if is royal flush function is true, and increment counter by 1 using reference so it updates in main.

void numRoyalFlush(bool checkRoyalFlush, int& royalFlushCounter){
    if(checkRoyalFlush){
        royalFlushCounter++;
    }
}
//generate number of full houses by checking if is full house function is true, and increment counter by 1 using reference so it updates in main.

int numFullHouse(bool checkFullHouse, int& fullHouseCounter){
    if(checkFullHouse){
        fullHouseCounter++;
    }
    return fullHouseCounter;
}

//output final stats using numbers generated in helper functions. Multiply by 100 for percentage.

void ComputerStats(double runs, double full, double royal, double straight, double straightFlush, double flush){
    std::cout << "Total runs: " << runs << "\n" << "Flush percentage:" << (flush/runs)*100.0 << "\n" << "Fullhouse percentage: " << (full/runs)*100.0 << "\n" << "Royal Flush percantage: " << (royal/runs)*100.0 << "\n" << "Straight percentage: " << (straight/runs)*100.0 << "\n" << "StraightFlush: " << (straightFlush/runs)*100.0 << "\n";
}


