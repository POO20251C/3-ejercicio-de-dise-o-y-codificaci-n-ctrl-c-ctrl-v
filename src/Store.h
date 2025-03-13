//
// Created by karen on 12/03/2025.
//

#ifndef STORE_H
#define STORE_H
#include <string>
#include <vector>

#include "Customer.h"
#include "Product.h"
using namespace std;

class Store {
public:
    //constructor
    Store();
    Store(string name, string address);
    //getters
    string getName();
    string getAddress();
    vector<Customer> getCustomers();
    vector<Product> getProducts();
    //setters
    void setName(string name);
    void setAddress(string address);
    //methods
    Customer* getCustomerByName(const std::string& name); // Declaración de la función
    Product* getProductByName(const std::string& name); // Declaración de la función
    string registerCustomer(Customer customer);
    string registerProduct(Product product);
    string showCustomers();
    string showProducts();
private:
    string name;
    string address;
    vector <Customer> customers;
    vector <Product> products;
};
#endif //STORE_H