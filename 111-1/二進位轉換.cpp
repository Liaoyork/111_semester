#include <iostream>
using namespace std;
int main() {
    int n, i, a[100];
    while (n = -1) {
        cin >> n;
        while (n > 1) {
            a[i] = n % 2;
            n = n / 2;
            i++;
        }
        a[i] = n;
        for (int k = i; k >= 0; k--) {
            cout << a[k];
        }
        cout << endl;
        i = 0;
    }
    return 0;
}
