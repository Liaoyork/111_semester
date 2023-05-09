#include <algorithm>
#include <cstdlib>
#include <iostream>
using namespace std;

int main() {
    srand(0);
    int arr[50];
    for (int i = 0; i < 50; i++) {
        arr[i] = rand() % 150;
    }
    sort(arr, arr + 50);
    for (int i = 0; i < 50; i++) {
        cout << arr[i] << " ";
    }
}
