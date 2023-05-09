#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int *a = new int[n];
    int tol = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    bool first = true;
    for (int i = 0; i <= n - 2; i++) {
        if (first) {
            if (a[0] == 0) {
                tol += a[1];
            }
            first = false;
        } else {
            if (a[i] == 0) {
                if (a[i - 1] < a[i + 1]) {
                    tol += a[i - 1];
                } else {
                    tol += a[i + 1];
                }
            }
        }
    }
    if (a[n - 1] == 0) {
        tol += a[n - 2];
    }
    cout << tol;
    return 0;
}
