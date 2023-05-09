#include <iostream>
using namespace std;

int factorial(int n) {
    if (n == 0)
        return 1;
    return (n * factorial(n - 1));
}
int main() {
    int n, m;
    cin >> n >> m;
    if (n < m)
        return -1;
    if (n < 0 || m < 0)
        return -1;
    int a, b, c;
    a = factorial(n);
    b = factorial(m);
    c = factorial(n - m);
    cout << a / b / c;
}