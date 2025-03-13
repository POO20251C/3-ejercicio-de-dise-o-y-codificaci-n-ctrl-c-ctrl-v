//
// Created by karen on 12/03/2025.
//

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Purchase.h"
#include <vector>
#include <string>
using namespace std;

class Customer {
public:
    //constructors
    Customer();
    Customer(string name, string phone);
    //getters
    string getName();
    string getPhone();
    vector<Purchase> getPurchase();
    //setters
    void setName(string name);
    void setPhone(string phone);
    //methods
    string registerPurchase(Purchase bag);
    string showPurchases();
    string toString();
private:
    string name;
    string phone;
    vector<Purchase> purchases;
};

#endif //CUSTOMER_H