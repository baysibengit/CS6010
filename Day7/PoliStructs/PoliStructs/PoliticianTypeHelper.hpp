//
//  PoliticanTypeHelper.hpp
//  PoliStructs
//
//  Created by Ben Baysinger  on 8/29/23.
//

#ifndef PoliticianTypeHelper_hpp
#define PoliticianTypeHelper_hpp
#include <string>
#include <vector>
#include <stdio.h>
struct Politician {
    std::string name;
    std::string partyAffiliation;
    std::string stateOrFedPoli;
};
bool isJavacans (Politician politician);
bool isCpluser (Politician politician);
std::vector<Politician> Javacans (std::vector<Politician> politicians);
std::vector <Politician> federalCplusers (std::vector<Politician> politicians);
#endif /* PoliticanTypeHelper_hpp */
