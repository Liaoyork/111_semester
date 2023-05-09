#include <iostream>
using namespace std;

int main() {
    double high = 0.0, low = 0.0;
    double target = 0.0;
    double high_p = 0.0, low_p = 0.0;
    cout << "target: ";  // enter the target number of people of accumulation
    cin >> target;
    cout << "high_p: ";  // find the score that its number of people of accumulation between "target" and cin higher one number of people of accumulation
    cin >> high_p;
    cout << "low_p: ";  // find the score that its number of people of accumulation between "target" and cin lower one number of people of accumulation
    cin >> low_p;
    cout << "high: ";  // find the score that its number of people of accumulation between "target" and cin higher one score
    cin >> high;
    low = high - 1;
    cout << ((target - high_p) * low + (low_p - target) * high) / (low_p - high_p);
    return 0;
}