classDiagram
    direction TB
    class Store {
        -String name
        -String address
        -Customer[] customers
        -Product[] products
        +registerCustomer() String
        +showCustomers() Customer[]
        +registerProduct(name, quantity) String
        +showProducts() Product[]
    }
    class Customer {
        -String name
        -String phone
        -Purchase[] purchases
        +registerPurchase(customer, products) String
        +showPurchases() Purchase[]
    }
    class Product {
        -String name
        -int quantity
        +increaseStock(quantity) String
        +decreaseStock(quantity) string
    }
    class Purchase {
        -String customer
        -Product[] products
    }

Store "1" o-- "0...*" Customer : contains
Store "1" o-- "0...*" Product : contains
Customer "1" o-- "0...*" Purchase : makes
Purchase "1" --> "1" Customer : belongs to
Purchase "1" o-- "1...*" Product : includes
Product --> Purchase : sold in