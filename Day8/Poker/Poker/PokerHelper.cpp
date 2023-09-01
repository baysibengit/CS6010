//
//  PokerHelpers.cpp
//  Cards
//
//  Created by Zach Allred, Ben Baysinger, and Jake Dame on 8/30/23.
//

#include "PokerHelper.hpp"

std::vector<CardTypes> generateDeck(){
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

void ShuffleDeck(std::vector<CardTypes>& deck){
    for(int a = 0; a <= 51; a++){
        int randomCardVal = std::rand() % 52;
        CardTypes tempCard = deck[a];
        deck[a]= deck[randomCardVal];
        deck[randomCardVal] = tempCard;
    }
}


std::vector<CardTypes> GetFiveCards(std::vector<CardTypes> deck){
    std::vector<CardTypes> fiveCards;
    for(int f=0; f < 5;f++){
        CardTypes tempCard = deck[f];
        fiveCards.push_back(tempCard);
    }
    return fiveCards;
}


bool isThereKing(std::vector<CardTypes> fiveCards){
    std::string suit = fiveCards[0].cardName;
    for(int i = 1; i < 5; i++) {
        if(fiveCards[i].cardName == "King") {
            return true;
        }
    }
    return false;
}


std::vector<int> SortHand(std::vector<CardTypes> fiveCards){
    std::vector<int> rankSort;
    for(CardTypes card:fiveCards){
        int rank = card.rank;
        
        if(rank==1 && isThereKing(fiveCards)){
            rank=14;
            
           }
        
        rankSort.push_back(rank);
    }
    std::sort(rankSort.begin(), rankSort.end());
    return rankSort;
    }

bool isStraight(std::vector<int> rankedFiveCards){
    for(int a=1; a < 5; a++){
        if((rankedFiveCards[a-1]+1)!=rankedFiveCards[a]){
            return false;
        }
    }
    return true;
}

bool isFlush(std::vector<CardTypes> fiveCards) {
    std::string suit = fiveCards[0].suit;
    for(int i = 1; i < 5; i++) {
        if(fiveCards[0].suit != fiveCards[i].suit) {
            return false;
        }
    }
    return true;
}

bool isStraightFlush(bool isFlush, bool isStraight){
    if(isFlush && isStraight){
        return true;
    }
    return false;
}

bool isRoyalFlush(bool isFlush, std::vector<int> fiveCards){
    if (fiveCards[0]==10 && isFlush && fiveCards[4]==14){
        return true;
    }
    return false;
}
bool isPair(std::vector<int> fiveCards){
    int pairCounter=1;
    for(int a=0; a< 4; a++){
        if(fiveCards[a] == fiveCards[a+1]){
            pairCounter++;
        }
        if(pairCounter==2){
            return true;
            break;
        }
    }
    return false;
}

bool isTriple(std::vector<int> fiveCards){
    int pairCounter=1;
    for(int a=0; a< 4; a++){
        if(fiveCards[a] == fiveCards[a+1]){
            pairCounter++;
        }
        if(pairCounter==3){
            return true;
            break;
        }
    }
    return false;
}


bool isFullHouse(bool isPair, bool isTriple){
    if(isTriple && isPair){
        return true;
    }
    return false;
}
/*
bool isFullHouse(std::vector<int> fiveCards){
    int FirstLoop=1;
    int SecondLoop=1;
    for(int i=1; i < 5; i++){
        if(fiveCards[0] == fiveCards[i]){
            FirstLoop ++;
        }
        for(int i=3; i >= 0; i--){
            if(fiveCards[4]==fiveCards[i]){
                SecondLoop++;
            }
        }
    }
    if((FirstLoop == 3 && SecondLoop == 2) || (FirstLoop==2 && SecondLoop==3)){
        return true;
    }
        return false;

}
*/
int numStraight(bool checkStraight, int& straightCounter){
    if(checkStraight){
        straightCounter++;
    }
    return straightCounter;
}

int numFlush(bool checkFlush, int& flushCounter){
    if(checkFlush){
        flushCounter++;
    }
    return flushCounter;
}

int numStraightFlush(bool checkFlush, int& straightFlushCounter){
    if(checkFlush){
        straightFlushCounter++;
    }
    return straightFlushCounter;
}

void numRoyalFlush(bool checkRoyalFlush, int& royalFlushCounter){
    if(checkRoyalFlush){
        royalFlushCounter++;
    }
}

int numFullHouse(bool checkFullHouse, int& fullHouseCounter){
    if(checkFullHouse){
        fullHouseCounter++;
    }
    return fullHouseCounter;
}

void testFlush(std::vector<CardTypes> flushTest){
    assert(isFlush(flushTest) && "Should be flush");
}

void testFullHouse(bool isPair, bool isTriple){
    assert(isFullHouse(isPair, isTriple) && "Should be full house");
}

void ComputerStats(double runs, double full, double royal, double straight, double straightFlush, double flush){
    std::cout << "Total runs: " << runs << "\n" << "Flush percentage:" << flush/runs*100 << "\n" << "Fullhouse percentage: " << full/runs*100 << "\n" << "Royal Flush percantage: " << royal/runs*100 << "\n" << "Straight percentage: " << straight/runs*100 << "\n" << "StraightFlush: " << straightFlush/runs*100 << "/n";
}
/*
bool isStraight(std::vector<CardTypes>& fiveCards){
    std::vector<CardTypes> sortedFive = fiveCards;
    std::sort(sortedFive.begin(), sortedFive.end());
    for(int a=1; a < 5; a++){
        if((sortedFive[a-1].rank+1)!=sortedFive[a].rank){
            return false;
        }
    }
    return true;
}

bool isFlush(std::vector<CardTypes>& fiveCards){
    std::vector<CardTypes> sortedFive = fiveCards;
    std::sort(sortedFive.begin(), sortedFive.end());
    for(int a=1; a < 5; a++){
        if((sortedFive[a-1].suit)!=sortedFive[a].suit){
            return false;
        }
    }
    return true;
}




*/
