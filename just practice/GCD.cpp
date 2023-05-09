#include <iostream>
using namespace std;
int gcd_fuc(int n1, int n2) {
    if (n1 < n2) {
        swap(n1, n2);
    }
    if (n1 == 0) return n2;
    if (n2 == 0) return n1;
    gcd_fuc(n1 - n2, n2);
}
int main() {
    int a, b, c;
    cin >> a >> b;
    c = gcd_fuc(a, b);
    cout << c;
}
