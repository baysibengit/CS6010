//
//  main.cpp
//  LabNumConvert
//
//  Created by Ben Baysinger  on 9/5/23.
//

#include <iostream>
#include <string>

int main(int argc, const char * argv[]) {
  
    
    int i = 0;
    int n = n/2;
    int b = 0;
    while (n >= 1){
        b[i] = n % 2;
        n = n/2;
    }
    for (int j = b.size()-1; j >= 0; j++){
        std::cout<<b[j];
    }
    return 0;
}
