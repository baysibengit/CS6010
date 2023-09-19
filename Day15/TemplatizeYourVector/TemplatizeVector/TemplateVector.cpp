
//  TemplateVector.cpp DiyVector Created by Ben Baysinger and Jake Dame on 9/18/23.

#include "TemplateVector.hpp"
//Helper function for count_if
bool isEven(double num) {
    return static_cast<int>(num) % 2 == 0;
}

void testMethods() {

    Vektor<std::string> fruit;
    fruit.push_back("Apple");
    fruit.push_back("Banana");
    fruit.push_back("Watermelon");
    fruit.push_back("Orange");
    assert(fruit[0] == "Apple");
    assert(fruit[3] == "Orange");
    assert(fruit.size() == 4);
    assert(fruit.capacity() == 10);


    Vektor<std::string> desserts;
    desserts.push_back("Pie");
    desserts.push_back("Cream");
    desserts.push_back("Tart");
    assert(desserts[0] == "Pie");
    assert(desserts.size() == 3);
    assert(desserts.capacity() == 10);
    assert(desserts.get(2) == "Tart");

    fruit.pop_back();
    fruit.set("Peach", 2);
    assert(fruit[2] == "Peach");
    assert(fruit.size() == 3);
    assert(fruit.capacity() == 10);

    assert(fruit > desserts == false);

    Vektor<std::string> fruitDesserts = fruit + desserts;

    assert(fruitDesserts[2] == "PeachTart");

    
    
    Vektor<double> doubles1;
    doubles1.push_back(3.14159);
    doubles1.push_back(-3.14159);
    doubles1.push_back(728.827);
    doubles1.push_back(1.1);
    assert(doubles1[0] == 3.14159);
    assert(doubles1[3] == 1.1);
    assert(doubles1.size() == 4);
    assert(doubles1.capacity() == 10);


    Vektor<double> doubles2;
    doubles2.push_back(1);
    doubles2.push_back(-1);
    doubles2.push_back(0.1);
    assert(doubles2[0] == 1);
    assert(doubles2.size() == 3);
    assert(doubles2.capacity() == 10);
    assert(doubles2.get(2) == 0.1);

    doubles1.pop_back();
    doubles1.set(0.0001, 2);
    assert(doubles1[2] == 0.0001);
    assert(doubles1.size() == 3);
    assert(doubles1.capacity() == 10);

    assert(doubles1 > doubles2 == false);
    
    Vektor<double> doubles1and2 = doubles1 + doubles2;
    
    assert(doubles1and2[0] == 4.14159);
    
    std::cout << "All tests passed.\n";

}

//Function for LabSTLVector
void testLabSTLVector (){
    Vektor<double> doubles1;
    doubles1.push_back(3.14159);
    doubles1.push_back(-3.14159);
    doubles1.push_back(728);
    doubles1.push_back(1.1);
    doubles1.push_back(2.0);
    doubles1.push_back(4.0);
    doubles1.push_back(6.0);
    
    //Calling print vector function to print out contents
    std::cout<< "Elements in doubles1 vector: \n"; printVector(doubles1);
    
    //Checking std::sort
    std::sort(doubles1.begin(), doubles1.end());
    std::cout<< "Sorted elements in doubles1 vector: \n";
    printVector(doubles1);
    
    //Storing element of min_element in variable and printing
    auto min = std::min_element(doubles1.begin(), doubles1.end());
    std::cout<< "Minimum element of doubles1 vector: " <<  *min << "\n";
    
    //Same process for sum
    auto sum = std::accumulate(doubles1.begin(), doubles1.end(), 0);
    std::cout<< "Sum of values in double1 vector: " << sum << "\n";
    
    //Count if. Calls helper function to determine if even
    int count = std::count_if(doubles1.begin(), doubles1.end(), isEven);
        std::cout<< "Number of even elements in vector: " << count << "\n";
    //Lambda form of count if
    int countLambdaForm = std::count_if(doubles1.begin(), doubles1.end(), [](double num) {
        return static_cast<int>(num) % 2 == 0;
    });
    std::cout<< "Number of even elements in vector using lambda: " << countLambdaForm << "\n";
    //Remove if. Calls helper functoin 
    auto vecWithoutEven = std::remove_if(doubles1.begin(), doubles1.end(), isEven);
}
