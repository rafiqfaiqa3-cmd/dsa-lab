#include <iostream>
using namespace std;

int main() {
    char* ptr = new char;

    cout << "Enter a character: ";
    cin >> *ptr;

    cout << "Stored character: " << *ptr << endl;

    delete ptr;
    ptr = nullptr;

    cout << "Memory deallocated successfully." << endl;

    return 0;
}
