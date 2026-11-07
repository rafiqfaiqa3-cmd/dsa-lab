
#include <iostream>
using namespace std;

const int SIZE = 10;

// Display Array
void displayArray(int arr[]) {
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Selection Sort
void selectionSort(int arr[]) {
    for (int i = 0; i < SIZE - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < SIZE; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

// Bubble Sort
void bubbleSort(int arr[]) {
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = 0; j < SIZE - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Insertion Sort
void insertionSort(int arr[]) {
    for (int i = 1; i < SIZE; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

// Binary Search
int binarySearch(int arr[], int target) {
    int low = 0;
    int high = SIZE - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid;
        }
        else if (arr[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return -1;
}

int main() {
    int arr[SIZE];
    int choice;

    // Input 10 integers
    cout << "Enter 10 integers:" << endl;

    for (int i = 0; i < SIZE; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }

    do {
        cout << "\n===== MENU =====" << endl;
        cout << "1. Selection Sort" << endl;
        cout << "2. Bubble Sort" << endl;
        cout << "3. Insertion Sort" << endl;
        cout << "4. Binary Search" << endl;
        cout << "5. Display Array" << endl;
        cout << "0. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                selectionSort(arr);
                cout << "Array after Selection Sort: ";
                displayArray(arr);
                break;

            case 2:
                bubbleSort(arr);
                cout << "Array after Bubble Sort: ";
                displayArray(arr);
                break;

            case 3:
                insertionSort(arr);
                cout << "Array after Insertion Sort: ";
                displayArray(arr);
                break;

            case 4: {
                // Copy and sort array before Binary Search
                int sortedArr[SIZE];

                for (int i = 0; i < SIZE; i++) {
                    sortedArr[i] = arr[i];
                }

                insertionSort(sortedArr);

                int target;
                cout << "Enter number to search: ";
                cin >> target;

                int result = binarySearch(sortedArr, target);

                if (result != -1) {
                    cout << "Element found at position "
                         << result + 1 << " in sorted array." << endl;
                }
                else {
                    cout << "Element not found!" << endl;
                }

                break;
            }

            case 5:
                cout << "Current Array: ";
                displayArray(arr);
                break;

            case 0:
                cout << "Program Exited." << endl;
                break;

            default:
                cout << "Invalid Choice! Try Again." << endl;
        }

    } while (choice != 0);

    return 0;
}
