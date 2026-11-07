#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertAtEnd(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
}

void displayList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data;
        if (current->next != nullptr) {
            cout << " -> ";
        }
        current = current->next;
    }
    cout << endl;
}

void deleteByValue(Node*& head, int value) {
    if (head == nullptr) {
        cout << "Value not found" << endl;
        return;
    }

    // Case 1: The value is in the first node.
    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    // Cases 2 and 3: Search the middle/end, or report not found.
    Node* current = head;
    while (current->next != nullptr && current->next->data != value) {
        current = current->next;
    }

    if (current->next == nullptr) {
        cout << "Value not found" << endl;
        return;
    }

    Node* temp = current->next;
    current->next = temp->next;
    delete temp;
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

    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    insertAtEnd(head, 40);
    insertAtEnd(head, 50);

    cout << "Original list: ";
    displayList(head);

    int value;
    cout << "Enter the value to delete: ";
    cin >> value;

    deleteByValue(head, value);

    cout << "Updated list: ";
    displayList(head);

    deleteList(head);
    return 0;
}
