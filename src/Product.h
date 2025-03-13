//
// Created by karen on 12/03/2025.
//

#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>

using namespace std;

class Product {
public:
    //constructor
    Product();
    Product(string name, int quantity);

    //getters
    string getName();
    int getQuantity();

    //setters
    void setName(string name);
    void setQuantity(int quantity);

    //methods
    string increaseStock(int quantity);
    string decreaseStock(int quantity);
    string toString();
private:
    string name;
    int quantity;
};
#endif //PRODUCT_H