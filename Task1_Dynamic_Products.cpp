#include <iostream>
#include <string>
#include <limits>
using namespace std;

struct Product {
    string name;
    int code;
    double price;
};

int main() {
    int n;

    cout << "Enter number of products: ";
    cin >> n;

    if (n <= 0) {
        cout << "Number of products must be positive." << endl;
        return 0;
    }

    Product* products = new Product[n];

    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for product " << i + 1 << ":" << endl;

        cout << "Name: ";
        getline(cin >> ws, products[i].name);

        cout << "Code: ";
        cin >> products[i].code;

        cout << "Price: ";
        cin >> products[i].price;
    }

    cout << "\n--- Product Details ---" << endl;
    for (int i = 0; i < n; i++) {
        cout << "\nProduct " << i + 1 << endl;
        cout << "Name: " << products[i].name << endl;
        cout << "Code: " << products[i].code << endl;
        cout << "Price: " << products[i].price << endl;
    }

    delete[] products;
    products = nullptr;

    cout << "\nMemory freed successfully." << endl;

    return 0;
}
