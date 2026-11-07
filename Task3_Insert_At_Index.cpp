#include <iostream>
using namespace std;

int main() {
    int arr[5] = {10, 20, 30, 40};
    int n = 4;
    int index = 2;
    int value = 25;

    if (index < 0 || index > n) {
        cout << "Invalid index." << endl;
        return 0;
    }

    for (int i = n; i > index; i--) {
        arr[i] = arr[i - 1];
    }

    arr[index] = value;
    n++;

    cout << "Array after insertion: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
