#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void displayList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    int n, value, target;

    cout << "How many values do you want to enter? ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter value " << i + 1 << ": ";
        cin >> value;

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
    }

    cout << "Original linked list: ";
    displayList(head);

    cout << "Enter the existing value before which to insert: ";
    cin >> target;
    cout << "Enter the new value: ";
    cin >> value;

    Node* newNode = new Node{value, nullptr};

    // Special case: insert before the first node.
    if (head != nullptr && head->data == target) {
        newNode->next = head;
        head = newNode;
        cout << "Value inserted before " << target << "." << endl;
    } else {
        Node* previous = head;
        Node* current = (head == nullptr) ? nullptr : head->next;

        // Find the target while keeping track of the previous node.
        while (current != nullptr && current->data != target) {
            previous = current;
            current = current->next;
        }

        if (current == nullptr) {
            cout << target << " was not found. No insertion made." << endl;
            delete newNode;
        } else {
            newNode->next = current;
            previous->next = newNode;
            cout << "Value inserted before " << target << "." << endl;
        }
    }

    cout << "Updated linked list: ";
    displayList(head);

    // Free allocated memory.
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
