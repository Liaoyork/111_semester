#include <iostream>
#include <string>
#define f(x) 8 * x* x + 5 * x + 2

using namespace std;

int main() {
    // int m = 0;
    // cout << "input number m: ";
    // cin >> m;1
    // cout << "f(" << m + 2 << ") = " << f((m + 2));
    int* ptr;
    int a[3] = {1, 2, 3};

    ptr = &a[2];

    cout << *ptr;
}