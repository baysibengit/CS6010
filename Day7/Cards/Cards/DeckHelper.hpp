//
//  DeckHelper.hpp
//  Cards
//
//  Created by Ben Baysinger  on 8/30/23.
//

#ifndef DeckHelper_hpp
#define DeckHelper_hpp
#include <string>
#include <stdio.h>
//Identify values in your struct
struct card{
  int rank;
  std::string suit;
};

//Deck builder for suit of cards
std::vector <card> deckBuilder();
    
//Signature of deckPrinter function
    void deckPrinter ( std::vector<card> deck);
    




#endif /* DeckHelper_hpp */
