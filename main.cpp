#include <iostream>

#include "src/Customer.h"
#include "src/Product.h"
#include "src/Purchase.h"



int main()
{
    Product product1("Guayos", 10);
    cout << product1.toString() << endl;
    Product product2("Balones", 20);
    Product product3("Camiseta real madrid", 40);
    Product product4("Camiseta liverpool", 30);
    Product product5("Camiseta paris", 15);

    Customer Mariana( "Mariana", "123456");
    cout << Mariana.toString() << endl;
    Customer Karen("Karen", "654321");
    cout << Karen.toString() << endl;

    Purchase bagMari("Mariana");
    cout << bagMari.buyProduct(product1,1)<< endl;
    cout << bagMari.buyProduct(product2, 2)<< endl;

    Purchase bagKaren("Karen");
    cout << bagKaren.buyProduct(product3,1)<< endl;
    cout << bagKaren.buyProduct(product4, 1)<< endl;
    cout << bagKaren.buyProduct(product5, 1)<< endl;

    cout << Mariana.registerPurchase(bagMari)<< endl;
    cout << Karen.registerPurchase(bagKaren)<< endl;

    cout << Mariana.getName() + " has: " + Mariana.showPurchases()<< endl;
    cout << Karen.getName() + " has: " +  Karen.showPurchases()<< endl;

    return 0;
}
