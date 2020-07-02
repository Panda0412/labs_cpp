#include <iostream>
#include <algorithm>
using namespace std;

int xform(int i) {
    return i*i; // квадрат исходного значения
}

int main() {
    int arr[5] = {0, 1, 2, 3, 4};
//    transform(begin(arr), end(arr), begin(arr), xform);
    for (int i=0; i<5; i++) {
        arr[i] = arr[i]*arr[i];
        cout << arr[i] << " ";
    }
    return 0;
}
