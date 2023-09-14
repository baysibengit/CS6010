//
//  NumberRepresentations.cpp
//  NumberRepresentations
//
//  Created by Ben Baysinger  on 9/12/23.
//

#include "NumberRepresentations.hpp"


bool approxEquals( double a, double b, double tolerance){
    if(std::abs(a-b) < tolerance){
        return true;
    }
    return false;
}
