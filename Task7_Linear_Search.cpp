#include <iostream>
using namespace std;

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int n = 5;
    int target = 40;
    int foundIndex = -1;

    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex != -1) {
        cout << target << " found at index " << foundIndex << "." << endl;
    } else {
        cout << target << " not found." << endl;
    }

    return 0;
}
