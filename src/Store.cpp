//
// Created by karen on 12/03/2025.
//

#include "Store.h"

Store::Store(string name, string address)
{
    this->name = name;
    this->address = address;
}
//getters
string Store::getName()
{
    return name;
}
string Store::getAddress()
{
    return address;
}
vector<Customer> Store::getCustomers()
{
    return customers;
}
vector<Product> Store::getProducts()
{
    return products;
}
//setters
void Store::setName(string name)
{
    this->name = name;
}
void Store::setAddress(string address)
{
    this->address = address;
}

//methods
string Store::registerCustomer(Customer customer)
{
    if (customer.getName() != "")
    {
        customers.push_back(customer); //like append on python
        return "Customer added";
    }else
    {
        return "Customer has no name";
    }
}
string Store::registerProduct(Product product)
{
    if (product.getQuantity() != 0)
    {
        products.push_back(product); //like append on python
        return "Product added";
    }else
    {
        return "Not enough quantity";
    }
}
string Store::showCustomers()
{
    string ans;
    if (customers.empty())
    {
        ans = "No customers to show";
    }
    else
    {
        for (size_t i = 0; i < customers.size(); i++)
        {
            ans += to_string(i+1) + ". " + customers[i].toString() + "\n";
        }
    }
    return ans;
}
string Store::showProducts()
{
    string ans;
    if (products.empty())
    {
        ans = "No Products to show";
    }
    else
    {
        for (size_t i = 0; i < products.size(); i++)
        {
            ans += to_string(i+1) + ". " + products[i].toString() + "\n";
        }
    }
    return ans;
}

