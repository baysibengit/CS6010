
//  TemplateVector.cpp DiyVector Created by Ben Baysinger and Jake Dame on 9/18/23.

#include "TemplateVector.hpp"

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
