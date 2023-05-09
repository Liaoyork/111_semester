#include <iostream>
using namespace std;

void swapp(int &p, int &q) {
    int temp;
    temp = p;
    p = q;
    q = temp;
}
int main() {
    int x = 5;
    int y = 7;

    swapp(x, y);

    cout << x << " " << y;
}
