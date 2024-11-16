#include <iostream>
#include <vector>
#include <string>
#include <iomanip>  // for formatting prices

using namespace std;

// Product class to represent each product
class Product {
public:
    string name;
    double price;
    int stock;

    Product(string name, double price, int stock) {
        this->name = name;
        this->price = price;
        this->stock = stock;
    }

    void display() {
        cout << left << setw(20) << name << setw(10) << price << setw(10) << stock << endl;
    }
};

// Cart class to handle the shopping cart
class Cart {
public:
    vector<Product> cartItems;
    
    void addToCart(Product product, int quantity) {
        if (quantity <= product.stock) {
            product.stock -= quantity;  // Decrease stock after adding to cart
            for (int i = 0; i < quantity; i++) {
                cartItems.push_back(product);  // Add the product to the cart
            }
            cout << quantity << " " << product.name << "(s) added to the cart.\n";
        } else {
            cout << "Insufficient stock available.\n";
        }
    }

    void viewCart() {
        if (cartItems.empty()) {
            cout << "Your cart is empty.\n";
            return;
        }
        cout << "Items in your cart:\n";
        double total = 0;
        for (auto &item : cartItems) {
            cout << left << setw(20) << item.name << setw(10) << item.price << endl;
            total += item.price;
        }
        cout << "Total: $" << total << endl;
    }

    void checkout() {
        if (cartItems.empty()) {
            cout << "Your cart is empty. Please add items to the cart before checking out.\n";
            return;
        }
        double total = 0;
        for (auto &item : cartItems) {
            total += item.price;
        }
        cout << "Checking out...\n";
        cout << "Total amount to be paid: $" << total << endl;
        cout << "Thank you for your purchase!\n";
        cartItems.clear();  // Clear the cart after checkout
    }
};

int main() {
    vector<Product> products = {
        Product("Laptop", 999.99, 10),
        Product("Smartphone", 499.99, 20),
        Product("Headphones", 199.99, 15),
        Product("Smartwatch", 249.99, 5)
    };

    Cart cart;
    int choice;
    int quantity;
    bool running = true;

    while (running) {
        cout << "\n===== E-Commerce Store =====\n";
        cout << "1. View Products\n";
        cout << "2. Add to Cart\n";
        cout << "3. View Cart\n";
        cout << "4. Checkout\n";
        cout << "5. Exit\n";
        cout << "Please choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                // Display products
                cout << left << setw(20) << "Product" << setw(10) << "Price" << setw(10) << "Stock" << endl;
                for (auto &product : products) {
                    product.display();
                }
                break;

            case 2:
                // Add product to cart
                cout << "Enter product number to add to cart: ";
                int productNumber;
                cin >> productNumber;
                if (productNumber >= 1 && productNumber <= products.size()) {
                    cout << "Enter quantity: ";
                    cin >> quantity;
                    cart.addToCart(products[productNumber - 1], quantity);
                } else {
                    cout << "Invalid product number.\n";
                }
                break;

            case 3:
                // View cart
                cart.viewCart();
                break;

            case 4:
                // Checkout
                cart.checkout();
                break;

            case 5:
                // Exit
                running = false;
                cout << "Thank you for visiting the store!\n";
                break;

            default:
                cout << "Invalid option. Please try again.\n";
        }
    }

    return 0;
}
