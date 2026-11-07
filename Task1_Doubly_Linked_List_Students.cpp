#include <iostream>
using namespace std;

struct Node {
    int rollNumber;
    Node* prev;
    Node* next;
};

void insertAtStart(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr, head};

    if (head != nullptr) {
        head->prev = newNode;
    }

    head = newNode;
}

bool insertAfter(Node* head, int target, int value) {
    Node* current = head;

    while (current != nullptr && current->rollNumber != target) {
        current = current->next;
    }

    if (current == nullptr) {
        return false;
    }

    Node* newNode = new Node{value, current, current->next};

    if (current->next != nullptr) {
        current->next->prev = newNode;
    }

    current->next = newNode;
    return true;
}

void insertAtEnd(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr, nullptr};

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }

    current->next = newNode;
    newNode->prev = current;
}

void displayList(Node* head) {
    Node* current = head;

    while (current != nullptr) {
        cout << current->rollNumber;
        if (current->next != nullptr) {
            cout << " <-> ";
        }
        current = current->next;
    }

    cout << endl;
}

void freeList(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node* head = nullptr;

    // Create the initial list: 10 <-> 20 <-> 30 <-> 40 <-> 50
    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    insertAtEnd(head, 40);
    insertAtEnd(head, 50);

    cout << "Original student roll numbers: ";
    displayList(head);

    // 1. Add 5 at the start.
    insertAtStart(head, 5);

    // 2. Add 25 after 20.
    if (!insertAfter(head, 20, 25)) {
        cout << "Roll number 20 was not found." << endl;
    }

    // 3. Add 60 at the end.
    insertAtEnd(head, 60);

    // 4. Display the final list.
    cout << "Final doubly linked list: ";
    displayList(head);

    freeList(head);
    return 0;
}
