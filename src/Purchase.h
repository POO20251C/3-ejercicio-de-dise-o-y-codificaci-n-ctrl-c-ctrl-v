//
// Created by karen on 12/03/2025.
//

#ifndef PURCHASE_H
#define PURCHASE_H

#include "Product.h"
#include <vector>
#include <string>
using namespace std;

class Purchase {
public:
    //constructor
    Purchase();
    Purchase(string name);

    //getters
    string getName();
    vector<Product> get_products();

    //setter
    void setName(string name);

    //methods
    string buyProduct(Product product, int number);
    string toString();

private:
    string name;
    vector<Product> products;
};
#endif //PURCHASE_H