//
// Created by karen on 12/03/2025.
//

#include "Product.h"
//constructor
Product::Product(string name, int quantity)
{
    this->name = name;
    this->quantity = quantity;
}

//getters
string Product::getName()
{
    return name;
}
int Product::getQuantity()
{
    return quantity;
}

//setters
void Product::setName(string name)
{
    this->name = name;
}
void Product::setQuantity(int quantity)
{
    this->quantity = quantity;
}

//methods

string Product::increaseStock(int quantity)
{
    string ans;
    this->quantity += quantity;
    ans += "There are " + to_string(this->quantity) + "of" + this->name + "\n";
    return ans;
}
string Product::decreaseStock(int quantity)
{
    string ans;
    this->quantity -= quantity;
    ans += "There are " + to_string(this->quantity) + "of" + this->name + "\n";
    return ans;
}
string Product::toString()
{
    string ans;
    ans +=  "There are " + to_string(quantity) + " " + name + " in stock" + "\n";
    return ans;
}
