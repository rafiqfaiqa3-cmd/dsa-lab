#include <iostream>
using namespace std;

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int n = 5;

    if (n > 0) {
        for (int i = 0; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        n--;
    }

    cout << "Array after deletion: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
