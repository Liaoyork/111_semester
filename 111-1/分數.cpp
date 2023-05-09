#include <iostream>
using namespace std;
int main() {
    int score;
    int i = 0, j = 0, k = 0, l = 0, m = 0;
    char det = 'y';
    while (1) {
        if (det == 'y') {
            cout << "Score: ";
            cin >> score;
            cout << "continue(y/n)? ";
            cin >> det;
            switch (score) {
                case 0 ... 39:
                    i++;
                    break;
                case 40 ... 59:
                    j++;
                    break;
                case 60 ... 79:
                    k++;
                    break;
                case 80 ... 100:
                    l++;
                    break;
            }
        } else {
            cout << "G-A: ";
            for (m = i; m > 0; m--) {
                cout << "*";
            }
            cout << i << endl;
            cout << "G-B: ";
            for (m = j; m > 0; m--) {
                cout << "*";
            }
            cout << j << endl;
            cout << "G-C: ";
            for (m = k; m > 0; m--) {
                cout << "*";
            }
            cout << k << endl;
            cout << "G-D: ";
            for (m = l; m > 0; m--) {
                cout << "*";
            }
            cout << l << endl;
            break;
        }
    }
    return 0;
}
