#include <iostream>
using namespace std;

int main() {
    int rows, cols;

    cout << "Enter number of rows: ";
    cin >> rows;

    cout << "Enter number of columns: ";
    cin >> cols;

    if (rows <= 0 || cols <= 0) {
        cout << "Rows and columns must be positive." << endl;
        return 0;
    }

    // Dynamically allocate an array of row pointers.
    int** matrix = new int*[rows];

    // Dynamically allocate each row.
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }

    cout << "\nEnter matrix elements:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }

    cout << "\nMatrix:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    // Free each row, then free the array of row pointers.
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    matrix = nullptr;

    cout << "\nMemory freed successfully." << endl;

    return 0;
}
