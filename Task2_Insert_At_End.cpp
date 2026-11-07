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
    int n, value;

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

    cout << "Enter value to insert at the end: ";
    cin >> value;

    Node* newNode = new Node{value, nullptr};

    if (head == nullptr) {
        // If the list is empty, the new node becomes the head.
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
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
