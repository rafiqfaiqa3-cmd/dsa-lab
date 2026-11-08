#include <iostream>
using namespace std;

const int SIZE = 5;
int circularQueue[SIZE];
int frontIndex = -1;
int rearIndex = -1;
int count = 0;

bool isEmpty() {
    return count == 0;
}

bool isFull() {
    return count == SIZE;
}

void enqueue(int value) {
    if (isFull()) {
        cout << "Queue is FULL!" << endl;
        return;
    }

    if (isEmpty()) {
        frontIndex = 0;
    }

    rearIndex = (rearIndex + 1) % SIZE;
    circularQueue[rearIndex] = value;
    count++;

    cout << value << " added." << endl;
}

void dequeue() {
    if (isEmpty()) {
        cout << "Queue is EMPTY!" << endl;
        return;
    }

    cout << circularQueue[frontIndex] << " removed." << endl;
    frontIndex = (frontIndex + 1) % SIZE;
    count--;

    if (isEmpty()) {
        frontIndex = -1;
        rearIndex = -1;
    }
}

void display() {
    if (isEmpty()) {
        cout << "Queue is EMPTY!" << endl;
        return;
    }

    cout << "FRONT => ";
    for (int i = 0; i < count; i++) {
        int index = (frontIndex + i) % SIZE;
        cout << circularQueue[index] << " ";
    }
    cout << "<- REAR" << endl;
}

int main() {
    enqueue(101);
    enqueue(102);
    enqueue(103);
    enqueue(104);
    enqueue(105);

    dequeue();
    dequeue();

    enqueue(106);
    enqueue(107);
    enqueue(108);

    cout << "\nFinal Queue:" << endl;
    display();

    cout << "Front = " << frontIndex << endl;
    cout << "Rear = " << rearIndex << endl;
    cout << "Count = " << count << endl;

    return 0;
}
