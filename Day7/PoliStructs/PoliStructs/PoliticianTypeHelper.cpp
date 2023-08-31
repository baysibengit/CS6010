//
//  PoliticanTypeHelper.cpp
//  PoliStructs
//
//  Created by Ben Baysinger  on 8/29/23.
//

#include "PoliticianTypeHelper.hpp"
#include <string>
#include <vector>
#include <iostream>
/* Helper function to detetmine if politican is javacan*/
bool isJavacans (Politician politician)
{
    if (politician.partyAffiliation == "Javacan"){
        
        return true;
    }
    else {
        return false;
    }
}

/* Helper function to determine if politician is cpluser*/
bool isCpluser (Politician politician)
{
    if (politician.partyAffiliation == "Cpluser"){
        
        return true;
    }
    else {
        return false;
    }
}

/* Javancans function returns a vector from politicians structure. Using for each loop to go over politicans and call isJavacans function to determine which politicians are javacan*/
std::vector<Politician> Javacans (std::vector<Politician> politicians)
{
    std::vector<Politician> Jc;
    for (Politician c: politicians){
        if (isJavacans(c)){
            Jc.push_back(c);
            std::cout<< c.name << "\n";
        }
    }
    return Jc;
}

/* federalCplusers function returns a vector of politicians. Run if statement in for each loop to check if politician is a federal/state && if cpluser. Called isCpluser helper function*/
std::vector <Politician> federalCplusers (std::vector<Politician> politicians)
{
    std::vector<Politician> CplusFed;
    for (Politician c: politicians){
        if (c.stateOrFedPoli == "Federal politician" && isCpluser(c)) {
            CplusFed.push_back(c);
            std::cout<<c.name << "\n";
        }
    }
    return CplusFed;
}
