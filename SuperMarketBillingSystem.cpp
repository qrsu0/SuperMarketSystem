
/*
	as cashier 
	as a customer

	1- as cashier : 
		1- add item
		2- remove item 
		3- edit item 
		4- exit

	2- as customer
		1- view menu
		2 - exit 

		1- view menu 
			menu 
			condition adding to cart 
			condition proceed for the final bill


*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Supermarket {
private:
    vector<pair<int, pair<string, float>>> products; // To store productCode, productName, and price
    vector<pair<int, pair<string, float>>> cart; // To store items added to the cart

public:
    void productMenu();
    void buyer();
    void cashier();
    void edit();
    void add();
    void remove();
    void addToCart(int code);
    void displayCart();
    void proceedToBill();
};

void Supermarket::productMenu() {
    cout << "\nProduct Menu:\n";
    if (products.empty()) {
        cout << "No products available.\n";
        return;
    }
    for (const auto& product : products) {
        cout << "Code: " << product.first << ", Name: " << product.second.first << ", Price: " << product.second.second << endl;
    }
}

void Supermarket::add() {
    int code;
    string name;
    float price;
    cout << "Enter product code: ";
    cin >> code;
    cout << "Enter product name: ";
    cin >> name;
    cout << "Enter product price: ";
    cin >> price;
    products.push_back({ code, {name, price} });
    cout << "Product added successfully.\n";
}

void Supermarket::edit() {
    int code;
    cout << "Enter product code to edit: ";
    cin >> code;
    for (auto& product : products) {
        if (product.first == code) {
            cout << "Enter new name: ";
            cin >> product.second.first;
            cout << "Enter new price: ";
            cin >> product.second.second;
            cout << "Product updated successfully.\n";
            return;
        }
    }
    cout << "Product not found.\n";
}

void Supermarket::remove() {
    int code;
    cout << "Enter product code to remove: ";
    cin >> code;
    for (auto it = products.begin(); it != products.end(); ++it) {
        if (it->first == code) {
            products.erase(it);
            cout << "Product removed successfully.\n";
            return;
        }
    }
    cout << "Product not found.\n";
}

void Supermarket::cashier() {
    int cashierChoice;
    do {
        cout << "\t\t=================================\n";
        cout << "\t\t             Cashier             \n";
        cout << "\t\t=================================\n";
        cout << "\t\t==    1.Add product            ==\n";
        cout << "\t\t==    2.Edit product           ==\n";
        cout << "\t\t==    3.Remove product         ==\n";
        cout << "\t\t==    4.View product menu      ==\n";
        cout << "\t\t==    5.Back to main menu      ==\n";
        cout << "\t\t=================================\n";
        cout << "\t\tchoice: ";
        cin >> cashierChoice;
        switch (cashierChoice) {
        case 1:
            add();
            break;
        case 2:
            edit();
            break;
        case 3:
            remove();
            break;
        case 4:
            productMenu();
            break;
        case 5:
            cout << "Returning to main menu...\n";
            return; // Exit the cashier function
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (cashierChoice != 5);
}

void Supermarket::addToCart(int code) {
    for (const auto& product : products) {
        if (product.first == code) {
            cart.push_back(product);
            cout << "Added " << product.second.first << " to cart.\n";
            return;
        }
    }
    cout << "Product not found.\n";
}

void Supermarket::displayCart() {
    cout << "\nCart:\n";
    if (cart.empty()) {
        cout << "Your cart is empty.\n";
        return;
    }
    for (const auto& item : cart) {
        cout << "Code: " << item.first << ", Name: " << item.second.first << ", Price: " << item.second.second << endl;
    }
}

void Supermarket::proceedToBill() {
    float total = 0;
    cout << "\nFinal Bill:\n";
    if (cart.empty()) {
        cout << "Your cart is empty.\n";
        return;
    }
    for (const auto& item : cart) {
        cout << "Code: " << item.first << ", Name: " << item.second.first << ", Price: " << item.second.second << endl;
        total += item.second.second;
    }
    cout << "Total Price: " << total << endl;
    cart.clear(); // Clear the cart after checkout
}

void Supermarket::buyer() {
    int buyerChoice;
    do {
        cout << "\t\t=================================\n";
        cout << "\t\t            Buyer Menu           \n";
        cout << "\t\t=================================\n";
        cout << "\t\t==    1.View Menu              ==\n";
        cout << "\t\t==    2.Add to Cart            ==\n";
        cout << "\t\t==    3.View Cart             ==\n";
        cout << "\t\t==    4.Proceed to Bill        ==\n";
        cout << "\t\t==    5.Exit                   ==\n";
        cout << "\t\t=================================\n";
        cout << "\t\tchoice: ";
        cin >> buyerChoice;

        switch (buyerChoice) {
        case 1:
            productMenu(); // Display the product menu
            break;
        case 2: {
            int code;
            cout << "Enter product code to add to cart: ";
            cin >> code;
            addToCart(code); // Add selected product to cart
            break;
        }
        case 3:
            displayCart(); // Display items in the cart
            break;
        case 4:
            proceedToBill(); // Show the final bill
            break;
        case 5:
            cout << "Exiting...\n";
            return; // Exit the buyer function
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (buyerChoice != 5);
}

void mainMenu() {
    cout << "\t\t=================================\n";
    cout << "\t\t         Fake SuperMarket        \n";
    cout << "\t\t=================================\n";
    cout << "\t\t==    1.Login as a customer    ==\n";
    cout << "\t\t==    2.Login as a cashier     ==\n";
    cout << "\t\t==    3.Exit                   ==\n";
    cout << "\t\t=================================\n";
    cout << "\t\tchoice: ";
}

int main() {
    int choice;
    Supermarket market; // Create an instance of the Supermarket class

    do {
        mainMenu();
        cin >> choice;
        switch (choice) {
        case 1:
            market.buyer();
            break;
        case 2:
            market.cashier();
            break;
        case 3:
            cout << "Exiting...\n";
            break;
        default:
            cout << "\n\t\tPlease Write a valid choice: ";
        }
    } while (choice != 3);

    return 0;
}