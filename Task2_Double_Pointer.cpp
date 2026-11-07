#include <iostream>
using namespace std;

int main() {
    int num = 50;
    int* p = &num;
    int** pp = &p;

    cout << "Original value: " << num << endl;

    **pp = 100;

    cout << "Modified value: " << num << endl;

    return 0;
}
