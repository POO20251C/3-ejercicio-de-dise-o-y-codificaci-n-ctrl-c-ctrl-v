#include <iostream>
#include <vector>
#include "src/Customer.h"
#include "src/Product.h"
#include "src/Purchase.h"
#include "src/Store.h"

using namespace std;

void showMenu() {
    cout << "\n===== MENU =====" << endl;
    cout << "1. Registrar cliente" << endl;
    cout << "2. Agregar producto al sistema" << endl;
    cout << "3. Mostrar productos con existencia" << endl;
    cout << "4. Registrar compra de un cliente" << endl;
    cout << "5. Consultar compras de un cliente" << endl;
    cout << "6. Mostrar clientes registrados" << endl;
    cout << "7. Salir" << endl;
    cout << "Ingrese una opción: ";
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
                cout << "Ingrese el nombre del cliente: ";
                getline(cin, name);
                cout << "Ingrese el ID del cliente: ";
                getline(cin, id);
                myStore.registerCustomer(Customer(name, id));
                cout << "Cliente registrado exitosamente." << endl;
                break;
            }
            case 2: {
                string productName;
                int price, stock;
                cout << "Ingrese el nombre del producto: ";
                getline(cin, productName);
                cout << "Ingrese la cantidad en existencia: ";
                cin >> stock;
                cin.ignore();
                myStore.registerProduct(Product(productName, stock));
                cout << "Producto agregado exitosamente." << endl;
                break;
            }
            case 3:
                cout << myStore.showProducts() << endl;
                break;
            case 4: {
                string customerName;
                int numProducts;
                cout << "Ingrese el nombre del cliente: ";
                getline(cin, customerName);
                Customer* customer = myStore.getCustomerByName(customerName);
                if (!customer) {
                    cout << "Cliente no encontrado." << endl;
                    break;
                }
                Purchase purchase(customerName);
                cout << "Ingrese la cantidad de productos a comprar: ";
                cin >> numProducts;
                cin.ignore();
                for (int i = 0; i < numProducts; i++) {
                    string productName;
                    int quantity;
                    cout << "Ingrese el nombre del producto: ";
                    getline(cin, productName);
                    cout << " y cuantos quiere?: ";
                    cin >> quantity;
                    cin.ignore();
                    Product* product = myStore.getProductByName(productName);
                    if (!product) {
                        cout << "Producto no encontrado." << endl;
                        continue;
                    }
                    if (product->getQuantity() < quantity) {
                        cout << "No hay suficiente stock de " << productName << endl;
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
                cout << "Ingrese el nombre del cliente: ";
                getline(cin, customerName);
                Customer* customer = myStore.getCustomerByName(customerName);
                if (customer) {
                    cout << customer->getName() + " ha comprado: " + customer->showPurchases() << endl;
                } else {
                    cout << "Cliente no encontrado." << endl;
                }
                break;
            }
            case 6:
                cout << myStore.showCustomers() << endl;
                break;
            case 7:
                cout << "Saliendo del sistema..." << endl;
                break;
            default:
                cout << "Opción inválida, intente de nuevo." << endl;
        }
    } while (option != 7);

    return 0;
}