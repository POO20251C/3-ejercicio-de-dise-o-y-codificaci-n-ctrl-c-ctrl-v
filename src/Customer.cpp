//
// Created by karen on 12/03/2025.
//

#include "Customer.h"

//constructor
Customer::Customer(string name, string phone)
{
    this->name = name;
    this->phone = phone;
}
//getters
string Customer::getName()
{
    return name;
}
string Customer::getPhone()
{
    return phone;
}
vector<Purchase> Customer::getPurchase()
{
    return purchases;
}
//setters
void Customer::setName(string name)
{
    this->name = name;
}
void Customer::setPhone(string phone)
{
    this->phone = phone;
}
//methods
string Customer::registerPurchase(Purchase bag)
{
    if (bag.get_products().size() != 0)
    {
        purchases.push_back(bag);
        return "Done.";
    }
    else
    {
        return "No products in the bag";
    }
}
string Customer::showPurchases()
{
    string ans;
    if (purchases.empty())
    {
        ans = "No purchases to show";
    }
    else
    {
        for (size_t i = 0; i < purchases.size(); i++)
        {
            ans += purchases[i].toString() + "\n";
        }
    }
    return ans;
}
string Customer::toString()
{
    string ans;
    ans +=  name + " phone: " + phone + "\n";
    return ans;
}


