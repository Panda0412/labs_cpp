#include "lab2_b.h"
#include <iostream>
using namespace std;

int main() {
    // tests
    int size = 5;

    safe_c_array_t<int> arr1 = safe_c_array_t<int>(size);

    cout << "size = " << arr1.get_size() << endl;

    cout << endl << "arr1 (without definition)" << endl;
    for (int i = 0; i < size; ++i) {
        cout << "i = " << i << ": " << arr1[i] << endl;
    }

    safe_c_array_t<int> arr2(size);

    for (int i = 0; i < size; ++i) {
        arr2[i] = i + 1;
    }

    cout << endl << "arr2" << endl;
    for (int i = 0; i < size; ++i) {
        cout << "i = " << i << ": " << arr2[i] << endl;
    }

    safe_c_array_t<int> arr3(arr2);

    cout << endl << "arr3 (equal arr2)" << endl;
    for (int i = 0; i < size; ++i) {
        cout << "i = " << i << ": " << arr3[i] << endl;
    }

    arr1 = arr2;

    cout << endl << "arr1 after assignment (arr1 = arr2)" << endl;
    for (int i = 0; i < size; ++i) {
        cout << "i = " << i << ": " << arr1[i] << endl;
        arr1[i] *= 10;
    }

    arr1 = arr1;

    cout << " (arr1 = arr1)" << endl;
    for (int i = 0; i < size; ++i) {
        cout << "i = " << i << ": " << arr1[i] << endl;
    }
}