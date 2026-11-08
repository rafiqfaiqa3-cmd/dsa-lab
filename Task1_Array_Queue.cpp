#include <iostream>
using namespace std;

const int SIZE = 6;
int queueArr[SIZE];
int frontIndex = 0, rearIndex = -1, token = 1;

bool isEmpty() {
    return frontIndex > rearIndex;
}

bool isFull() {
    return rearIndex == SIZE - 1;
}

void issueToken() {
    if (isFull()) {
        cout << "Waiting room is FULL!" << endl;
        return;
    }
    queueArr[++rearIndex] = token;
    cout << "Token " << token << " issued." << endl;
    token++;
}

void serveCustomer() {
    if (isEmpty()) {
        cout << "No customer is waiting!" << endl;
        return;
    }

    cout << "Token " << queueArr[frontIndex] << " is served." << endl;
    frontIndex++;

    if (frontIndex > rearIndex) {
        frontIndex = 0;
        rearIndex = -1;
    }
}

void display() {
    if (isEmpty()) {
        cout << "No customers waiting." << endl;
        return;
    }

    cout << "Waiting Tokens: ";
    for (int i = frontIndex; i <= rearIndex; i++) {
        cout << queueArr[i] << " ";
    }
    cout << endl;
}

int main() {
    int choice;

    do {
        cout << "\n--- Bank Token System ---" << endl;
        cout << "1. Issue Token" << endl;
        cout << "2. Serve Customer" << endl;
        cout << "3. Show Waiting Customers" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: issueToken(); break;
            case 2: serveCustomer(); break;
            case 3: display(); break;
            case 4: cout << "Exiting..." << endl; break;
            default: cout << "Invalid choice!" << endl;
        }
    } while (choice != 4);

    return 0;
}
