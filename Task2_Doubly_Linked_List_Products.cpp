#include <iostream>
using namespace std;

struct Node {
    int productID;
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

    while (current != nullptr && current->productID != target) {
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

bool deleteFirst(Node*& head) {
    if (head == nullptr) {
        return false;
    }

    Node* temp = head;
    head = head->next;

    if (head != nullptr) {
        head->prev = nullptr;
    }

    delete temp;
    return true;
}

bool deleteByValue(Node*& head, int value) {
    Node* current = head;

    while (current != nullptr && current->productID != value) {
        current = current->next;
    }

    if (current == nullptr) {
        return false;
    }

    if (current->prev != nullptr) {
        current->prev->next = current->next;
    } else {
        head = current->next;
    }

    if (current->next != nullptr) {
        current->next->prev = current->prev;
    }

    delete current;
    return true;
}

bool deleteLast(Node*& head) {
    if (head == nullptr) {
        return false;
    }

    Node* current = head;

    if (current->next == nullptr) {
        delete current;
        head = nullptr;
        return true;
    }

    while (current->next != nullptr) {
        current = current->next;
    }

    current->prev->next = nullptr;
    delete current;
    return true;
}

void displayList(Node* head) {
    Node* current = head;

    while (current != nullptr) {
        cout << current->productID;
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

    // Create the initial list: 101 <-> 102 <-> 103 <-> 104 <-> 105
    insertAtEnd(head, 101);
    insertAtEnd(head, 102);
    insertAtEnd(head, 103);
    insertAtEnd(head, 104);
    insertAtEnd(head, 105);

    cout << "Original product IDs: ";
    displayList(head);

    // 1. Add product 100 at the start.
    insertAtStart(head, 100);

    // 2. Add product 1035 after product 103.
    if (!insertAfter(head, 103, 1035)) {
        cout << "Product 103 was not found." << endl;
    }

    // 3. Add product 106 at the end.
    insertAtEnd(head, 106);

    // 4. Delete the first product.
    deleteFirst(head);

    // 5. Delete product 104.
    if (!deleteByValue(head, 104)) {
        cout << "Product 104 was not found." << endl;
    }

    // 6. Delete the last product.
    deleteLast(head);

    // 7. Display the final list.
    cout << "Final doubly linked list: ";
    displayList(head);

    freeList(head);
    return 0;
}
