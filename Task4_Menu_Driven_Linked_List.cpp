#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertAtStart(Node*& head, int value) {
    Node* newNode = new Node{value, head};
    head = newNode;
    cout << "Value inserted at the beginning." << endl;
}

void insertAtEnd(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }

    cout << "Value inserted at the end." << endl;
}

void insertAfterValue(Node* head, int target, int value) {
    Node* current = head;

    while (current != nullptr && current->data != target) {
        current = current->next;
    }

    if (current == nullptr) {
        cout << target << " was not found. No insertion made." << endl;
        return;
    }

    Node* newNode = new Node{value, current->next};
    current->next = newNode;
    cout << "Value inserted after " << target << "." << endl;
}

void displayList(Node* head) {
    if (head == nullptr) {
        cout << "The list is empty." << endl;
        return;
    }

    cout << "Linked list: ";
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void deleteList(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node* head = nullptr;
    int n, value;

    cout << "How many initial values do you want to enter? ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter value " << i + 1 << ": ";
        cin >> value;
        insertAtEnd(head, value);
    }

    int choice;

    do {
        cout << "\n--- LINKED LIST MENU ---" << endl;
        cout << "1. Insert at Start" << endl;
        cout << "2. Insert at End" << endl;
        cout << "3. Insert in Middle (after a value)" << endl;
        cout << "4. Display List" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter new value: ";
                cin >> value;
                insertAtStart(head, value);
                break;

            case 2:
                cout << "Enter new value: ";
                cin >> value;
                insertAtEnd(head, value);
                break;

            case 3: {
                int target;
                cout << "Enter the existing value after which to insert: ";
                cin >> target;
                cout << "Enter new value: ";
                cin >> value;
                insertAfterValue(head, target, value);
                break;
            }

            case 4:
                displayList(head);
                break;

            case 5:
                cout << "Exiting program." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    deleteList(head);
    return 0;
}
