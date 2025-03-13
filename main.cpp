#include <iostream>
#include "src/Customer.h"
#include "src/Product.h"
#include "src/Purchase.h"
#include "src/Store.h"

using namespace std;

void showMenu() {
    cout << "\n===== MENU =====" << endl;
    cout << "1. Register customer" << endl;
    cout << "2. Add product to the system" << endl;
    cout << "3. Show products in stock" << endl;
    cout << "4. Register a customer purchase" << endl;
    cout << "5. View customer purchases" << endl;
    cout << "6. Show registered customers" << endl;
    cout << "7. Exit" << endl;
    cout << "Enter an option: ";
}

int main() {
    Store myStore("Nikke", "123456");
    int option;

    do {
        showMenu();
        cin >> option;
        cin.ignore();

        switch (option) {
            case 1: {
                string name, id;
                cout << "Enter customer name: ";
                getline(cin, name);
                cout << "Enter customer ID: ";
                getline(cin, id);
                myStore.registerCustomer(Customer(name, id));
                cout << "Customer registered successfully." << endl;
                break;
            }
            case 2: {
                string productName;
                int price, stock;
                cout << "Enter product name: ";
                getline(cin, productName);
                cout << "Enter stock quantity: ";
                cin >> stock;
                cin.ignore();
                myStore.registerProduct(Product(productName, stock));
                cout << "Product added successfully." << endl;
                break;
            }
            case 3:
                cout << myStore.showProducts() << endl;
                break;
            case 4: {
                string customerName;
                int numProducts;
                cout << "Enter customer name: ";
                getline(cin, customerName);
                Customer* customer = myStore.getCustomerByName(customerName);
                if (!customer) {
                    cout << "Customer not found." << endl;
                    break;
                }
                Purchase purchase(customerName);
                cout << "Enter the number of products to purchase: ";
                cin >> numProducts;
                cin.ignore();
                for (int i = 0; i < numProducts; i++) {
                    string productName;
                    int quantity;
                    cout << "Enter product name: ";
                    getline(cin, productName);
                    cout << "Enter quantity: ";
                    cin >> quantity;
                    cin.ignore();
                    Product* product = myStore.getProductByName(productName);
                    if (!product) {
                        cout << "Product not found." << endl;
                        continue;
                    }
                    if (product->getQuantity() < quantity) {
                        cout << "Not enough stock for " << productName << endl;
                        continue;
                    }
                    cout << purchase.buyProduct(*product, quantity) << endl;
                    product->decreaseStock(quantity);
                }
                cout << customer->registerPurchase(purchase) << endl;
                break;
            }
            case 5: {
                string customerName;
                cout << "Enter customer name: ";
                getline(cin, customerName);
                Customer* customer = myStore.getCustomerByName(customerName);
                if (customer) {
                    cout << customer->getName() + " has purchased: " + customer->showPurchases() << endl;
                } else {
                    cout << "Customer not found." << endl;
                }
                break;
            }
            case 6:
                cout << myStore.showCustomers() << endl;
                break;
            case 7:
                cout << "Exiting the system..." << endl;
                break;
            default:
                cout << "Invalid option, please try again." << endl;
        }
    } while (option != 7);

    return 0;
}