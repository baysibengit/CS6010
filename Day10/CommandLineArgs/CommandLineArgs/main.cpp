//
//  main.cpp
//  CommandLineArgs
//
//  Created by Ben Baysinger  on 9/1/23.
//

#include <iostream>
#include <string>
/*Made function that prints Argv. Make sure to pass through matching values of argc and argv. Make sure brackets are empty so it can print totality of array. Run for loop to print each line of argv*/

void printArgv (int argc, const char * argv[]){
    for (int i = 0; i < argc; i++){
        std::cout<< argv[i]<<"\n";
    }
}

int main(int argc, const char * argv[]) {
    printArgv(argc, argv);
    

    //The first element  at argv[0] is ./main
    
    return 0;
}
