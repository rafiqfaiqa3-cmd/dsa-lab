#include <iostream>
using namespace std;

int main() {
    int arr[5] = {10, 15, 20, 25, 30};
    int* ptr = arr;

    int even = 0, odd = 0;

    for (int i = 0; i < 5; i++) {
        if (*(ptr + i) % 2 == 0) {
            even++;
        } else {
            odd++;
        }
    }

    cout << "Even numbers: " << even << endl;
    cout << "Odd numbers: " << odd << endl;

    return 0;
}
