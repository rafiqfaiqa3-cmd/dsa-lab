#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

int main() {
    Node* first = new Node();
    Node* second = new Node();
    Node* third = new Node();

    first->data = 90;
    second->data = 30;
    third->data = 10;

    first->next = second;
    second->next = third;
    third->next = nullptr;

    Node* temp = first;

    cout << "Linked List: ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    delete first;
    delete second;
    delete third;

    return 0;
}
