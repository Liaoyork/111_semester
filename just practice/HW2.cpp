#include <iostream>
#include <sstream>
using namespace std;

int chocolate = 0;
int coupon = 0;

void change(int n) {
    if (n < 7) {
        return;
    }
    if (n >= 7) {
        chocolate += n / 7;
        coupon -= n / 7 * 7;
        coupon += n / 7;
        change(coupon);
    }
}
int main() {
    int money = 0;
    cin >> money;
    chocolate = money;
    coupon = money;
    change(coupon);
    cout << chocolate << " " << coupon;
}