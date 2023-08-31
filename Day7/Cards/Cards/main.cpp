//
//  main.cpp
//  Cards
//
//  Created by Ben Baysinger  on 8/29/23.
//

#include <iostream>
#include <string>
#include <vector>

struct card{
    int rank;
    std::string suit;
};
std::vector <card> deckBuilder(){
    std::vector<std::string> cardSuit = {
        "heart", "diamond", "spade", "club"
    };
    std::vector<card> deck;
    for (std::string c: cardSuit){
        for (int i = 1; i <= 13; i++){
            card tempCard {i,c} ;
            deck.push_back(tempCard);
        }
        
    }
    return deck;
}

//Void function because we are not returning a value
/*Ran if statements so we could replace 1, 11, 12, and 13 with ace, jack, queen, and king*/
void deckPrinter ( std::vector<card> deck){
    for (card h: deck){
        if (h.rank == 2|| h.rank == 3 || h.rank == 4 || h.rank == 5 || h.rank == 6 || h.rank == 7 || h.rank == 8 || h.rank == 9 || h.rank == 10) {
            std::cout<< h.suit << " " << h.rank << "\n";
        }
        if(h.rank == 11){
            std::cout<< h.suit << " " <<'j' << "\n";
        }
        if(h.rank == 12){
            std::cout<< h.suit << " " << 'q' << "\n";
        }
        if(h.rank == 13){
            std::cout<< h.suit << " " << 'k' << "\n";
        }
        if(h.rank == 1){
            std::cout<< h.suit << " " << "ace" << "\n";
        }
    }

    }

int main(int argc, const char * argv[]) {
    std::vector<card> deck = deckBuilder();
    //create a deck
    
    
    //print the deck
    deckPrinter(deck);
}
