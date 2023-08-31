//
// main.cpp
// Cards
//
// Created by Ben Baysinger on 8/29/23.
//
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include "DeckHelper.hpp"


int main(int argc, const char * argv[]) {
    
    
  std::vector<card> deck = deckBuilder();
  //create a vector of cards
  //print the cards to make a deck 
  deckPrinter(deck);
}
