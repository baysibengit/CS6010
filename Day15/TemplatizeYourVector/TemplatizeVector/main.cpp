//
//  main.cpp TemplateVector Created by Ben Baysinger and Jake Dame on 9/18/23.

#include "TemplateVector.hpp"

int main(int argc, const char * argv[]) {
        
    
    testMethods();
    
//     FOR CODE REVIEW DEMO
    
    Vektor<std::string> fruit;
    fruit.push_back("Apple");
    fruit.push_back("Banana");
    fruit.push_back("Watermelon");
    fruit.push_back("Orange");

    Vektor<std::string> desserts;
    desserts.push_back("Pie");
    desserts.push_back("Cream");
    desserts.push_back("Tart");


    fruit.print();
    std::cout << "Size: " << fruit.size() << "\n";
    std::cout << "Capacity: " << fruit.capacity() << "\n";
    std::cout << "Get value: " << fruit.get(2) << "\n";

    fruit.pop_back();
    fruit.set("Cherry", 2);

    fruit.print();
    std::cout << "Size: " << fruit.size() << "\n";
    std::cout << "Capacity: " << fruit.capacity() << "\n";
    std::cout << "Get value: " << fruit.get(1) << "\n\n";

    if(fruit > desserts) {
        std::cout << "Fruit is greater than desserts.\n";
    } else {
        std::cout << "Fruit is not greater than desserts.\n";
    }

    Vektor<std::string> fruitDesserts = fruit + desserts;
    fruitDesserts.print();
    std::cout << "\n";




    Vektor<double> V3;
    V3.push_back(3.14159);
    V3.push_back(-3.14159);
    V3.push_back(1.2345);
    V3.push_back(728.827);

    Vektor<double> V4;
    V4.push_back(1);
    V4.push_back(-2);
    V4.push_back(10);


    V3.print();
    std::cout << "Size: " << V3.size() << "\n";
    std::cout << "Capacity: " << V3.capacity() << "\n";
    std::cout << "Get value: " << V3.get(2) << "\n\n";

    V3.pop_back();
    V3.set(0.0001, 2);

    V3.print();
    std::cout << "Size: " << V3.size() << "\n";
    std::cout << "Capacity: " << V3.capacity() << "\n";
    std::cout << "Get value: " << V3.get(1) << "\n\n";

    if(V3 > V4) {
        std::cout << "V3 is greater than V4.\n";
    } else {
        std::cout << "V3 is not greater than V4.\n";
    }

    Vektor<double> V5 = V3 + V4;
    V5.print();
    std::cout << "\n";

    
    return 0;
}
