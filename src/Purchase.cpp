//
// Created by karen on 12/03/2025.
//

#include "Purchase.h"
//constructor
Purchase::Purchase(string name)
{
    this->name = name;
}

//setters
void Purchase::setName(string name)
{
    this->name = name;
}

//getters
string Purchase::getName()
{
    return name;
}
vector<Product> Purchase::get_products()
{
    return products;
}

//methods
string Purchase::buyProduct(Product product, int number)
{
    string ans;
    if (product.getQuantity() > 0)
    {
        products.push_back(product); //Save product in purchase
        product.decreaseStock(number);
        ans += "Product added, there are" + to_string(product.getQuantity()) + " left" +  "\n";
    }else
    {
        ans = "No stock";
    }
    return ans;
}
string Purchase::toString()
{
    string ans;
    for(std::vector<Product>::iterator it = products.begin(); it != products.end(); it++)
    {
        ans += it->getName() + ", ";
    }
    ans += "\n";
    return ans;
}

