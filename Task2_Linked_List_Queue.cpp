#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* frontNode = nullptr;
Node* rearNode = nullptr;

bool isEmpty() {
    return frontNode == nullptr;
}

void enqueue(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (isEmpty()) {
        frontNode = rearNode = newNode;
    } else {
        rearNode->next = newNode;
        rearNode = newNode;
    }

    cout << value << " added." << endl;
}

void dequeue() {
    if (isEmpty()) {
        cout << "Queue is EMPTY!" << endl;
        return;
    }

    Node* temp = frontNode;
    cout << temp->data << " removed." << endl;
    frontNode = frontNode->next;

    if (frontNode == nullptr) {
        rearNode = nullptr;
    }

    delete temp;
}

int countNodes() {
    int count = 0;
    Node* temp = frontNode;

    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

void displayRear() {
    if (isEmpty()) {
        cout << "Queue is EMPTY!" << endl;
        return;
    }
    cout << "Rear element: " << rearNode->data << endl;
}

void clearQueue() {
    while (!isEmpty()) {
        Node* temp = frontNode;
        frontNode = frontNode->next;
        delete temp;
    }
    rearNode = nullptr;
    cout << "Queue cleared successfully!" << endl;
}

void display() {
    if (isEmpty()) {
        cout << "Queue is EMPTY!" << endl;
        return;
    }

    Node* temp = frontNode;
    cout << "FRONT => ";
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    enqueue(12);
    enqueue(22);
    enqueue(32);
    enqueue(42);
    enqueue(52);

    cout << "\nQueue: ";
    display();

    cout << "Total Nodes: " << countNodes() << endl;
    displayRear();

    dequeue();

    cout << "\nAfter Dequeue: ";
    display();

    cout << "Total Nodes: " << countNodes() << endl;

    clearQueue();
    display();

    return 0;
}
